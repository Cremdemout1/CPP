/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:50:10 by yohan             #+#    #+#             */
/*   Updated: 2025/02/06 16:16:47 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    private:
    int integer;
    static const int fractionalBit = 8;
    public:
    Fixed();
    Fixed(const Fixed &copy); // to copy values from existing object to new object
    Fixed &operator=(const Fixed &other); // to copy values of existing object to other existing object
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed();
};

#endif