#include <iostream>

#include "parse_apt_dat.h"
#include "set_dsf_txt.h"

/*
	TODO: 
	- Get the last obj id from the dsf file that is converted to txt (later, do the conversion urself)
	- Parse the apt.dat file for stand locations and headings
	- In the dsf converted to txt, add the stoppingposition.obj to every stand position (and later for docking guidance style as well)
	- Ask the user for distance from stand to the marshaller
	- In the dsf txt file add marshaller.objs, the user desired distance from every stand.


*/






int main()
{
	std::vector<std::vector<double>> stand_data = read_apt_dat();
	for (int i = 0; i < stand_data[0].size(); i++)
	{
		//std::cout << stand_data[0][i] << "\t" << stand_data[1][i] << "\t" << stand_data[2][i] << "\n";
	}

	std::cout << get_highest_id() << "\n\n\n";

	return 0;
}