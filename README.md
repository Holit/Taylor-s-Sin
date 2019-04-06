正弦函数的近似函数
=======
中文
* 编写及调试环境<br>
  Microsoft Visual Studio 2017 Community
* 基础运行(Debug)<br>
  Windows 10 Enterprise x64
-------
程序通过循环结构实现了应用有限泰勒级数近似sin(x)的值。
* 目的
  * 泰勒级数的计算机算法实现
  * 有效的sin(x)近似
* 特性
  * 完成多次循环，从而模拟实验
  * 可变的精度需求
* 原理(https://en.wikipedia.org/wiki/Taylor_series)
  * ![image](https://wikimedia.org/api/rest_v1/media/math/render/svg/46dd2bf78ad7d792988cf616a6ea94024f30b3d9)
  * ![image](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e4/Sintay_SVG.svg/300px-Sintay_SVG.svg.png)
  泰勒多项式的次数逐渐上升，逼近原函数。 该图像显示了sin x及其泰勒近似，即1级，3级，5级，7级，9级，11级和13级的多项式。
-------
其他说明见源文件

Approximation function of sine function
=======
English
* Writing and debugging environment<br>
   Microsoft Visual Studio 2017 Community
* Basic operation (Debug)<br>
   Windows 10 Enterprise x64
-------
The program implements a value that applies a finite Taylor series approximation sin(x) through a loop structure.
* Purpose
  * Computer algorithm implementation of Taylor series
  * Effective sin(x) approximation
* Features
  * Complete multiple cycles to simulate the experiment
  * Variable precision requirements
* Principle (https://en.wikipedia.org/wiki/Taylor_series)
  * ![image](https://wikimedia.org/api/rest_v1/media/math/render/svg/46dd2bf78ad7d792988cf616a6ea94024f30b3d9)
  * ![image](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e4/Sintay_SVG.svg/300px-Sintay_SVG.svg.png)
  As the degree of the Taylor polynomial rises, it approaches the correct function. This image shows sin x and its Taylor approximations, polynomials of degree 1, 3, 5, 7, 9, 11 and 13.
-------
  Other description is included in source file which all referenced.
