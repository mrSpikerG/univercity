#pragma once
#include<iostream>
using namespace std;
class student {
private:
	string name;
	int* marks;
	size_t size;
public:
	student(string name)
	{
		marks = nullptr;
		this->name = name;
		this->size = 0;
	}

	size_t getMarkSize() {
		return this->size;
	}

	void addMark(int mark) {
		if (size == 0) {
			this->marks = new int[1];
			this->marks[0] = mark;
			this->size++;
			return;
		}

		int* TEMP = new int[size + 1];
		for (int i = 0; i < size; i++) {
			TEMP[i] = this->marks[i];
		}

		TEMP[size] = mark;
		//delete this->marks;

		this->size++;
		for (int i = 0; i < this->size; i++) {
			this->marks[i] = TEMP[i];
		}
	}

	float getMarks() {
		float sum = 0;
		for (int i = 0; i < size; i++) {
			sum += this->marks[i];
		}
		return sum / size;
	}

	int* getMarkMas(){
		return this->marks;
	}

	string getName() {
		return this->name;
	}
};