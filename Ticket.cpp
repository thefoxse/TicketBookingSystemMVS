#include "pch.h"
#include "Ticket.h"
Ticket::Ticket()
{

}

Ticket::Ticket(int p_id, string a_city, string a_place, string an_address, string a_name, string a_time, float a_price)
{
	id = p_id;
	city = a_city;
	place = a_place;
	address = an_address;
	name = a_name;
	time = a_time;
	price = a_price;
}

string Ticket::toString()
{
	stringstream ss;
	ss << "№ " << id << "; ";
	ss << "Город: " << city << "; ";
	ss << "Место: " << place << "; ";
	ss << "Адрес: " << address << "; ";
	ss << "Название: " << name << "; ";
	ss << "Время: " << time << "; ";
	ss << "Цена: " << price;
	return ss.str();
}

void Ticket::printRow()
{
	cout.setf(ios::left);
	cout.width(0);
	cout << "|";
	cout.width(6);
	cout << id;
	cout.width(0);
	cout << "|";
	cout.width(10);
	cout << city;
	cout.width(0);
	cout << "|";
	cout.width(25);
	cout << place;
	cout.width(0);
	cout << "|";
	cout.width(25);
	cout << address;
	cout.width(0);
	cout << "|";
	cout.width(25);
	cout << name;
	cout.width(0);
	cout << "|";
	cout.width(20);
	cout << time;
	cout.width(0);
	cout << "|";
	cout.width(6);
	cout << price;
	cout.width(0);
	cout << "|";
	cout << endl;
}

bool Ticket::compareByName(Ticket i, Ticket j)
{
	bool result = false;
	result = (strcmp(i.name.c_str(), j.name.c_str()) < 0);
	return result;
}

bool Ticket::compareById(Ticket i, Ticket j)
{
	bool result = false;
	result = (i.id < j.id);
	return result;
}
bool Ticket::compareByCity(Ticket i, Ticket j)
{
	bool result = false;
	result = (strcmp(i.city.c_str(), j.city.c_str()) < 0);
	return result;
}

int Ticket::getId()
{
	return id;
}
void Ticket::setId(int p_id)
{
	id = p_id;
}
float Ticket::getPrice()
{
	return price;
}
void Ticket::setPrice(float p_price)
{
	price = p_price;
}
string Ticket::getCity()
{
	return city;
}
void Ticket::setCity(string p_city)
{
	city = p_city;
}
string Ticket::getPlace()
{
	return place;
}
void Ticket::setPlace(string p_place)
{
	place = p_place;
}
string Ticket::getAddress()
{
	return address;
}
void Ticket::setAddress(string p_address)
{
	address = p_address;
}
string Ticket::getName()
{
	return name;
}
void Ticket::setName(string p_name)
{
	name = p_name;
}
string Ticket::getTime()
{
	return time;
}
void Ticket::setTime(string p_time)
{
	time = p_time;
}
