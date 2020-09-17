#include <cmath>
#include <iostream>
#include <string>
#include <complex>

bool isBelongMondelbrot(std::complex<long double> point, int estimation, int maxNum)
{
	std::complex<long double> functionVal(0, 0);
	for (int i = 0; i < estimation; i++)
	{
		if (functionVal.real() > maxNum || functionVal.imag() > maxNum)
		{
			return false;
		}
		functionVal = pow(functionVal, 2) + point;
	}
	return true;
}

int main()
{
	double maxNum = 0;
	int estimation = 0;
	std::cout << "Enter value that is close to inf: ";
	std::cin >> maxNum;
	std::cout << "Enter estimation order: ";
	std::cin >> estimation;

	std::cout << isBelongMondelbrot(std::complex<long double>(static_cast<long double>(-3) / static_cast<long double>(4), static_cast <long double>(1) / static_cast <long double>(100)), estimation, maxNum);

	return 0;
}