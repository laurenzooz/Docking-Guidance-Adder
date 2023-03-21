adg: Main.o file_reader.o parse_apt_dat.o set_dsf_txt.o
	g++ Main.o file_reader.o parse_apt_dat.o set_dsf_txt.o -o adg


Main.o: src/Main.cpp
	g++ -c src/Main.cpp

file_reader.o: src/file_reader.cpp
	g++ -c src/file_reader.cpp

parse_apt_dat.o: src/parse_apt_dat.cpp
	g++ -c src/parse_apt_dat.cpp

set_dsf_txt.o: src/set_dsf_txt.cpp
	g++ -c src/set_dsf_txt.cpp
	
clean: 
	rm *.o adg