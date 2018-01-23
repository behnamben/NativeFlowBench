//
// Created by Xingwei Lin on 14/1/18.
//

#include <jni.h>


#define LOG_TAG    "summary_based_bench"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

extern "C" {
JNIEXPORT jobject JNICALL
Java_org_arguslab_summary_1based_1bench_MainActivity_fieldAssignmentFromArg(JNIEnv *env,
                                                                            jobject thisObj,
                                                                            jobject summaryBasedUtil,
                                                                            jobject foo);
JNIEXPORT jobject JNICALL
Java_org_arguslab_summary_1based_1bench_MainActivity_fieldAssignmentFromNative(JNIEnv *env,
                                                                               jobject thisObj,
                                                                               jobject summaryBasedUtil);

JNIEXPORT jobject JNICALL
Java_org_arguslab_summary_1based_1bench_MainActivity_fieldAssignmentFromAnotherObject(JNIEnv *env,
                                                                                      jobject thisObj,
                                                                                      jobject summaryBasedUtil,
                                                                                      jobject summaryBasedUtilAnother);
}


JNIEXPORT jobject JNICALL
Java_org_arguslab_summary_1based_1bench_MainActivity_fieldAssignmentFromArg(JNIEnv *env,
                                                                            jobject thisObj,
                                                                            jobject summaryBasedUtil,
                                                                            jobject foo) {
    jclass summaryBasedUtilClass = env->GetObjectClass(summaryBasedUtil);
    jfieldID fooFieldID = env->GetFieldID(summaryBasedUtilClass, "foo",
                                          "Lorg/arguslab/summary_based_bench/Foo;");
    env->SetObjectField(summaryBasedUtil, fooFieldID, foo);
    jobject returnFoo = env->GetObjectField(summaryBasedUtil, fooFieldID);
    return returnFoo;
}

JNIEXPORT jobject JNICALL
Java_org_arguslab_summary_1based_1bench_MainActivity_fieldAssignmentFromNative(JNIEnv *env,
                                                                               jobject thisObj,
                                                                               jobject summaryBasedUtil) {

    jclass fooClass = env->FindClass("org/arguslab/summary_based_bench/Foo");
    jmethodID constructionMethod = env->GetMethodID(fooClass, "<init>", "()V");
    jobject fooObject = env->NewObject(fooClass, constructionMethod);

    jfieldID fooStrFieldID = env->GetFieldID(fooClass, "fooStr",
                                             "Ljava/lang/String;");
    jstring fooStr = env->NewStringUTF("fieldAssignmentFromNative");
    env->SetObjectField(fooObject, fooStrFieldID, fooStr);
    jfieldID fooNumFieldID = env->GetFieldID(fooClass, "fooNum", "I");
    env->SetIntField(fooObject, fooNumFieldID, 2018);

    jclass summaryBasedUtilClass = env->GetObjectClass(summaryBasedUtil);
    jfieldID fooFieldID = env->GetFieldID(summaryBasedUtilClass, "foo",
                                          "Lorg/arguslab/summary_based_bench/Foo;");
    env->SetObjectField(summaryBasedUtil, fooFieldID, fooObject);
    jobject returnFoo = env->GetObjectField(summaryBasedUtil, fooFieldID);
    return returnFoo;
}

JNIEXPORT jobject JNICALL
Java_org_arguslab_summary_1based_1bench_MainActivity_fieldAssignmentFromAnotherObject(JNIEnv *env,
                                                                                      jobject thisObj,
                                                                                      jobject summaryBasedUtil,
                                                                                      jobject summaryBasedUtilAnother) {

    jclass summaryBasedUtilClass = env->GetObjectClass(summaryBasedUtil);
    jfieldID fooFieldID = env->GetFieldID(summaryBasedUtilClass, "foo",
                                          "Lorg/arguslab/summary_based_bench/Foo;");

    jobject fooAnother = env->GetObjectField(summaryBasedUtilAnother, fooFieldID);
    env->SetObjectField(summaryBasedUtil, fooFieldID, fooAnother);
    jobject returnFoo = env->GetObjectField(summaryBasedUtil, fooFieldID);
    return returnFoo;
}
