## QML语法（QML Syntax）
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
