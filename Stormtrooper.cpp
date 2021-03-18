#include "Stormtrooper.hpp"

StormtrooperRank stormtrooperRankType(char* input)
{
	toLower(input);

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

Stormtrooper::Stormtrooper()
{
	this->id = nullptr;
	this->rank = StormtrooperRank::Undefine;
	this->type = nullptr;
}

Stormtrooper::Stormtrooper(const char* _id, const StormtrooperRank _rank, const char* _type, const Planet& _planet)
{
	this->id = new char[strlen(_id) + 1];
	strcpy_s(this->id, (strlen(_id) + 1), _id);

	this->rank = _rank;

	this->type = new char[strlen(_type) + 1];
	strcpy_s(this->type, (strlen(_type) + 1), _type);

	this->planet = _planet;

}

Stormtrooper::Stormtrooper(const Stormtrooper& entity)
{
	int size = 0;

	size = strlen(entity.id) + 1;
	this->id = new char[size];
	strcpy_s(this->id, size, entity.id);
	size = 0;

	this->rank = entity.rank;

	size = strlen(entity.type) + 1;
	this->type = new char[size];
	strcpy_s(this->type, size, entity.type);
	size = 0;


	this->planet = entity.planet;

}

Stormtrooper& Stormtrooper::operator=(const Stormtrooper& entity)
{
	if (this != &entity)
	{
		delete[] id;
		this->rank = StormtrooperRank::Undefine;
		delete[] type;
		planet.~Planet();

		if (entity.get_id() != nullptr)
		{
			this->id = new char[strlen(entity.id) + 1];
			strcpy_s(this->id, (strlen(entity.id) + 1), entity.id);
		}
		else
		{
			this->id = nullptr;
		}

		this->rank = entity.rank;

		if (entity.get_type() != nullptr)
		{
			this->type = new char[strlen(entity.type) + 1];
			strcpy_s(this->type, (strlen(entity.type) + 1), entity.type);
		}
		else
		{
			this->type = nullptr;
		}
		

		this->planet = entity.planet;

	}

	return *this;
}

bool Stormtrooper::operator==(const Stormtrooper& entity) const
{
	return strcmp(this->get_id(), entity.get_id()) && this->get_rank() == entity.get_rank() && strcmp(this->get_type(), entity.get_type()) && this->planet == entity.planet;
}

bool Stormtrooper::operator!=(const Stormtrooper& entity) const
{
	return !(*this == entity);
}

std::ostream& operator<<(std::ostream& out, const Stormtrooper entity)
{
	out << "Stormtrooper" << std::endl;
	out << "Id: " << entity.get_id() << std::endl;
	out << "Rank: ";

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

	out << "Type: " << entity.get_type() << std::endl;
	out << "Planet: " << entity.planet.get_name() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Stormtrooper& entity)
{
	char* temp = new char[100];

	std::cout << "Enter data: " << std::endl;
	std::cout << "Id: ";
	in.getline(temp, 100);
	entity.set_id(temp);
	delete[] temp;
	temp = nullptr;

	///to do...
	std::cout << "Rank: ";
	temp = new char[100];
	in.getline(temp, 100);
	StormtrooperRank rank = stormtrooperRankType(temp);
	entity.set_rank(rank);
	delete[] temp;
	temp = nullptr;


	temp = new char[100];
	std::cout << "Type: ";
	in.getline(temp, 100);
	entity.set_type(temp);
	delete[] temp;
	temp = nullptr;
	
	temp = new char[100];
	std::cout << "Planet name: ";
	in.getline(temp, 100);

	Planet _planet = Planet();
	_planet.set_name(temp);
	

	entity.set_planet(_planet);
	delete[] temp;
	temp = nullptr;

	return in;
}

Stormtrooper::~Stormtrooper()
{
	delete[] id;
	id = nullptr;
	delete[] type;
	type = nullptr;
}