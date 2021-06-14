#pragma once
//#include <iostream>
//#include <fstream>
#include "Jedi.h"
#include "Stormtrooper.h"
#include "Planet.h"
#include "String.h"
#include <assert.h>

enum class Equipment {
	easy,
	medium,
	hard
};

Equipment stringToEnum(String str) {
	str.toLowerCase();
	if (str == "easy")
	{
		return Equipment::easy;
	}
	else if (str == "medium")
	{
		return Equipment::medium;
	}
	else
	{
		return Equipment::hard;
	}
}

String EnumToString(Equipment& _eq) {
	String result;
	switch (_eq)
	{
	case Equipment::easy: {
		result = "easy";
		break;
	}
	case Equipment::medium: {
		result = "medium";
		break;
	}
	case Equipment::hard: {
		result = "hard";
		break;
	}
	default: result = "undefine";
		break;
	}
	return result;
}

template<class T>
class BattleShip {
private:
	double speed;
	int weaponsNumber;
	bool huperJump;
	int size;
	T pilot;
	double fuel;
	Equipment equipment;
	double strenghtCorps;

public:
	//Constructors
	BattleShip();

	BattleShip(double _speed, int _weaponsNumber, bool _huperJump, int _size, T& _pilot, double _fuel, const Equipment& _eq, double _strenghtCorps);

	BattleShip(const BattleShip<T>& entity);

	//Operators
	BattleShip& operator=(const BattleShip<T>& entity);
	bool operator==(const BattleShip<T>& entity) const;
	bool operator!=(const BattleShip<T>& entity) const;

	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const BattleShip<T>& entity);
	template<typename T>
	friend std::istream& operator>>(std::istream& in, BattleShip<T>& entity);

	//Functions..
	void copy(const BattleShip<T>&);	
	void refillFuel();
	void changeStrenghtCorps();
	bool isNeededStrenghtCorps();

	//Getters...
	double get_speed() const {
		return this->speed;
	}
	int get_weaponsNumber() const {
		return this->weaponsNumber;
	}
	bool get_huperJump() const {
		return this->huperJump;
	}
	int get_size() const {
		return this->size;
	}
	T& get_pilot() const {
		return this->pilot;
	}
	double get_fuel() const {
		return this->fuel;
	}
	Equipment& get_equipment() const {
		return this->equipment;
	}
	double get_strenghtCorps() const {
		return this->strenghtCorps;
	}


	//Setters....
	void set_speed(const double _speed) {
		if (_speed < 0)
		{
			this->speed = 0;
		}
		else {
			this->speed = _speed;
		}
	}
	void set_weaponsNumber(const int _weaponsNum) {
		this->weaponsNumber = _weaponsNum;
	}
	void set_huperJump(const bool _huperJump) {
		this->huperJump = _huperJump;
	}
	void set_size(const int _size) {
		this->size = _size;
	}
	void set_pilot(T& _pilot) {
		this->pilot = _pilot;
	}
	void set_fuel(double _fuel) {
		assert(_fuel < 10000);
		this->fuel = _fuel;
	}
	void set_equipment(const Equipment& _eq) {
		this->equipment = _eq;
	}
	void set_strenghtCorps(double _strenghtCorps) {
		this->strenghtCorps = _strenghtCorps;
	}
};

///Functions...
template<typename T>
void BattleShip<T>::refillFuel() {
	if (this.get_fuel() + (100) > 1000)
	{
		std::cout << "Too much fuel! Cannot make this change!" << std::endl;
		return;
	}
	set_fuel(get_fuel() + 100);
}

template<typename T>
void BattleShip<T>::changeStrenghtCorps() {
	set_strenghtCorps(get_strenghtCorps() + 40);

	if (get_speed() - 10 < 0)
	{
		std::cout << "Negative speed! We cannot make this change!\n";
		return;
	}
	set_speed(get_speed() - 20);
}

template<typename T>
bool BattleShip<T>::isNeededStrenghtCorps() {
	return get_strenghtCorps() > 60;
}

//Hepler Func...
template<class T>
void BattleShip<T>::copy(const BattleShip<T>& entity) {
	this->speed = entity.get_speed();
	this->weaponsNumber = entity.get_weaponsNumber();
	this->huperJump = entity.get_huperJump();
	this->size = entity.get_size();

	this->pilot = entity.pilot;

	this->fuel = entity.fuel;
	this->equipment = entity.equipment;
	this->strenghtCorps = entity.strenghtCorps;
}

//Constructors:
template<class T>
BattleShip<T>::BattleShip()
{
	this->speed = 0.0;
	this->weaponsNumber = 0;
	this->huperJump = false;
	this->size = 0;
	this->fuel = 20;
	this->equipment = Equipment::easy;
	this->pilot = T();
}

template<class T>
BattleShip<T>::BattleShip(double _speed, int _weaponsNumber, bool _huperJump, int _size, T& _pilot, double _fuel, const Equipment& _eq, double _strenghtCorps)
{
	this->speed = _speed;
	this->weaponsNumber = _weaponsNumber;
	this->huperJump = _huperJump;
	this->size = _size;

	this->pilot = T(_pilot);

	this->fuel = _fuel;
	this->equipment = _eq;
	this->strenghtCorps = _strenghtCorps;

}

template<class T>
BattleShip<T>::BattleShip(const BattleShip<T>& entity)
{
	copy(entity);
}

//Operators...
template<class T>
BattleShip<T>& BattleShip<T>::operator=(const BattleShip<T>& entity) {

	if (this != &entity) {

		//clear();
		copy(entity);
	}

	return *this;
}

template<class T>
bool BattleShip<T>::operator==(const BattleShip<T>& entity) const {
	return (this->speed == entity.get_speed())
		&& (this->weaponsNumber == entity.get_weaponsNumber())
		&& (this->huperJump == entity.get_huperJump())
		&& (this->size == entity.get_size())
		&& (this->pilot == entity.get_pilot())
		&& (this->fuel == entity.fuel)
		&& (this->equipment == entity.equipment)
		&& (this->strenghtCorps == entity.strenghtCorps);
}

template<class T>
bool BattleShip<T>::operator!=(const BattleShip<T>& entity) const {
	return !(*this == entity);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const BattleShip<T>& entity) {

	out << entity.get_speed() << std::endl;
	out << entity.get_weaponsNumber()<< std::endl;
	out << entity.get_huperJump() << std::endl;
	out << entity.get_size() << std::endl;

	out << entity.pilot;
	out << std::endl;

	out << entity.fuel << std::endl;
	out << EnumToString(entity.equipment) << std::endl;
	out << entity.strenghtCorps << std::endl;

	return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, BattleShip<T>& entity) {

	double _speed = 0;
	int _weaponsNumber = 0;
	bool _huperJump = 0;
	int _size = 0;
	double _fuel = 0;
	//Equipment _eq;
	double _strengthCorps = 0;

	//std::cout << "Reading from the file" << std::endl;

	in >> _speed;
	entity.set_speed(_speed);

	in >> _weaponsNumber;
	entity.set_weaponsNumber(_weaponsNumber);

	in >> _huperJump;
	entity.set_huperJump(_huperJump);

	in >> _size;
	entity.set_size(_size);
	in.ignore();

	T _pilot = T();
	in >> _pilot;
	entity.set_pilot(_pilot);

	std::cout << std::endl;
	in >> _fuel;
	entity.set_fuel(_fuel);

	String _eq;
	in >> _eq;
	entity.set_equipment(stringToEnum(_eq));

	in >> _strengthCorps;
	entity.set_strenghtCorps(_strengthCorps);

	return in;
}


