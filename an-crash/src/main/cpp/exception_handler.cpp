//
// Created by Avengong on 2022/9/15.
//
#include "jni.h"
#include "signal.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <signal.h>
#include <sys/syscall.h>
#include "exception_handler.h"
#include "an_common.h"
#include "xcc_fmt.h"
#include "xcc_errno.h"
#include "xcc_unwind.h"
#include "xcc_util.h"

#define AN_CRASH_EMERGENCY_BUF_LEN (30*1024)
//#define XC_CRASH_EMERGENCY_BUF_LEN         (30 * 1024)

size_t dump_backtrace(char *buf, size_t len, siginfo_t *si, ucontext_t *uc) {
    // 如何去获取调用堆栈呢？
    // 我的想法： 根据当前奔溃的寄存器pc、sp得到当前函数栈帧的区间 fp-sp(因为pc的地址)。
    size_t used = 0;
    used += xcc_fmt_snprintf(buf + used, len - used, "\n backtrace:\n ");

    // 原理：在调用函数时候，会开辟新栈内存空间。同时会把当前调用者的fp、sp寄存器值(main函数)入栈，以及返回地址lr都保存到新的函数栈中。
    //当处理完后，会把之前存储的fp、sp、lr等重新赋值给寄存器。 继续执行main()函数。
    //因此，当奔溃发生时，我们可以查找栈内的fp、sp，以恢复mian()函数。
    //
    // 疑问，如何找栈内main函数的fp和sp呢？

    // 原理2： 利用elf文件中有一个.eh_frame段。它记录了fp寄存器的变更记录，我们可以从这个恢复函数的fp，从而得出调用堆栈。

    //不管是哪种方式，我们都只是得到了内存的编号调用序列。那么如何得到这些内存地址对应的符号呢？
    //1. 通过符号表 .sysmtab。但是只能是debug
    //2. 通过.dynamtab 和 .strtab??


    //方式一，通过fp unwind
//    used+= xcc_fmt_snprintf(buf+used,len-used,"%",);

    used += xcc_unwind_get(29, si, uc, buf + used, len - used);

    if (used >= len - 1) {
        buf[len - 3] = '\n';
        buf[len - 2] = '\0';
        used = len - 2;
    }
    used += xcc_fmt_snprintf(buf + used, len - used, "\n");
    return used;
}


namespace {
    const int siglist[] = {SIGSEGV, SIGABRT, SIGFPE, SIGILL, SIGBUS, SIGTRAP};
    const int sig_size = sizeof(siglist) / sizeof(siglist[0]);
    bool handlers_installed = false;
    struct sigaction old_handlers[sig_size];
    char *xc_crash_emergency;
}

int rethrow_sig() {
    int r = 1;
    for (int i = 0; i < sig_size; i++) {
        sigaction(siglist[i], &old_handlers[i], NULL);
    }
    return r;
}


size_t dump_signal_info(char *buf, size_t len, siginfo_t *si) {
    ALOGV("sinal info dump_signal_info . xc_common_process_id:%lu", xc_common_process_id);
    int signum = si->si_signo;
    const char *name = xcc_util_get_signame(si);
    int code = si->si_code;
    const char *codename = xcc_util_get_sigcodename(si);
    // 获取信号的发送者信息
    char sender_desc[64] = "";
    ALOGV("---from sender_desc:%s, addr:%p，pointsize:%d", sender_desc, sender_desc,
          sizeof(codename));
    //--from sender_desc:C�ٕr���@, addr:0x75162be858，pointsize:8
    //---from sender_desc:, addr:0x746a91e858，pointsize:8  40位地址？？
    // 解答：理论上是位64。但是目前志勇了48位。因为用不到这么宽的地址。因为浪费。 二Android这里用的是40位。
//    ALOGV("---from pid %d, uid %d",si->si_pid,
//          si->si_uid );
    if (xcc_util_signal_has_sender(si, xc_common_process_id)) {
        xcc_fmt_snprintf(sender_desc, sizeof(sender_desc), "from pid %d, uid %d", si->si_pid,
                         si->si_uid);
    }

    ALOGV(">> dump_signal_info >> sender_desc name:%s,,codename:%s，", name, codename);
    char addr_desc[64];
    if (xcc_util_signal_has_si_addr(si)) {
        xcc_fmt_snprintf(addr_desc, sizeof(addr_desc), "%p", si->si_addr);
    } else {
        xcc_fmt_snprintf(addr_desc, sizeof(addr_desc), "--------");
    }
//    ALOGV(">> dump_signal_info >> buf... sender_desc:%s,addr_desc:%s ",sender_desc,addr_desc);
    return xcc_fmt_snprintf(buf, len, "signal %d (%s), code %d "
                                      "(%s%s), fault addr %s\n",
                            si->si_signo, name,
                            si->si_code, codename, sender_desc, addr_desc);

}

size_t dump_regs(char *buf, size_t len, siginfo_t *si, ucontext_t *uc) {
    // 获取寄存器，重点是获取arm平台： sp、lr、pc
    // x86平台： ebp   rsp   rip 三个值
#if defined(__aarch64__)

    // 32个寄存器(30个常规，一个sp寄存器、一个lr寄存器) + pc地址
    return xcc_fmt_snprintf(buf, len,
                            "    x0  %016lx  x1  %016lx  x2  %016lx  x3  %016lx\n"
                            "    x4  %016lx  x5  %016lx  x6  %016lx  x7  %016lx\n"
                            "    x8  %016lx  x9  %016lx  x10 %016lx  x11 %016lx\n"
                            "    x12 %016lx  x13 %016lx  x14 %016lx  x15 %016lx\n"
                            "    x16 %016lx  x17 %016lx  x18 %016lx  x19 %016lx\n"
                            "    x20 %016lx  x21 %016lx  x22 %016lx  x23 %016lx\n"
                            "    x24 %016lx  x25 %016lx  x26 %016lx  x27 %016lx\n"
                            "    x28 %016lx  x29 %016lx\n"
                            "    sp  %016lx  lr  %016lx  pc  %016lx\n\n",
                            uc->uc_mcontext.regs[0],
                            uc->uc_mcontext.regs[1],
                            uc->uc_mcontext.regs[2],
                            uc->uc_mcontext.regs[3],
                            uc->uc_mcontext.regs[4],
                            uc->uc_mcontext.regs[5],
                            uc->uc_mcontext.regs[6],
                            uc->uc_mcontext.regs[7],
                            uc->uc_mcontext.regs[8],
                            uc->uc_mcontext.regs[9],
                            uc->uc_mcontext.regs[10],
                            uc->uc_mcontext.regs[11],
                            uc->uc_mcontext.regs[12],
                            uc->uc_mcontext.regs[13],
                            uc->uc_mcontext.regs[14],
                            uc->uc_mcontext.regs[15],
                            uc->uc_mcontext.regs[16],
                            uc->uc_mcontext.regs[17],
                            uc->uc_mcontext.regs[18],
                            uc->uc_mcontext.regs[19],
                            uc->uc_mcontext.regs[20],
                            uc->uc_mcontext.regs[21],
                            uc->uc_mcontext.regs[22],
                            uc->uc_mcontext.regs[23],
                            uc->uc_mcontext.regs[24],
                            uc->uc_mcontext.regs[25],
                            uc->uc_mcontext.regs[26],
                            uc->uc_mcontext.regs[27],
                            uc->uc_mcontext.regs[28],
                            uc->uc_mcontext.regs[29],
                            uc->uc_mcontext.sp,
                            uc->uc_mcontext.regs[30], //lr
                            uc->uc_mcontext.pc);
#elif defined(__arm__)
    return xcc_fmt_snprintf(buf, len,
                            "    r0  %08x  r1  %08x  r2  %08x  r3  %08x\n"
                            "    r4  %08x  r5  %08x  r6  %08x  r7  %08x\n"
                            "    r8  %08x  r9  %08x  r10 %08x  r11 %08x\n"
                            "    ip  %08x  sp  %08x  lr  %08x  pc  %08x\n\n",
                            uc->uc_mcontext.arm_r0,
                            uc->uc_mcontext.arm_r1,
                            uc->uc_mcontext.arm_r2,
                            uc->uc_mcontext.arm_r3,
                            uc->uc_mcontext.arm_r4,
                            uc->uc_mcontext.arm_r5,
                            uc->uc_mcontext.arm_r6,
                            uc->uc_mcontext.arm_r7,
                            uc->uc_mcontext.arm_r8,
                            uc->uc_mcontext.arm_r9,
                            uc->uc_mcontext.arm_r10,
                            uc->uc_mcontext.arm_fp,
                            uc->uc_mcontext.arm_ip,
                            uc->uc_mcontext.arm_sp,
                            uc->uc_mcontext.arm_lr,
                            uc->uc_mcontext.arm_pc);

#elif defined(__x86_64__)
    return xcc_fmt_snprintf(buf, len,
                            "    rax %016lx  rbx %016lx  rcx %016lx  rdx %016lx\n"
                            "    r8  %016lx  r9  %016lx  r10 %016lx  r11 %016lx\n"
                            "    r12 %016lx  r13 %016lx  r14 %016lx  r15 %016lx\n"
                            "    rdi %016lx  rsi %016lx\n"
                            "    rbp %016lx  rsp %016lx  rip %016lx\n\n",
                            uc->uc_mcontext.gregs[REG_RAX],
                            uc->uc_mcontext.gregs[REG_RBX],
                            uc->uc_mcontext.gregs[REG_RCX],
                            uc->uc_mcontext.gregs[REG_RDX],
                            uc->uc_mcontext.gregs[REG_R8],
                            uc->uc_mcontext.gregs[REG_R9],
                            uc->uc_mcontext.gregs[REG_R10],
                            uc->uc_mcontext.gregs[REG_R11],
                            uc->uc_mcontext.gregs[REG_R12],
                            uc->uc_mcontext.gregs[REG_R13],
                            uc->uc_mcontext.gregs[REG_R14],
                            uc->uc_mcontext.gregs[REG_R15],
                            uc->uc_mcontext.gregs[REG_RDI],
                            uc->uc_mcontext.gregs[REG_RSI],
                            uc->uc_mcontext.gregs[REG_RBP],
                            uc->uc_mcontext.gregs[REG_RSP],
                            uc->uc_mcontext.gregs[REG_RIP]);
#elif defined(__i386__)
    return xcc_fmt_snprintf(buf, len,
                            "    eax %08x  ebx %08x  ecx %08x  edx %08x\n"
                            "    edi %08x  esi %08x\n"
                            "    ebp %08x  esp %08x  eip %08x\n\n",
                            uc->uc_mcontext.gregs[REG_EAX],
                            uc->uc_mcontext.gregs[REG_EBX],
                            uc->uc_mcontext.gregs[REG_ECX],
                            uc->uc_mcontext.gregs[REG_EDX],
                            uc->uc_mcontext.gregs[REG_EDI],
                            uc->uc_mcontext.gregs[REG_ESI],
                            uc->uc_mcontext.gregs[REG_EBP],
                            uc->uc_mcontext.gregs[REG_ESP],
                            uc->uc_mcontext.gregs[REG_EIP]);
//    xcc_fmt_snprintf(buf,len,"eax %08x ebx %08x ecx %08x  edx %08x\n "
//                             "edi %08x  esi %08x\n"
//                             "ebp %08x esp %08x eip %08x \n\n",uc->uc_mcontext.gregs[REG_EAX]);

#endif

}

void sig_handler(int sig, siginfo_t *siginfo, void *uc) {

    // 11
    ALOGD("i catcher the signal!!! ,ready to rethrow sig:%d", sig);
    rethrow_sig();
//    the crash si_code :1,si_errno:0,si_signo:11
    ALOGD("the crash si_code :%d,si_errno:%d,si_signo:%d ", siginfo->si_code, siginfo->si_errno,
          siginfo->si_signo);
    // 根据不同平台获取uc 结构体
    ucontext_t *context = (ucontext_t *) uc;
//    memcpy(context, uc, sizeof(ucontext));
    size_t used = 0;
    // 获取奔溃信号信息、奔溃的地址
    used += dump_signal_info(xc_crash_emergency + used, AN_CRASH_EMERGENCY_BUF_LEN - used, siginfo);
    // 获取寄存器信息
    used += dump_regs(xc_crash_emergency + used, AN_CRASH_EMERGENCY_BUF_LEN - used, siginfo,
                      context);
//    sp  0000007ff3d78170  lr  00000074240570e0  pc  00000074240570f0
    // 获取调用堆栈

    char *newBuf;
    newBuf = static_cast<char *>(calloc(AN_CRASH_EMERGENCY_BUF_LEN, 1));
    used += dump_backtrace(newBuf, AN_CRASH_EMERGENCY_BUF_LEN, siginfo, context);
    ALOGV("sinal info show: >>> : %s,\n newBuf:%s", xc_crash_emergency, newBuf);

    exit:


    return;
}


int initAnCatch(const char *path) {

    if (handlers_installed)
        return 0;

    // 分配紧急情况下的内存,分配了3k的内存块。同时返回内存块的首地址编号。指针指向了该内存块。后续可以往里面写内容
    if (NULL ==
        (xc_crash_emergency = static_cast<char *>(calloc(AN_CRASH_EMERGENCY_BUF_LEN, 1))))
        return XCC_ERRNO_NOMEM;
    xc_common_process_id = getpid();
    xcc_unwind_init(29);

    // 注册信号
    struct sigaction si;
    memset(&si, 0, sizeof(si));
    si.sa_sigaction = sig_handler;
    si.sa_flags = SA_RESTART | SA_SIGINFO | SA_ONSTACK;

    for (int i = 0; i < sig_size; i++) {
        sigaction(siglist[i], &si, &old_handlers[i]);
    }
    handlers_installed = true;

    return 1;
}










