
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 15:42:38 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 15:42:38 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void replace_function(std::string fileName, std::string s1, std::string s2)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }
    std::string line;
    std::string tmp;
    std::string newFileName = fileName + ".replace";
    std::ofstream newFile(newFileName.c_str());
    if (!newFile.is_open())
    {
        std::cerr << "Error: Could not create file " << newFileName << std::endl;
        return;
    }
    while (std::getline(file, line))
    {
        std::string result;
        size_t pos = 0;
        size_t found;
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            result += line.substr(pos, found - pos); // add text before s1
            result += s2;                            // add replacement
            pos = found + s1.length();               // move past s1
        }
        result += line.substr(pos); // add the rest of the line
        newFile << result << std::endl; 
    }
    file.close();
    newFile.close();
}


int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "enter fileName s1 and s2" << std::endl; 
		return(1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if(s1.empty() || s2.empty())
	{
		std::cerr << "Error: The string is empty!" << std::endl;
		return(1);
	}
    replace_function(argv[1], s1, s2);
}