#include <iostream>
#include <string>
#include <C:\wx\VSC\Console\CPP\Classes\ORENOMATH\orenomath.h>
using namespace std;
double beforeguess;
double funcx(double guess, double a)
{
	return (guess * guess) - a;
}
double turevfunc(double guess)
{
	return 2*guess;
}
double karekok(double a)
{
	double guess = 48;
	while(true)
	{
		guess = guess - (funcx(guess, a) / turevfunc(guess));
		if(guess * guess == a || to_string(guess) == to_string(beforeguess))
		{
			return guess;
			break;
		}
		beforeguess = guess;
	}
	
}