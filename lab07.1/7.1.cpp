#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
double Z1(int a)
{
	return (cos(a) + sin(a) + cos(3.0 * a) + sin(3.0 * a));
}
double Z2(int a, double pi)
{
	return (2.0 * sqrt(2.0)*cos(a)*sin((pi / 4.0) + (2.0*a)));
}
int main() {

	setlocale(LC_ALL, "Russian");
	int a;
	double pi = acos(-1);
	double z1, z2;
	printf("¬ведите значение а:\n");
	scanf("%d", &a);
	printf("z1(%d) = %f\n", a, Z1(a));
	printf("z2(%d) = %f\n", a, Z2(a, pi));
	scanf("%d", &a);
}
