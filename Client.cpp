/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:32:24 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/05 17:11:01 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client() : socket(0), ret(0) { buffer.resize(1024); }

Client::Client(int sd) : socket(sd), ret(0) { buffer.resize(1024); };

Client::~Client() {}

int	Client::getSocket() const { return(socket); }

void	Client::setSocket(int sd) { socket = sd; }

int	Client::getRet() const { return(ret); }

void	Client::setRet(int val) { ret = val; }

std::string & Client::getBuff() { return(buffer); }
