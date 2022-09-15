package com.ztsdk.lib.ancrash

import android.content.Context
import com.bumptech.glide.GlideBuilder
import com.bumptech.glide.annotation.GlideModule
import com.bumptech.glide.module.AppGlideModule

@GlideModule
class MyGlideModule : AppGlideModule() {

    override fun isManifestParsingEnabled(): Boolean {
        return false
    }

    override fun applyOptions(context: Context, builder: GlideBuilder) {
        super.applyOptions(context, builder)

    }

}