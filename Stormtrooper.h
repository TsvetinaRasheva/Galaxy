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

	//Func
	void clear();
	void copy(const Stormtrooper&);
	void copyId(const char* source);
	void copyType(const char* source);

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
	StormtrooperRank get_rank() const {
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
		copyId(_id);
	}
	void set_rank(const StormtrooperRank _rank)
	{
		this->rank = _rank;
	}
	void set_type(const char* _type)
	{
		copyType(_type);
	}
	void set_planet(const Planet& _planet)
	{
		this->planet = _planet;
	}


};