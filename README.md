# StringCompare
实现指定规则的字符串大小比较功能

## 实现思路
### 1. 抽象接口ComparableSubString
对于规则中的子字母串和子数字串，抽象出一个接口：ComparableSubString，即可比较的子串接口.<br/>
此接口暴露了3个接口方法：获取子串类型GetType()，获取子串的值GetValue()，获取子串的长度GetLength()<br/>
其中，GetValue()以字符串的形式返回子串的值,用于后续根据不同的规则进行比较大小
* 对于纯字母的串，就是各字母组成的字符串
* 对于纯数字的串，是数字的十进制形式的每一位数字组成的字符串，
* 比如数字串"001\A\A"，其数字值为 1\*100+65\*10+65=815，则此接口返回的字符串为"815",不含前面的无效0的个数
   
GetLength()返回子串的长度，比如对于数字串"001\A\A"，返回的长度为5.

### 2. StringSplitter工具类
设计StringSplitter工具类，用于从原始字符串中分离出各个子串，返回一个列表

### 3. 比较规则类CompareRule
根据规则对输入的两个包含子串的列表进行比较<br/>
在比较两个子串时，根据两个子串的各自的类型，决定采用的比较规则<br/>
* 对于子字母串和子数字串的比较，返回-1
* 对于两个子数字串的比较，调用GetValue获取字符串后，根据数值进行比较
* 对于两个字母串的比较，调用GetValue获取字符串值后，根据strcmp进行比较

## 目录说明
```
StringCompare
  |
  |---3rdparty
  |---bin
       |-----main_StringCompare.exe
  |
  |---include
       |-----StringCompare.h
  |
  |---main
        |----main.cpp
        |----CMakeLists.txt
  |
  |---src
        |----StringCompare.cpp
        |----Rule
               |----CompareRule.h
               |----CompareRule.cpp
        |----Splitter
               |----StringSplitter.cpp
               |----StringSplitter.cpp
        |----SubString
               |----ComparableSubString.h
               |----CharSubString.h
               |----CharSubString.cpp
               |----DigitSubString.h
               |----DigitSubString.cpp
  |
  |---test
        |----case
               |----test_StringCompare.cpp
```
* include/StringCompare.h是对外提供的接口头文件
* src/StringCompare.cpp是接口的实现入口源文件，调用SubString、Splitter和Rule目录下面的相关类来实现接口。
* main/main.cpp是生成可执行的二进制文件的入口。
* test/case/test_StringCompare.cpp包含测试用例。
* bin/main_StringCompare.exe是可执行文件，在Win10 64位系统Visual Studio 2017平台编译生成。







## 需求描述
两个字符串（字符串1、字符串2）的大小比较，字符串只可能含有如下字符

1）字母：a～z|A~Z

2）数字：0～9

3）转义符：\

比较规则如下：

(1)从左到右分离单纯的子字母串（均为字母）和子数字串（均为数字）进行比较；

(2)如果一边已无子串（子字母串或子数字串），另外一方还有子串，则无子串的小；如果双方均无子串，则相等

(3)如果被比较的一边是子数字串，一边是子字母串，则子数字串小；

(4)如果被比较的都是子字母串，则按C库strcmp的规则比较子字母串大小；

(5)如果被比较的都是子数字串，则按数值比较规则比较大小，如果值相等，则子数字串短的一方（前面的0少）小；

(6)如果当前子串相等，才需要比较下一个子串；

(7)支持转义符\，对后面的1至3个（尽可能多的匹配）数字作字母处理，\当做不存在，比如，abc\123，作为子字母串abc123;

(8)支持转义符\，对后面的1个字母，按其ascii码作为数字处理，数字长度算为1，\当做不存在，比如1\A\A，值为1*100+65*10+65，长度为3；

(9)转义符\后只能跟字母或数字；

举例：按照上述字符串大小比较规则，对如下字符串组进行递增排序时：

B1，B11，B01，B2：输出应该是B1，B01，B2，B11；

附加限制：

(1)不能用递归

(2)使用TDD开发，同步提交表达清晰的用例

(3)开发语言：c/c++、java、python、scala，不能使用正则表达式库，不能使用三方库（测试框架例外）

(4)提供源码、用例，另外需提供完整可执行文件包，其中入口可执行文件给定两个字符串s1,s2，输出1,0,-1，分别s1>s2、s1=s2、s1<s2，非法字符返回-2。

【补充说明】

1、请在3月11日（周日）24点前，将源码、测试用例和二进制可运行包，打包后单独发给张继红10040623。压缩包统一命名为“技术教练专业能力测评答卷”；

2、提交的所有源码、测试用例、二进制可运行包及压缩包中，均不得出现姓名、工号、部门等标识信息，否则视为无效答卷；

3、逾期不提交答卷者，视为放弃本次认证；

4、对试题本身如有疑问的，请直接咨询：丁辉（南京）、徐宁（上海）、李永顺（西安&天津）、张晔（深圳&长沙&重庆）。或直接在本帖发表评论提问。
