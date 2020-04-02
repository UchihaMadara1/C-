#ifndef PTHREAD_POOL_HPP
#define PTHREAD_POOL_HPP
#include<iostream>
#include<string>
#include<queue>
#include<unistd.h>
#include<pthread.h>

#define NUM 5
class Task
{
public:
	Task()
	{
		a = 1;
		b = 1;
		op = '+';
	}
	Task(int _a, int _b, char _op) :a(_a), b(_b), op(_op)
	{}
	~Task()
	{}
	void Run()//handler task
	{
		int result = 0;
		switch (op)
		{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case'/':
			result = b == 0 ? -1 : (a / b);
			break;
		default:
			break;
		}
		std::cout << "thread_id : " << pthread_self() << " : " << a << op << b << " = " << result << std::endl;
	}
private:
	int a;
	int b;
	char op;
};

class PthreadPool
{
public:
	bool TaskQueueEmpty()
	{
		return q.size() == 0;
	}
	void LockTaskQueue()
	{
		pthread_mutex_lock(&lock);
	}
	void UnlockTaskQueue()
	{
		pthread_mutex_unlock(&lock);
	}
	void ThreadWait()
	{
		pthread_cond_wait(&cond, &lock);
	}
	void ThreadWakeUp()
	{
		pthread_cond_signal(&cond);
	}
public:
	PthreadPool(int val = NUM) :num(val)
	{}
	static void *Routine(void *arg)
	{
		PthreadPool *self = (PthreadPool*)arg;
		while (true)
		{
			self->LockTaskQueue();
			while (self->TaskQueueEmpty())
			{
				self->ThreadWait();
			}
			Task t;
			self->PopTask(t);
			self->UnlockTaskQueue();

			t.Run();
		}
	}
	void PthreadPoolInit()
	{
		pthread_t tid;
		for (int i = 0; i < num; ++i)
			pthread_create(&tid, nullptr, Routine, this/*dang qian dui xiang */);
		pthread_mutex_init(&lock, nullptr);
		pthread_cond_init(&cond, nullptr);
	}
	void PushTask(Task &t)
	{
		LockTaskQueue();
		q.push(t);
		UnlockTaskQueue();
		ThreadWakeUp();
	}
	void PopTask(Task &t)
	{
		t = q.front();
		q.pop();
	}
	~PthreadPool()
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&cond);
	}
private:
	std::queue<Task> q;
	int num;

	pthread_mutex_t lock;
	pthread_cond_t cond;
};












#endif
