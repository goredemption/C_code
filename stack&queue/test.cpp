#include"queue.h"
#include"stack.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace bit;
using namespace std;
void test_stack1()
{
	//bit::stack<int, list<int>> st;
	//bit::stack<int, vector<int>> st;
	bit::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
void test_queue1()
{
	bit::queue<int> q;
	q.push(1);
	q.push(2);

	cout << q.front() << " ";
	q.pop();

	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main() {
	test_stack1();
	test_queue1();
	return 0;
}