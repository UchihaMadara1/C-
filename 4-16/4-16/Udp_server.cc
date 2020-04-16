#define _CRT_SECURE_NO_WARNINGS
#include "Udp_server.hpp"

void Usage(std::string _port)
{
	std::cout << _port << " " << "ip  port" << std::endl;
}

// ./Udp_server ip port
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	Server *sp = new Server(argv[1], atoi(argv[2]));
	sp->ServerInit();
	sp->Run();
	return 0;
}
