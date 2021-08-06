#include "warehouse.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	Warehouse test;
	test.Add(Product("Мыло", "Хозтовары", 5, Product::Date(2021, 7, 28), 500, 10));
	test.Add(Product("Ведро", "Хозтовары", 5, Product::Date(2021, 7, 28), 500, 10));
	test.Add(Product("Швабра", "Хозтовары", 5, Product::Date(2021, 7, 28), 500, 10), 1);
	test.Print();
	return 0;
}