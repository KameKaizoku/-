// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stack>



int main()
{
	std::string str;
	std::cin >> str;

	int res = -1;

	std::stack <char> st;
	std::stack <int> num;

	for (int i = 0; i < str.length(); i++)
	{
		char temp = str[i];

		if (temp == '[' || temp == '{' || temp == '(')
		{
			st.push(temp);
			num.push(i + 1);
		}

		if (temp == ']' || temp == '}' || temp == ')')
		{
			if (st.empty())
			{
				num.push(i + 1);
				break;
			}
			else
			{
				if (st.top() == '[' && temp != ']'
					|| st.top() == '(' && temp != ')'
					|| st.top() == '{' && temp != '}')
				{
					num.push(i + 1);
					break;

				}
				else
				{
					st.pop();
					num.pop();
				}
			}

		}
	}

	if(!num.empty())
		std::cout << num.top();
	else std::cout << "Success";

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
