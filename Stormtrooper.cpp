#include "Stormtrooper.h"
#include <cstring>

StormtrooperRank stormtrooperRankType(char* input)
{
	toLowerCase(input);

	std::string str(input);

	if (str == "juniorelisted")
	{
		return StormtrooperRank::JuniorElisted;
	}
	else if (str == "elisted")
	{
		return StormtrooperRank::Elisted;
	}
	else if (str == "corporal")
	{
		return StormtrooperRank::Corporal;
	}
	else if (str == "sergeant")
	{
		return StormtrooperRank::Sergeant;
	}
	else if (str == "officer")
	{
		return StormtrooperRank::Officer;
	}
	else if (str == "commander")
	{
		return StormtrooperRank::Commander;
	}
	else
	{
		return StormtrooperRank::Undefine;
	}
}

void Stormtrooper::copy(const Stormtrooper& entity) {
	copyId(entity.get_id());
	this->rank = entity.rank;
	copyType(entity.get_type());
	this->planet = entity.planet;
}

//Func
void Stormtrooper::clear()
{
	delete[] id;
	id = nullptr;
	delete[] type;
	type = nullptr;
}
void Stormtrooper::copyId(const char* source) {
	if (source != nullptr)
	{
		delete[] this->id;

		size_t size = strlen(source);
		this->id = new char[size+1];
		strcpy_s(this->id, size+1, source);
	}
	else
	{
		this->id = nullptr;
	}
}
void Stormtrooper::copyType(const char* source) {
	if (source != nullptr)
	{
		delete[] this->type;
		size_t size = strlen(source);
		this->type = new char[size+1];
		strcpy_s(this->type, size+1, source);
	}
	else
	{
		this->type = nullptr;
	}
}

//Constructors
Stormtrooper::Stormtrooper()
{
	this->id = nullptr;
	this->rank = StormtrooperRank::Undefine;
	this->type = nullptr;
}

Stormtrooper::Stormtrooper(const char* _id, const StormtrooperRank _rank, const char* _type, const Planet& _planet)
{
	copyId(_id);
	this->rank = _rank;
	copyType(_type);
	this->planet = _planet;

}

Stormtrooper::Stormtrooper(const Stormtrooper& entity)
{
	copy(entity);
}

Stormtrooper::~Stormtrooper()
{
	clear();
}


//Operators
Stormtrooper& Stormtrooper::operator=(const Stormtrooper& entity)
{
	if (this != &entity)
	{
		clear();
		this->rank = StormtrooperRank::Undefine;
		//planet.~Planet();

		copy(entity);
	}

	return *this;
}

bool Stormtrooper::operator==(const Stormtrooper& entity) const
{
	return !strcmp(this->get_id(), entity.get_id()) 
		&& this->get_rank() == entity.get_rank() 
		&& !strcmp(this->get_type(), entity.get_type()) 
		&& this->planet == entity.planet;
}

bool Stormtrooper::operator!=(const Stormtrooper& entity) const
{
	return !(*this == entity);
}

std::ostream& operator<<(std::ostream& out, const Stormtrooper& entity)
{
	out << entity.get_id() << std::endl;

	switch (entity.get_rank())
	{
	case JuniorElisted: out << "Junior elisted" << std::endl;	break;
	case Elisted: out << "Elisted" << std::endl; break;
	case Corporal: out << "Corporal" << std::endl; break;
	case Sergeant: out << "Sergeant" << std::endl; break;
	case Officer: out << "Officer" << std::endl; break;
	case Commander: out << "Commander" << std::endl; break;
	default: out << "Undefine!" << std::endl; break;
	}

	out << entity.get_type() << std::endl;
	out << entity.planet;
	out << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Stormtrooper& entity)
{
	char* temp = new char[100];


	//std::cout << "Id: ";
	in.getline(temp, 100);
	entity.set_id(temp);
	delete[] temp;
	temp = nullptr;


	//std::cout << "Rank: ";
	temp = new char[100];
	in.getline(temp, 100);
	StormtrooperRank rank = stormtrooperRankType(temp);
	entity.set_rank(rank);
	delete[] temp;
	temp = nullptr;


	temp = new char[100];
	//std::cout << "Type: ";
	in.getline(temp, 100);
	entity.set_type(temp);
	delete[] temp;
	temp = nullptr;
	

	//std::cout << "Planet: ";
	Planet _planet = Planet();
	in >> _planet;
	entity.set_planet(_planet);
	delete[] temp;
	temp = nullptr;

	return in;
}


