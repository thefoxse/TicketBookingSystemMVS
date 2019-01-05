#ifndef INOUTUTILS_H
#define INOUTUTILS_H
#include <fstream>
#include <cstdlib>
#include<string>
#include <vector>
#include "Ticket.h"
#include "Order.h"
#include <iomanip>
#include <ctime>
#include "App.h"

class InOutUtils
{
public:
	InOutUtils();
	static vector<Ticket> loadTicketsFromFile(const char* filename);
	static void writeTicketsToFile(const char* filename, vector<Ticket> *tickets);
	static vector<Admin> loadAdminsFromFile(const char* filename);
	static void writeAdminsToFile(const char* filename, vector<Admin> *admins);
	static vector<Customer> loadCustomersFromFile(const char* filename);
	static void writeCustomersToFile(const char* filename, vector<Customer> *customers);
	static vector<Order> loadOrdersFromFile(const char* filename);
	static void writeOrdersToFile(const char* filename, vector<Order> *orders);

	//static

protected:

private:

};

#endif // INOUTUTILS_H
