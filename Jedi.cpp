#include "Jedi.hpp"

JediRank JediRankType(char* input)
{
	toLower(input);

	std::string str(input);

	if (str == "youngling")
	{
		return JediRank::Youngling;
	}
	else if (str == "initiate")
	{
		return JediRank::Initiate;
	}
	else if (str == "padawan")
	{
		return JediRank::Padawan;
	}
	else if (str == "knightaspirant")
	{
		return JediRank::KnightAspirant;
	}
	else if (str == "knight")
	{
		return JediRank::Knight;
	}
	else if (str == "master")
	{
		return JediRank::Master;
	}
	else if (str == "grandmaster")
	{
		return JediRank::GrandMaster;
	}
	else
	{
		return JediRank::Unnone;
	}

}


Jedi::Jedi()
{
	this->name = nullptr;
	this->rank = JediRank::Unnone;
	this->midi_chlorian = 0.0;
	this->spicies = nullptr;
	this->militaryRank = nullptr;
}

Jedi::Jedi(const char* _name, const JediRank _rank, const float _midi, const Planet& _planet, const char* _spicies, const char* _militaryRank)
{
	int size = 0;

	size = strlen(_name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, _name);

	this->rank = _rank;

	this->midi_chlorian = _midi;

	this->planet = _planet;

	size = strlen(_spicies) + 1;
	this->spicies = new char[size];
	strcpy_s(this->spicies, size, _spicies);

	size = strlen(_militaryRank) + 1;
	this->militaryRank = new char[size];
	strcpy_s(this->militaryRank, size, _militaryRank);
}

Jedi::Jedi(const Jedi& entity)
{
	int size = 0;

	if (entity.get_name() != nullptr)
	{
		size = strlen(entity.name) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, entity.name);
	}
	else
	{
		this->name = nullptr;
	}

	this->rank = entity.rank;

	this->midi_chlorian = entity.midi_chlorian;

	this->planet = entity.planet;

	if (entity.get_spicies() != nullptr)
	{
		size = strlen(entity.spicies) + 1;
		this->spicies = new char[size];
		strcpy_s(this->spicies, size, entity.spicies);
	}
	else
	{
		this->spicies = nullptr;
	}

	if (entity.get_militaryRank() != nullptr)
	{
		size = strlen(entity.militaryRank) + 1;
		this->militaryRank = new char[size];
		strcpy_s(this->militaryRank, size, entity.militaryRank);
	}
	else
	{
		this->militaryRank = nullptr;
	}
	
}

Jedi& Jedi::operator=(const Jedi& entity)
{
	if (this != &entity)
	{
		delete[] name;
		//this->rank = RankOfJedi::Null;
		this->midi_chlorian = 0.0;
		planet.~Planet();
		delete[] spicies;
		delete[] militaryRank;

		*this = Jedi(entity);

	}

	return *this;
}

bool Jedi::operator==(const Jedi& entity) const
{
	return strcmp(this->get_name(), entity.get_name()) && this->get_rank() == entity.get_rank() && this->get_midi_chlorian() == entity.get_midi_chlorian() && this->get_planet() == entity.planet &&
		strcmp(this->get_spicies(), entity.get_spicies()) && strcmp(this->get_militaryRank(), entity.get_militaryRank());
}

bool Jedi::operator!=(const Jedi& entity) const
{
	return !(*this == entity);
}

std::ostream& operator<<(std::ostream& out, const Jedi entity)
{
	out << "Jedi" << std::endl;
	out << "Name: " << entity.get_name() << std::endl;
	out << "Rank: ";

	switch (entity.get_rank())
	{
	case Youngling: out << "Youngling" << std::endl;	break;
	case Initiate: out << "Initiate" << std::endl; break;
	case Padawan: out << "Padawan" << std::endl; break;
	case KnightAspirant: out << "Knight Aspirant" << std::endl; break;
	case Knight: out << "Knight" << std::endl; break;
	case Master: out << "Master" << std::endl; break;
	case BattleMaster: out << "Battle Master" << std::endl; break;
	case GrandMaster: out << "Grand Master" << std::endl; break;
	default: out << "Undefine!" << std::endl; break;
	}

	out << "Midi-chlorian: " << entity.get_midi_chlorian() << std::endl;
	out << "Planet: " << entity.planet.get_name() << std::endl;
	out << "Spicies: " << entity.get_spicies() << std::endl;
	out << "Military rank: " << entity.get_militaryRank() << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Jedi& entity)
{
	char* temp = new char[100];

	std::cout << "\nEnter: " << std::endl;
	std::cout << "Jedi name: ";
	in.getline(temp, 100);
	entity.set_name(temp);
	delete[] temp;
	temp = nullptr;

	
	std::cout << "Rank: ";
	temp = new char[100];
	in.getline(temp, 100);
	JediRank rank = JediRankType(temp);
	entity.set_rank(rank);
	delete[] temp;
	temp = nullptr;


	int temp_midi_chlorian = 0;
	std::cout << "Midi-chlorial: ";
	in >> temp_midi_chlorian;
	entity.set_midi_chlorian(temp_midi_chlorian);

	temp = new char[100];
	std::cout << "Planet name: ";
	in.ignore();
	in.getline(temp, 100);

	Planet _planet = Planet();
	_planet.set_name(temp);

	entity.set_planet(_planet);
	delete[] temp;
	temp = nullptr;


	temp = new char[100];
	std::cout << "Spicies: ";
	in.getline(temp, 100);
	entity.set_spicies(temp);
	delete[] temp;
	temp = nullptr;

	temp = new char[100];
	std::cout << "Military rank:: ";
	in.getline(temp, 100);
	entity.set_militaryRank(temp);
	delete[] temp;
	temp = nullptr;

	return in;

}

Jedi::~Jedi()
{
	delete[] name;
	name = nullptr;
	delete[] spicies;
	spicies = nullptr;
	delete[] militaryRank;
	militaryRank = nullptr;
}

