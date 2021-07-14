#include "iostream"
#include "stdio.h"

volatile int terminate_gp;
void display_d()
{
	terminate_gp = 90;
	printf("GURU display %d\n",terminate_gp);
}
