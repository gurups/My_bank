#ifndef _MY_BANK
#define _MY_BANK
static volatile int terminate_g;

typedef struct _mb_thread{
	pthread_t tid;
}mb_thread;
#endif
