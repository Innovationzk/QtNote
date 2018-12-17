# QML快速入门（Quick Starter）
_____________________________
# 一、QML语法（QML Syntax）
```
// import声明导入了一个指定的模块版本。一般来说会导入QtQuick2.0来作为初始元素的引用。
import QtQuick 2.0

// 使用//可以单行注释，使用/**/可以多行注释，就像C/C++和JavaScript一样。
Rectangle {
    // 每一个QML文件都需要一个根元素，就像HTML一样。
    id: root

    // properties: <name>: <value>
    width: 120; height: 240

    // color property
    color: "#D8D8D8"

    // Declare a nested element (child of root)
    // 一个元素使用它的类型声明，然后使用{}进行包含。
    Image {
    	id: rocket

        // reference the parent
        // 元素拥有属性，他们按照name:value的格式来赋值。
        x: (parent.width - width)/2; y: 40

        source: 'assets/rocket.png'
    }

    // Another child of root
    // 元素可以嵌套，这意味着一个父元素可以拥有多个子元素。子元素可以通过访问parent关键字来访问它们的父元素。
    Text {
        // un-named element

        // reference element by id
        y: rocket.y + rocket.height + 20

        // reference root element
        //任何在QML文档中的元素都可以使用它们的id进行访问（id是一个任意的标识符）。
        width: root.width

        horizontalAlignment: Text.AlignHCenter
        text: 'Rocket'
    }
}
```
**建议**

**你会经常使用id或者关键字parent来访问你的父对象。有一个比较好的方法是命名你的根元素对象id为root（id:root），这样就不用去思考你的QML文档中的根元素应该用什么方式命名了。**

**提示**

**你可以在你的操作系统命令行模式下使用QtQuick运行环境来运行这个例子，比如像下面这样：**

>  zhoukui@zhoukuiPC: qmlscene rectangle.qml

## 属性（Properties）
1. id属性：是一个唯一标识符，在QML文件中被用来引用元素。
2. 默认值：一个属性能够设置一个值，这个值依赖于它的类型。如果没有对一个属性赋值，那么它将会被初始化为一个默认值。
3. 自定义属性：使用property修饰符来添加自定义属性，使用default关键字可以将一个属性定义为默认属性。
4. alias关键字：alias关键字允许我们转发一个属性或者转发一个属性对象自身到另一个作用域。一个属性别名不需要类型，它使用引用的属性类型或者对象类型。
5. 按组分配的属性：当一个属性需要结构化并且相关的属性需要联系在一起时，我们可以这样使用它。比如下面这样：
```
	font{family: "UBuntu"; pixelSize: 24 }。
```
或者是下面这样：
```
    font.family: "Ubuntu"
    font.pixelSize: 24
```
6. 信号：对于每个元素都可以提供一个信号操作。这个操作在属性值改变时被调用。
```
	 onHeightChanged: console.log('height:', height)
```

**警告**

**一个元素id应该只在当前文档中被引用。QML提供了动态作用域的机制，后加载的文档会覆盖之前加载文档的元素id号，这样就可以引用已加载并且没有被覆盖的元素id，这有点类似创建全局变量。但不幸的是这样的代码阅读性很差。目前这个还没有办法解决这个问题，所以你使用这个机制的时候最好仔细一些甚至不要使用这种机制。如果你想向文档外提供元素的调用，你可以在根元素上使用属性导出的方式来提供。**

## 脚本（Scripting）
- JavaScript函数：avaScript函数使用这种格式function (){....}

**注意**

**QML的：（属性绑定）与JavaScript的=（赋值）是不同的。绑定是一个协议，并且存在于整个生命周期。然而JavaScript赋值（=）只会产生一次效果。当一个新的绑定生效或者使用JavaScript赋值给属性时，绑定的生命周期就会结束。例如一个按键的操作设置文本属性为一个空的字符串将会销毁我们的增值显示：**

____________________________________________________________

# 二、基本元素（Basic Elements）

## 基础元素对象（Item Element）
Item（基础元素对象）是所有可视化元素的基础对象，所有其它的可视化元素都继承自Item。它自身不会有任何绘制操作，但是定义了所有可视化元素共有的属性：
- Geometry（几何属性）: x,y（坐标）定义元素左上角的位置，width，height（长和宽）定义元素的显示范围，z（堆叠次序）定义元素之间的重叠顺序。
- Layout handling（布局操作)：anchors（锚定），包括左（left），右（right），上（top），下（bottom），水平与垂直居中（vertical center，horizontal center），与margins（间距）一起定义了元素与其它元素之间的位置关系。
- Key handlikng（按键操作）: 附加属性key（按键）和keyNavigation（按键定位）属性来控制按键操作，处理输入焦点（focus）可用操作。
- Transformation（转换）:缩放（scale）和rotate（旋转）转换，通用的x,y,z属性列表转换（transform），旋转基点设置（transformOrigin）。
- Visual（可视化）:不透明度（opacity）控制透明度，visible（是否可见）控制元素是否显示，clip（裁剪）用来限制元素边界的绘制，smooth（平滑）用来提高渲染质量。
- State definition（状态定义）states（状态列表属性）提供了元素当前所支持的状态列表，当前属性的改变也可以使用transitions（转变）属性列表来定义状态转变动画。

**矩形框元素（Rectangle Element）**
Rectangle（矩形框）是基本元素对象的一个扩展，增加了一个颜色来填充它。它还支持边界的定义，使用border.color（边界颜色），border.width（边界宽度）来自定义边界。你可以使用radius（半径）属性来创建一个圆角矩形。

**文本元素（Text Element）**
Text元素（Text Element），它最值得注意的属性时字符串类型的text属性。这个元素会使用给出的text（文本）与font（字体）来计算初始化的宽度与高度。可以使用字体属性组来（font property group）来改变当前的字体，例如font.family，font.pixelSize，等等。改变文本的颜色值只需要改变颜色属性就可以了。

**图像元素（Image Element）**
一个图像元素（Image Element）能够显示不同格式的图像（例如PNG,JPG,GIF,BMP）。想要知道更加详细的图像格式支持信息，可以查看Qt的相关文档。source属性（source property）提供了图像文件的链接信息，fillMode（文件模式）属性能够控制元素对象的大小调整行为。

**鼠标区域元素（MouseArea Element）**MouseArea（鼠标区域）元素是一个矩形的非可视化元素对象，你可以通过它来捕捉鼠标事件。当用户与可视化端口交互时，mouseArea通常被用来与可视化元素对象一起执行命令。
_______________________________________

# 三、组件（Compontents）

一个组件是一个可以重复使用的元素，一个文件就是一个基础组件。一个以文件为基础的组件在文件中创建了一个QML元素，并且将文件以元素类型来命名（例如Button.qml）。

*注：用文件的方式创建组件，文件名首字母必须大写*
______________________________________________

# 四、转换（Transformations）
- x,y：坐标
- rotation：旋转，以角度作为单位
- scale：缩放，小于1意味着缩小，大于1意味着放大

**注意**
**在代码中先出现的元素有更低的堆叠顺序（叫做z顺序值z-order），如果你点击火箭1足够多次，你会看见火箭1移动到了火箭2下面。z轴顺序也可以使用元素对象的z-property来控制。**
_________________________________________________

# 五、定位元素（Positioning Element）
QtQuick模块提供了Row，Column，Grid，Flow用来作为定位器。
- **Column**: colomn（列）元素将它的子对象通过顶部对齐的列方式进行排列。spacing属性用来设置每个元素之间的间隔大小。
- **Row**：row（行）元素将它的子对象从左到右，或者从右到左依次排列，排列方式取决于layoutDirection属性。spacing属性用来设置每个元素之间的间隔大小。
- **Grid**：grid（栅格）元素通过设置rows（行数）和columns（列数）将子对象排列在一个栅格中。可以只限制行数或者列数。
- **Flow**：flow（流）通过flow属性和layoutDirection（布局方向）属性来控制流的方向。它能够从头到底的横向布局，也可以从左到右或者从右到左进行布局。为了让一个流可以工作，必须指定一个宽度或者高度，可以通过属性直接设定，或者通过anchor（锚定）布局设置。
- **Repeater**：通常Repeater（重复元素）与定位器一起使用。它的工作方式就像for循环与迭代器的模式一样。下面是一个简单的例子：
```
Grid{
    anchors.fill: parent
    anchors.margins: 8
    spacing: 4
    Repeater {
        model: 16
        Rectangle {
            width: 56; height: 56
            property int colorIndex: Math.floor(Math.random()*3)
            color: root.colorArray[colorIndex]
            border.color: Qt.lighter(color)
            Text {
                anchors.centerIn: parent
                color: "#f0f0f0"
                text: "Cell " + index
            }
        }
    }
}
```

# 布局元素（Layout Items）
QML使用anchors（锚）对元素进行布局。anchoring（锚定）是基础元素对象的基本属性，可以被所有的可视化QML元素使用。一个anchors（锚）就像一个协议，并且比几何变化更加强大。Anchors（锚）是相对关系的表达式，你通常需要与其它元素搭配使用。

一个元素有6条锚定线（top顶，bottom底，left左，right右，horizontalCenter水平中，verticalCenter垂直中）。在文本元素（Text Element）中有一条文本的锚定基线（baseline）。每一条锚定线都有一个偏移（offset）值，在top（顶），bottom（底），left（左），right（右）的锚定线中它们也被称作边距。对于horizontalCenter（水平中）与verticalCenter（垂直中）与baseline（文本基线）中被称作偏移值。

# 输入元素（Input Element）
## 文本输入（TextInput）
文本输入允许用户输入一行文本。这个元素支持使用正则表达式验证器来限制输入和输入掩码的模式设置。
## 焦点区域（FocusScope）
一个焦点区域（focus scope）定义了如果焦点区域接收到焦点，它的最后一个使用focus:true的子元素接收焦点，它将会把焦点传递给最后申请焦点的子元素。
## 文本编辑（TextEdit）
文本编辑（TextEdit）元素与文本输入（TextInput）非常类似，它支持多行文本编辑。它不再支持文本输入的限制，但是提供了已绘制文本的大小查询（paintedHeight，paintedWidth）。
## 按键元素（Key Element）
附加属性key允许你基于某个按键的点击来执行代码。例如使用up，down按键来移动一个方块，left，right按键来旋转一个元素，plus，minus按键来缩放一个元素。
_______________________

# 动态元素（Fluid Elements）

# 动画（Animations）
动画被用于属性的改变。一个动画定义了属性值改变的曲线，将一个属性值变化从一个值过渡到另一个值。动画是由一连串的目标属性活动定义的，平缓的曲线算法能够引发一个定义时间内属性的持续变化。所有在QtQuick中的动画都由同一个计时器来控制，因此它们始终都保持同步，这也提高了动画的性能和显示效果。
## 动画元素（Animation Elements）
常用的动画有：
- PropertyAnimation（属性动画）- 使用属性值改变播放的动画
- NumberAnimation（数字动画）- 使用数字改变播放的动画
- ColorAnimation（颜色动画）- 使用颜色改变播放的动画
- RotationAnimation（旋转动画）- 使用旋转改变播放的动画

QtQuick还提供了一切特殊场景下使用的动画：
- PauseAnimation（停止动画）- 运行暂停一个动画
- SequentialAnimation（顺序动画）- 允许动画有序播放
- ParallelAnimation（并行动画）- 允许动画同时播放
- AnchorAnimation（锚定动画）- 使用锚定改变播放的动画
- ParentAnimation（父元素动画）- 使用父对象改变播放的动画
- SmotthedAnimation（平滑动画）- 跟踪一个平滑值播放的动画
- SpringAnimation（弹簧动画）- 跟踪一个弹簧变换的值播放的动画
- PathAnimation（路径动画）- 跟踪一个元素对象的路径的动画
- Vector3dAnimation（3D容器动画）- 使用QVector3d值改变播放的动画

## 应用动画（Applying Animations）
动画可以通过以下几种方式来应用：
- 属性动画 - 在元素完整加载后自动运行
- 属性动作 - 当属性值改变时自动运行
- 独立运行动画 - 使用start()函数明确指定运行或者running属性被设置为true（比如通过属性绑定）

## 缓冲曲线（Easing Curves）
属性值的改变能够通过一个动画来控制，缓冲曲线属性影响了一个属性值改变的插值算法。动画的默认缓冲类型是Easing.Linear。使用easing.type来改变缓冲类型。比如easing.type: Easing.OutCirc。

## 动画分组（Grouped Animations）
可以将SequentialAnimation（连续动画）和ParallelAnimation（平行动画）作为动画的容器来包含其它的动画元素。

# 状态与过渡（States and Transitions）
通常我们将用户界面描述为一种状态。一个状态定义了一组属性的改变，并且会在一定的条件下被触发。另外在这些状态转化的过程中可以有一个过渡(transition)，定义了这些属性的动画或者一些附加的动作。当进入一个新的状态时，动作也可以被执行。
示例代码：
```
Item{
    id: root
    width: 150
    height: 250
    Rectangle {
        id: light1
        x: 25; y: 15
        width: 100; height: width
        scale: 1
        radius: width/2
        color: "black"
    }
    Rectangle {
        id: light2
        x: 25; y: 135
        width: 100; height: width
        scale: 0
        radius: width/2
        color: "black"
    }
    state: "stop"    //state默认为空字符串，即 state: ""
    states: [
        State {
            name: "stop"
            PropertyChanges { target: light1; scale: 1; color: "red" }
            PropertyChanges { target: light2; scale: 0; color: "black" }
        },
        State {
            name: "go"
            PropertyChanges { target: light1; scale: 0; color: "black" }
            PropertyChanges { target: light2; scale: 1; color: "green" }
        }
    ]
    transitions: [
        Transition {
            from: "stop"
            to: "go"
            PropertyAnimation { target: light1; properties: "scale,color"; duration: 500; }
            PropertyAnimation { target: light2; properties: "scale,color"; duration: 500 }
        },
        Transition {
            from: "go"
            to: "stop"
            PropertyAnimation { target: light1; properties: "scale,color"; duration: 500 }
            PropertyAnimation { target: light2; properties: "scale,color"; duration: 500 }
        }
    ]
    MouseArea {
        anchors.fill: parent
        onClicked: parent.state = (parent.state == "stop"? "go" : "stop")
    }
}
```
## 状态（States）
在QML中，使用State元素来定义状态，需要与基础元素对象（Item）的states序列属性连接。状态通过它的状态名来鉴别，由组成它的一系列简单的属性来改变元素。默认的状态在初始化元素属性时定义，并命名为“”（一个空的字符串）。

在一个状态中，只需要描述属性如何从它们的默认状态改变（而不是前一个状态的改变）。
## 过渡（Transitions）
任何元素都可以加入一系列过渡，一个过渡由状态的改变触发执行。你可以使用属性的from:和to:来定义状态改变的指定过渡。这两个属性就像一个过滤器，当过滤器为true时，过渡生效。你也可以使用“”来表示任何状态。例如from:""; to:"*"表示从任一状态到另一个任一状态的默认值，这意味着过渡用于每个状态的切换。

# 模型-视图-代理（Model-View-Delegate）
在QtQuick中，数据通过model-view（模型-视图）分离。对于每个view（视图），每个数据元素的可视化都分给一个代理（delegate）。