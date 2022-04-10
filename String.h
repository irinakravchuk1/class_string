#include <iostream>
#include <cstring>

class string
{
private:
    char* str;
	int size;

	void add_str(const char* str);

public:

    string(){};
    string(const char* str);
	string(const string& other);
    ~string();
	

    void operator = (char* str);
    void operator = (string& other);
    void operator << (const string& other);

    char& operator [] (const int& i);

    string operator + (const string& other);
    string& operator += (const string& other);

    bool operator == (const string& other);
    bool operator != (const string& other);

    friend std::ostream& operator<< (std::ostream& out, const string& other)
	{
		out << other.str;
		return out;
	}

    friend std::istream& operator >>(std::istream& in, string& other)
	{
		in >> other.str;
		return in;
	}

    int length();
    void clear();
    bool empty();

};