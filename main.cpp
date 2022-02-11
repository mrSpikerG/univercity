#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
using namespace std;



class group {
private:
	List* party = new List();
public:
	void addStudent(string name) {

		this->party->addToEnd(name);
	}

	student* getStudent(string name) {
		return party->getByName(name);
	}

	List* getGroup() {
		return this->party;
	}

	void save() {
		ofstream file("DataBase.txt");
		if (file.is_open()) {
			for (int i = 0; i < (this->party->getSize()); i++) {
				file << party->getById(i)->getName() << ":";
				for (int j = 0; j < party->getById(i)->getMarkSize(); j++) {
					file << party->getById(i)->getMarkMas()[j] << " ";
				}
				if (i != this->party->getSize() - 1) {
					file << "\n";
				}
			}
		}
		else {
			cout << "Error: FileNotFoundError";
		}
		file.close();
	}
	void read() {
		ifstream fin("DataBase.txt");
		if (fin.is_open()) {

			string text, name;
			string mark;
			char comma;
			int id = 0;
			while (!fin.eof())
			{
				text.clear();
				name.clear();

				getline(fin, text);
				text.find(':');
				name = text.substr(0, text.find(':'));
				text.erase(0, text.find(':') + 1);

				this->party->addToEnd(name);

				while (text.find(',') != -1) {
					mark = text.substr(0, text.find(','));
					//	mark.pop_back();

					this->party->getById(id)->addMark(stoi(mark));
					text.erase(0, text.find(',') + 1);
				}
				id++;

			}

		}
		else {
			cout << "Error: FileNotFoundError";
		}
		fin.close();

	}
};
int main() {

	group* club = new group();
	//club->addStudent("Vasya");
	//club->addStudent("Petya");

	//club->getStudent("Petya")->addMark(6);
	//club->getStudent("Petya")->addMark(6);


	//club->getGroup()->getById(0)->addMark(3);
	//club->getGroup()->getById(0)->addMark(9);
	//club->getGroup()->getById(0)->addMark(12);
	//club->getGroup()->getById(1)->addMark(12);
	//club->getGroup()->getById(1)->addMark(12);
	//club->getGroup()->getById(1)->addMark(12);

	//club->getStudent("Vasya")->addMark(6);
	//club->getStudent("Vasya")->addMark(122);
	//club->getStudent("Vasya")->addMark(9);
	club->read();

	int test = club->getGroup()->getById(0)->getMarks();
	cout << test;

	string text = club->getGroup()->getById(0)->getName();
	cout << text.c_str();

}