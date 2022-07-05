/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:27:17 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/05 17:51:05 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class	Client
{
	public:
			Client();
			Client(int sd);
			~Client();

			int	getSocket() const;
			void setSocket(int sd);

			int	getRet() const;
			void setRet(int sd);

			std::string	& getBuff();

	private:
			int	socket;
			int	ret;
			std::string	buffer;
};

#endif
