#include <iostream>
#include"student.h"
#pragma once
using namespace std;
struct Node {
	Node* next;
	student *student;
	Node()
	{
		this->next = NULL;
	}
};

class List {
private:
	Node* head;
	int size;

	void addFirst(string name) {
		this->head = new Node();
		this->head->student = new student(name);
	}

public:
	List()
	{
		this->head = NULL;
		this->size = 0;
	}

	void addToEnd(string name) {
		this->size++;
		if (this->head == NULL) {
			this->addFirst(name);
			return;
		}
		Node* tmp = this->head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new Node;

		tmp->next->next = NULL;
		tmp->next->student= new student(name);
	}

	int getSize() {
		return this->size;
	}

	student* getByName(string name) {
		
		Node* tmp = this->head;
		while (tmp->next != NULL) {
			if (tmp->student->getName()==name){
				return tmp->student;
			}
			tmp = tmp->next;
		}
	}

	student* getById(int id) {
		Node* tmp = this->head;
		for (int i = 0; i < id; i++) {
			tmp = tmp->next;
		}
		return tmp->student;
	}

};
