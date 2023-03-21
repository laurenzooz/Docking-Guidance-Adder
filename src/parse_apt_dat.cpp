#include <vector>
#include <iostream>

#include "file_reader.h"



std::vector<std::vector<double>> read_apt_dat()
{
	std::vector<std::vector<double>> stand_data;

	stand_data.resize(3); // [0]: Lat, [1]: Lon, [2]: Heading


	std::string input = read_file_to_string("Earth nav data/apt.dat"); 


	size_t found = input.find("\n1300  "); // -1 if not found
	while (found != -1)
	{
		std::string temp_row = ""; // read one row at a time (if the row has "1300 ")

		for (int i = found + 6; i < input.size(); i++) // where the important stuff actuallyt starts
		{
			if (input[i] == '\n') { break; }
			temp_row += input[i];
		}



		std::string temp_str = "";
		int inputs_found = 0; // basically search for periods/full stops. The coordinate always has one so a good way to keep track of how many are found

		for (int i = 0; i < temp_row.size(); i++)
		{
			if (temp_row[i] != '\n') {temp_str += temp_row[i];} // don't add row changes

			// a coordinate or a heading input is found. (they always have a period)
			if (temp_row[i] == '.')
			{
				inputs_found++;

				if (inputs_found == 1) 	// when first period is found, iterate till next space to get the x coordinate
				{
					for (int j = i; j < temp_row.size(); j++)
					{
						i++; // make sure also i gets iterated

						if (temp_row[i] == ' ')
						{
							stand_data[0].push_back(std::stod(temp_str)); // lat

							temp_str = ""; // empty the temp
							break;
						}


						temp_str += temp_row[i];

					}
					continue;

				}

				else if (inputs_found == 2) 	// exactly same idea for the heading
				{
					for (int j = i; j < temp_row.size(); j++)
					{
						i++; // make sure also i gets iterated

						if (temp_row[i] == ' ')
						{

							stand_data[1].push_back(std::stod(temp_str)); // Lon

							temp_str = "";
							break;
						}
						temp_str += temp_row[i];

					}

					continue;


				}


				else if (inputs_found == 3)
				{
					for (int j = i; j < temp_row.size(); j++)
					{
						i++;

						if (temp_row[i] == ' ')
						{
								stand_data[2].push_back(std::stod(temp_str)); // hdg



							temp_str = "";
							break;
						}
						temp_str += temp_row[i];

					}
					continue;
				}

			}


		}

		size_t found_new = input.find("\n1300 ", found + 1); // continue from the next one
		found = found_new;

		
	}

	return stand_data;
}