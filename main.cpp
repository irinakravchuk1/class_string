#include "String.h"

int main()
{
	string s1("test");
	string s6 = "loshok";
	std::cout << s6;
	string s2(s1);
	//s1 += s2;
	//std::cout << s1 << std::endl;
	//s1 = s2;
	//std::cout << s1;
	//std::cout << s2[1]<<std::endl;
	//string s3= s1 + s2;
	//std::cout << s3<<std::endl;
	std::cout << (s1 == s2)<<' '<<(s1!=s2)<<std::endl;
	const char* chr = "fgb";
	string s3 = chr;
	string s4 = s1 + s2+s3;
	std::cout << s4 << std::endl;
	string s5(s1 + s2);
	std::cout << s5 << std :: endl;
}
