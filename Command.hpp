/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:05:58 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/24 16:44:49 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "Server.hpp"
# include "utile.hpp"

class	Command
{
	public :

			Command();
			Command(int pass);
			~Command();

			void	parsCmd(std::string buf, Client const & client);

	private :

			int	pass;
			std::string	cmd;
			std::vector<std::string>	cmds;
};

#endif
