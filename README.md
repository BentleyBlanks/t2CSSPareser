# t2CSSPareser

使用Flex+Bison完成CSS词法分析与语法分析工作，具体BNF是参考[W3C](http://www.w3.org/TR/CSS21/grammar.html)中CSS2.0标准实现(实现了部分CSS3.0)。

感谢[tang3w](http://tang3w.com/2015/02/01/%E4%BD%BF%E7%94%A8-lemon-%E5%AE%9E%E7%8E%B0-css-%E8%AF%AD%E6%B3%95%E5%88%86%E6%9E%90%E5%99%A8.html)给出了使用Flex+Lemon的简易CSS解析器实现，以及其推荐的[可视化AST](http://tang3w.com/2015/02/01/%E6%8A%BD%E8%B1%A1%E8%AF%AD%E6%B3%95%E6%A0%91%E7%9A%84%E5%8F%AF%E8%A7%86%E5%8C%96.html)的实现方法。

## 依赖项说明
1.[Flex](http://flex.sourceforge.net/) 2.5.35

2.[Bison](https://www.gnu.org/software/bison/) 2.4.1

(Windows版本可以使用[MinGW](http://www.mingw.org/)，OSX为自带)

3.[Graphviz](http://www.graphviz.org/)(可选)，用于可视化生成AST树

## 构建说明
1.自带Makefile，自带demo.css无需其他平台依赖项

2.不使用g++ 而使用Visual Studio编译时可能会遇到```unistd.h```无法找到的问题，目前的解决方案可以是直接在VS的include目录下添加

具体操作可以参见[在VC下如何使用头文件unistd.h](http://weilihero.blog.163.com/blog/static/13411039520109218831848/)

## 使用说明
1.目前支持CSS2.0大部分特性，正如demo.css中显示的

2.所有数值不带单位，例如
```css
/* 已知错误 */
font-size: 80;
/* font-size: 80px; */

```
此处一旦数值带有单位将会发生```不可预测错误```。

3.AST基本数据类型已经在```t2CSSNode.hpp```中显示，其中可视化AST可以调用```printAsDot()```方法。

4.目前语法错误无法检测具体错误类型，只能显示```Error: syntax error.```。

5.目前规则不能为空，例如
```css
/* Syntax error */
hello.a{}
```
6.目前最后一个选择器后建议不加空格
```css
/* Unsupported */
.haha {}

/* supported */
.haha{}
```
原因是生成的AST会认为```.haha```之后还有一个selector(紧跟的空格引起)，因此外部需要额外的解析工作来消除这一影响，但不影响正常解析。

在t2CSSParser中会被认为有语法错误,目前的解决办法是手工直接删除空规则，等待版本。

7.不支持类```function```的写法，如```color: rgba(...);```等


## 可视化AST
此为给出的demo.css生成的AST具体样式
![AST](https://raw.githubusercontent.com/BentleyBlanks/t2CSSPareser/master/AST/AST.png)


## 关于作者
```cpp
int 官某某 = "Bingo";

char[] 个人博客 = "http://bentleyblanks.github.io";
```
