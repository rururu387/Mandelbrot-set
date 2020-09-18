#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <chrono>
#include <windows.h>
#define WIDTH 60
#define HEIGHT 60
#define SCALE 3.0

bool isBelongMondelbrot(std::complex<long double> point, int estimation, 
int maxNum)
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

std::complex<long double> offset(int i, int j)
{
	return std::complex<long double>((i - (HEIGHT / 2)) * SCALE / HEIGHT, 
										(j - WIDTH / 2) * SCALE / WIDTH);
}

void fillConsole(int estimation, int maxNum)
{
	std::cout << std::setw(7) << std::flush;
	for (int i = HEIGHT; i > 0; i--)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			//std::cout << std::to_string(offset(j, i).real())[0] << std::to_string(offset(j, i).real())[1] << " " << std::to_string(offset(j, i).imag())[0] << std::to_string(offset(j, i).imag())[1] << ",\t";
			bool isIncluded = 0;
			auto start = std::chrono::steady_clock::now();
			isIncluded = isBelongMondelbrot(offset(j, i), estimation, maxNum);
			auto end = std::chrono::steady_clock::now();
    		std::chrono::duration<double> elapsed_seconds = end-start;
			if (isIncluded)
			{
				SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ), 0x2F);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ), 0x1F);
			}
    		std::cout << std::setw(2) << std::chrono::duration_cast<std::
						chrono::microseconds>(elapsed_seconds).count() << " " << std::flush;
			/*SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ), 0x0F);
			std::cout << " " << std::flush;*/
		}
		std::cout << "\n";
	}
}

int main()
{
	double maxNum = 0;
	int estimation = 0;
	std::cout << "Enter value that is close to inf: ";
	std::cin >> maxNum;
	std::cout << "Enter estimation order: ";
	std::cin >> estimation;

	fillConsole(estimation, maxNum);
	//std::cout << isBelongMondelbrot(std::complex<long double>(1, 1), estimation, maxNum) << isBelongMondelbrot(std::complex<long double>(static_cast<long double>(-3) / static_cast<long double>(4), static_cast <long double>(1) / static_cast <long double>(100)), estimation, maxNum);
	char a;
	std::cin >> a;
	return 0;
}