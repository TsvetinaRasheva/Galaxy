#pragma once
#include "Planet.h"

enum JediRank {
	Youngling,
	Initiate,
	Padawan,
	KnightAspirant,
	Knight,
	Master,
	BattleMaster,
	GrandMaster,
	Unnone
};

class Jedi {
private:
	char* name;
	JediRank rank;
	float midi_chlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;

	//Func
	void clear();
	void copyName(const char* source);
	void copySpicies(const char* source);
	void copyMilitaryRank(const char* source);
	void copy(const Jedi&);

public:
	
	//Constructors: 
	Jedi();
	
	Jedi(const char* _name, const JediRank _rank, const float _midi, const Planet& _planet, const char* _spicies, const char* _militaryRank);

	Jedi(const Jedi& entity);

	~Jedi();


	//Operators
	Jedi& operator=(const Jedi& entity);

	bool operator==(const Jedi& entity) const;

	bool operator!=(const Jedi& entity) const;

	friend std::ostream& operator<<(std::ostream& out, const Jedi& entity);

	friend std::istream& operator>>(std::istream& in, Jedi& entity);


	//Getters..
	char* get_name() const
	{
		return this->name;
	}
	JediRank get_rank() const {
		return this->rank;
	}
	float get_midi_chlorian() const
	{
		return this->midi_chlorian;
	}
	Planet get_planet() const
	{
		return this->planet;
	}
	char* get_spicies() const
	{
		return this->spicies;
	}
	char* get_militaryRank() const
	{
		return this->militaryRank;
	}

	//Setters...
	void set_name(const char* _name)
	{
		copyName(_name);
	}
	void set_rank(const JediRank _rank)
	{
		this->rank = _rank;
	}
	void set_midi_chlorian(const float _midi_chlorian)
	{
		this->midi_chlorian = _midi_chlorian;
	}
	void set_planet(const Planet& _planet)
	{
		this->planet = _planet;
	}
	void set_spicies(const char* _spicies)
	{
		copySpicies(_spicies);
	}
	void set_militaryRank(const char* _militaryRank)
	{
		copyMilitaryRank(_militaryRank);
	}

	

};
