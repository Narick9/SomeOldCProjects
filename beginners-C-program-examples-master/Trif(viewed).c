#include<stdio.h>
#include<math.h>
void main()     ////стоило бы правильно строить функции
{ double a,b;
printf("Enter the degree : ");
scanf("%lf",&a);
a=(a*3.14)/180;     ////импортировали же math
b=sin(a);
printf("Sine is %lf",b);
}
