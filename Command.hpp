/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:05:58 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/12 17:03:25 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <list>
# include <iostream>
# include <algorithm>
# include <string>
# include <map>
# include <sys/socket.h>

# include "User.hpp"
# include "utile.hpp"
# include "define.hpp"

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class	Command
{
	typedef void (Command::*pfunc)(std::vector<std::string>, User &);
	public :

			Command(std::string const & pass, std::list<User> & users);
			~Command();

			void	sendError(User const & user, std::string nb, std::string opt, std::string err);

			void	parsCmd(User & user);

			void	nick(std::vector<std::string> cmds, User & user);

	private :

			std::string	pass;
			std::list<User> & users;
			std::map<std::string, pfunc>	cmdMap;
};

#endif
