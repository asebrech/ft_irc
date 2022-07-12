/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:07:42 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/12 17:24:39 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
Command::Command(std::string const & pass, std::list<User> & users) : pass(pass), users(users) 
{
	cmdMap[std::string("NICK")] = &Command::nick; 
}

Command::~Command() {}

void	Command::sendError(User const & user, std::string nb, std::string opt, std::string err)
{
	std::string	error(":ft_server ");
	if (!opt.empty())
		error += nb + " " + user.getNick() + " " + opt + " " + err + "\r\n";
	else
		error += nb + " " + user.getNick() + " " + err + "\r\n";
	send(user.getSocket(), error.c_str(), error.length(), 0);
}

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
		if (cmds[0][0] == ':')
		{
			cmds[0].erase(0, 1);
			if (cmds[0] != user.getNick())
				return ;
			cmds.erase(cmds.begin());
		}
		std::transform(cmds[0].begin(), cmds[0].end(),cmds[0].begin(), toupper);
		iter = cmdMap.find(cmds[0]);
		if (iter != cmdMap.end())
			CALL_MEMBER_FN(*this, iter->second) (cmds, user);
	}
}

void	Command::nick(std::vector<std::string> cmds, User & user)
{
	(void)user;
	if (cmds.size() == 1)
	{
		sendError(user, "431", "", ERR_NONICKNAMEGIVEN);
		return ;
	}
	std::list<User>::iterator	it = users.begin();
	for(; it != users.end(); it++)
		if (cmds[1] == it->getNick())
		{
			sendError(user, "433", cmds[1], ERR_NICKNAMEINUSE);
			return ;
		}
	user.getNick().assign(cmds[1]);
	user.setRegistered(true);
}
