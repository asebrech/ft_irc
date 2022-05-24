/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:27:17 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/24 14:03:35 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

class	Client
{
	public:
			Client();
			Client(int sd);
			~Client();

			int	getSocket() const;
			void setSocket(int sd);
	private:
			int	socket;
};

#endif
