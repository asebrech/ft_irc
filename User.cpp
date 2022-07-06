/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:47 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/06 15:43:50 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User() : socket(0), buffer() {}

User::User(int sd) : socket(sd), buffer() {}

User::~User() {}

int	User::getSocket() const { return(socket); }

void	User::setSocket(int sd) { socket = sd; }

std::string & User::getBuff() { return(buffer); }
