/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:05:58 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/06 16:50:16 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <list>
# include <iostream>
# include <string>

# include "User.hpp"
# include "utile.hpp"

class	Command
{
	public :

			Command(std::string const & pass, std::list<User> & users);
			~Command();

			void	parsCmd(std::list<User>::iterator const & user);

	private :

			std::string	pass;
			std::list<User> & users;
};

#endif
