#ifndef TICKET_H
#define TICKET_H
#include <string>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;
class Ticket
{

public:
	Ticket();
	Ticket(int id, string city, string place, string address, string name, string time, float price);

	int getId();
	void setId(int id);
	float getPrice();
	void setPrice(float price);
	string getCity();
	void setCity(string city);
	string getPlace();
	void setPlace(string place);
	string getAddress();
	void setAddress(string address);
	string getName();
	void setName(string name);
	string getTime();
	void setTime(string time);

	static bool compareByName(Ticket i, Ticket j);
	static bool compareById(Ticket i, Ticket j);
	static bool compareByCity(Ticket i, Ticket j);

	string toString();

	void printRow();

protected:

private:
	int id;
	string city;
	string name;
	string place;
	string address;
	string time;
	float price;
};

#endif // TICKET_H
