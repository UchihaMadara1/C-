#define _CRT_SECURE_NO_WARNINGS

#include "protocol.hpp"
void Usage(std::string proc)
{
	std::cout << "proc" << " " << "ip port" << std::endl;
}
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
}
