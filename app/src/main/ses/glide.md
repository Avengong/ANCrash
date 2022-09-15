# glide 初识

- 支持不同的网络下载库 glide支持拉取、解码和展示视频快照，图片和gif动画。 默认支持 HttpUrlConnection 网络栈。同时也支持 Google的 volley 和 suare 的
  okhttp。 但同时也提供了与Google Volley和Square OkHttp快速集成的工具库。

- 支持远程图片的拉取、缩放、显示 虽然Glide 的主要目标是让任何形式的图片列表的滚动尽可能地变得更快、更平滑，但实际上，Glide几乎能满足你对远程图片的拉取/缩放/显示的一切需求。

# 性能

Android 图片加载性能的两个方面：

- 图片解码速度
- 解码图片带来的资源压力

## 要求

不仅要快速加载展示，同时不能过多的主线程I/O和频繁的GC，导致页面闪烁和抖动现象。 Google采用了如下方案来解决：

- 自动、智能下采样(sampling) 和缓存 (caching) ，以最小化存储开销和解码次数
- 积极的资源重用 。如 字节数组和bitmap， 以最小化垃圾回收gc和 堆碎片化
- 深度生命周期集成 ，以确保优先处理活跃的Activity/ fragment 的请求。并有利于应用在后台时候释放资源，避免被杀。

# 使用

```

Glide.with(fragment)
    .load(url)
    .into(imageView);

```

## 使用 Generated API

目前只能在app模块使用。

## GlideExtension

可以在app和 module中使用。

两种类型：

- GlideOption

- GlideType

# 参考

https://muyangmin.github.io/glide-docs-cn/



