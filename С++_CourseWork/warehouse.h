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
		head->next = head;
		head->previous = head;
	}
	else {
		Element* current = head;
		while (current->next != head)
		{
			current = current->next;
		}
		Element* newItem = new Element(value, head, head->previous);
		current->next = newItem;
		head->previous = newItem;
	}
	size++;
}

inline void Warehouse::Print()
{
	Element* current = head;
	int i = 0;
	do {
		cout << "����� ����� " << i << endl;
		cout << "��� ������: " << current->data.name << endl;
		cout << "���������� ������: " << current->data.count << " ��." << endl;
		cout << "���� �������� ������: " << current->data.arrivalDate.year << "." << current->data.arrivalDate.month <<
			"." << current->data.arrivalDate.day << endl;
		cout << "��������� ������: " << current->data.cost << " ������" << endl;
		cout << "�������� �������� ������: " << current->data.percent << "%" << endl;
		current = current->next;
		i++;
	} while (current != head);
}
