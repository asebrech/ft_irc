/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:07:42 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/24 16:45:27 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command() {}

Command::Command(int pass) : pass(pass) {}

Command::~Command() {}

void	Command::parsCmd(std::string buf, Client const & client)
{
		cmd = buf;
		cmds = split(buf, ' ');
		(void)client;
		(void)pass;
}
