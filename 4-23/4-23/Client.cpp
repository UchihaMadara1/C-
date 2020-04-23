#define _CRT_SECURE_NO_WARNINGS
#include "Server.hpp"

void Usage(std::string proc)
{
	std::cout << "Usage: " << proc << " local_ip local_port" << std::endl;
}
int main(int argc, char *argv[])
{
	if (argc != 3){
		Usage(argv[0]);
		exit(1);
	}

	int port = atoi(argv[2]);
	std::string ip = argv[1];

	Server *sp = new Server(ip, port);
	sp->InitServer();
	sp->Start();

	return 0;
}
