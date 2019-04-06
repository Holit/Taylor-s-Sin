// Taylor's_Sin.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>  
#include <iomanip>
#include <Windows.h>
#define PI 3.1415926535897932384626433832795028841971693993751
//digitals of PI : 50
long long factorial(long x);	//used to calcuate the factorial
long double talyors_sin(double x, int iTerm);	//main function, using the Taylor series method.
bool verify_prec(double precision_max, int verify_Term, int split_Term);
//used to verify if the precision the main function provided is allowed

long long factorial(long x)
{
	if (x > 20)
	{
		throw x;
		
		/*
		Program limitation:
			Although the calculate saving variable is set as type 'long long', but it also has a limitaion which will cause dangerous overlow.
			According to the Reference(C++11), the max of type 'long long' is 2^63-1, if trying saving a number larger than the max value,
		it may trying to paste this result into other memory space of system or application no matter what application or area it is.Sometimes
		if the program paste this over-long number into the fatal system area, it may cause the crash.
			To prevent this from happenning, we has limited the variable range of factorial by 20, accoring to the calculator,
					20! =				02,432,902,008,176,640,000
					MAX[long long] =	09,223,372,036,854,775,807
					21! =				51,090,942,171,709,440,000
			Obviously, we only able to calcuate the factorial of 20 instead of 21 which will cause overflow.

			By this limitaion, we can't give the approximated function of sin(x) which has a smaller precision like 0.01;
		How to solve:
			You could import a larger number to solve this problem.For example, you could rebuilt this program by using the library below
				https://github.com/Holit/BigNumberCalcuator
		this is our library to solve huge number question.But we don't include it here.
		*/
	}
	long long sum = 1;
	for (int i = 1; i <= x; i++)
	{
		sum = sum * i;	//n=1*2*3*...*n
	}
	return sum;
}
long double talyors_sin(double x, int iTerm)
{
	long double sum = 0;
	for (int i = 1; i <= iTerm; i++)
	{
		if (i % 2 == 0)
		{
			sum = sum - (pow(x, (double)(2 * i - 1)) / (factorial(2 * i - 1)));
		}
		else {
			sum = sum + (pow(x, (double)(2 * i - 1)) / (factorial(2 * i - 1)));
		}
		
		/*
		f(x)=sin(x) ≈ x -(x^3)/3! + (x^5)/5! -...
		if the term is singular, its flag(sgn(x)) must be negative, otherwise it will be postitive.
		This is because the derivative of the function sin(x) is repeat by cos(x), -sin(x), -cos(x), sin(x), and this also makes the 
		sin(x)' equals to 0(sin(0)), 1, 0, -1, 0...
		*/
	}
	return sum;
}
bool verify_prec(double precision_max, int verify_Term, int split_Term)
/*
argument desription:
	1) [double] precision_average : this value ordered the average of the deviation value
	2) [double] precision_variance : this value ordered the variance of the deviation
	3) [int] verify_term : the testing trems of the series, this can directly influence whether the output true or false.
	4) [int] split_Term : this value will devide the space (0,2π) into split_Term terms.
*/
{
	double d;
	//double sum, sumS, vari, aver;
	//sum = 0;
	//sumS = 0;
	split_Term++;
	//to calcuate from 0 to 360
	std::vector<long double>  value(split_Term);
	for (int i = 1; i <= split_Term; i++)
	{
		d = (PI/(double)180) * i;
		value[i-1] = abs(talyors_sin(d, verify_Term)) - abs(sin(d));
		//sum = sum + abs(value[i-1]);
		if (value[i - 1] > precision_max) 
		{ 
			return false; 
		}
	}
	return true;
	/*
	aver = sum / (double)split_Term;
	for (int i = 1; i < split_Term; i++)
	{
		sumS = sumS + pow((value[i-1] - aver), 2);
	}
	vari = sumS / (double)split_Term;
	value.clear();
	
	std::cout << "<Verify> Precision(aver,vari) = (" << aver << "," << vari << ")";
	if (aver <= precision_average && vari <= precision_variance)
	{
			return true;
	}
	else
	{
		return false;
	}*/
}
int main()
{
	double precision_max;
	precision_max = 0.01;
	int term = 1;
	try 
	{
		while (!verify_prec(precision_max, term, 360))
		{
			std::cout << "#" << term << " - not satisfacted." << std::endl;
			term++;
		}
		std::cout << "#" << term << " - Satisfacted!" << std::endl;
		std::cout <<std::endl<< "Press any key to clear the screen and show the result";
		std::cin.get();
		system("cls");
		std::cout << "Precision - Max precision not larger than " << precision_max << std::endl
			<< "Certifcated terms - " << term << std::endl
			<< std::endl
			<< "--------------------sin x---------------------------" << std::endl
			<< std::setw(10) << "Test value"
			<< "\t"
			<< std::setw(10) << "value"
			<< "\t"
			<< std::setw(10) << "system sin(x)"
			<< "\t"
			<< std::setw(4) << "preci"
			<< "\t" << std::endl;

		double d;
		for (int i = 0; i < 361; i++)
		{
			d = (PI / (double)180) * i;
			std::cout << std::setw(4) << i
				<< std::setprecision(10)
				<< "\t"
				<< std::setw(15) << talyors_sin(d, term)
				<< "\t"
				<< std::setw(15) << sin(d)
				<< "\t";
			std::cout << std::setw(4) << std::setprecision(2) << ((talyors_sin(d, term) - sin(d)) / sin(d)) * 1000 << "‰" << std::endl;
		}
	}catch (long x)
	{
		std::cout <<"!!![EXCEPTION]EXCEPTION_STACK_OVERFLOW : "<< x <<" is too larger to factorial" << std::endl;
	};
	std::cout << "----------Press any key...-----------" << std::endl;
	std::cin.get();
}
