#pragma once
#include <typeinfo> 
#include <assert.h>
#include "Jedi.h"
#include "Stormtrooper.h"


template<class T>
class BattleShip {
private:
	double speed;
	int weaponsNumber;
	bool huperJump;
	int size;
	T pilot;

public:
	//Constructors
	BattleShip();

	BattleShip(const double _speed, const int _weaponsNumber, const bool _huperJump, const int _size, const T _pilot);

	BattleShip(const BattleShip& entity);

	~BattleShip();


	//Operators
	BattleShip& operator=(const BattleShip& entity);

	bool operator==(const BattleShip& entity) const;

	bool operator!=(const BattleShip& entity) const;

	friend std::ostream& operator<<(std::ostream& out, const BattleShip& entity);

	friend std::istream& operator>>(std::istream& in, BattleShip& entity);

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

	//Setters....
	void set_speed(const double _speed) {
		this->speed = _speed;
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
	void set_pilot(const T& _pilot) {
		assert(typeid(_pilot).name() == "Jedi" || typeid(_pilot).name() == "Stormtrooper");
		this->pilot = _pilot;
	}
};


