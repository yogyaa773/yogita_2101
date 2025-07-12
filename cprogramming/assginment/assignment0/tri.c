#include<stdio.h>
void main()
{
	int h,b,aot;
	printf("Enter the base:");
	scanf("%d",&b);
	printf("Enter the height:");
	scanf("%d",&h);
	aot=1%2*b*h;
	printf("area of triangle:",aot);
}