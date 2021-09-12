#include<stdio.h>
void main()     ////стоило бы правильно строить функции
{ float a,r;
printf("Enter the Radius : ");
scanf("%f",&r);
a=3.14*r*r;     ////#include <math.h> для точного pi
printf("Area is %f",a); ////проблемы с пробелами
}
