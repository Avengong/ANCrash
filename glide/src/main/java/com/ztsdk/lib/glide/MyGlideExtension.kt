package com.ztsdk.lib.glide

import com.bumptech.glide.annotation.GlideExtension
import com.bumptech.glide.annotation.GlideOption
import com.bumptech.glide.request.BaseRequestOptions


@GlideExtension
object MyGlideExtension {

    const val MINI_THUMB_SIZE = 100

    @JvmStatic
    @JvmOverloads
    @GlideOption
    open fun miniThumb(options: BaseRequestOptions<*>): BaseRequestOptions<*> {
        return options.fitCenter().override(MINI_THUMB_SIZE)


    }

//    companion object{
//
//        const val MINI_THUMB_SIZE=100
//
//
//
//    }


}