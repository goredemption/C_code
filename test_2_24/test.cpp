#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> ctn;
    string match(char num) {
        if (num == '2') {
            return "abc";
        }
        if (num == '3') {
            return "def";
        }
        if (num == '4') {
            return "ghi";
        }
        if (num == '5') {
            return "jkl";
        }
        if (num == '6') {
            return "mno";
        }
        if (num == '7') {
            return "pqrs";
        }
        if (num == '8') {
            return "tuv";
        }
        if (num == '9') {
            return "wxyz";
        }
        return "hello";
    }
    void combine(char num) {
        string tmp = match(num);
        vector<string> after;
        for (int i = 0;i < tmp.size();i++) {
            vector<string> before(ctn);
            vector<string>::iterator it = before.begin();
            while (it != before.end()) {
                (*it).push_back(tmp[i]);
                after.push_back(*it);
                it++;
            }
        }
        ctn.swap(after);
    }
    vector<string> letterCombinations(string digits) {
        for (int i = 0;i < digits.size();i++) {
            if (i == 0) {
                string tmp=match(digits[0]);
                for (int j = 0;j < tmp.size();j++) {
                    string instance;
                    instance.push_back(tmp[j]);
                    ctn.push_back(instance);
                }
            }
            else {
                combine(digits[i]);
            }
        }
        return ctn;
    }
};

int main() {
	//vector<int> v1;
	//v1.push_back(10);
	//v1.push_back(20);
	//v1.push_back(30);
	//v1.push_back(40);
	///*vector<int>::iterator it1 = v1.begin();
	//vector<int>::iterator it2 = v1.end();
	//it1 == it2;
	//cout << it1;*/
	//cout << v1.at(6);
	////cout << v1[6];

    string digits("23");
    Solution test;
    test.letterCombinations(digits);
	return 0;
}