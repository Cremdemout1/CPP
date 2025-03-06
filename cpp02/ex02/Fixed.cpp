/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:04:54 by yohan             #+#    #+#             */
/*   Updated: 2025/02/07 21:19:12 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : integer(0) {std::cout << "Default constructor called" << std::endl;};

Fixed::Fixed(const int newValue)
{
    std::cout << "Integer constructor called" << std::endl;
    integer = newValue << fractionalBit;
}

Fixed::Fixed(const float newValue)
{
    std::cout << "Float constructor called" << std::endl;
    integer = roundf(newValue * (1 << fractionalBit));
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    integer = copy.integer;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->integer = other.integer;
    return (*this);
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;};

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->integer = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->integer);
}

int Fixed::toInt( void ) const
{
    return (this->integer >> fractionalBit);
}

float Fixed::toFloat( void ) const
{
    return (float(this->integer) / (1 << fractionalBit));
}

 //_______________________operators______________________________//
 
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->integer > other.integer);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->integer < other.integer);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->integer >= other.integer);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->integer <= other.integer);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->integer == other.integer);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->integer != other.integer);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator++(void) // ++i
{
    integer += 1;
    return (*this);
}

Fixed Fixed::operator--(void) // --i
{
    integer -= 1;
    return(*this);
}

Fixed Fixed::operator++(int) // i++
{
    Fixed temp = *this;
    integer += 1;
    return (temp);
}

Fixed Fixed::operator--(int) // i--
{
    Fixed temp = *this;
    integer -= 1;
    return (temp);
}

// _________________Public overloaded functions____________________ //

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}
    