//
// Created by mrecorder on 2022/11/26.
//

#include <jni.h>
#include "lame-lib.h"

Mp3Encoder *encoder;

extern "C" JNIEXPORT jint JNICALL
Java_com_manna_audio_LameEncode_pcmToMp3JNI(
        JNIEnv *env,
        jclass clazz,
        jstring pcm_path,
        jstring mp3_path,
        jint sample_rate,
        jint channel,
        jint bit_rate) {
    const char *pcmPath = env->GetStringUTFChars(pcm_path, NULL);
    const char *mp3Path = env->GetStringUTFChars(mp3_path, NULL);

    encoder = new Mp3Encoder();
    encoder->Init(pcmPath, mp3Path, sample_rate, channel, bit_rate);
    encoder->Encode();

    env->ReleaseStringUTFChars(pcm_path, pcmPath);
    env->ReleaseStringUTFChars(mp3_path, mp3Path);
    return 0;
}


