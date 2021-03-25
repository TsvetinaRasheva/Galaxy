#pragma once
#include "Planet.h"

enum StormtrooperRank {
	JuniorElisted,
	Elisted,
	Corporal,
	Sergeant,
	Officer,
	Commander,
	Undefine
};


class Stormtrooper {
private:
	char* id;
	StormtrooperRank rank;
	char* type;
	Planet planet;

public:

	//Constructors...
	Stormtrooper();

	Stormtrooper(const char* _id, const StormtrooperRank _rank, const char* _type, const Planet& _planet);

	Stormtrooper(const Stormtrooper& entity);

	~Stormtrooper();


	//Operators
	Stormtrooper& operator=(const Stormtrooper& entity);

	bool operator==(const Stormtrooper& entity) const;

	bool operator!=(const Stormtrooper& entity) const;

	friend std::ostream& operator<<(std::ostream& out, const Stormtrooper& entity);

	friend std::istream& operator>>(std::istream& in, Stormtrooper& entity);


	//Getters...
	char* get_id() const
	{
		return this->id;
	}
	StormtrooperRank get_rank() const
	{
		return this->rank;
	}
	char* get_type() const
	{
		return this->type;
	}
	const Planet& get_planet() const
	{
		return this->planet;
	}

	//Setters...
	void set_id(const char* _id)
	{
		if (_id != nullptr)
		{
			delete[] this->id;
			int size = strlen(_id) + 1;
			this->id = new char[size];
			strcpy_s(this->id, size, _id);
		}
		else
		{
			this->id = nullptr;
		}
	}
	void set_rank(const StormtrooperRank _rank)
	{
		this->rank = _rank;
	}
	void set_type(const char* _type)
	{
		if (_type != nullptr)
		{
			delete[] this->type;
			int size = strlen(_type) + 1;
			this->type = new char[size];
			strcpy_s(this->type, size, _type);
		}
		else
		{
			this->type = nullptr;
		}
	}
	void set_planet(const Planet& _planet)
	{
		this->planet = _planet;
	}

	//Func
	void clear();
	//void copy(char* dest, char* source);
};