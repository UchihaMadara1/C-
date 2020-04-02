#define _CRT_SECURE_NO_WARNINGS
#include"thread_pool.hpp"

int main()
{
	PthreadPool *tp = new PthreadPool(5);
	tp->PthreadPoolInit();
	srand((unsigned int)time(nullptr));
	std::string s = "+-*/";
	while (true)
	{
		int x = rand() % 500 + 1;
		int y = rand() % 50 + 1;
		char op = s[rand() % 4];

		Task t(x, y, op);
		tp->PushTask(t);
		sleep(1);
	}
	delete tp;
	return 0;
}

