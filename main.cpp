#include"string.h"
#include<string>
using namespace bit;
size_t string::npos = -1;
void test_string0() {
	string s1("12345");
	s1.push_back('6');
	s1.push_back('6');
	s1.push_back('6');
	s1.push_back('6');
	s1.push_back('6');
	for (auto ch : s1) {
		std::cout << ch;
	}
}
void test_string1() {
	string s1("12345");
	s1.append("56789");
	std::cout << s1;
}
void test_string2() {
	string s1("1234");
	string s2("5678");
	s1.swap(s2);
	std::cout << s1;
	std::cout << s2;
}
void test_string3() {
	string s1("1234");
	s1.resize(10, '9');
	std::cout << s1;
	s1.resize(3);
	std::cout << s1;
}
void test_string4() {
	string s1("123456");
	string::iterator e1=s1.begin();
	*e1 = '3';
	std::cout << s1;
}
void test_string5() {
	string s1("1234567");
	int t = s1.find('8', 0);
	std::cout << t;
}
void test_string6() {
	string s1("12345678");
	char s2[] = "4567";
	std::cout << s1.find(s2, 0);
}
void test_string7() {
	string s1("123456");
	s1.insert(3, '3');
	s1.insert(0, '0');
	std::cout << s1;
}
void test_string8() {
	string s1("123456");
	s1.insert(3, "abcd");
	std::cout << s1;
	s1.erase(2, 2);
	std::cout << s1;
}
int main() {
	/*std::string s1("1234");
	s1.resize(17);*/
	test_string8();
	return 0;
}