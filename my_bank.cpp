#include "iostream"
#include "stdio.h"
#include "my_bank.h"
#include "mb_util.h"
#include <pthread.h>
#include <signal.h>

using namespace std;
extern int terminate_gp;

void* mb_process_data(void *mb_process_vdata)
{
	printf("GURU mb_process_data\n");
	pthread_exit(NULL);
}

void* mb_system_data(void *mb_ststem_vdata)
{
	cout<<"System thread"<<endl;
	pthread_exit(NULL);
}

int main()
{
	terminate_g = 78;
	terminate_gp = 89;
	mb_thread mb_process;
	mb_thread mb_system;
	int mb_status = 0;
	
	mb_status = pthread_create(&mb_process.tid, NULL,mb_process_data, NULL);
	if(mb_status != 0){
		cout<<"failed to create process thread"<<endl;
		goto MB_GOTO1;
	}
	mb_status = pthread_create(&mb_system.tid,NULL,mb_system_data,NULL);
	if(mb_status != 0){
		cout<<"Failed to create system thread"<<endl;
		goto MB_GOTO2;
	}
	
	pthread_join(mb_process.tid,NULL);
	pthread_join(mb_system.tid,NULL);
	printf("GURU %d %d\n",terminate_g,terminate_gp);
	display_d();
	return 0;

MB_GOTO1:
	return 1;
MB_GOTO2:
	return 2;

}
