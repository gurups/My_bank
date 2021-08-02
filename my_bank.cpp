#include "iostream"
#include "stdio.h"
#include <string.h>
#include "my_bank.h"
#include <thread>
#include "mb_util.h"
#include "mb_sb_data.h"
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

using namespace std;

volatile int terminate_g;

void signal_handler(int signal);

void signal_handler(int signal)
{
	if(signal == SIGINT){
		terminate_g = 1;
		cout<<"recieved sigint"<<endl;
	}else{
		cout<<"other than sigint"<<endl;
	}
}


template <typename G>
G printme(G v, G c)
{
	cout<<"TV "<<v<<"TC "<<c<<endl;
	return v+c;
}

template <class CT>
class G_array{
	private:
		CT *ptr;
		int size;
	public:
		G_array(CT arr[], int s);
		void printme();
};

template <class CT>
G_array<CT>::G_array(CT arr[],int s)
{
	int k = 0;
	ptr = new CT[s];
	size = s;
	while(k < size){
		ptr[k] = arr[k];
		k++;
	}
}

template <class CT>
void G_array<CT>::printme()
{
	int l=0;
	while(l<size){
		cout<<"F "<<*(ptr + l)<<endl;
		l++;
	}
}
// This thread is launched by using 
// function pointer as callable
void mb_thread_fp(int gp)
{
	int k = 5;
	while(1){
		printf("GURU foo %d\n",k);
		sleep(2);
		k--;
	}

	return;
}

// A callable object
class thread_obj {
public:
    void operator()(int x)
    {
    	int i = 7;
        while(1){
            cout << "Thread using function"
                  " object as  callable\n"<<i--<<endl;
			sleep(2);
		}
    }
};

void mb_bank_data::set_data()
{
	this->mb_customer_id = 900;
	this->mb_balance = 1999;
}
void mb_bank_data::display_data()
{
	cout<<"cus id "<<this->mb_customer_id<<endl;
	cout<<"bal "<<this->mb_balance<<endl;
}

void mb_savings_account::set_account_details()
{
	cout<<"set account details"<<endl;
}

void mb_address::read_user_data()
{
	cout<<"read_user_data"<<endl;
}

void* mb_system_data(void *mb_ststem_vdata)
{
	cout<<"System thread"<<endl;
	pthread_exit(NULL);
}

int main()
{
	mb_thread_st mb_process;
	mb_thread_st mb_system;
	int mb_status = 0;
	int arr[] = {1,2,3,4,5};
	G_array<int> ga(arr,5);
	ga.printme();
	signal(SIGINT,signal_handler);
	cout <<"SUM"<<printme<int>(4,7)<<endl;
	cout <<"SUM2 "<<printme<double>(8.9,3.1)<<endl;
	cout<<"SUN3 "<<printme<char>('A','A')<<endl;
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
	
	display_d();
	while(!terminate_g){}

	
	pthread_join(mb_process.tid,NULL);
	pthread_join(mb_system.tid,NULL);
	
	return 0;

MB_GOTO1:
	return 1;
MB_GOTO2:
	return 2;

}
