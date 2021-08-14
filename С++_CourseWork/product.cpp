#include "product.h"

Product::Product()
{
	cost = 0;
	count = 0;
	percent = 0;
}

Product::Product(string name, string category, int count, Date arrivalDate, int cost, int percent)
{
	this->name = name;
	this->category = category;
	this->count = count;
	this->arrivalDate = arrivalDate;
	this->cost = cost;
	this->percent = percent;
}

Product Product::CreateProduct()
{
	int count, cost, percent;
	string name, category;
	Product::Date arrivalDate;
	cout << "��������: ";
	cin >> name;
	cout << "���������: ";
	cin >> category;
	cout << "����������: ";
	cin >> count;
	cout << "���� �����������: ";
	cin >> arrivalDate.year >> arrivalDate.month >> arrivalDate.day;
	cout << "���������: ";
	cin >> cost;
	cout << "������� �������� ��������: ";
	cin >> percent;
	Product product(name, category, count, arrivalDate, cost, percent);
	return product;
}