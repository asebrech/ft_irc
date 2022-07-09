/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:07:42 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/09 17:16:04 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
Command::Command(std::string const & pass, std::list<User> & users) : pass(pass), users(users) 
{
	cmdMap[std::string("NICK")] = &Command::nick; 
}

Command::~Command() {}

void	Command::parsCmd(User & user)
{
	(void)users;
	std::vector<std::string>	cmd;
	if(user.getBuff()[user.getBuff().length() - 2] == '\r')
		cmd = split(user.getBuff(), "\r\n");
	else
		cmd = split(user.getBuff(), "\n");
	std::vector<std::string>::iterator	it = cmd.begin();
	std::map<std::string, pfunc>::iterator	iter;
	for (; it != cmd.end(); it++)
	{
		std::vector<std::string>	cmds = split(*it, " ");
		iter = cmdMap.find(cmds[0]);
		if (iter != cmdMap.end())
			CALL_MEMBER_FN(*this, iter->second) (cmds);
	}
}

void	Command::nick(std::vector<std::string>  cmds)
{
	std::vector<std::string>::iterator	it = cmds.begin();
	for(; it != cmds.end(); it++)
		std::cout << *it << std::endl;
}
