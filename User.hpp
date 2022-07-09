/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:59 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/09 16:36:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP

#include <string>

class	User
{
	public:
			User();
			User(int sd, char * IP, uint32_t port );
			~User();

			int	getSocket() const;
			void setSocket(int sd);

			std::string	& getBuff();
			std::string	const & getIP() const;
			uint32_t	getPort() const;
			std::string	& getNick();
			std::string	& getUser();

	private:
			int	socket;
			std::string	IP;
			uint32_t port;
			std::string	buffer;
			std::string	nick;
			std::string user;
};

#endif
