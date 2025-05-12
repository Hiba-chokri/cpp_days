/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:05:32 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:05:32 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include<cstring>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (size_t j = 0; j < strlen(argv[i]); j++)
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                {
                    argv[i][j] = toupper(argv[i][j]);
                }
                std::cout << argv[i][j];
            }
        }
        std::cout << std::endl;
    }
}