#include<stdio.h>
void main()
{ float a,c,f;
printf("Enter the Temperature in Celcius : ");
scanf("%f",&c);
f=c*(9/5)+32;   //// (9/5) усекается до int 
printf("Temperature in Fahernheit is %f",f);
}
