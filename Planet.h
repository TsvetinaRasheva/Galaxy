#pragma once
#include <iostream>
#include <cstring>
#include <ostream>
#include <istream>
#include <fstream>


//Enum
enum TypePlanet {
	Invalid,
	Chthonian,
	Carbon,
	Coreless,
	Desert,
	GasDwarf,
	GasGiant,
	Helium,
	IceGiant,
	Ice,
	Iron,
	Lava,
	Ocean,
	Protoplanet,
	Puffy,
	Silicate,
	Terrestrial
};

//Class
class Planet {
private:
	char* name;
	TypePlanet type;
	char* planetSystem;
	char* republic;
public:

	//Constructors:
	Planet();

	Planet(const char* _name, const TypePlanet _type, const char* _planetSystem, const char* _republic);

	Planet(const Planet& entity);

	~Planet();

	//Operators
	Planet& operator=(const Planet& entity);

	bool operator==(const Planet& entity) const;

	bool operator!=(const Planet& entity) const;

	friend std::ostream& operator<<(std::ostream& out, const Planet& entity);

	friend std::istream& operator>>(std::istream& in, Planet& entity);


	//Getters...
	char* get_name() const
	{
		return this->name;
	}
	TypePlanet get_type() const
	{
		return this->type;
	}
	char* get_planetSystem() const
	{
		return this->planetSystem;
	}
	char* get_republic() const
	{
		return this->republic;
	}

	//Setters..
	void set_name(const char* _name)
	{
		if (_name != nullptr)
		{
			delete[] this->name;
			int size = strlen(_name) + 1;
			this->name = new char[size];
			strcpy_s(this->name, size, _name);
		}
		else
		{
			this->name = nullptr;
		}
	}
	void set_type(const TypePlanet _type)
	{
		this->type = _type;
	}
	void set_planetSystem(const char* _planetSystem)
	{
		if (_planetSystem != nullptr)
		{
			delete[] this->planetSystem;
			int size = strlen(_planetSystem) + 1;
			this->planetSystem = new char[size];
			strcpy_s(this->planetSystem, size, _planetSystem);
		}
		else
		{
			this->planetSystem = nullptr;
		}
	}
	void set_republic(const char* _republic)
	{
		if (_republic != nullptr)
		{
			delete[] this->republic;
			int size = strlen(_republic) + 1;
			this->republic = new char[size];
			strcpy_s(this->republic, size, _republic);
		}
		else
		{
			this->republic = nullptr;
		}
	}

	//Functions
	void clear();
	void copy(char* dest,const char* source);
};


//Template functions:
template<class ConvertToLower>
void toLower(ConvertToLower input)
{
	int index = 0;

	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ')
		{
			index--;
		}

		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			input[index] = input[i] + 'a' - 'A';
		}
		else if (input[i] >= 'a' && input[i] <= 'z')
		{
			input[index] = input[i];
		}
		index++;
	}
	input[index] = '\0';
}


template<class Input>
void setData(std::istream& in, Input& entity)
{
	in >> entity;
}


template<class Write>
void write(std::ostream& out, const Write& entity)
{
	out << entity;
}

