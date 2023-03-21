#include <string>
#include <iostream>
#include <cstring>


#include "file_reader.h"


int get_highest_id()
{
	std::string input = read_file_to_string("Earth nav data/dsf.txt"); 
	std::cout << input;
	
	// TODO: A system that finds the dsf file itself, and doesn't require user to rename it to dsf.txt and moving



	int highest = -1;
	
	size_t found = input.find("\nOBJECT ");
	
	while (found != std::string::npos) // as long as object is found, check the id after it and save the highest
	{
		//std::cout << "Found at: " << found << "\n";
		std::string temp = "";

		int i = found + 8; // 8 is the length of the string we found using find last of. (so skip the name, and start iterating from where the id starts)
		while(input[i] != ' ')
		{
			temp += input[i];
			i++;
		}

		// check if the found one is larger than the highest so far
		if (std::stoi(temp) > highest) {highest = std::stoi(temp);}


		found = input.find("\nOBJECT ", found + 1); // get the next one
	}




		

		// next space was found, the id is now in tempstr. Convert that to int

		return (highest);

	

}
