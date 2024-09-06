# 捉红三卡牌游戏
> 捉红三（又名 扎股子、倒红三、捣红三）是大同当地具有地方特色的跑牌类游戏，由于其简单、刺激、有趣的玩法，成为大同、太原、朔州等地区主流的扑克游戏之一。

## 构建指南
**环境准备**：
    1. Git
    2. Visual Studio（构建Windows需要）
    3. MinGW [官网](https://www.mingw-w64.org/) (构建Web需要)
    4. Emscripten（构建Web需要）
> 仅在`Windows11`环境下通过测试, `shell`使用`Powershell`
>

1. clone raylib 项目到根目录
> git clone git@github.com:raysan5/raylib.git


### 为 WIndows构建

使用 Visual Studio 打开项目即可直接构建WIndows平台下项目

### 为 Web 构建

**步骤**

1. 激活emsdk环境 执行`emsdk_env.ps1`
> 本操作需要提前先将 Emscripten 的安装目录和 其下的`emscripten`目录配置到环境变量

2. 为raylib编译web，切换到`raylib/src`目录下执行`mingw32-make PLATFORM=PLATFORM_WEB -B`
你会看到一下错误输出，但是没有关系，最终会成功编译生成`libraylib.a`

3. 修改根目录下的`makefile`文件内容，将其中的`EMSDK_PATH`修改为本地的值

4. 来到项目根目录，执行`mingw32-make`
同样的会有一些错误输出，这也不是问题，如果正确编译你会在web目录下看到生成的 `.html`,`.js`,和`.wasm`文件

5. 大功告成，注意你不能直接在文件夹打开.html文件，你需要在web目录启动一个简单的http服务器，有很多工具可以帮助你，例如VS_Code的Live Server（Five Server）插件就是一个很好的选择

## 附： Emscripten安装
```bash
# Get the emsdk repo
git clone https://github.com/emscripten-core/emsdk.git

# Enter that directory
cd emsdk

# install latest version
.\emsdk.bat install latest
```
之后你需要将`emsdk`的目录以及`emscripten`目录配置到环境变量以便你能更方便的使用它。

每次你启动新的Powershell，你需要在你使用emsdk前激活环境，使用命令`emsdk_env.ps1`

## 附：参考

[Raylib Github](https://github.com/raysan5/raylib)
[Raylib Games Github](https://github.com/raysan5/raylib-games)
[Raylib 官网](https://www.raylib.com/)
[Raylib Wiki（Web）](https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5))
[Raylib Wiki（Windows）](https://github.com/raysan5/raylib/wiki/Working-on-Windows)
[Emscripten Github](https://github.com/emscripten-core/emsdk)
[Emscripten 教程](https://emscripten.org/docs/getting_started/downloads.html)
[mozilla - WebAssembly](https://developer.mozilla.org/zh-CN/docs/WebAssembly)
[mozilla - WebRTC](https://developer.mozilla.org/zh-CN/docs/Web/API/WebRTC_API)
[WebRTC官网](https://webrtc.org/?hl=zh-cn)
[WebRTC - adapter Github](https://github.com/webrtc/adapter)
[WebRTC - adapter samples Github](https://github.com/webrtc/samples)