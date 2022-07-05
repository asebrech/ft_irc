/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:27:10 by asebrech          #+#    #+#             */
/*   Updated: 2022/07/05 18:20:17 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utile.hpp"

std::vector<std::string> split(const std::string& s, char *seperator, int len)
{
   std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(seperator, pos)) != std::string::npos)
    {
        std::string substring( s.substr(prev_pos, pos-prev_pos) );

        output.push_back(substring);

		pos += len;
        prev_pos = pos;
    }

	if (prev_pos == 0)
    	output.push_back(s.substr(prev_pos, pos-prev_pos));

    return output;
}
