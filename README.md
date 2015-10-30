# t2CSSPareser

使用Flex+Bison完成CSS词法分析与语法分析工作，具体BNF是参考W3C中CSS2.0标准实现(实现了部分CSS3.0)。

###依赖项说明
1.[Flex](http://flex.sourceforge.net/) 2.5.35 
2.[Bison](https://www.gnu.org/software/bison/) 2.4.1
(Windows版本可以使用[MinGW](http://www.mingw.org/)，OSX为自带)
3.[Graphviz](http://www.graphviz.org/)(可选)，用于可视化生成AST树

###构建说明
1.自带Makefile，自带demo.css无需其他平台依赖项

###使用说明
1.目前支持CSS2.0大部分特性，正如demo.css中显示的

2.所有数值不带单位，例如font-size: 80;此处一旦数值带有单位将会发生```不可预测错误```。

3.AST基本数据类型已经在t2CSSNode.hpp中显示，其中可视化AST可以调用printAsDot()方法。

4.目前语法错误无法检测具体错误类型，只能显示```Error: syntax error.```。

###可视化AST
此为给出的demo.css生成的AST具体样式
![AST](https://github.com/BentleyBlanks/WovenCloth/blob/master/screenshot/1.png)






