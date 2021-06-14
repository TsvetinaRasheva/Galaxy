#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include "../GalaxyProject/BattleShip.h"
#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"
#include "LinkedList.h"
#include "String.h"
#include <cstring>


template<typename T>
using fn = void(*) (T&);
template<typename T>
using func = bool(*) (const T&);

template<typename T>
void mapFunc(std::vector<T>& vectors, size_t size, fn<T> func) { 
	for (size_t i = 0; i < size; i++)
	{
		func(vectors.at(i));
	}
}

template<typename T>
void filterFunc(std::vector<T>& vectors, func<T> func) { 
	for (size_t i = 0; i < vectors.size(); i++)
	{
		if (!func(vectors.at(i)))
		{
			vectors.erase(vectors.begin() + i);
		}
	}
}



int main()
{




	return 0;
}

