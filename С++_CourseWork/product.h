#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

struct Product 
{
	struct Date 
	{
		Date() {
			year = 0;
			month = 0;
			day = 0;
		}
		Date(int year, int month, int day) {
			this->year = year;
			this->month = month;
			this->day = day;
		}
		int year;
		int month;
		int day;
	};

	string name;
	string category;
	int count;
	Date arrivalDate;
	int cost;
	int percent;

	Product();
	Product(string name, string category, int count, Date arrivalDate, int cost, int percent);
	static Product CreateProduct();
};