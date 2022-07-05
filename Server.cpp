/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:47:49 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/05 18:23:29 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "utile.hpp"

Server::Server() : port(4242), pass("pass") {}

Server::~Server() {} ;

void	Server::init()
{
	int	opt = 1;

	if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)  
		throw std::runtime_error("socket");

	if(setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0)  
		throw std::runtime_error("setsockopt");

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)  
		throw std::runtime_error("bind failed");
	std::cout << "Listener on port " << port << " pass is " << pass << std::endl;

	if (listen(master_socket, 3) < 0)  
		throw std::runtime_error("listen");
	addrlen = sizeof(address);
	std::cout << "Waiting for connections ..." << std::endl;
}

void	Server::run()
{
	int	sd;
	int	max_sd;
	int	ret;
	std::list<Client>::iterator	it;
	std::string buffer;
	buffer.resize(1024);

	while(true)
	{
		FD_ZERO(&readfds);
		FD_SET(master_socket, &readfds);  
		max_sd = master_socket;
		for (it = client.begin(); it != client.end(); it++)
		{
			sd = it->getSocket();		
			FD_SET(sd, &readfds);
			if (sd > max_sd)
				max_sd = sd;
		}
		ret = select(max_sd + 1 , &readfds , NULL , NULL , NULL);  
		if ((ret < 0) && (errno!=EINTR))  
			throw std::runtime_error("select error");
		if (FD_ISSET(master_socket, &readfds))  
		{
			if ((ret = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)  
				throw std::runtime_error("accept");
			std::cout << "New connection, socket fd : " << ret << ", IP : " << inet_ntoa(address.sin_addr) << ", port : " << ntohs(address.sin_port) << std::endl;
			client.push_back(Client(ret));
		}
		for (it = client.begin(); it != client.end(); it++)
		{
			sd = it->getSocket();
			if (FD_ISSET(sd, &readfds))
			{
				if ((ret = recv(sd, (void*)&it->getBuff().data()[it->getRet()], 1024, 0)) == 0)
				{
					getpeername(sd , (struct sockaddr*)&address , (socklen_t*)&addrlen);  
					std::cout << "Host disconnected, socket fd : " << sd << ", IP : " << inet_ntoa(address.sin_addr) << ", port : " << ntohs(address.sin_port) << std::endl;
					close(sd);
					client.erase(it);
				}	
				else
				{
					it->setRet(it->getRet() + ret);
					if (it->getBuff()[it->getRet() - 1] == '\n')
					{
						getpeername(sd , (struct sockaddr*)&address , (socklen_t*)&addrlen);  
						std::cout << "Command received, socket fd : " << sd << ", IP : " << inet_ntoa(address.sin_addr) << ", port : " << ntohs(address.sin_port)
						<< ", Content : " << std::endl ;//<< buffer;
						std::vector<std::string>	cmd = split(it->getBuff(), (char *)"\r\n", 2);
						std::vector<std::string>::iterator	itt = cmd.begin();
						std::cout << cmd.size() << std::endl;
						for (itt = cmd.begin(); itt != cmd.end(); itt++)
							std::cout << *itt << " | ";
						std::cout << std::endl;
						it->getBuff().clear();
						it->getBuff().resize(1024);
						it->setRet(0);
					}
				}
			}
		}
	}
}
