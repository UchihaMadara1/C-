#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>


class Client
{
public:
	Client(std::string _peer_ip = "127.0.0.1", short _peer_port = 8080) :peer_ip(_peer_ip), peer_port(_peer_port), sockfd(-1)
	{}
	void ClientInit()
	{

		sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if (sockfd < 0)
		{
			std::cerr << "sockfd error" << std::endl;
			exit(2);
		}
	}
	void Run()
	{
		std::string massage;
		struct sockaddr_in server;
		server.sin_family = AF_INET;
		server.sin_port = htons(peer_port);
		server.sin_addr.s_addr = inet_addr(peer_ip.c_str());

		socklen_t len = sizeof(server);
		char buf[1024];
		struct sockaddr_in tmp;
		while (1)
		{
			socklen_t  size = sizeof(tmp);
			std::cout << "请输入要发送的信息:" << std::endl;
			std::cin >> massage;
			sendto(sockfd, massage.c_str(), massage.size(), 0, (struct sockaddr*)&server, len);
			ssize_t s = recvfrom(sockfd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&tmp, &len);
			if (s > 0)
			{
				buf[s] = 0;
				std::cout << "server #:" << buf << std::endl;
			}
		}
	}
	~Client()
	{
		if (sockfd >= 0)
		{
			close(sockfd);
		}
	}
private:
	int sockfd;
	std::string peer_ip;
	short peer_port;
};
