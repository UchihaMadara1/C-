#define _CRT_SECURE_NO_WARNINGS
#include "ringqueue.hpp"

void *consumer(void * arg)
{
	RingQueue *rq = (RingQueue*)arg;
	while (true)
	{
		int data;
		rq->PopData(data);

		std::cout << "consumer data done...:" << data << std::endl;
	}
}
void *productor(void *arg)
{
	RingQueue *rq = (RingQueue*)arg;
	srand((unsigned int)time(nullptr));
	while (true)
	{
		int data = rand() % 100 + 1;
		rq->PushData(data);

		std::cout << "productor data done ...:" << data << std::endl;
	}
}
int main()
{
	RingQueue *cp = new RingQueue(5);

	pthread_t c, p;
	pthread_create(&c, nullptr, consumer, cp);
	pthread_create(&p, nullptr, productor, cp);

	pthread_join(c, nullptr);
	pthread_join(p, nullptr);

	delete cp;
	return 0;
}

