package com.ztsdk.lib.ancrash

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.ztsdk.lib.ancrash.databinding.ActivityMainBinding
import com.ztsdk.lib.breakpad.BreakpadInit
import com.ztsdk.lib.glide.GlideActivity
import java.io.File

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        initBreakPad()
        initAnCatcher()
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method

        binding.btnClick.setOnClickListener {
            startActivity(Intent(this, GlideActivity::class.java))

        }
        binding.btnJni.setOnClickListener {
            binding.sampleText.text = stringFromJNI("i will success!! ")

        }

        GlideApp.with(this)
            .load("")
            .into(binding.ivIcon)

    }

    private fun initAnCatcher() {

        AnCatcher.initAnCatch(applicationContext)
    }

    /**
     * A native method that is implemented by the 'ancrash' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(content: String): String

    companion object {
        // Used to load the 'ancrash' library on application startup.
        init {
            System.loadLibrary("ancrash")
            System.loadLibrary("ancatch")
        }
    }

    var externalReportPath: File? = null
    private fun initBreakPad() {
        if (externalReportPath == null) {
            externalReportPath = File(getExternalFilesDir("crash"), "crashDump")
            if (!externalReportPath!!.exists()) {
                externalReportPath?.mkdirs()
            }
        }
        Log.d("ancrash_crash", "debug--" + externalReportPath!!.getAbsolutePath())
        BreakpadInit.initBreakpad(externalReportPath!!.getAbsolutePath())
    }


}