#pragma once
#include "product.h"

class Warehouse
{
	class Element
	{
	public:
		Element(Product data, Element* next = nullptr, Element* previous = nullptr) {
			this->next = next;
			this->previous = previous;
			this->data = data;
		}
		Product data;
		Element* next;
		Element* previous;
	};
	Element* head;
	int size;

public:
	Warehouse();
	void Add(Product value);
	void Add(Product value, int index);
	void Delete();
	void Delete(int index);
	void Print();
};

inline Warehouse::Warehouse()
{
	head = nullptr;
}

inline void Warehouse::Add(Product value)
{
	if (head == nullptr) {
		head = new Element(value);
		head->next = nullptr;
		head->previous = nullptr;
	}
	else {
		Element* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		Element* newItem = new Element(value, nullptr, current);
		current->next = newItem;
	}
	size++;
}

inline void Warehouse::Add(Product value, int index)
{
	Element* current = head;
	if (index == 0) {
		head = new Element(value, head, nullptr);
	}
	else if (index == size) {
		while (current->next != nullptr) {
			current = current->next;
		}
		Element* newItem = new Element(value, nullptr, current);
		current->next = newItem;
	}
	else {
		while (index - 1 > 0) {
			current = current->next;
			index--;
		}
		Element* newItem = new Element(value, current->next, current);
		current->next = newItem;
		current->next->previous = newItem;
	}
	size++;
}

inline void Warehouse::Delete()
{
	if (head == nullptr) return;
	else {
		Element* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}
	size--;
}

inline void Warehouse::Delete(int index)
{
	Element* current = head;
	if (index == 0) {
		head = head->next;
		delete head->previous;
		head->previous = nullptr;
	}
	else if (index == size - 1) {
		Element* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}
	else {
		while (index > 0) {
			current = current->next;
			index--;
		}
		current->next->previous = current->previous;
		current->previous->next = current->next;
		delete current;
	}
	size--;
}

inline void Warehouse::Print()
{
	Element* current = head;
	int i = 0;
	do {
		cout << "Товар номер " << i << endl;
		cout << "Имя товара: " << current->data.name << endl;
		cout << "Количество товара: " << current->data.count << " шт." << endl;
		cout << "Дата прибытия товара: " << current->data.arrivalDate.year << "." << current->data.arrivalDate.month <<
			"." << current->data.arrivalDate.day << endl;
		cout << "Стоимость товара: " << current->data.cost << " рублей" << endl;
		cout << "Торговая надбавка товара: " << current->data.percent << "%" << endl << endl;
		current = current->next;
		i++;
	} while (current != nullptr);
}
