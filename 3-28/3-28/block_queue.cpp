#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<string>
#include"block_queue.hpp"
using namespace std;
void* productor(void *arg)
{
	BlockQueue *bp = (BlockQueue*)arg;
	srand((unsigned int)time(nullptr));
	while (true)
	{
		int data = rand() % 100 + 1;
		bp->Push(data);
		cout << "product data is" << data << endl;
		sleep(1);
	}
}
void * consumer(void *arg)
{
	BlockQueue *bp = (BlockQueue*)arg;
	int data;
	while (true)
	{
		bp->Pop(data);
		cout << "consumer data is" << data << endl;
	}
}
int main()
{
	BlockQueue *bp = new BlockQueue();

	pthread_t c, p;
	pthread_create(&c, nullptr, consumer, (void*)bp);
	pthread_create(&p, nullptr, productor, (void*)bp);

	pthread_join(c, nullptr);
	pthread_join(p, nullptr);
	delete bp;
	return 0;
}
