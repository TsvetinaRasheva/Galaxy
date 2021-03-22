#include <iostream>
#include <fstream>
#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"


int main()
{

	//Planet planet = Planet("Rishi",TypePlanet::Ice, "Rishi system","Republic Navy");
	//Stormtrooper st = Stormtrooper("LS - 005",RankOfStormtrooper::Commander,"Magma trooper",planet);
	//Jedi jedi = Jedi("Yoda",RankOfJedi::GrandMaster,17700,planet,"Yoda’s species","General");
	
	Planet planet = Planet();
	setData(planet);
	print(planet);
	


	return 0;
}