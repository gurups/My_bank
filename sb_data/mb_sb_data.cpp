#include "stdio.h"
#include "iostream"

#include "mb_sb_data.h"
//#include "my_bank.h"

void* mb_process_data(void *mb_process_vdata)
{
	printf("GURU mb_process_data\n");
	
	pthread_exit(NULL);
}


