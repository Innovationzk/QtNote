# QtNote
____________________________________________________________________________

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

* 注：用文件的方式创建组件，文件名首字母必须大写*