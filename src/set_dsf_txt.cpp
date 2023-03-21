#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <utility>
#include <functional>
#include <iomanip>


#include "file_reader.h"
#include "parse_apt_dat.h"


int get_highest_id()
{
	std::string input = read_file_to_string("Earth nav data/dsf.txt"); 
	
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


void add_stoppingpoint()
{
	std::vector<std::vector<double>> stand_data = read_apt_dat();

	std::string file = read_file_to_string("Earth nav data/dsf.txt"); 

	file += "\n\n"; // start writing the new stuff

	// add the stoppingpoint object definition
	file += "OBJECT_DEF adgs/StoppingPoint.obj\n";

	int id = get_highest_id() + 1; // id for the stoppingpoint object
	

	for (int i = 0; i < stand_data[0].size(); i++)
	{
		file += "OBJECT ";
		file += std::to_string(id);
		file += " ";
		
		file += std::to_string(stand_data[1][i]);
		file += " ";
		
		file += std::to_string(stand_data[0][i]);
		file += " ";
		
		file += std::to_string(stand_data[2][i]);
		file += "\n";

		// for some reason, in X-Plane dsf files the lat and lon are the wrong way around???

	}

	std::ofstream write_output("Earth nav data/dsf_out.txt");
	write_output << file;


	// write an output file

	// std::cout << file;
	
// std::cout << "\n\n\n\n ID: " << id << "\n\n\n\n\n";
}


double deg2rad(double deg)
{
    return ((deg * M_PI) / 180.0);
}

double rad2deg(double rad)
{
    return ((rad * 180) / M_PI);
}








std::pair<double, double> get_marshaller_coordinates(double lat, double lon, double hdg, double dist = 10)
{
	double R = 6371000; // earth radius
	double latr = deg2rad(lat);
	double lonr = deg2rad(lon);
	double hdgr = deg2rad(hdg);

	//double lat_new = asin(sin())
	//double lat_new = 

	
	double lat_new = asin(sin(latr) * cos(dist / R) + cos(latr) * sin(dist / R) * cos(hdgr));


	double lon_new = lonr + atan2(sin(hdgr) * sin(dist / R) * cos(latr), cos(dist / R) - sin(latr) * sin(lat_new));

	return (std::make_pair(rad2deg(lat_new), rad2deg(lon_new)));

}


void add_marshaller(double dist = 20)
{
	std::vector<std::vector<double>> stand_data = read_apt_dat();

	std::string file = read_file_to_string("Earth nav data/dsf_out.txt"); 

	file += "\n\n"; 

	file += "OBJECT_DEF adgs/Marshaller.obj\n";

	int id = get_highest_id() + 2; // marshaller id is one higher than stoppingpoint
	

	for (int i = 0; i < stand_data[0].size(); i++)
	{

		std::pair<double, double> coords = get_marshaller_coordinates(stand_data[0][i], stand_data[1][i], stand_data[2][i], dist); 	// get the new coordinates with the given distance


		file += "OBJECT ";
		file += std::to_string(id);
		file += " ";
		
		file += std::to_string(coords.second); 
		file += " ";
		
		
		file += std::to_string(coords.first);
		file += " ";
		
		
		file += std::to_string(stand_data[2][i]);
		file += "\n";

		// for some reason, in X-Plane dsf files the lat and lon are the wrong way around???

	}

	std::ofstream write_output("Earth nav data/dsf_out.txt");
	write_output << file;


	// write an output file

	// std::cout << file;
	
// std::cout << "\n\n\n\n ID: " << id << "\n\n\n\n\n";
}


