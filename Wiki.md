- [开发文档](#开发文档)
  - [js交互](#js交互)
    - [Js提供的方法](#js提供的方法)
      - [createRoom](#createroom)
      - [joinRoom](#joinroom)
  - [类设计](#类设计)
    - [界面的子类 - Frame子类](#界面的子类---frame子类)
      - [LaunchFrame](#launchframe)
      - [TeamSelect](#teamselect)
      - [RoomCreateFrame](#roomcreateframe)
      - [RoomJoinFrame](#roomjoinframe)
      - [TeamWaitFrame](#teamwaitframe)
      - [GamePreFrame](#gamepreframe)
      - [PlayingFrame](#playingframe)


# 开发文档

## js交互
> 这部分
>

### Js提供的方法
#### createRoom
创建房间

#### joinRoom
加入房间

## 类设计
### 界面的子类 - Frame子类

#### LaunchFrame
游戏启动界面，装饰作用，加载一个启动动画，也可以就是简单放一张游戏开始的壁纸，页面自动计时，几秒后跳转到其他界面

#### TeamSelect
选择加入游戏的方式
    1. 创建房间
    2. 加入房间

本界面也是装饰功能，最基础的就是放两个按钮让玩家选择跳转到哪个操作页面，有能力应该做的美观一些

#### RoomCreateFrame
基础功能也就是设计一个按钮用来创建房间
更进一步可以加一个文本输入框让用户来输入一个名字作为房间的名字

#### RoomJoinFrame
一个输入框和加入按钮

#### TeamWaitFrame
能够显示当前加入房间的人数，当前房间的名称，当前房间的加入编号（4位的随机字符串，服务器给的，具体实现不用管，会有js自动传递过来的），如果是房主的话，还应该显示一个开启房间的按钮，加入的玩家则是显示等待房主开启房间

#### GamePreFrame
所有人链接完毕后的界面，再此之前的界面其实大多都是静态的界面，顶多有一些按钮，这是应为那些连接逻辑都是直接调用js的对应方法就行，到这里为止点对点连接建立完毕，其实已经可以开始游戏了，这个界面是为了玩家能够给自己选择头像，昵称，选好了后可以点击开始游戏按钮，进入等待

#### PlayingFrame
所有人都点击开始后进入
人物、桌子啥的都是静态贴图。唯一就是下方的扑克牌需要麻烦一点，还有中间一个区域要来显示打出的牌