package com.ztsdk.lib.glide

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.bumptech.glide.Glide
import com.bumptech.glide.load.model.GlideUrl
import com.bumptech.glide.load.model.LazyHeaders
import com.ztsdk.lib.glide.databinding.GlideActivityBinding

class GlideActivity : AppCompatActivity() {


    lateinit var binding: GlideActivityBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = GlideActivityBinding.inflate(layoutInflater)
        setContentView(binding.root)
        var url1 =
            "https://beta-breathing-cdn.2tianxin.com/beta/resources/effect/1610093809604545375.png"

        var url2 = " https://beta-breathing-cdn.2tianxin" +
                ".com/beta/resources/effect/1610093787999328921.png"// 这个不行，我丢。

        Glide.with(this).load(url1)
            .centerCrop()
            .into(binding.ivGlideImageview)

        var url3 = "https://goo.gl/gEgYUd"
        Glide.with(this).load(url3)
            .centerCrop()
            .into(binding.ivGlideImageview2)


        binding.tvGlideText.text = "有点东西"

//        testHighCpu()


    }

    private fun testHighCpu() {

        Thread(Runnable {
            var i = 0;
            while (true) {
                var cpuHigh = CpuHigh("a", i)
                i++
                Log.d("CpuHigh", "testHighCpu: ")
            }

        }, "highCpu").start()

    }

    class CpuHigh(var name: String, var id: Int) {

    }

}