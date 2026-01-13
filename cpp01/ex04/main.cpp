/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:14:41 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/13 16:18:58 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char *argv[])
{
	std::string	fileName, fileNameReplace, line, modifiedLine, s1, s2;
	size_t		pos, found;

	if (argc != 4)
	{
		std::cerr << GREEN "Usage: ./replace <filename> <s1> <s2>" RESET << std::endl;
		return (1);
	}
	fileName = argv[1];
	s1 = argv[2];
	if (s1.empty())
	{
		std::cout << RED "Error! The string to replace cannot be empty." RESET << std::endl;
		return (1);
	}
	s2 = argv[3];
	std::ifstream inFile(fileName.c_str(), std::ifstream::in);
	if (!inFile.is_open())
	{
		std::cerr << RED "Failed to open file: " << fileName << RESET << std::endl;
		return (1);
	}
	fileNameReplace = fileName + ".replace";
	std::ofstream outFile(fileNameReplace.c_str());
	if (!outFile.is_open())
	{
		std::cerr << RED "Failed to open file: " << fileName + ".replace" RESET << std::endl;
		inFile.close();
		return (1);
	}
	while (getline(inFile, line))
	{
		modifiedLine = "";
		pos = 0;
		while ((found = line.find(s1, pos)) != std::string::npos)
		{
			modifiedLine += line.substr(pos, found - pos);
			modifiedLine += s2;
			pos = found + s1.length();
		}
		modifiedLine += line.substr(pos);
		outFile << modifiedLine;
		if (!inFile.eof())
			outFile << std::endl;
	}
	inFile.close();
	outFile.close();
	return (0);
}
