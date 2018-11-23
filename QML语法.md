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
