/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:07:07 by yohan             #+#    #+#             */
/*   Updated: 2025/02/06 13:29:07 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        return (1);
    std::string input = argv[1];    
    std::string s1 = argv[2];    
    std::string s2 = argv[3];    
    
    ReplaceFile file(input, s1, s2);
    //file.read();
    file.Replace();
}