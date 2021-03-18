#include <iostream>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

int main()
{
	//Planet planet = Planet("Rishi",PlanetType::Ice, "Rishi system","Republic Navy");
	//Stormtrooper st = Stormtrooper("LS - 005",RankOfStormtrooper::Commander,"Magma trooper",planet);
	//Jedi jedi = Jedi("Yoda",RankOfJedi::GrandMaster,17700,planet,"Yoda’s species","General");


	Planet planet = Planet();
	std::cin >> planet;	
	std::cout << std::endl;
	print(planet);
	std::cout << std::endl;

	Stormtrooper st = Stormtrooper();
	std::cin >> st;
	std::cout << std::endl;
	print(st);
	std::cout << std::endl;


	Jedi jedi = Jedi();
	std::cin >> jedi;
	std::cout << std::endl;
	print(jedi);
	std::cout << std::endl;


	return 0;
}