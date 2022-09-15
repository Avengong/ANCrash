#include <jni.h>
#include <string>
#include "coffe/coffeecatch.h"
#include "coffe/coffeejni.h"
#include <thread>
#include "include/an_log.h"
#include <sys/types.h>
#include <time.h> // 时间
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <jni.h>

void testDefineFunc(jstring pJstring);

/** The potentially dangerous function. **/
jint call_dangerous_function(JNIEnv *env, jobject object) {
    // ... do dangerous things!
    int *p = nullptr;
    int a = *p * 2;
    return 42;
}

/** Protected function stub. **/
void foo_protected(JNIEnv *env, jobject object, jint *retcode) {
    /* Try to call 'call_dangerous_function', and raise proper Java Error upon
     * fatal error (SEGV, etc.). **/
    COFFEE_TRY_JNI(env, *retcode = call_dangerous_function(env, object));


}

jstring charTojstring(JNIEnv *env, const char *pat) {
    //定义java String类 strClass
    jclass strClass = (env)->FindClass("Ljava/lang/String;");
    //获取String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    //建立byte数组
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));
    //将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte *) pat);
    // 设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("GB2312");
    //将byte数组转换为java String,并输出
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}

char *jstringToChar(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

void testDefineFunc(std::string pJstring) {

//#define  XX_DUMP_STR (v)do{ \
//               if (1){       \
//                            \
//               }         \
//                         \
//}while(0)
//
//#define XX_FREE_STR()do{ \
//                         \
//                         \
//}  while(0)


#define XC_COMMON_DUP_STR(v) do {                                       \
        if(NULL == (v) || 0 == strlen(v))                                 \
            xc_common_##v = "unknown";                                  \
        else                                                            \
        {                                                               \
            if(NULL == (xc_common_##v = strdup(v)))                     \
            {                                                           \
                r = XCC_ERRNO_NOMEM;                                    \
                goto err;                                               \
            }                                                           \
        }                                                               \
    } while (0)

#define XC_COMMON_FREE_STR(v) do {                                      \
        if(NULL != xc_common_##v) {                                     \
            free(xc_common_##v);                                        \
            xc_common_##v = NULL;                                       \
        }                                                               \
    } while (0)


}

extern "C" JNIEXPORT jstring JNICALL
Java_com_ztsdk_lib_ancrash_MainActivity_stringFromJNI(
        JNIEnv *env, jobject ob /* this */, jstring content) {

    std::string hello = "Hello from C++";

    jint retcode = 0;
//    LOGI("call coffe bad method start...");
//    foo_protected(env,ob,&retcode);
//    LOGI("call coffe bad method  end...");
//    (*env)->GetStringUTFChars(env, os_version,0))
//char  * c_os_version;
//    if(NULL == (c_os_version        = (*env)->GetStringUTFChars(env, content,        0))) goto clean;

    std::string newContent = (*env).GetStringUTFChars(content, JNI_FALSE);


    testDefineFunc(newContent);

    int *p = nullptr;
    *p = 2;

    return env->NewStringUTF(hello.c_str());


}




