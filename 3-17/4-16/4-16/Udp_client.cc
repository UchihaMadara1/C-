#define _CRT_SECURE_NO_WARNINGS

#include "Udp_client.hpp"


void Usage(std::string _proc)
{
	std::cout << _proc << " " << "server_ip server_port " << std::endl;
}
// ./Udp_client server_ip server_port
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}

	return 0;
}
