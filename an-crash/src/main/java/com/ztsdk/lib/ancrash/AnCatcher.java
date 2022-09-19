package com.ztsdk.lib.ancrash;

import android.content.Context;

import java.io.File;

public class AnCatcher {


    public static void initAnCatch(Context context) {

        initAnCatchNative(context.getExternalFilesDir("ancrash").getAbsolutePath());


    }

    public static native void initAnCatchNative(String path);

}
