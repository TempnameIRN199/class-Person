#pragma once
#include "Header.h"
/*���������� ����� Person.
������ ����������� �������, ���������� ������ diskOut() � diskIn(), � ������� ������ ��������� ������ ������ � ���������� ��� ���� � ���� PERSFILE.DAT.
����� ������� ������ ����� ����������� � ����� �����.
�������� ������ diskIn() ��������� ������ ������ � ����� �������� �� �����.
��� �������������� ������� ��������� ������, ��������� �� ������� ����� �������� ����������� �����  diskCount(), ������������ ����� �����, ���������� � ������� �������� � �����.*/

class Person
{
private:
	char name[20];
	char surname[20];
	char patronymic[20];
	char address[20];
	char phone[20];
	char email[20];
public:
	Person() {
		strcpy(name, " ");
		strcpy(surname, " ");
		strcpy(patronymic, " ");
		strcpy(address, " ");
		strcpy(phone, " ");
		strcpy(email, " ");
	}
	Person(char* name, char* surname, char* patronymic, char* address, char* phone, char* email) {
		strcpy(this->name, name);
		strcpy(this->surname, surname);
		strcpy(this->patronymic, patronymic);
		strcpy(this->address, address);
		strcpy(this->phone, phone);
		strcpy(this->email, email);
	}
	void setName(char* name) {
		strcpy(this->name, name);
	}
	void setSurname(char* surname) {
		strcpy(this->surname, surname);
	}
	void setPatronymic(char* patronymic) {
		strcpy(this->patronymic, patronymic);
	}
	void setAddress(char* address) {
		strcpy(this->address, address);
	}
	void setPhone(char* phone) {
		strcpy(this->phone, phone);
	}
	void setEmail(char* email) {
		strcpy(this->email, email);
	}
	char* getName() {
		return name;
	}
	char* getSurname() {
		return surname;
	}
	char* getPatronymic() {
		return patronymic;
	}
	char* getAddress() {
		return address;
	}
	char* getPhone() {
		return phone;
	}
	char* getEmail() {
		return email;
	}
	void diskOut() {
		ofstream fout("PERSFILE.dat", ios::binary | ios::app);
		fout.write((char*)this, sizeof(*this));
		fout.close();
	}
	void diskIn(int n) {
		ifstream fin("PERSFILE.dat", ios::binary);
		fin.seekg(n * sizeof(*this));
		fin.read((char*)this, sizeof(*this));
		fin.close();
	}
	static int diskCount() {
		ifstream fin("PERSFILE.dat", ios::binary);
		fin.seekg(0, ios::end);
		int n = fin.tellg() / sizeof(Person);
		fin.close();
		return n;
	}
};