#include <iostream>
#include <stack>
#include <string>
using namespace std;

//проверка на расстановку скобок. ответ - правда или ложь

bool CheckBrecket(const string& st)
{
	stack<char> stack;

	for (size_t i = 0; i < st.length(); ++i)
	{
		char symbol = st[i];

		if (symbol == '(' || symbol == '{' || symbol == '[')
		{
			stack.push(symbol);
		}

		else
			if (symbol == ')' || symbol == '}' || symbol == ']')
			{
				if (stack.empty())
				{
					return  0;
				}

				char top = stack.top();
				stack.pop();

				if (symbol == ')' && top != '(' || symbol == '}' && top != '{' || symbol == ']' && top != '[')
				{
					return 0;
				}
			}
	}

	return stack.empty();
}

int main()
{
	setlocale(LC_ALL, "RU");
	string stroka;

	cout << "Введите выражение: ";
	getline(cin, stroka);

	if (CheckBrecket(stroka))
		cout << "\nСкобки расставлены корректно";
	else
		cout << "\nСкобки расставлены некорректно";



}

