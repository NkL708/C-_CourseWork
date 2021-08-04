#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Product {
	class Date {
	public:
		Date() {

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

	Product(string name, string category, int count, Date arrivalDate, int cost, int percent) {
		this->name = name;
		this->category = category;
		this->count = count;
		this->arrivalDate = arrivalDate;
		this->cost = cost;
		this->percent = percent;
	}
	Product() {

	}
	string name;
	string category;
	int count;
	Date arrivalDate;
	int cost;
	int percent;
};