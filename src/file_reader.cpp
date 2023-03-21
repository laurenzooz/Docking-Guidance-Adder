#include <fstream>
#include <string>
#include <iostream>

#include "file_reader.h"


std::string read_file_to_string(std::string path)
{
	std::ifstream file(path);

	std::string file_input = "";
	std::string row;
	if (file.is_open())
	{
		while (std::getline(file, row))
		{
			file_input += row;
			file_input.push_back('\n');
		}
	}
	else
	{
		std::cout << "File not found!\n";
	}
	

	return file_input;
}