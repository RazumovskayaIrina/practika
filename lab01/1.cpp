#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>

void main()

{
	setlocale(LC_ALL, "Russian");
	int a;
	double pi = acos(-1);
	double z1, z2;
	printf("¬ведите а: \n");
	scanf("%d", &a);
	z1 = cos(a) + sin(a) + cos(3.0 * a) + sin(3.0 * a);
	z2 = 2.0 * sqrt(2.0)*cos(a)*sin((pi / 4.0) + (2.0*a));
	printf("z1(%d) = %f\n", a, z1);
	printf("z2(%d) = %f\n", a, z2);
	scanf("%d", &a);
}