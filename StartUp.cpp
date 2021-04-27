#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include "../GalaxyProject/BattleShip.h"
#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"
#include <cstring>


template<typename T>
using fn = void(*) (T&);

template<typename T>
using func = bool(*) (const T&);


template<typename T>
void mapFunc(std::vector<T>& vectors, size_t size, fn<T> func) { //std::function<void(T&, size_t)> func) {
	for (size_t i = 0; i < size; i++)
	{
		func(vectors.at(i));
	}

}

template<typename T>
void refillFuel(BattleShip<T>& other) {
	//something like validation()
	if (other.get_fuel() + 50 > 1000)
	{
		std::cout << "Too much fuel! Cannot make this change!" << std::endl;
		return;
	}
	other.set_fuel(other.get_fuel() + 50);
}

template<typename T>
void changeStrenghtCorps(BattleShip<T>& other) {
	other.set_strenghtCorps(other.get_strenghtCorps() + 40);

	if (other.get_speed() - 10 < 0)
	{
		std::cout << "Negative speed! We cannot make this change!\n";
		return;
	}
	other.set_speed(other.get_speed() - 10);
}

template<typename T>
void filterFunc(std::vector<T>& vectors, func<T> func) { //std::function<void(T&, size_t)> func) {
	for (size_t i = 0; i < vectors.size(); i++)
	{
		if (!func(vectors.at(i)))
		{
			vectors.erase(vectors.begin() + i);
		}
	}
}

template<typename T>
bool isCorrectEntity(const BattleShip<T>& entity) {
	return entity.get_strenghtCorps() > 60;
}


//To Do .....
template<typename T>
struct Node {
	T data;
	Node* next;

	Node() {}

	Node(const T& _data, Node<T>* obj = nullptr)
	{
		this->data = _data;
		this->next = obj;
	}
};

template <typename T>
struct ActivityLog {
	Node<T>* head;

	ActivityLog() : head(nullptr) {}
	ActivityLog(const T& _data) {
		this->head = _data;
	}

	void pushBack(const T _data);
	void reverse();
	void printLog();	
	void remove();
	//recursionReverse()

	//Addition methods..
	void pushFront(const T _data);
	void popFront();
	void popBack();
	Node<T>*& find(T& data);
};

template<typename T>
void ActivityLog<T>::pushFront(const T _data) {
	Node<T>* newNode = new Node<T>(_data);
	newNode->next = head;
	head = newNode;
}

template<typename T>
void ActivityLog<T>::pushBack(const T _data) {
	Node<T>* newNode = new Node<T>(_data, nullptr);
	Node<T>* curr = head;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	while (curr->next) {
		curr = curr->next;
	}
	curr->next = newNode;
}

template<typename T>
void ActivityLog<T>::popFront() {
	Node<T>* curr = head;
	head = head->next;
	head->next = head->next;
	delete curr;
	curr = nullptr;
}

template<typename T>
void ActivityLog<T>::popBack() {
	Node<T>* curr = head;
	while (curr->next->next) {
		curr = curr->next;
	}
	delete curr->next;
	curr->next = nullptr;
}

template<typename T>
void ActivityLog<T>::reverse() {
	Node<T>* previous = nullptr;
	Node<T>* next = nullptr;
	Node<T>* curr = head;

	while (curr) {
		next = curr->next;
		curr->next = previous;
		previous = curr;
		curr = next;
	}

	head = previous;
}

template<typename T>
void ActivityLog<T>::printLog()
{
	struct Node<T>* curr = head;

	while (curr) {
		std::cout << curr->data << " ";
		curr = curr->next;
	}
}

template<typename T>
void ActivityLog<T>::remove() {

	if (head->data == "activity:changeStrenghtCorps")
	{
		if (head->next == nullptr)
		{
			std::cout << "Invalid operation!";
			return;
		}

		head->data = head->next->data;
		head->next = head->next->next;
		return;
	}

	Node<T>* prev = head;

	while (prev->next) {
		if (prev->next->data == "activity:changeStrenghtCorps")
		{
			prev->next = prev->next->next;
			continue;
		}
		prev = prev->next;
	}
		
	return;
}

template<typename T>
Node<T>*& ActivityLog<T>::find(T& data) {
	Node<T>* curr = head;
	while (curr) {
		if (curr->data == data) {
			return curr;
		}
		curr = curr->next;
	}
	std::cout << "Invalid!";
	return head;
}



int main()
{

	/*
	 BattleShip<Stormtrooper> bs1 = BattleShip<Stormtrooper>();
	 BattleShip<Stormtrooper> bs2 = BattleShip<Stormtrooper>();
	 BattleShip<Stormtrooper> bs3 = BattleShip<Stormtrooper>();

	 setData(std::cin, bs1);
	 setData(std::cin, bs2);
	 setData(std::cin, bs3);


	 std::vector<BattleShip<Stormtrooper>> battleShips;

	 battleShips.push_back(bs1);
	 battleShips.push_back(bs2);
	 battleShips.push_back(bs3);

	 //Refill fuel...
	 std::cout << "\nBefore map: \n";
	 for (size_t i = 0; i < battleShips.size(); i++)
	 {
		 std::cout << battleShips.at(i).get_fuel() << " ";
	 }

	 mapFunc(battleShips, battleShips.size(), refillFuel);

	 std::cout << "\nAfter map: \n";
	 for (size_t i = 0; i < battleShips.size(); i++)
	 {
		 std::cout << battleShips.at(i).get_fuel() << " ";
	 }


	 //Change strenghts..
	 std::cout << "\nBefore map: \n";
	 for (size_t i = 0; i < battleShips.size(); i++)
	 {
		 std::cout << battleShips.at(i).get_strenghtCorps() << " ";
	 }

	 mapFunc(battleShips, battleShips.size(), changeStrenghtCorps);

	 std::cout << "\nAfter map: \n";
	 for (size_t i = 0; i < battleShips.size(); i++)
	 {
		 std::cout << battleShips.at(i).get_strenghtCorps() << " ";
	 }

	 //Remove
	 std::cout << "\nBefore filter: \n";
	 for (size_t i = 0; i < battleShips.size(); i++)
	 {
		 std::cout << battleShips.at(i).get_strenghtCorps() << " ";
	 }

	 filterFunc(battleShips, isCorrectEntity);

	 std::cout << "\nAfter filter: \n";
	 for (size_t i = 0; i < battleShips.size(); i++)
	 {
		 std::cout << battleShips.at(i).get_strenghtCorps() << " ";
	 }
	 */

   ActivityLog<std::string> entity;
   entity.pushBack("activity:filterFunc");
   entity.pushBack("activity:filterFunc");
   entity.pushBack("activity:changeStrenghtCorps");
   entity.pushBack("activity:changeStrenghtCorps");
   entity.pushBack("asctivity:mapFunc");

   entity.pushFront("asctivity:mapFunc");

   entity.printLog();

   std::cout << std::endl;

   entity.popFront();

   entity.printLog();

   std::cout << std::endl;

   entity.popBack();

   entity.printLog();

   std::cout << std::endl;

   entity.remove();

   entity.pushFront("asctivity:mapFunc");

   entity.reverse();

   entity.printLog();

   entity.pushBack("activity:changeStrenghtCorps");

   std::string str = "asctivity:mapFunc";
   std::cout << std::endl;
   std::cout << entity.find(str)->next->data << std::endl;

	return 0;
}

