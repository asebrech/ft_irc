/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:59 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/06 15:44:01 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP

#include <string>

class	User
{
	public:
			User();
			User(int sd);
			~User();

			int	getSocket() const;
			void setSocket(int sd);

			std::string	& getBuff();

	private:
			int	socket;
			std::string	buffer;
};

#endif
