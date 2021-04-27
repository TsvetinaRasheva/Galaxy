#include "Planet.h" 
#include <iostream>


TypePlanet typePlanet(char* input)
{
	toLowerCase(input);

	std::string str(input);

	if (str == "chthonian")
	{
		return TypePlanet::Chthonian;
	}
	else if (str == "carbon")
	{
		return TypePlanet::Carbon;
	}
	else if (str == "coreless")
	{
		return TypePlanet::Coreless;
	}
	else if (str == "desert")
	{
		return TypePlanet::Desert;
	}
	else if (str == "gasdwarf")
	{
		return TypePlanet::GasDwarf;
	}
	else if (str == "gasgiant")
	{
		return TypePlanet::GasGiant;
	}
	else if (str == "helium")
	{
		return TypePlanet::Helium;
	}
	else if (str == "icegiant")
	{
		return TypePlanet::IceGiant;
	}
	else if (str == "ice")
	{
		return TypePlanet::Ice;
	}
	else if (str == "iron")
	{
		return TypePlanet::Iron;
	}
	else if (str == "lava")
	{
		return TypePlanet::Lava;
	}
	else if (str == "ocean")
	{
		return TypePlanet::Ocean;
	}
	else if (str == "protoplanet")
	{
		return TypePlanet::Protoplanet;
	}
	else if (str == "puffy")
	{
		return TypePlanet::Puffy;
	}
	else if (str == "silicate")
	{
		return TypePlanet::Silicate;
	}
	else if (str == "terrestrial")
	{
		return TypePlanet::Terrestrial;
	}
	else
	{
		return TypePlanet::Invalid;
	}

}

//Funcs
void Planet::clear()
{
	delete[] name;
	name = nullptr;
	delete[] planetSystem;
	planetSystem = nullptr;
	delete[] republic;
	republic = nullptr;
}
void Planet::copyName(const char* source) {
	if (source != nullptr)
	{
		delete[] this->name;
		size_t size = 0;
		size = strlen(source) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, source);
	}
	else
	{
		this->name = nullptr;
	}
}
void Planet::copyPalnetSystem(const char* source) {

	if (source != nullptr)
	{
		delete[] this->planetSystem;
		size_t size = 0;
		size = strlen(source) + 1;
		this->planetSystem = new char[size];
		strcpy_s(this->planetSystem, size, source);
	}
	else
	{
		this->planetSystem = nullptr;
	}
}
void Planet::copyRepublic(const char* source) {

	if (source != nullptr)
	{
		delete[] this->republic;
		size_t size = 0;
		size = strlen(source) + 1;
		this->republic = new char[size];
		strcpy_s(this->republic, size, source);
	}
	else
	{
		this->republic = nullptr;
	}
}

void Planet::copy(const Planet& entity) {
	copyName(entity.get_name());
	this->type = entity.get_type();
	copyPalnetSystem(entity.get_planetSystem());
	copyRepublic(entity.get_republic());
}

//Construtors
Planet::Planet()
{
	this->name = nullptr;
	this->type = TypePlanet::Invalid;
	this->planetSystem = nullptr;
	this->republic = nullptr;
}

Planet::Planet(const char* _name, TypePlanet _type, const char* _planetSystem, const char* _republic)
{
	copyName(_name);
	this->type = _type;
	copyPalnetSystem(_planetSystem);
	copyRepublic(_republic);
}

Planet::Planet(const Planet& entity)
{
	copy(entity);
}

Planet::~Planet()
{
	clear();
}


//Operators
Planet& Planet::operator=(const Planet& entity)
{
	if (this != &entity) {
		clear();

		copy(entity);

	}
	return *this;
}

bool Planet::operator==(const Planet& entity) const
{
	return !strcmp(this->get_name(), entity.get_name())
		&& this->type == entity.get_type()
		&& !strcmp(this->get_planetSystem(), entity.get_planetSystem())
		&& !strcmp(this->get_republic(), entity.get_republic());
}

bool Planet::operator!=(const Planet& entity) const
{
	return !(*this == entity);
}

std::ostream& operator<<(std::ostream& out, const Planet& entity)
{
	out << entity.get_name() << std::endl;

	switch (entity.get_type())
	{
	case Chthonian: out << "Chthonian" << std::endl;	break;
	case Carbon: out << "Carbon" << std::endl; break;
	case Coreless: out << "CorCorelessporal" << std::endl; break;
	case Desert: out << "Desert" << std::endl; break;
	case GasDwarf: out << "Gas Dwarf" << std::endl; break;
	case GasGiant: out << "Gas Giant" << std::endl; break;
	case Helium: out << "Helium" << std::endl; break;
	case IceGiant: out << "Ice Giant" << std::endl; break;
	case Ice: out << "Ice" << std::endl; break;
	case Iron: out << "Iron" << std::endl; break;
	case Lava: out << "Lava" << std::endl; break;
	case Ocean: out << "Ocean" << std::endl; break;
	case Protoplanet: out << "Protoplanet" << std::endl; break;
	case Puffy: out << "Puffy" << std::endl; break;
	case Silicate: out << "Silicate" << std::endl; break;
	case Terrestrial: out << "Terrestrial" << std::endl; break;
	default: out << "Undefine!" << std::endl; break;
	}

	out << entity.get_planetSystem() << std::endl;
	out << entity.get_republic() << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Planet& entity)
{
	char* temp = new char[100];

	std::cout << "Reading from the file" << std::endl;

	//std::cout << "Name" << std::endl;
	in.getline(temp, 100);
	entity.set_name(temp);
	delete[] temp;
	temp = nullptr;

	//std::cout << "Rank " << std::endl;
	temp = new char[100];
	in.getline(temp, 100);
	TypePlanet type = typePlanet(temp);
	entity.set_type(type);
	delete[] temp;
	temp = nullptr;

	temp = new char[100];
	//std::cout << "System" << std::endl;
	in.getline(temp, 100);
	entity.set_planetSystem(temp);
	delete[] temp;
	temp = nullptr;

	temp = new char[100];
	//std::cout << "Republic " << std::endl;
	in.getline(temp, 100);
	entity.set_republic(temp);
	delete[] temp;
	temp = nullptr;

	return in;
}



