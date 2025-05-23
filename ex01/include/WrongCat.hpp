/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:56:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/23 11:56:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Constructors
		WrongCat();
		WrongCat(const WrongCat &original);
	// Destructors
		~WrongCat();
	// Operator overloads
		WrongCat &operator=(const WrongCat &original);
	// Getters
		std::string const	getType() const;
	// Setters
		void				setType(std::string type);
	// Member functions
		void				makeSound() const;
};

#endif // WRONG_CAT_HPP
