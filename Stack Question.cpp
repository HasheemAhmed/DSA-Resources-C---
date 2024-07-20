#include <iostream>
using namespace std;
#include <stack>

stack<int> copystack(stack<int> s1)
{
	stack<int> s2, s3;

	while (!s1.empty())
	{
		s3.push(s1.top());
		s1.pop();
	}

	while (!s3.empty())
	{
		s2.push(s3.top());
		s3.pop();
	}

	return s2;
}

void display(stack<int> st)
{
	while (!st.empty())
	{
		cout << st.top() << "  ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	stack<int> s1,s2;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);

	
	display(s1);
	s2 = copystack(s1);

	display(s2);
	
	return 0;
}