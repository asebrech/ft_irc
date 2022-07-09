/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:47 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/09 16:34:33 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User() : socket(0), IP(), port(), buffer(), nick() {}

User::User(int sd, char * IP, uint32_t port) : socket(sd), IP(IP), port(port), buffer(), nick() {}

User::~User() {}

int	User::getSocket() const { return(socket); }

void	User::setSocket(int sd) { socket = sd; }

std::string const & User::getIP() const { return(IP); }

uint32_t	User::getPort() const { return(port); }

std::string & User::getBuff() { return(buffer); }

std::string & User::getNick() { return(nick); }

std::string & User::getUser() { return(user); }
