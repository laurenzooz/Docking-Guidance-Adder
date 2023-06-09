#pragma once
#ifndef SET_DSF_TXT_H
#define SET_DSF_TXT_H

#include <utility>

int get_highest_id(); // returns the highest object id found

void add_stoppingpoint(); // adds the stoppingpoint.obj to every stand position found in apt dat.

std::pair<double, double> get_marshaller_coordinates(double, double, double, double = 10); // returns the new lat lon, input is (lat, lon, hdg, distance) 
void add_marshaller(double = 20, int = 0); // adds the marshaller.obj to every stand found in apt dat, an user given distance from the stand and type .

double deg2rad();
double rad2deg();

#endif