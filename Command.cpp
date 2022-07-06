/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:07:42 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/06 17:07:22 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(std::string const & pass, std::list<User> & users) : pass(pass), users(users) {}

Command::~Command() {}

void	Command::parsCmd(std::list<User>::iterator const & ite)
{
	std::list<User>::iterator	it = users.begin();
	while (it != ite)
			it++;
	std::cout << it->getBuff();
}
