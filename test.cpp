#include<iostream>
#include<string>
#include<cctype>
using namespace std;
//string addStrings(string num1, string num2) {
//    string result;
//    if (num2.size() > num1.size()) {
//        num1.swap(num2);
//    }
//    string::reverse_iterator it1 = num1.rbegin();
//    string::reverse_iterator it2 = num2.rbegin();
//    char carrier = '0';
//    while (it1 != num1.rend()) {
//        if (it2 == num2.rend()) {
//            if (carrier == '1') {
//                char tmp = *it1 + carrier - 48;
//                if (tmp > 57) {
//                    carrier = '1';
//                    tmp -= 10;
//                }
//                else {
//                    carrier = '0';
//                }
//                result.push_back(tmp);
//            }
//            else {
//                result.push_back(*it1);
//            }
//        }
//        else {
//            char tmp = *it1 + *it2  + carrier - 96;
//            if (tmp > 57) {
//                carrier = '1';
//                tmp -= 10;
//            }
//            else {
//                carrier = '0';
//            }
//            result.push_back(tmp);
//        }
//        if (it2 != num2.rend()) {
//            it1++, it2++;
//        }
//        else {
//            it1++;
//        }
//    }
//    if (carrier == '1') {
//        result.push_back('1');
//    }
//    string tmp;
//    string::reverse_iterator r = result.rbegin();
//    while (r != result.rend()) {
//        tmp.push_back(*r);
//        r++;
//    }
//    return tmp;
//}
//int main() {
//    string n1 = "9";
//    string n2 = "99";
//    cout<<addStrings(n1,n2);
//    return 0;
//}

//int main()
//{
//    std::string str("This is an example sentence.");
//    std::cout << str << '\n';
//    // "This is an example sentence."
//    str.erase(10, 8);                        //            ^^^^^^^^
//    std::cout << str.size() << '\n';
//    // "This is an sentence."
//    str.erase(str.begin() + 9);               //           ^
//    std::cout << str.size() << '\n';
//    // "This is a sentence."
//    str.erase(str.begin() + 5, str.end() - 9);  //       ^^^^^
//    std::cout << str.size() << '\n';
//    // "This sentence."
//    return 0;
//}

//int firstUniqChar(string s) {
//    string tmp(s);
//    string::iterator cmp = tmp.begin();
//    while (cmp != tmp.end()) {
//        string::iterator it = cmp + 1;
//        int cnt = 0;
//        while (it != tmp.end()) {
//            if (*cmp == *it) {
//                cnt++;
//                tmp.erase(it);
//            }
//            else {
//                it++;
//            }
//        }
//        if (cnt > 0) {
//            tmp.erase(cmp);
//        }
//        else {
//            return s.find(*cmp);
//        }
//    }
//    return -1;
//}

//int main() {
//    string s = "dddccdbba";
//    cout<<firstUniqChar(s);
//    return 0;
//}

bool isPalindrome(string s) {
	string::iterator it = s.begin();
	while (it != s.end()) {
		if ((*it > 47 && *it < 58) || (*it > 64 && *it < 91) || (*it > 96 && *it < 123)) {
			*it=tolower(*it);
			it++;
		}
		else {
			s.erase(it);
		}
	}
	int front=0;
	int back = s.size()-1;
	while (front < back) {
		if (s[front] == s[back]) {
			front++, back--;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	string s = "A man, a plan, a canal: Panama";
	cout<<isPalindrome(s);
	return 0;
}