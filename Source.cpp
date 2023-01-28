#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

class PostfixToInfix
{
	string infix;
	string postfix;
	stack<string> strStack;
public:
	PostfixToInfix() :infix(""), postfix("") {}
	void setter();
	void getter();
	void convertToInfix();

};
void PostfixToInfix::setter()
{
	cout << "\n Enter Postfix: ";
	getline(cin, postfix);
}
void PostfixToInfix::getter()
{
	cout << "Infix Notation: " << infix << endl;
}
void PostfixToInfix::convertToInfix()
{
	string str;
	int i = 0;
	
	while (postfix[i] != NULL)
	{
		str = postfix.substr(i, 1);
		i++;

		if ((str >= "A" && str <= "Z") || (str >= "a" && str <= "z"))
			strStack.push(str);
		else if (str == "+" || str == "-" || str == "/" || str == "*" || str == "^")
		{
	
			string operand_2 = strStack.top();
			strStack.pop();
			string operand_1 = strStack.top();
			strStack.pop();

			strStack.push("(" + operand_1 + str + operand_2 + ")");
		}
	}

	infix = strStack.top();
	strStack.pop();
}
int main()
{
    PostfixToInfix obj;
	obj.setter();
	obj.convertToInfix();
	obj.getter();
}