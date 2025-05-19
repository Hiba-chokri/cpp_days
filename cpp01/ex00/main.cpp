/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:03:53 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:03:53 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

    Zombie* heapZombie;
    heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie; // must manually destroy heap object
    randomChump("StackZom"); // auto-destroyed at end of function

    return 0;
}