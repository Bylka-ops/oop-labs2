// ConsoleApplication34.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"

int main()
{

	try
	{
		Array Mas;
		Mas.set_array();
		Mas.get_array();
		Mas.sort();
		cout << endl;
		Mas.get_array();
		
		cout << endl;
		cout << Mas;
	}
	catch(Array::size)
	{ 
		cout << "the array is empty"<<endl;
	}
	catch (Array::input)
	{
		cout << "invalid input" << endl;
	}
	catch (Array::memory)
	{
		cout << "memory freed" << endl;
	}
	
	system("pause");
}

