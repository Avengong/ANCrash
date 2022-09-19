//
// Created by Avengong on 2022/9/17.
//
#include "xcc_unwind.h"
#include "xcc_unwind_libcorkscrew.h"
#include "xcc_unwind_libunwind.h"
#include "xcc_unwind_clang.h"


void xcc_unwind_init(int api_level) {

#if defined(__arm__) || defined(__i386__)
    //在4.1.1以上，5.0以下：使用安卓系统自带的libcorkscrew.so
    if (api_level >= 16 && api_level <= 20) {
        xcc_unwind_libcorkscrew_init();
    }
#endif
    // 5.0以上：安卓系统中没有了libcorkscrew.so，使用自己编译的libunwind，也存在系统中
//    if(api_level >= 21 && api_level <= 23)
    if (api_level >= 21) {

        xcc_unwind_libunwind_init();
    }


}

size_t xcc_unwind_get(int api_level, siginfo_t *si, ucontext_t *uc, char *buf, size_t len) {

    size_t used = 0;

#if defined(__arm__) || defined(__i386__)
    if (api_level >= 16 && api_level <= 20) {
        used = xcc_unwind_libcorkscrew_record(si, uc, buf, len);
        return used;
    }

#else
    (void)si;
#endif

//    if(api_level >= 21 && api_level <= 23)
    if (api_level >= 21) {
        used = xcc_unwind_libunwind_record(uc, buf, len);
        return used;
    }
    return xcc_unwind_clang_record(uc, buf, len);
}
