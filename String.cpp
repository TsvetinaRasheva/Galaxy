#pragma once
#include"String.h"


void String::clear() {
	delete[] buffer;
	buffer = nullptr;
	size = 0;
}

String::String() {
	buffer = nullptr;
	size = 0;
}

String::String(const String& other) {
	copy(other);
}

String::String(const char* _string) {
 	size_t temp_size = strlen(_string);

	this->buffer = new char[temp_size + 1];

	for (size_t i = 0; i < temp_size; i++)
	{
		buffer[i] = _string[i];
	}
	buffer[temp_size] = '\0';
	this->size = temp_size;
}

String::~String() {
	clear();
}


String& String::operator=(const String& other) {
	if (this != &other)
	{
		clear();
		copy(other);
	}

	return *this;
}

String& String::operator+(const String& other) {

	size_t temp_size = size;
	this->resize(size + other.size);

	for (size_t i = temp_size, p = 0; i < size; i++, p++)
	{
		this->buffer[i] = other.buffer[p];
	}

	this->buffer[size] = '\0';

	return *this;
}

bool String::operator==(const String& other) {
	return !strcmp(buffer, other.buffer) && size == other.size;
}

bool String::operator!=(const String& other) {
	return !(*this == other);
}

char String::operator[](size_t index) {
	if (index < size)
	{
		return buffer[index];
	}

	std::cout << "Error: [Out of range exception]";
	return '\0';
}

const char String::operator[](size_t index) const {
	if (index < size)
	{
		return buffer[index];
	}

	std::cout << "Error: [Out of range exception]";
	return '\0';
}

void String::resize(size_t new_size) {
	if (!c_str()) {
		buffer = new char[new_size + 1];
		size = new_size;
		return;
	}

	if (new_size < size)
	{
		std::cout << "Invalid operation!";
		return;
	}

	char* temp_buffer = new char[new_size + 1];

	for (size_t i = 0; i < size; i++)
	{
		temp_buffer[i] = buffer[i];
	}

	delete[] buffer;
	buffer = temp_buffer;

	buffer[new_size] = '\0';

	size = new_size;
}

void String::reverse() {
	char* temp = new char[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = this->buffer[size - 1 - i];
	}

	temp[size] = '\0';

	delete[] buffer;
	buffer = temp;
}

bool String::empty() {
	return size == 0;
}

char* String::getSubstring(size_t startIndex, size_t count)
{
	char* result = new char[count + 1];
	int index = 0;

	for (size_t i = startIndex; i < (startIndex + count); i++)
	{
		result[index++] = buffer[i];
	}
	result[index] = '\0';

	return result;
}

void String::push_back(const char elem) {
	char* newBuff = new char[size + 2];

	for (size_t i = 0; i < size; i++)
	{
		newBuff[i] = buffer[i];
	}

	newBuff[size] = elem;
	newBuff[size + 1] = '\0';
	size += 1;

	delete[] buffer;
	buffer = newBuff;
}

void String::copy(const String& new_string) {
	this->size = new_string.get_size();

	this->buffer = new char[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		this->buffer[i] = new_string.buffer[i];
	}

	this->buffer[size] = '\0';
}

void String::toLowerCase() {
	size_t index = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (this->buffer[i] >= 'A' && this->buffer[i] <= 'Z')
		{
			this->buffer[index] = this->buffer[i] + 'a' - 'A';
		}
		else if (this->buffer[i] >= 'a' && this->buffer[i] <= 'z')
		{
			this->buffer[index] = this->buffer[i];
		}
		index++;
	}
	this->buffer[index] = '\0';
}

void String::toUpperCase() {
	size_t index = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (this->buffer[i] >= 'A' && this->buffer[i] <= 'Z')
		{
			this->buffer[index] = this->buffer[i];
		}
		else if (this->buffer[i] >= 'a' && this->buffer[i] <= 'z')
		{
			this->buffer[index] = this->buffer[i] + 'A' - 'a';
		}
		index++;
	}
	this->buffer[index] = '\0';
}

void String::trimSpaces() {
	size_t i = 0, index = 0;
	while (buffer[i])
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			buffer[index++] = buffer[i];
		i++;
	}
	buffer[index] = '\0';
	this->size = index;

}

std::ostream& operator<<(std::ostream& out, const String& str) {

	out << str.c_str();
	return out;
}

std::istream& operator>>(std::istream& in, String& str) {
	str.clear();

	char c;
	do {
		c = in.get();
		if (c == '\n')
			break;
		str.push_back(c);
	} while (true);
	//str.push_back('\0');
	return in;
}