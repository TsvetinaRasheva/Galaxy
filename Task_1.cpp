#include <iostream>
#include<cstring>

const int ARR_SIZE = 100;

enum Rank {
	Null,
	Youngling,
	Initiate,
	Padawan,
	KnightAspirant,
	Knight,
	Master,
	BattleMaster,
	GrandMaster
};

//Convert rank type
void toLower(char* input)
{
	int index = 0;

	for (size_t i = 0; input[i] != '\0'; i++)
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
//Get rank type
Rank rankType(char* input)
{
	toLower(input);

	std::string str(input);

	if (str == "youngling")
	{
		return Rank::Youngling;
	}
	else if (str == "initiate")
	{
		return Rank::Initiate;
	}
	else if (str == "padawan")
	{
		return Rank::Padawan;
	}
	else if (str == "knightaspirant")
	{
		return Rank::KnightAspirant;
	}
	else if (str == "knight")
	{
		return Rank::Knight;
	}
	else if (str == "master")
	{
		return Rank::Master;
	}
	else if (str == "grandmaster")
	{
		return Rank::GrandMaster;
	}
	else
	{
		return Rank::Null;
	}

}
void printRank(Rank rank)
{
	if (rank == Rank::Youngling)
	{
		std::cout << "Youngling";
	}
	else if (rank == Rank::Initiate)
	{
		std::cout << "Initiate";
	}
	else if (rank == Rank::Padawan)
	{
		std::cout << "Padawan";
	}
	else if (rank == Rank::KnightAspirant)
	{
		std::cout << "Knight Aspirant";
	}
	else if (rank == Rank::Knight)
	{
		std::cout << "Knight";
	}
	else if (rank == Rank::Master)
	{
		std::cout << "Master";
	}
	else if (rank == Rank::BattleMaster)
	{
		std::cout << "Battle Master";
	}
	else if (rank == Rank::GrandMaster)
	{
		std::cout << "Grand Master";
	}
	else
	{
		std::cout << "Undefine!";
	}

}


//Planet class
class Planet {
private:
	char* name;
	char* planetSystem;
	char* republic;
public:
	//Default constructor
	Planet();

	//Constructor with parameters
	Planet(char* _name, char* _planetSystem, char* _republic);

	//Copy-constructor
	Planet(const Planet& entity);

	//operator=-constructor
	Planet& operator=(const Planet& entity);

	//Destructor
	~Planet();

	//Getters...
	char* get_name()
	{
		return this->name;
	}
	char* get_planetSystem()
	{
		return this->planetSystem;
	}
	char* get_republic()
	{
		return this->republic;
	}

	//Setters..
	void set_name(char* _name)
	{
		int size = strlen(_name) + 1;
		strcpy_s(this->name, size, _name);
	}
	void set_planetSystem(char* _planetSystem)
	{
		int size = strlen(_planetSystem) + 1;
		strcpy_s(this->planetSystem, size, _planetSystem);
	}
	void set_republic(char* _republic)
	{
		int size = strlen(_republic) + 1;
		strcpy_s(this->republic, size, _republic);
	}


	void print()
	{
		std::cout << "The name of this planet is " << this->name << std::endl;
		std::cout << "It's planet system: " << this->planetSystem << std::endl;
		std::cout << "Owner republic: " << this->republic << std::endl;
	}

};

Planet::Planet()
{
	this->name = nullptr;
	this->planetSystem = nullptr;
	this->republic = nullptr;
}

Planet::Planet(char* _name, char* _planetSystem, char* _republic)
{
	int size = 0;

	size = strlen(_name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, _name);

	size = strlen(_planetSystem) + 1;
	this->planetSystem = new char[size];
	strcpy_s(this->planetSystem, size, _planetSystem);

	size = strlen(_republic) + 1;
	this->republic = new char[size];
	strcpy_s(this->republic, size, _republic);
}

Planet::Planet(const Planet& entity)
{
	int size = 0;

	size = strlen(entity.name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, entity.name);

	size = strlen(entity.planetSystem) + 1;
	this->planetSystem = new char[size];
	strcpy_s(this->planetSystem, size, entity.planetSystem);

	size = strlen(entity.republic) + 1;
	this->republic = new char[size];
	strcpy_s(this->republic, size, entity.republic);
}

Planet& Planet::operator=(const Planet& entity)
{
	if (this != &entity) {
		delete[] name;
		delete[] planetSystem;
		delete[] republic;

		this->name = new char[strlen(entity.name) + 1];
		strcpy_s(this->name, (strlen(entity.name) + 1), entity.name);

		this->planetSystem = new char[strlen(entity.planetSystem) + 1];
		strcpy_s(this->planetSystem, (strlen(entity.planetSystem) + 1), entity.planetSystem);

		this->republic = new char[strlen(entity.republic) + 1];
		strcpy_s(this->republic, (strlen(entity.republic) + 1), entity.republic);
	}
	return *this;
}

Planet::~Planet()
{
	delete[] name;
	delete[] planetSystem;
	delete[] republic;
}


//Stormtrooper class
class Stormtrooper {
private:
	char* id;
	Rank rank;
	char* type;
	Planet planet;

public:
	//Default constructor
	Stormtrooper();

	//Constructor with parameters
	Stormtrooper(char* _id, Rank _rank, char* _type, Planet _planet);

	//Copy-consructor
	Stormtrooper(const Stormtrooper& entity);

	//Operator=-constructor
	Stormtrooper& operator=(const Stormtrooper& entity);

	//Destructor
	~Stormtrooper();


	//Getters...
	char* get_id()
	{
		return this->id;
	}
	Rank get_rank()
	{
		return this->rank;
	}
	char* get_type()
	{
		return this->type;
	}
	Planet& get_planet()
	{
		return this->planet;
	}

	//Setters...
	void set_id(char* _id)
	{
		int size = strlen(_id) + 1;
		strcpy_s(this->id, size, _id);
	}
	void set_rank(Rank _rank)
	{
		this->rank = _rank;
	}
	void set_type(char* _type)
	{
		int size = strlen(_type) + 1;
		strcpy_s(this->type, size, _type);
	}
	void set_planet(Planet& _planet)
	{
		this->planet = _planet;
	}


	void print()
	{
		std::cout << "The ID of this Stormtrooper is " << this->id << std::endl;
		std::cout << "His rank: ";
		printRank(this->rank);
		std::cout << std::endl;
		std::cout << "His type: " << this->type << std::endl;
		std::cout << "His planet: " << this->planet.get_name() << std::endl;
	};
};

Stormtrooper::Stormtrooper()
{
	this->id = nullptr;
	this->rank = Rank::Null;
	this->type = nullptr;
	this->planet.set_name(nullptr);
	this->planet.set_planetSystem(nullptr);
	this->planet.set_republic(nullptr);
}

Stormtrooper::Stormtrooper(char* _id, Rank _rank, char* _type, Planet _planet)
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
		this->rank = Rank::Null;
		delete[] type;
		planet.~Planet();

		this->id = new char[strlen(entity.id) + 1];
		strcpy_s(this->id, (strlen(entity.id) + 1), entity.id);

		this->rank = entity.rank;

		this->type = new char[strlen(entity.type) + 1];
		strcpy_s(this->type, (strlen(entity.type) + 1), entity.type);

		this->planet = entity.planet;

	}

	return *this;
}

Stormtrooper::~Stormtrooper()
{
	delete[] id;
	delete[] type;
}


//Jedi class
class Jedi {
private:
	char* name;
	Rank rank;
	float midi_chlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;

public:
	//Default constructor
	Jedi();

	//Constructor with parameters
	Jedi(char* _name, Rank _rank, float _midi, Planet& _planet, char* _spicies, char* _militaryRank);

	//Copy-constructor
	Jedi(const Jedi& entity);

	//operator=-constructor
	Jedi& operator=(const Jedi& entity);

	//Destructor
	~Jedi();


	//Getters..
	char* get_name()
	{
		return this->name;
	}
	Rank get_rank()
	{
		return this->rank;
	}
	float get_midi_chlorian()
	{
		return this->midi_chlorian;
	}
	Planet get_planet()
	{
		return this->planet;
	}
	char* get_spicies()
	{
		return this->spicies;
	}
	char* get_militaryRank()
	{
		return this->militaryRank;
	}

	//Setters...
	void set_name(char* _name)
	{
		int size = strlen(_name) + 1;
		strcpy_s(this->name, size, _name);
	}
	void set_rank(Rank _rank)
	{
		this->rank = _rank;
	}
	void set_midi_chlorian(float _midi_chlorian)
	{
		this->midi_chlorian = _midi_chlorian;
	}
	void set_planet(Planet& _planet)
	{
		this->planet = _planet;
	}
	void set_spicies(char* _spicies)
	{
		int size = strlen(_spicies) + 1;
		strcpy_s(this->spicies, size, _spicies);
	}
	void set_militaryRank(char* _militaryRank)
	{
		int size = strlen(_militaryRank) + 1;
		strcpy_s(this->militaryRank, size, _militaryRank);
	}

	void print()
	{
		std::cout << "The name of this Jedi is " << this->name << ":" << std::endl;
		std::cout << "His rank: ";
		printRank(this->rank);
		std::cout << std::endl;
		std::cout << "His midi-chlorian: " << this->midi_chlorian << std::endl;
		std::cout << "His planet: " << this->planet.get_name() << std::endl;
		std::cout << "Spicies: " << this->spicies << std::endl;
		std::cout << "His military rank: " << this->militaryRank << std::endl;
	}
};

Jedi::Jedi()
{
	this->name = nullptr;
	this->rank = Rank::Null;
	this->midi_chlorian = 0.0;
	this->planet = Planet();
	this->spicies = nullptr;
	this->militaryRank = nullptr;
}

Jedi::Jedi(char* _name, Rank _rank, float _midi, Planet& _planet, char* _spicies, char* _militaryRank)
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

	size = strlen(entity.name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, entity.name);

	this->rank = entity.rank;

	this->midi_chlorian = entity.midi_chlorian;

	this->planet = entity.planet;

	size = strlen(entity.spicies) + 1;
	this->spicies = new char[size];
	strcpy_s(this->spicies, size, entity.spicies);


	size = strlen(entity.militaryRank) + 1;
	this->militaryRank = new char[size];
	strcpy_s(this->militaryRank, size, entity.militaryRank);
}

Jedi& Jedi::operator=(const Jedi& entity)
{
	if (this != &entity)
	{
		delete[] name;
		this->rank = Rank::Null;
		this->midi_chlorian = 0.0;
		planet.~Planet();
		delete[] spicies;
		delete[] militaryRank;

		*this = Jedi(entity);

	}

	return *this;
}

Jedi::~Jedi()
{
	delete[] name;
	delete[] spicies;
	delete[] militaryRank;
}


int main()
{
	char arr1[] = "Mars";
	char arr2[] = "Mlechen pyt";
	char arr3[] = "Bul";
	Planet p2 = Planet(arr1, arr2, arr3);
	p2.print();

	Planet p3 = Planet(p2);
	p3.print();


	char iD[] = "125456";
	char type_st[] = "Worker";
	char arr[ARR_SIZE] = "Master";
	//std::cin.getline(arr,ARR_SIZE);
	Rank rank = rankType(arr);

	Stormtrooper st2 = Stormtrooper(iD, rank, type_st, p2);
	st2.print();


	char name1[] = "Gosho";
	char sp[] = "Creature";
	char mili[] = "Warrior";

	Jedi jedi1 = Jedi(name1, Rank::GrandMaster, 15.23, p3, sp, mili);
	jedi1.print();

	std::cout << std::endl;

	char name2[] = "Pesho";
	char spi[] = "kkkk";
	Jedi jedi2 = Jedi(name2, Rank::Initiate, 5.23, p3, spi, mili);

	return 0;
}

