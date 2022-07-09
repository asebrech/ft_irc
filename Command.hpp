/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:05:58 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/09 15:56:35 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <list>
# include <iostream>
# include <string>
# include <map>

# include "User.hpp"
# include "utile.hpp"

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class	Command
{
	typedef void (Command::*pfunc)(std::vector<std::string>);
	public :

			Command(std::string const & pass, std::list<User> & users);
			~Command();

			void	parsCmd(User & user);


			void	nick(std::vector<std::string> cmds);

	private :

			std::string	pass;
			std::list<User> & users;
			std::map<std::string, pfunc>	cmdMap;
};

#endif
