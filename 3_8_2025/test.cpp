#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class MinStack {
public:
    stack<int> nor;
    stack<int> min;
    MinStack() {
        ;
    }

    void push(int val) {
        nor.push(val);
        if (min.empty()) {
            min.push(val);
        }
        else if (val <= min.top()) {
            min.push(val);
        }
    }

    void pop() {
        if (nor.top() == min.top()) {
            min.pop();
        }
        nor.pop();
    }

    int top() {
        return nor.top();
    }

    int getMin() {
        return min.top();
    }
};

//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param pushV int整型vector
//     * @param popV int整型vector
//     * @return bool布尔型
//     */
//    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
//        stack<int> in;
//        int cursor = 0;
//		for (int i = 0;i < pushV.size();i++) {
//            in.push(pushV[i]);
//            while (in.top() == popV[cursor]) {
//                in.pop();
//                ++cursor;
//            }
//        }
//        while (!in.empty()) {
//            if (in.top() == popV[cursor]) {
//                ++cursor;
//            }
//            in.pop();
//        }
//        if (cursor == popV.size()) {
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expression;
        for (int i = 0;i < tokens.size();i++) {
            if (tokens[i] == "+") {
                int right = expression.top();
                expression.pop();
                int left = expression.top();
                expression.pop();
                int result = left + right;
                expression.push(result);
            }
            else if (tokens[i] == "-") {
                int right = expression.top();
                expression.pop();
                int left = expression.top();
                expression.pop();
                int result = left - right;
                expression.push(result);
            }
            else if (tokens[i] == "*") {
                int right = expression.top();
                expression.pop();
                int left = expression.top();
                expression.pop();
                int result = left * right;
                expression.push(result);
            }
            else if (tokens[i] == "/") {
                int right = expression.top();
                expression.pop();
				int left = expression.top();
				expression.pop();
                int result = left / right;
                expression.push(result);
            }
            else {
                expression.push(stoi(tokens[i]));
            }
        }
        return expression.top();
    }
};
int main() {
    /*MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout<<obj->getMin();
    obj->pop();
    cout<<obj->top();
    cout << obj->getMin();*/
    Solution test;
    vector<int> a1({ 2,1,0 });
    vector<int> a2({ 1,2,0 });
    test.IsPopOrder(a1, a2);
    return 0;
}
