//
// Created by Avengong on 2022/9/15.
//

/**
 * 1. 注册信号
 *      提供jni方法，共java层来初始化
 * 2. 打印log
 *
 */

#include "jni.h"
#include "signal.h"
//#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
//#include <inttypes.h>
//#include <errno.h>
//#include <signal.h>
//#include <sys/syscall.h>
//#include <android/log.h>
#include "exception_handler.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_ztsdk_lib_ancrash_AnCatcher_initAnCatchNative(JNIEnv *env, jclass clazz, jstring path) {

  const char *n_path = env->GetStringUTFChars(path, JNI_FALSE);

  initAnCatch(n_path);

}

namespace aa {

}







