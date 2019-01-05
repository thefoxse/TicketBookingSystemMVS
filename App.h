#ifndef APP_H
#define APP_H
#include <vector>
#include <ctime>
#include "Ticket.h"
#include "Order.h"
#include <algorithm>
#include <string>

using namespace std;

class User
{
public:
	User();
	User(int id, string username, string password, string surename, string firstname);
	string getFullName();

	int getId();
	void setId(int id);
	string getUsername();
	void setUsername(string username);
	string getPassword();
	void setPassword(string password);
	string getFirstname();
	void setFirstname(string firstname);
	string getSurename();
	void setSurename(string surename);

	void getMenu();

	void showAllTickets();
	void findTicketsByCity();
	void findTicketsByPlace();
	void findTicketsByName();

	vector<Ticket> sortTicketsByName();
	vector<Ticket> sortTicketsByCity();
	vector<Ticket> sortTicketsById();

protected:

private:
	int id;
	string username;
	string password;
	string surename;
	string firstname;

};

class Admin : public User
{
public:
	Admin();

	Admin(int id, string username, string password, string surename, string firstname);

	virtual ~Admin();

	void getMenu();

	void showAllUsers();
	void showAllOrders();
	virtual void createTicket();
	void deleteTicket();
	void editTicket();

protected:

private:
};

class Customer : public User
{
public:
	Customer();

	Customer(int id, string username, string password, string surename, string firstname);

	void showMyOrders();

	virtual ~Customer();

	void getMenu();
	void makeAnOrder();

protected:

private:
	vector<Order*> orders;
};

class App
{
public:
	App();
	virtual ~App();

	static vector<Admin>* getAdmins();
	static vector<Customer>* getCustomers();
	static vector<Ticket>* getTickets();
	static vector<Order>* getOrders();

	static Customer* getCustomerById(int id);
	static Ticket* getTicketById(int id);

	static void deleteTicketById(int id);

protected:

private:
	static vector<Admin> admins;
	static vector<Customer> customers;
	static vector<Ticket> tickets;
	static vector<Order> orders;
};

#endif // APP_H
