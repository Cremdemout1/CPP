/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:17:03 by yohan             #+#    #+#             */
/*   Updated: 2025/03/08 11:27:35 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/deque.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    PmergeMe instance(argv[1]);
    instance.getUnsorted();
    instance.getSequence();
    return 0;
}