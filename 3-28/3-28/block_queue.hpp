#pragma once
#include<queue>
#include<iostream>
#include<pthread.h>

class BlockQueue
{
public:
	BlockQueue(int cap = 5) :capacity(cap)
	{
		pthread_mutex_init(&lock, nullptr);
	}
	~BlockQueue()
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&cond_c);
		pthread_cond_destroy(&cond_p);
	}
private:
	bool IsFull()
	{
		return q.size() == capacity;
	}
	bool IsEmpty()
	{
		return q.size() == 0;
	}
private:
	void lockqueue()
	{
		pthread_mutex_lock(&lock);
	}
	void unlockqueue()
	{
		pthread_mutex_unlock(&lock);
	}
	void ProductorWait()
	{
		pthread_cond_wait(&cond_p, &lock);
	}
	void ConsumerWait()
	{
		pthread_cond_wait(&cond_c, &lock);
	}
public:
	void Push(int &data)
	{
		lockqueue();
		while (IsFull())
		{
			pthread_cond_signal(&cond_c);
			ProductorWait();
			//push data
		}
		q.push(data);
		unlockqueue();
		//	pthread_cond_signal(&cond_c);
	}
	void Pop(int &data)
	{
		lockqueue();
		while (IsEmpty())
		{
			pthread_cond_signal(&cond_p);
			ConsumerWait();
			//pop data
		}
		data = q.front();
		q.pop();

		unlockqueue();
		//pthread_cond_signal(&cond_p);
	}
private:
	int capacity;
	std::queue<int> q;

	pthread_mutex_t lock;
	pthread_cond_t cond_c;
	pthread_cond_t cond_p;
};
