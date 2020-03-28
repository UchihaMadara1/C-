#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<string>
using namespace std;
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex;
pthread_cond_t cond;
unsigned int ticket;
void * pthread_run1(void *arg)
{
	string name = (char*)arg;
	while (true)
	{
		pthread_cond_wait(&cond, &mutex);
		cout << name << "active ..." << endl;
	}
	pthread_exit(0);
}
void * pthread_run2(void * arg)
{
	while (true)
	{
		pthread_cond_signal(&cond);
		sleep(2);
	}
}

int main()
{
	pthread_mutex_init(&mutex, nullptr);
	pthread_cond_init(&cond, nullptr);

	pthread_t tid1, tid2;
	pthread_create(&tid1, nullptr, pthread_run1, (void*)"pthread_1");
	pthread_create(&tid2, nullptr, pthread_run2, (void*)"pthread_2");

	pthread_join(tid1, nullptr);
	pthread_join(tid2, nullptr);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	//	while(true)
	//	{
	//		cout<<"this is main pthread..."<<endl;
	//		sleep(1);
	//	}
	return 0;
}

