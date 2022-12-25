package com.manna.audio;

/**
 * 调用lame-lib.so中的native方法
 */
public class LameEncode {
    //加载lame-lib.so
    static {
        System.loadLibrary("lame-lib");
    }


    //PCM文件转成MP3
    //pcm文件路径,mp3文件路径,采样率,频道,比特率
    public static native int pcmToMp3JNI(String pcmPath,String mp3Path,int sampleRate,int channel, int bitRate);
}
