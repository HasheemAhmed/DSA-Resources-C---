#include <iostream>
using namespace std;
#include <stack>
#include <stdlib.h>

string infixToPostfix(string infix)
{
	int size = 0;
	string postfix = infix;
	stack<char> st;

	int junk = 0;

	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == ' ')
		{
			junk++;
		}
		else if (infix[i] == '(')
		{
			st.push(infix[i]);
			junk++;
		}
		else if (infix[i] == '*' || infix[i] == '/')
		{
			st.push(infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-')
		{
			if (st.empty())
			{
				st.push(infix[i]);
			}
			else if (st.top() == '(')
			{
				st.push(infix[i]);
			}
			else 
			{
				while (!st.empty() && st.top() != '(')
				{
					postfix[size] = st.top();
					st.pop();
					size++;
				}
				st.push(infix[i]);
			}
		}
		else if (infix[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				postfix[size] = st.top();
				st.pop();
				size++;
			}
			st.pop();
			junk++;
		}
		else
		{
			postfix[size] = infix[i];
			size++;
		}
	}

	while (!st.empty())
	{
		if(st.top() != '(' && st.top() != ')')
		postfix[size] = st.top();
		st.pop();
		size++;
	}

	for (int i = size; i < junk+size; i++)
	{
		postfix[i] = ' ';
	}

	return postfix;
}
int main()
{
	cout << infixToPostfix("( ( 2 * 3 ) + ( 3 * 2 ) ) - ( ( 3 * 3 ) + ( 4 - 2 ) )");

	return 0;
}