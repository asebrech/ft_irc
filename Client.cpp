/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:32:24 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/24 14:03:59 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client() : socket(0) {}

Client::Client(int sd) : socket(sd) {}

Client::~Client() {}

int	Client::getSocket() const { return(socket); }

void	Client::setSocket(int sd) { socket = sd; }
