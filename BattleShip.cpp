#include "BattleShip.h"

//Constructors:
template<class T>
BattleShip<T>::BattleShip()
{
	this->speed = 0.0;
	this->weaponsNumber = 0;
	this->huperJump = false;
	this->size = 0;
}

template<class T>
BattleShip<T>::BattleShip(const double _speed, const int _weaponsNumber, const bool _huperJump, const int _size, const T _pilot)
{
	this->speed = _speed;
	this->weaponsNumber = _weaponsNumber;
	this->huperJump = _huperJump;
	this->size = _size;
	this->pilot = _pilot;
}

template<class T>
BattleShip<T>::BattleShip(const BattleShip& entity)
{
	this->speed = entity.get_speed();
	this->weaponsNumber = entity.get_weaponsNumber();
	this->huperJump = entity.get_huperJump();
	this->size = entity.get_size();
	this->pilot = entity.get_pilot();
}

template<class T>
BattleShip<T>::~BattleShip() {}


//Operators...
template<class T>
BattleShip<T>& BattleShip<T>::operator=(const BattleShip& entity) {
	
	if (this != &entity) {
		
		this->speed = entity.get_speed();
		this->weaponsNumber = entity.get_weaponsNumber();
		this->huperJump = entity.get_huperJump();
		this->size = entity.get_size();
		this->pilot = entity.get_pilot();
	}

	return *this;
}

template<class T>
bool BattleShip<T>::operator==(const BattleShip& entity) const {
	return (this->speed == entity.get_speed())
		&& (this->weaponsNumber == entity.get_weaponsNumber())
		&& (this->huperJump == entity.get_huperJump())
		&& (this->size == entity.get_size())
		&& (this->pilot == entity.get_pilot());
}

template<class T>
bool BattleShip<T>::operator!=(const BattleShip& entity) const {
	return !(*this == entity);
}

template<class T>
std::ostream& operator<<(std::ostream& out, const BattleShip<T>& entity) {
	
	out << entity.get_speed() << std::endl;
	out << entity.get_weaponsNumber << std::endl;
	out << entity.get_huperJump << std::endl;
	out << entity.get_size() << std::endl;

    //out << entity.get_pilot() << std::endl;

	return out;
}


template<class T>
std::istream& operator>>(std::istream& in, BattleShip<T>& entity) {
	
	double _speed = 0;
	int _weaponsNumber = 0;
	bool _huperJump = 0;
	int _size = 0;
	T _pilot;

	std::cout << "Reading from the file" << std::endl;

	in >> _speed;
	entity.set_speed(_speed);

	in >> _weaponsNumber;
	entity.set_weaponsNumber(_weaponsNumber);
	
	in >> _huperJump;
	entity.set_huperJump(_huperJump);

	in >> _size;
	entity.set_size(_size);


	char* temp = new char[100];
	in.getline(temp, 100);
	
	if (toLower(temp) == "jedi")
	{
		Jedi jedi = Jedi();
		in >> jedi;
		entity.set_pilot(jedi);

	}
	else if (toLower(temp) == "stormtrooper")
	{
		Stormtrooper stormtrooper = Stormtrooper();
		in >> stormtrooper;
		entity.set_pilot(stormtrooper);

	}


	return in;
}


