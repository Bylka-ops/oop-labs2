#pragma once
#include <iostream>

using namespace std;

class Array
{
private:
	double *mas;
	int count;
	void quickSort(double *numbers, int left, int right);
public:
	class size
	{

	};
	class input
	{

	};
	class memory
	{

	};
	friend ostream& operator<< (ostream &out, const Array &a);
	friend istream& operator>> (istream &in, Array &a);
	Array();
	void set_array();
	void get_array();
	void sort();
	~Array();

private:

};
istream& operator>> (istream &in, Array &a)
{
	cout << "enter massiv" << endl;
	for (int i = 0; i < a.count; i++)
	{
		in>>a.mas[i] ;
	}
	return in;
}
ostream& operator<< (ostream &out, const Array &a)
{
	out << "output in hexadecimal notation" << endl;
	out.precision(3);
	out.setf(ios::fixed);
	for (int i = 0; i < a.count; i++)
	{
		out << a.mas[i]<<" ";
	}
	out.unsetf(ios::fixed);
	out << endl;
	out << "output in octal number system" << endl;
	
	out.setf(ios::showpoint);
	for (int i = 0; i < a.count; i++)
	{
		out << a.mas[i] << " ";
	}
	out << endl;
	out.unsetf(ios::showpoint);
	out << "decimal notation" << endl;
	
	
	for (int i = 0; i < a.count; i++)
	{
		out.width(100);
		out.setf(ios::right);
		out << a.mas[i];
		out.unsetf(ios::right);
		out << endl;
	}
	out << endl;
	
	out << "+" << endl;
	out.setf(ios::showpos);
	for (int i = 0; i < a.count; i++)
	{
		out << a.mas[i] << " ";
	}
	out << endl;
	out.unsetf(ios::showpos);
	out << "e" << endl;
	out.setf(ios::scientific);
	for (int i = 0; i < a.count; i++)
	{
		out << a.mas[i] << " ";
	}
	out << endl;

	return out;
}

Array::Array()
{
	cout<<"enter size array"<<endl;
	if (!(cin >> count))
		throw input();
	mas = new double[count];


}

void Array::quickSort(double *numbers, int left, int right)
{
	int pivot; 
	int l_hold = left; 
	int r_hold = right; 
	pivot = numbers[left];
	while (left < right) 
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			numbers[left] = numbers[right]; 
			left++; 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; 
		if (left != right) 
		{
			numbers[right] = numbers[left]; 
			right--; 
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}

void Array::set_array()
{
	for (int i = 0; i < count; i++)
	{
		mas[i] = (rand()%10000)/100;
	}
}

void Array::get_array()
{
	for (int i = 0; i < count; i++)
	{
		cout << mas[i] << " ";
	}
}
void Array::sort()
{
	if (count==0)
		throw size();
	quickSort(mas, 0, count - 1);
}

Array::~Array()
{
	if (!mas)
		throw memory();
	delete[] mas;
}