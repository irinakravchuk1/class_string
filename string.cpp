#include "String.h"

void string::add_str(const char* str)
{
	this->size = strlen(str);
	this->str = new char[this->size + 1];
	for (int i = 0; i < this->size + 1; ++i)
		this->str[i] = str[i];
}


string::string(const char* str)
{
	add_str(str);
}

string::string(const string& other)
{
	this->size = other.size;
	this->str = other.str;
}

string::~string()
{
		delete[] this->str;
}


void string::operator = (char* str)
{
	add_str(str);
}

void string::operator = (string& other)
{
	this->str = other.str;
	this->size = other.size;
	other.str = nullptr;
}

void string::operator << (const string& other)
{
	for (int i = 0; i < other.size; ++i)
		std::cout << other.str[i];
}


char& string::operator [] (const int& i)
{
    return this->str[i];
}


string string::operator + (const string& other)
{
	string new_str;
	new_str.size = other.size + this->size;
	new_str.str = new char[new_str.size + 1];
	for (int i = 0; i < this->size; ++i)
		new_str.str[i] = this->str[i];
	for (int i = this->size; i < new_str.size + 1; ++i)
		new_str.str[i] = other.str[i - this->size];
	return new_str;
}

string& string::operator += (const string& other)
{
	string new_str;
	new_str.size = other.size + this->size;
	new_str.str = new char[new_str.size + 1];
	for (int i = 0; i < this->size; ++i)
		new_str.str[i] = this->str[i];
	for (int i = this->size; i < new_str.size + 1; ++i)
		new_str.str[i] = other.str[i - this->size];
	delete[] this->str;
	this->str = new_str.str;
	this->size = new_str.size;
	new_str.str = nullptr;
	return *this;
}


bool string::operator == (const string& other)
{
	if (this->size != other.size)
		return 0;
	for (int i = 0; i < this->size; ++i)
	{
		if (this->str[i] != other.str[i])
			return 0;
	}
	return 1;
}

bool string::operator != (const string& other)
{
	//return!(this->operator== other);
	if (this->size != other.size)
		return 1;
	for (int i = 0; i < this->size; ++i)
	{
		if (this->str[i] != other.str[i])
			return 1;
	}
	return 0;
}


int string::length()
{
	return this->size;
}

void string::clear()
{
	delete[] this->str;
}

bool string::empty()
{
    if (this->str == nullptr)
	{
		return true;
	}
	return false;
}