2022-08-21 09:59:44.356 3251-3251/? I/crash_dump64: obtaining output fd from tombstoned, type:
kDebuggerdTombstone

2022-08-21 09:59:44.367 798-798/? I/tombstoned: received crash request for pid 20591 2022-08-21 09:
59:44.368 3251-3251/? I/crash_dump64: performing dump of process 20591 (target tid = 20591)
2022-08-21 09:59:44.372 3251-3251/?
A/DEBUG: *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
2022-08-21 09:59:44.372 3251-3251/? A/DEBUG: Build fingerprint: 'OnePlus/OnePlus9_IND/OnePlus9:
11/RKQ1.201105.002/2111112053:user/release-keys' 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:
Revision: '0' 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG: ABI: 'arm64' 2022-08-21 09:59:44.372
3251-3251/? A/DEBUG: Timestamp: 2022-08-21 09:59:44+0800 2022-08-21 09:59:44.372 3251-3251/?
A/DEBUG: pid: 20591, tid: 20591, name: .zygote.insight  >>> com.zygote.insight <<<
2022-08-21 09:59:44.372 3251-3251/? A/DEBUG: uid: 10274 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:
signal 11 (SIGSEGV), code 1 (SEGV_MAPERR), fault addr 0x0 2022-08-21 09:59:44.372 3251-3251/?
A/DEBUG: Cause: null pointer dereference 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:     x0
0000000000000001 x1 0000000000000000 x2 0000000000000050 x3 0000000000000003 2022-08-21 09:59:44.372
3251-3251/? A/DEBUG:     x4 0000007ff0e3b540 x5 0000000000000030 x6 fefefefefefefeff x7
7f7f7f7f7f7f7f7f 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:     x8 0000000000000000 x9
5f555c83bb53cef7 x10 0000000000000001 x11 0000000000000000 2022-08-21 09:59:44.372 3251-3251/?
A/DEBUG:     x12 0000007ff0e3b660 x13 000000000000002a x14 0012af0982e47a8a x15 0000000034155555
2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:     x16 0000007467a74740 x17 0000007467d42fdc x18
fffffffffffffff7 x19 b4000072e3487010 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:     x20
0000000000000000 x21 b4000072e3487010 x22 00000074697be000 x23 b4000072e34870c8 2022-08-21 09:59:
44.372 3251-3251/? A/DEBUG:     x24 000000715d796eb8 x25 00000074697be000 x26 0000000000000069 x27
0000000000000002 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:     x28 0000007ff0e3cee0 x29
0000007ff0e3ceb0 2022-08-21 09:59:44.372 3251-3251/? A/DEBUG:     lr 00000070f60d4008 sp
0000007ff0e3ce00 pc 00000070f60d4018 pst 0000000060001000 2022-08-21 09:59:44.406 1782-3246/?
D/AudioTrack: ClientUid 1000 AudioTrack::stop 2022-08-21 09:59:44.437 27790-27790/? W/DetectPable:
type=1400 audit(0.0:612828): avc: denied { getattr } for path="/proc/keys" dev="proc" ino=4026532168
scontext=u:r:shell:s0 tcontext=u:object_r:proc_keys:s0 tclass=file permissive=0 2022-08-21 09:59:
44.472 1117-1459/? D/APM_AudioPolicyManager: stopOutput() output 13, stream 1, session 81, portId 35
2022-08-21 09:59:44.472 1782-2904/? I/system_server: oneway function results will be dropped but
finished with status OK and parcel size 4 2022-08-21 09:59:44.551 3251-3251/? A/DEBUG: backtrace:
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #00 pc 000000000000f018 /data/app/~~
girCZu1Bfdsqkfp41nkaUg==/com.zygote.insight-_SJh1eio5C0bRFvIPSjsRg==/lib/arm64/libinsight.so (
Java_com_zygote_insight_SecondActivity_tellJNI+228) (BuildId:
8e9fc828b718c64790f2c09554cb6e3bb71201cf)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #01 pc 000000000013ced4
/apex/com.android.art/lib64/libart.so (art_quick_generic_jni_trampoline+148) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #02 pc 0000000000133564
/apex/com.android.art/lib64/libart.so (art_quick_invoke_stub+548) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #03 pc 00000000001a8a78
/apex/com.android.art/lib64/libart.so (art::ArtMethod::Invoke(art::Thread*, unsigned int*, unsigned
int, art::JValue*, char const*)+200) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #04 pc 00000000003185d8
/apex/com.android.art/lib64/libart.so (art::interpreter::ArtInterpreterToCompiledCodeBridge(art::
Thread*, art::ArtMethod*, art::ShadowFrame*, unsigned short, art::JValue*)+376) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #05 pc 000000000030e904
/apex/com.android.art/lib64/libart.so (bool art::interpreter::DoCall<false, false>(art::ArtMethod*,
art::Thread*, art::ShadowFrame&, art::Instruction const*, unsigned short, art::JValue*)+996) (
BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #06 pc 000000000067ccf4
/apex/com.android.art/lib64/libart.so (MterpInvokeVirtual+848) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #07 pc 000000000012d814
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_virtual+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #08 pc
000000000003d1d8  [anon:dalvik-classes2.dex extracted in memory from /data/app/~~girCZu1Bfdsqkfp41nkaUg==/com.zygote.insight-_SJh1eio5C0bRFvIPSjsRg==/base.apk!classes2.dex] (
com.zygote.insight.SecondActivity.sendJNI+4)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #09 pc 0000000000305f00
/apex/com.android.art/lib64/libart.so (art::interpreter::Execute(art::Thread*, art::
CodeItemDataAccessor const&, art::ShadowFrame&, art::JValue, bool, bool) (
.llvm.12004784806048457752)+268) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #10 pc 000000000066b9fc
/apex/com.android.art/lib64/libart.so (artQuickToInterpreterBridge+780) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #11 pc 000000000013cff8
/apex/com.android.art/lib64/libart.so (art_quick_to_interpreter_bridge+88) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #12 pc 0000000000133564
/apex/com.android.art/lib64/libart.so (art_quick_invoke_stub+548) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #13 pc 00000000001a8a78
/apex/com.android.art/lib64/libart.so (art::ArtMethod::Invoke(art::Thread*, unsigned int*, unsigned
int, art::JValue*, char const*)+200) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #14 pc 0000000000555e64
/apex/com.android.art/lib64/libart.so (art::InvokeMethod(art::ScopedObjectAccessAlreadyRunnable
const&, _jobject*, _jobject*, _jobject*, unsigned long)+1364) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #15 pc 00000000004d5548
/apex/com.android.art/lib64/libart.so (art::Method_invoke(_JNIEnv*, _jobject*, _jobject*, _
jobjectArray*)+52) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #16 pc 000000000008a6f4
/apex/com.android.art/javalib/arm64/boot.oat (art_jni_trampoline+180) (BuildId:
f3abbf7f7b16d75544b33437039cf4d7fc3bf37d)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #17 pc 0000000000133564
/apex/com.android.art/lib64/libart.so (art_quick_invoke_stub+548) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #18 pc 00000000001a8a78
/apex/com.android.art/lib64/libart.so (art::ArtMethod::Invoke(art::Thread*, unsigned int*, unsigned
int, art::JValue*, char const*)+200) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #19 pc 00000000003185d8
/apex/com.android.art/lib64/libart.so (art::interpreter::ArtInterpreterToCompiledCodeBridge(art::
Thread*, art::ArtMethod*, art::ShadowFrame*, unsigned short, art::JValue*)+376) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #20 pc 000000000030e904
/apex/com.android.art/lib64/libart.so (bool art::interpreter::DoCall<false, false>(art::ArtMethod*,
art::Thread*, art::ShadowFrame&, art::Instruction const*, unsigned short, art::JValue*)+996) (
BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #21 pc 000000000067ccf4
/apex/com.android.art/lib64/libart.so (MterpInvokeVirtual+848) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #22 pc 000000000012d814
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_virtual+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #23 pc
00000000001e69ca  [anon:dalvik-classes.dex extracted in memory from /data/app/~~girCZu1Bfdsqkfp41nkaUg==/com.zygote.insight-_SJh1eio5C0bRFvIPSjsRg==/base.apk] (
android.support.v7.app.AppCompatViewInflater$DeclaredOnClickListener.onClick+50)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #24 pc 000000000067e9cc
/apex/com.android.art/lib64/libart.so (MterpInvokeInterface+1808) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #25 pc 000000000012da14
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_interface+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #26 pc 00000000002c831c
/system/framework/framework.jar (offset 0x1261000) (android.view.View.performClick+60)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #27 pc 000000000067cf94
/apex/com.android.art/lib64/libart.so (MterpInvokeVirtual+1520) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #28 pc 000000000012d814
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_virtual+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #29 pc 00000000002c834e
/system/framework/framework.jar (offset 0x1261000) (android.view.View.performClickInternal+6)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #30 pc 000000000067f610
/apex/com.android.art/lib64/libart.so (MterpInvokeDirect+1248) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #31 pc 000000000012d914
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_direct+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #32 pc 00000000002c399c
/system/framework/framework.jar (offset 0x1261000) (android.view.View.access$3600)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #33 pc 000000000067fef0
/apex/com.android.art/lib64/libart.so (MterpInvokeStatic+1224) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #34 pc 000000000012d994
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_static+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #35 pc 000000000029efdc
/system/framework/framework.jar (offset 0x1261000) (android.view.View$PerformClick.run+16)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #36 pc 000000000067e9cc
/apex/com.android.art/lib64/libart.so (MterpInvokeInterface+1808) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #37 pc 000000000012da14
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_interface+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #38 pc 000000000037d91c
/system/framework/framework.jar (offset 0x931000) (android.os.Handler.handleCallback+4)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #39 pc 000000000067fef0
/apex/com.android.art/lib64/libart.so (MterpInvokeStatic+1224) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #40 pc 000000000012d994
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_static+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #41 pc 000000000037d788
/system/framework/framework.jar (offset 0x931000) (android.os.Handler.dispatchMessage+8)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #42 pc 000000000067cf94
/apex/com.android.art/lib64/libart.so (MterpInvokeVirtual+1520) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #43 pc 000000000012d814
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_virtual+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #44 pc 00000000003a5928
/system/framework/framework.jar (offset 0x931000) (android.os.Looper.loop+560)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #45 pc 0000000000305f00
/apex/com.android.art/lib64/libart.so (art::interpreter::Execute(art::Thread*, art::
CodeItemDataAccessor const&, art::ShadowFrame&, art::JValue, bool, bool) (
.llvm.12004784806048457752)+268) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #46 pc 000000000030def0
/apex/com.android.art/lib64/libart.so (art::interpreter::ArtInterpreterToInterpreterBridge(art::
Thread*, art::CodeItemDataAccessor const&, art::ShadowFrame*, art::JValue*)+200) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #47 pc 000000000030f2d8
/apex/com.android.art/lib64/libart.so (bool art::interpreter::DoCall<false, true>(art::ArtMethod*,
art::Thread*, art::ShadowFrame&, art::Instruction const*, unsigned short, art::JValue*)+1772) (
BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #48 pc 0000000000177f40
/apex/com.android.art/lib64/libart.so (void art::interpreter::ExecuteSwitchImplCpp<true, false>(
art::interpreter::SwitchImplContext*)+57848) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #49 pc 000000000013f7d8
/apex/com.android.art/lib64/libart.so (ExecuteSwitchImplAsm+8) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #50 pc 00000000001a5368
/system/framework/framework.jar (android.app.ActivityThread.main)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #51 pc 0000000000306008
/apex/com.android.art/lib64/libart.so (art::interpreter::Execute(art::Thread*, art::
CodeItemDataAccessor const&, art::ShadowFrame&, art::JValue, bool, bool) (
.llvm.12004784806048457752)+532) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #52 pc 000000000066b9fc
/apex/com.android.art/lib64/libart.so (artQuickToInterpreterBridge+780) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #53 pc 000000000013cff8
/apex/com.android.art/lib64/libart.so (art_quick_to_interpreter_bridge+88) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #54 pc 00000000001337e8
/apex/com.android.art/lib64/libart.so (art_quick_invoke_static_stub+568) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #55 pc 00000000001a8a94
/apex/com.android.art/lib64/libart.so (art::ArtMethod::Invoke(art::Thread*, unsigned int*, unsigned
int, art::JValue*, char const*)+228) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #56 pc 0000000000555e64
/apex/com.android.art/lib64/libart.so (art::InvokeMethod(art::ScopedObjectAccessAlreadyRunnable
const&, _jobject*, _jobject*, _jobject*, unsigned long)+1364) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #57 pc 00000000004d5548
/apex/com.android.art/lib64/libart.so (art::Method_invoke(_JNIEnv*, _jobject*, _jobject*, _
jobjectArray*)+52) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #58 pc 000000000008a6f4
/apex/com.android.art/javalib/arm64/boot.oat (art_jni_trampoline+180) (BuildId:
f3abbf7f7b16d75544b33437039cf4d7fc3bf37d)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #59 pc 0000000000133564
/apex/com.android.art/lib64/libart.so (art_quick_invoke_stub+548) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #60 pc 00000000001a8a78
/apex/com.android.art/lib64/libart.so (art::ArtMethod::Invoke(art::Thread*, unsigned int*, unsigned
int, art::JValue*, char const*)+200) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #61 pc 00000000003185d8
/apex/com.android.art/lib64/libart.so (art::interpreter::ArtInterpreterToCompiledCodeBridge(art::
Thread*, art::ArtMethod*, art::ShadowFrame*, unsigned short, art::JValue*)+376) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #62 pc 000000000030e904
/apex/com.android.art/lib64/libart.so (bool art::interpreter::DoCall<false, false>(art::ArtMethod*,
art::Thread*, art::ShadowFrame&, art::Instruction const*, unsigned short, art::JValue*)+996) (
BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #63 pc 000000000067ccf4
/apex/com.android.art/lib64/libart.so (MterpInvokeVirtual+848) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #64 pc 000000000012d814
/apex/com.android.art/lib64/libart.so (mterp_op_invoke_virtual+20) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #65 pc 00000000004c7cca
/system/framework/framework.jar (offset 0x1261000) (
com.android.internal.os.RuntimeInit$MethodAndArgsCaller.run+22)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #66 pc 0000000000305f00
/apex/com.android.art/lib64/libart.so (art::interpreter::Execute(art::Thread*, art::
CodeItemDataAccessor const&, art::ShadowFrame&, art::JValue, bool, bool) (
.llvm.12004784806048457752)+268) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #67 pc 000000000066b9fc
/apex/com.android.art/lib64/libart.so (artQuickToInterpreterBridge+780) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:47.537 27790-27790/? W/DetectPable: type=1400 audit(0.0:612984): avc: denied {
getattr } for path="/proc/misc" dev="proc" ino=4026531984 scontext=u:r:shell:s0 tcontext=u:object_r:
proc_misc:s0 tclass=file permissive=0 2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #68 pc
000000000013cff8 /apex/com.android.art/lib64/libart.so (art_quick_to_interpreter_bridge+88) (
BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #69 pc 00000000008d82ac
/system/framework/arm64/boot-framework.oat (com.android.internal.os.ZygoteInit.main+2444) (BuildId:
4861aef26d9f3da0d4537372da9bd0a1e6e40c27)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #70 pc 00000000001337e8
/apex/com.android.art/lib64/libart.so (art_quick_invoke_static_stub+568) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #71 pc 00000000001a8a94
/apex/com.android.art/lib64/libart.so (art::ArtMethod::Invoke(art::Thread*, unsigned int*, unsigned
int, art::JValue*, char const*)+228) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #72 pc 00000000005548a0
/apex/com.android.art/lib64/libart.so (art::JValue art::InvokeWithVarArgs<art::ArtMethod*>(art::
ScopedObjectAccessAlreadyRunnable const&, _jobject*, art::ArtMethod*, std::__va_list)+448) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #73 pc 0000000000554d54
/apex/com.android.art/lib64/libart.so (art::JValue art::InvokeWithVarArgs<_jmethodID*>(art::
ScopedObjectAccessAlreadyRunnable const&, _jobject*, _jmethodID*, std::__va_list)+92) (BuildId:
f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #74 pc 0000000000438e74
/apex/com.android.art/lib64/libart.so (art::JNI<true>::CallStaticVoidMethodV(_JNIEnv*, _jclass*, _
jmethodID*, std::__va_list)+656) (BuildId: f7fe6fddde911f51d36098ac151be391)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #75 pc 000000000009b424
/system/lib64/libandroid_runtime.so (_JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
+124) (BuildId: 3b5caf554fabd6283ba9f03b94513fb6)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #76 pc 00000000000a34e8
/system/lib64/libandroid_runtime.so (android::AndroidRuntime::start(char const*, android::
Vector<android::String8> const&, bool)+836) (BuildId: 3b5caf554fabd6283ba9f03b94513fb6)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #77 pc 0000000000003674
/system/bin/app_process64 (main+1580) (BuildId: 877d617e6836814ff828a92ca826a70e)
2022-08-21 09:59:44.551 3251-3251/? A/DEBUG:       #78 pc 00000000000499e4
/apex/com.android.runtime/lib64/bionic/libc.so (__libc_init+108) (BuildId:
07fbaeed7b7a19203975f06be6f1d5ef)
2022-08-21 09:59:44.762 798-798/? E/tombstoned: Tombstone written to: /data/tombstones/tombstone_03