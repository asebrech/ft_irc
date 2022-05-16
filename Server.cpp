/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:47:49 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/16 18:19:41 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server() : port(4242), pass("pass") {} 

Server::~Server() {} ;

void	Server::init()
{
	int	opt = 1;
	if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)  
	{  
		perror("socket failed");  
		exit(EXIT_FAILURE);  
	}
	if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )  
	{  
		perror("setsockopt");  
		exit(EXIT_FAILURE);  
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)  
	{  
		perror("bind failed");  
		exit(EXIT_FAILURE);  
	}  
	printf("Listener on port %d \n", port);
	if (listen(master_socket, 3) < 0)  
	{  
		perror("listen");  
		exit(EXIT_FAILURE);  
	}
	addrlen = sizeof(address);
	puts("Waiting for connections ...");
}

void	Server::run()
{
	int	sd;
	int	activity;
	int	new_socket;
	std::vector<Client>::iterator	it;
	char message[] = "ECHO Daemon v1.0 \r\n";

	while(true)
	{
		FD_ZERO(&readfds);
		FD_SET(master_socket, &readfds);  
		max_sd = master_socket;
		for (it = client.begin(); it != client.end(); it++)
		{
			sd = it->getSocket();		
			if (sd > 0)
				FD_SET(sd, &readfds);
			if (sd > max_sd)
				max_sd = sd;
		}
		activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);  
		if ((activity < 0) && (errno!=EINTR))  
		{  
			printf("select error");  
		}
		if (FD_ISSET(master_socket, &readfds))  
		{
			if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)  
			{  
				perror("accept");  
				exit(EXIT_FAILURE);  
			}
		}
		printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
		if( (size_t)send(new_socket, message, strlen(message), 0) != strlen(message) )  
		{  
			perror("send");  
		}
	}
}
