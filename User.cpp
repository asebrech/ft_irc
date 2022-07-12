/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:47 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/12 16:46:44 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User() : socket(0), IP(), port(), buffer(), nick("*"), registered(false) {}

User::User(int sd, char * IP, uint32_t port) : socket(sd), IP(IP), port(port), buffer(), nick("*"), registered(false) {}

User::~User() {}

int	User::getSocket() const { return(socket); }

void	User::setSocket(int sd) { socket = sd; }

std::string const & User::getIP() const { return(IP); }

uint32_t	User::getPort() const { return(port); }

std::string & User::getBuff() { return(buffer); }

std::string & User::getNick() { return(nick); }
std::string const & User::getNick() const { return(nick); }

std::string & User::getUser() { return(user); }

bool	User::getRegistered() const { return(registered); }

void	User::setRegistered(bool val) { registered = val; }
