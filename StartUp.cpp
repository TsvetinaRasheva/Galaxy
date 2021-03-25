#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../GalaxyProject/BattleShip.h"
#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"


using namespace std;

//#include <assert.h>
//assert(bool) -> if not True, it kills program




int main()
{

	Planet planet = Planet("tt",TypePlanet::Lava,"ggg","hhh");
	Stormtrooper stormtrooper = Stormtrooper();
	Jedi jedi = Jedi();

	/*std::cout << "\n Read data for Planet: " << std::endl;
	std::ofstream outfile;
	outfile.open("Planet.txt", ios_base::out | ios_base::app);	
	setData(std::cin, planet);
	write(outfile, planet);
	outfile.close();

	std::cout << "\n Display data for Planet: " << std::endl;
	std::ifstream infile;
	infile.open("Planet.txt");
	setData(infile, planet);
	write(std::cout, planet);
	outfile.close();

	std::cout << "\n Read data for Stormtrooper: " << std::endl;
	std::ofstream outfile1;
	outfile1.open("Storm.txt", ios_base::out | ios_base::app);
	setData(std::cin, stormtrooper);
	write(outfile1, stormtrooper);
	outfile1.close();
	
	std::cout << "\n Display data for Stormtrooper: " << std::endl;
	std::ifstream infile1;
	infile1.open("Storm.txt");
	setData(infile1, stormtrooper);
	write(std::cout, stormtrooper);
	infile1.close();

	std::cout << "\n Read data for Jedi: " << std::endl;
	std::ofstream outfile2;
	outfile2.open("Jedi.txt", ios_base::out | ios_base::app);
	setData(std::cin, jedi);
	write(outfile2, jedi);
	outfile2.close();

	std::cout << "\n Display data for Jedi: " << std::endl;
	std::ifstream infile2;
	infile2.open("Jedi.txt");
	setData(infile2, jedi);
	write(std::cout, jedi);
	infile2.close();
	*/

	
	/*BattleShip<Jedi> battleShip = BattleShip<Jedi>(1,22,true,2,jedi);
	std::cin >> battleShip;*/

	return 0;
}

