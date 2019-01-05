#include "pch.h"
#include <iostream>
#include "InOutUtils.h"
#include <windows.h>
#include <vector>
#include <fstream>
#include "App.h"

using namespace std;

// Инициализация статических переменных
vector<Admin> App::admins = InOutUtils::loadAdminsFromFile("admin.txt");
vector<Customer> App::customers = InOutUtils::loadCustomersFromFile("customer.txt");
vector<Ticket> App::tickets = InOutUtils::loadTicketsFromFile("tickets.txt");
vector<Order> App::orders = InOutUtils::loadOrdersFromFile("orders.txt");

// формула кодирования
char EncryptSymbol(int iSymbol) {
	iSymbol = iSymbol - 51;
	iSymbol = (iSymbol ^= 10);
	return (char)iSymbol;
}

// формула декодирования
char DecryptSymbol(int iSymbol) {
	iSymbol = (iSymbol ^= 10);
	iSymbol = iSymbol + 51;
	return (char)iSymbol;
}

string encryptString(string str)
{
	string shifr = "";
	for (unsigned int i = 0; i < str.length(); i++)
	{
		shifr = shifr + EncryptSymbol((int)str[i]);
	}
	return shifr;
}

string decryptString(string str)
{
	string deshifr = "";
	for (unsigned int i = 0; i < str.length(); i++)
	{
		deshifr = deshifr + DecryptSymbol((int)str[i]);
	}
	return deshifr;
}


bool loginAdmin()
{
	string username, password;
	cout << "логин: ";
	cin >> username;
	cout << "пароль: ";
	cin >> password;
	vector<Admin> *admins = App::getAdmins();
	for (unsigned int i = 0; i < admins->size(); i++)
	{
		Admin admin = admins->at(i);
		if (admin.getUsername() == username && admin.getPassword() == encryptString(password))
		{
			admin.getMenu();
			return true;
		}
	}
	return false;
}

bool loginCustomer()
{
	string username, password;
	cout << "логин: ";
	cin >> username;
	cout << "пароль: ";
	cin >> password;
	vector<Customer> *customers = App::getCustomers();
	for (unsigned int i = 0; i < customers->size(); i++)
	{
		Customer *customer = &customers->at(i);
		if (customer->getUsername() == username && customer->getPassword() == encryptString(password))
		{
			customer->getMenu();
			return true;
		}
	}
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	cout << "Добро пожаловать в систему заказа билетов!" << endl;
	bool appWors = true;
	while (appWors)
	{
		string input;
		cout << "1 - Вход для администратора" << endl;
		cout << "2 - Вход для пользователя" << endl;
		cout << "0 - Выход" << endl;
		cout << "Ваш выбор: ";
		cin >> input;
		if (input == "1") { if (!loginAdmin()) cout << "Неверный логин или пароль!" << endl; }
		else if (input == "2") { if (!loginCustomer()) cout << "Неверный логин или пароль!" << endl; }
		else if (input == "0") { cout << "Выход"; appWors = false; }
		else { cout << "Неверный ввод! Попробуйте еще раз." << endl; }
	}

	// Сохранение данных в файлы перед завершением работы программы
	InOutUtils::writeCustomersToFile("customer.txt", App::getCustomers());
	InOutUtils::writeAdminsToFile("admin.txt", App::getAdmins());
	InOutUtils::writeTicketsToFile("tickets.txt", App::getTickets());
	InOutUtils::writeOrdersToFile("orders.txt", App::getOrders());

	return 0;
}
