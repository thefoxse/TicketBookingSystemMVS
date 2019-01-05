#include "pch.h"
#include "InOutUtils.h"

InOutUtils::InOutUtils()
{

}

vector<Ticket> InOutUtils::loadTicketsFromFile(const char* filename)
{
	vector<Ticket> tickets;
	string line;
	string value;
	ifstream fin(filename);
	while (getline(fin, line))
	{
		stringstream ss;
		ss << line;
		vector<string> record;
		while (getline(ss, value, '#'))
		{
			record.push_back(value);
		}
		int id;
		float price;
		istringstream(record[0]) >> id;
		istringstream(record[6]) >> price;
		Ticket ticket(id, record[1], record[2], record[3], record[4], record[5], price);
		tickets.push_back(ticket);
	}
	fin.close();
	return tickets;
}
void InOutUtils::writeTicketsToFile(const char* filename, vector<Ticket> *tickets)
{
	ofstream fout(filename);
	for (unsigned int i = 0; i < tickets->size(); i++)
	{
		Ticket ticket = tickets->at(i);
		fout << ticket.getId() << '#'
			<< ticket.getCity() << '#'
			<< ticket.getPlace() << '#'
			<< ticket.getAddress() << '#'
			<< ticket.getName() << '#'
			<< ticket.getTime() << '#'
			<< ticket.getPrice() << endl;
	}
	fout.close();
}
vector<Admin> InOutUtils::loadAdminsFromFile(const char* filename)
{
	vector<Admin> admins;
	string line;
	string value;
	ifstream fin(filename);
	while (getline(fin, line))
	{
		stringstream ss;
		ss << line;
		vector<string> record;
		while (getline(ss, value, '#'))
		{
			record.push_back(value);
		}
		int id;
		istringstream(record[0]) >> id;
		Admin admin(id, record[1], record[2], record[3], record[4]);
		admins.push_back(admin);
	}
	fin.close();
	return admins;
}

vector<Customer> InOutUtils::loadCustomersFromFile(const char* filename)
{
	vector<Customer> customers;
	string line;
	string value;
	ifstream fin(filename);
	while (getline(fin, line))
	{
		stringstream ss;
		ss << line;
		vector<string> record;
		while (getline(ss, value, '#'))
		{
			record.push_back(value);
		}
		int id;
		istringstream(record[0]) >> id;
		Customer customer(id, record[1], record[2], record[3], record[4]);
		customers.push_back(customer);
	}
	fin.close();
	return customers;
}

void InOutUtils::writeCustomersToFile(const char* filename, vector<Customer> *customers)
{
	ofstream fout(filename);
	for (unsigned int i = 0; i < customers->size(); i++)
	{
		Customer customer = customers->at(i);
		fout << customer.getId() << '#'
			<< customer.getUsername() << '#'
			<< customer.getPassword() << '#'
			<< customer.getFirstname() << '#'
			<< customer.getSurename() << endl;
	}
	fout.close();
}
vector<Order> InOutUtils::loadOrdersFromFile(const char* filename)
{
	vector<Order> orders;
	string line;
	string value;
	ifstream fin(filename);
	while (getline(fin, line))
	{
		stringstream ss;
		ss << line;
		vector<string> record;
		while (getline(ss, value, '#'))
		{
			record.push_back(value);
		}
		int id;
		int ticketId;
		int userId;
		string time;
		int quanyity;

		istringstream(record[0]) >> id;
		istringstream(record[1]) >> ticketId;
		istringstream(record[2]) >> userId;
		time = record[3];
		istringstream(record[4]) >> quanyity;
		Order order(id, ticketId, userId, time, quanyity);
		orders.push_back(order);
	}
	fin.close();
	return orders;
}


void InOutUtils::writeOrdersToFile(const char* filename, vector<Order> *orders)
{
	ofstream fout(filename);
	for (unsigned int i = 0; i < orders->size(); i++)
	{
		Order order = orders->at(i);
		fout << order.getId() << '#'
			<< order.getTicketId() << '#'
			<< order.getUserId() << '#'
			<< order.getCreated() << '#'
			<< order.getQuantity() << endl;
	}
	fout.close();
}

void InOutUtils::writeAdminsToFile(const char* filename, vector<Admin> *admins)
{
	ofstream fout(filename);
	for (unsigned int i = 0; i < admins->size(); i++)
	{
		Admin admin = admins->at(i);
		fout << admin.getId() << '#'
			<< admin.getUsername() << '#'
			<< admin.getPassword() << '#'
			<< admin.getFirstname() << '#'
			<< admin.getSurename() << endl;
	}
	fout.close();
}

