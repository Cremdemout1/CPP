/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:42:03 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 12:35:17 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/predictor.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    try
    {
        Predictor btc(argv[1]);
        // const std::string ha = "something cool";
        // btc.setFileName(ha);
        btc.evaluate("2010-04-22", 0.3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}