#pragma once


#include<iostream>
#include<unistd.h>
#include<queue>
#include<semaphore.h>

class RingQueue
{
private:
	std::vector<int> ring;
	int cap;
	sem_t sem_blank;
	sem_t sem_data;
	int product_step = 0;
	int consumer_step = 0;
public:
	void P(sem_t &sem)
	{
		sem_wait(&sem);
	}
	void V(sem_t &sem)
	{
		sem_post(&sem);
	}
public:
	RingQueue(int _cap = 20) :cap(_cap), ring(_cap)
	{
		sem_init(&sem_blank, 0, _cap);
		sem_init(&sem_data, 0, 0);
	}
	void PushData(int &data)
	{
		P(sem_blank);
		//product data
		ring[product_step] = data;

		V(sem_data);

		product_step++;
		product_step %= cap;
	}
	void PopData(int &data)
	{
		sleep(1);
		P(sem_data);
		//consumer data
		data = ring[consumer_step];
		V(sem_blank);

		consumer_step++;
		consumer_step %= cap;
	}
	~RingQueue()
	{
		sem_destroy(&sem_blank);
		sem_destroy(&sem_data);
	}
};
