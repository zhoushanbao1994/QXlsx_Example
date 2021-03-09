---
typora-root-url: ./
---

# QXlsx_Example
QXlsx使用方法

## 1. 新建

  Qt新建一个工程

   ![image-20210309115823005](/Image/image-20210309115823005.png)

   ![image-20210309115800599](/Image/image-20210309115800599.png)

## 2. 下载

  下载[QXlsx最新版](https://github.com/QtExcel/QXlsx/releases)，解压，将“QXlsx文件夹”拷贝至新建工程的根目录

   ![image-20210309115620641](/Image/image-20210309115620641.png)

   ![image-20210309115858391](/Image/image-20210309115858391.png)

## 3. 添加

将库添加到工程：修改*.pro文件。原作者的说明中还需要添加几个路径，但添加后报错，所以没有添加。只把pri包含进来即可。

```.pro
# QXlsx code for Application Qt project
include(./QXlsx/QXlsx.pri)
```

![image-20210309124354435](/Image/image-20210309124354435.png)

## 4. 修改

修改main.cpp，包含头文件

```cpp
#include <QApplication>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;
```

修改main.cpp，主函数增加

```cpp
QXlsx::Document xlsx;
xlsx.write("A1", "Hello Qt!");  // write "Hello Qt!" to cell(A,1). it's shared string.
xlsx.saveAs("Test.xlsx");       // save the document as 'Test.xlsx'
```

![image-20210309124452356](/Image/image-20210309124452356.png)

## 5. 编译运行

## 6. 查看文件

![image-20210309124631713](/Image/image-20210309124631713.png)

![image-20210309124724738](/Image/image-20210309124724738.png)

