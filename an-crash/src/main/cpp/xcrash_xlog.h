//
// Created by Avengong on 2022/9/7.
//

#ifndef XCRASH_XCRASH_XLOG_H
#define XCRASH_XCRASH_XLOG_H

#include <stdio.h>
#include <jni.h>
#include <android/log.h>

#define LOG_TAG "an_crash"

#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define ALOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define ALOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


#endif //XCRASH_XCRASH_XLOG_H
