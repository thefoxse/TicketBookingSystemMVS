#include "pch.h"
#include "App.h"

string getTimeStr(time_t seconds)
{
	return to_string(seconds);
}

int intInput()
{
	int value;
	string  s_value;
	bool ok = false;
	do
	{
		cin >> s_value;
		istringstream(s_value) >> value;
		if (value <= 0)
		{
			cout << "�������� ���� ������ �����! ���������� ��� ���." << endl;
		}
		else
		{
			ok = true;
		}
	} while (!ok);
	return value;
}

float floatInput()
{
	float value;
	string s_value;
	bool ok = false;
	do
	{
		cin >> s_value;
		istringstream(s_value) >> value;
		if (value == 0)
		{
			cout << "�������� ���� ����� � ��������� ������! ���������� ��� ���." << endl;
		}
		else
		{
			ok = true;
		}
	} while (!ok);
	return value;
}

void printHeader()
{
	cout.setf(ios::left);
	cout.width(7);
	cout << "|�";
	cout.width(11);
	cout << "|�����";
	cout.width(26);
	cout << "|�����";
	cout.width(26);
	cout << "|�����";
	cout.width(26);
	cout << "|��������";
	cout.width(21);
	cout << "|�����";
	cout.width(7);
	cout << "|����";
	cout.width(0);
	cout << "|";
	cout << endl;

	cout.fill('-');

	cout.width(7);
	cout << "+";
	cout.width(11);
	cout << "+";
	cout.width(26);
	cout << "+";
	cout.width(26);
	cout << "+";
	cout.width(26);
	cout << "+";
	cout.width(21);
	cout << "+";
	cout.width(7);
	cout << "+";
	cout.width(0);
	cout << "|";
	cout << endl;

	cout.fill(' ');

}

App::App()
{
	//ctor
}

App::~App()
{
	//dtor
}

vector<Admin>* App::getAdmins()
{
	return &admins;
}

vector<Customer>* App::getCustomers()
{
	return &customers;
}
vector<Ticket>* App::getTickets()
{
	return &tickets;
}
vector<Order>* App::getOrders()
{
	return &orders;
}
Customer* App::getCustomerById(int id)
{
	for (unsigned int i = 0; i < customers.size(); i++)
	{
		Customer* customer = &customers[i];
		if (customer->getId() == id)
		{
			return customer;
		}
	}
	return NULL;
}
Ticket* App::getTicketById(int id)
{
	for (unsigned int i = 0; i < tickets.size(); i++)
	{
		Ticket* ticket = &tickets[i];
		if (ticket->getId() == id)
		{
			return ticket;
		}
	}
	return NULL;
}

void App::deleteTicketById(int id)
{
	int deletedIndex;
	for (unsigned int i = 0; i < tickets.size(); i++)
	{
		Ticket* ticket = &tickets[i];
		if (ticket->getId() == id)
		{
			deletedIndex = i;
			break;
		}
	}
	tickets.erase(tickets.begin() + deletedIndex);
}


User::User()
{

}
User::User(int p_id, string p_username, string p_password, string p_firstname, string p_surename)
{
	id = p_id;
	username = p_username;
	password = p_password;
	firstname = p_firstname;
	surename = p_surename;
}
int User::getId()
{
	return id;
}
void User::setId(int p_id)
{
	id = p_id;
}
string User::getUsername()
{
	return username;
}
void User::setUsername(string p_username)
{
	username = p_username;
}
string User::getPassword()
{
	return password;
}
void User::setPassword(string p_password)
{
	password = p_password;
}
string User::getFirstname()
{
	return firstname;
}
void User::setFirstname(string p_firstname)
{
	firstname = p_firstname;
}
string User::getSurename()
{
	return surename;
}
void User::setSurename(string p_surename)
{
	surename = p_surename;
}

string User::getFullName()
{
	stringstream ss;
	ss << firstname << " " << surename;
	return ss.str();
}

void User::showAllTickets()
{
	vector<Ticket> tickets;
	string choice;
	cout << "������ ���� �������" << endl;
	cout << "����������� ��: 1 - ������, 2 - ������, - 3 - ��������" << endl;
	bool ok = false;
	do
	{
		cin >> choice;
		if (choice == "1")
		{
			tickets = this->sortTicketsById();
			ok = true;
		}
		else if (choice == "2")
		{
			tickets = this->sortTicketsByCity();
			ok = true;
		}
		else if (choice == "3")
		{
			tickets = this->sortTicketsByName();
			ok = true;
		}
		else
		{
			cout << "�������� ����! ����������� ��� ���!" << endl;
		}
	} while (!ok);

	printHeader();

	for (unsigned int i = 0; i < tickets.size(); i++)
	{
		Ticket ticket = tickets.at(i);
		ticket.printRow();
	}
	cout << endl;
}

void User::findTicketsByCity()
{
	string city;
	cout << "�����: ";
	cin >> city;
	cout << "������ ������� � ������ " << city << endl;
	vector<Ticket> *tickets = App::getTickets();
	printHeader();
	for (unsigned int i = 0; i < tickets->size(); i++)
	{
		Ticket ticket = tickets->at(i);
		if (ticket.getCity() == city)
			ticket.printRow();
	}
	cout << endl;
}
void User::findTicketsByPlace()
{
	string place;
	cout << "�����: ";
	cin >> place;
	cout << "������ ������� �� ����� " << place << endl;
	vector<Ticket> *tickets = App::getTickets();
	printHeader();
	for (unsigned int i = 0; i < tickets->size(); i++)
	{
		Ticket ticket = tickets->at(i);
		if (ticket.getPlace() == place)
			ticket.printRow();
	}
	cout << endl;
}
void User::findTicketsByName()
{
	string name;
	cout << "��������: ";
	cin >> name;
	cout << "������ ������� �� �������� " << name << endl;
	vector<Ticket> *tickets = App::getTickets();
	printHeader();
	for (unsigned int i = 0; i < tickets->size(); i++)
	{
		Ticket ticket = tickets->at(i);
		if (ticket.getName() == name)
			ticket.printRow();
	}
	cout << endl;
}
vector<Ticket> User::sortTicketsByName()
{
	vector<Ticket> tickets = *App::getTickets();
	sort(tickets.begin(), tickets.end(), Ticket::compareByName);
	return tickets;
}

vector<Ticket> User::sortTicketsById()
{
	vector<Ticket> tickets = *App::getTickets();
	sort(tickets.begin(), tickets.end(), Ticket::compareById);
	return tickets;
}

vector<Ticket> User::sortTicketsByCity()
{
	vector<Ticket> tickets = *App::getTickets();
	sort(tickets.begin(), tickets.end(), Ticket::compareByCity);
	return tickets;
}

Admin::Admin()
{

}

Admin::Admin(int id,
	string username,
	string password,
	string surename,
	string firstname
) : User(id, username, password, surename, firstname)
{
	//ctor
}

Admin::~Admin()
{
	//dtor
}

void Admin::getMenu()
{
	string input;
	cout << "������������, " << this->getFullName() << "!" << endl;
	while (true)
	{
		cout << "�������� ���� �� ���������� �������:" << endl;
		cout << "1 - �������� ���� �������" << endl;
		cout << "2 - ����� ������� �� ������" << endl;
		cout << "3 - ����� ������� �� �����" << endl;
		cout << "4 - ����� ������� �� ��������" << endl;

		cout << "5 - �������� ���� �������������" << endl;
		cout << "6 - �������� ���� �������" << endl;
		cout << "7 - �������� �����" << endl;
		cout << "8 - ������� �����" << endl;
		cout << "9 - ������������� �����" << endl;
		cout << "0 - �����" << endl;
		cin >> input;
		if (input == "1")
		{
			this->showAllTickets();
		}
		else if (input == "2")
		{
			this->findTicketsByCity();
		}
		else if (input == "3")
		{
			this->findTicketsByPlace();
		}
		else if (input == "4")
		{
			this->findTicketsByName();
		}
		else if (input == "5")
		{
			this->showAllUsers();
		}
		else if (input == "6")
		{
			this->showAllOrders();
		}
		else if (input == "7")
		{
			this->createTicket();
		}
		else if (input == "8")
		{
			this->deleteTicket();
		}
		else if (input == "9")
		{
			this->editTicket();
		}
		else if (input == "0")
		{
			cout << "�� ��������, " << this->getFullName() << "!" << endl;
			return;
		}
		else
		{
			cout << "�������� ����! ���������� ��� ���." << endl;
		}
	}
}

void Admin::showAllUsers()
{
	cout << "������ ���� �������������" << endl;
	cout.setf(ios::left);

	cout.width(0);
	cout << "|";
	cout.width(10);
	cout << "ID";

	cout.width(0);
	cout << "|";
	cout.width(20);
	cout << "�����";

	cout.width(0);
	cout << "|";
	cout.width(40);
	cout << "������� ���";
	cout.width(0);
	cout << "|";

	cout << endl;
	cout.fill('-');

	cout.width(11);
	cout << "|";
	cout.width(21);
	cout << "+";
	cout.width(41);
	cout << "+";
	cout.width(0);
	cout << "|";
	cout << endl;

	cout.fill(' ');

	vector<Customer> *customers = App::getCustomers();
	for (unsigned int i = 0; i < customers->size(); i++)
	{
		Customer customer = customers->at(i);

		cout.width(0);
		cout << "|";
		cout.width(10);
		cout << customer.getId();

		cout.width(0);
		cout << "|";
		cout.width(20);
		cout << customer.getUsername();

		cout.width(0);
		cout << "|";
		cout.width(40);
		cout << customer.getFullName();
		cout.width(0);
		cout << "|";

		cout << endl;
	}
}

void Admin::showAllOrders()
{
	cout << "������ ���� �������" << endl;
	vector<Order> *orders = App::getOrders();
	for (unsigned int i = 0; i < orders->size(); i++)
	{
		Order *order = &orders->at(i);
		Ticket *ticket = App::getTicketById(order->getTicketId());
		Customer *customer = App::getCustomerById(order->getUserId());
		cout << "����� � " << order->getId() << endl;
		cout << "�������: " << customer->getFullName() << " (" << customer->getUsername() << ") " << order->getCreated() << endl;
		ticket->printRow();
		cout << "����������: " << order->getQuantity() << endl;
		cout << "�����: " << order->calculateTotalPrice(ticket->getPrice(), order->getQuantity()) << endl;
		cout << endl;
	}
}

void Admin::createTicket()
{
	int id;
	float price;
	string city, place, address, name, time;
	cout << "�������� ����� �����" << endl;
	cout << "� (������ ���� ����������): ";
	id = intInput();
	cout << "�����: ";
	cin >> city;
	cout << "�����: ";
	cin >> place;
	cout << "�����: ";
	cin >> address;
	cout << "��������: ";
	cin >> name;
	cout << "�����: ";
	cin >> time;
	cout << "����: ";
	price = floatInput();
	Ticket ticket(id, city, place, address, name, time, price);
	cout << ticket.toString() << endl;
	bool ok = false;
	string choice;
	vector<Ticket> *tickets = App::getTickets();
	do
	{
		cout << "������� '��' ��� �� ���������, '���' - ��� ������" << endl;
		cin >> choice;
		if (choice == "��")
		{
			tickets->push_back(ticket);
			cout << "������ ���������!" << endl;
			ok = true;
		}
		else if (choice == "���")
		{
			cout << "�������� ��������" << endl;
			ok = true;
		}
		else
		{
			cout << "�������� ����! ����������� ��� ���!" << endl;
		}
	} while (!ok);

}

void Admin::deleteTicket()
{
	cout << "������� � ������, ������� �� ������ �������: ";
	int id = intInput();
	if (App::getTicketById(id) != NULL)
	{
		App::deleteTicketById(id);
		cout << "����� ������" << endl;
	}
	else
	{
		cout << "����� � ������� " << id << "�� ������!" << endl;
	}
}

void Admin::editTicket()
{
	cout << "������� � ������, ������� �� ������ �������������: ";
	int id = intInput();
	Ticket *ticket = App::getTicketById(id);
	if (ticket != NULL)
	{
		bool edit = true;
		bool ok = true;
		string input;
		string choice;;
		do
		{
			cout << "�������� ����, ������� �� ������ ��������������� " << endl;
			cout << "1 - �����" << endl;
			cout << "2 - �����" << endl;
			cout << "3 - �����" << endl;
			cout << "4 - ��������" << endl;
			cout << "5 - �����" << endl;
			cout << "6 - ����" << endl;
			cout << "0 - ������" << endl;

			cin >> input;

			float price;
			string city, place, address, name, time;

			if (input == "1")
			{
				cout << "�����: ";
				cin >> city;
				ticket->setCity(city);
			}
			else if (input == "2")
			{
				cout << "�����: ";
				cin >> place;
				ticket->setPlace(place);
			}
			else if (input == "3")
			{
				cout << "�����: ";
				cin >> address;
				ticket->setAddress(address);
			}
			else if (input == "4")
			{
				cout << "��������: ";
				cin >> name;
				ticket->setName(name);
			}
			else if (input == "5")
			{
				cout << "�����: ";
				cin >> time;
				ticket->setTime(time);
			}
			else if (input == "6")
			{
				cout << "����: ";
				price = floatInput();
				ticket->setPrice(price);
			}
			else if (input == "0")
			{
				cout << "�������������� �������� " << endl;
				edit = false;
			}
			do
			{
				cout << "������������� ������? ������� �� - ��� �� ���������� ��������������, ��� - ��� ������ � ����" << endl;
				cin >> choice;
				if (choice == "��")
				{
					ok = true;
				}
				else if (choice == "���")
				{
					edit = false;
					ok = true;
				}
				else
				{
					cout << "�������� ����! ����������� ��� ���!" << endl;
				}
			} while (!ok);

		} while (edit);

	}
	else
	{
		cout << "����� � ������� " << id << "�� ������!" << endl;
	}
}

Customer::Customer()
{

}

Customer::Customer(int id,
	string username,
	string password,
	string surename,
	string firstname
) : User(id, username, password, surename, firstname)
{

}

Customer::~Customer()
{
	//dtor
}

void Customer::getMenu()
{
	string input;
	cout << "������������, " << this->getFullName() << "!" << endl;
	bool ok = true;
	while (ok)
	{
		cout << "�������� ���� �� ���������� �������:" << endl;
		cout << "1 - �������� ���� �������" << endl;
		cout << "2 - ����� ������� �� ������" << endl;
		cout << "3 - ����� ������� �� �����" << endl;
		cout << "4 - ����� ������� �� ��������" << endl;
		cout << "5 - �������� ���� �������" << endl;
		cout << "6 - ������� �����" << endl;
		cout << "0 - �����" << endl;
		cin >> input;
		if (input == "1")
		{
			this->showAllTickets();
		}
		else if (input == "2")
		{
			this->findTicketsByCity();
		}
		else if (input == "3")
		{
			this->findTicketsByPlace();
		}
		else if (input == "4")
		{
			this->findTicketsByName();
		}
		else if (input == "5")
		{
			this->showMyOrders();
		}
		else if (input == "6")
		{
			this->makeAnOrder();
		}
		else if (input == "0")
		{
			cout << "�� ��������, " << this->getFullName() << "!" << endl;
			ok = false;
		}
		else
		{
			cout << "�������� ����! ���������� ��� ���." << endl;
		}
	}
}

void Customer::showMyOrders()
{
	cout << "������ ���� �������" << endl;
	vector<Order> *oders = App::getOrders();
	for (unsigned int i = 0; i < oders->size(); i++)
	{
		Order *order = &oders->at(i);
		if (order->getUserId() == this->getId())
		{
			Ticket *ticket = App::getTicketById(order->getTicketId());
			cout << "����� �" << order->getId() << endl;
			cout << "�� " << order->getCreated() << endl;
			ticket->printRow();
			cout << "����������: " << order->getQuantity() << endl;
			cout << "�����: " << order->calculateTotalPrice(ticket->getPrice(), order->getQuantity()) << endl;
			cout << endl;
		}
	}
}

void Customer::makeAnOrder()
{
	int ticketId;
	int ticketsCount;
	cout << "������� ����� ������, ��� �� ������� �����." << endl;
	cout << "�: ";
	ticketId = intInput();
	bool ok = false;
	do
	{
		Ticket *ticket = App::getTicketById(ticketId);
		if (ticket == NULL)
		{
			cout << "����� �� ������" << endl;
			ok = true;
		}
		else
		{
			cout << "������� ���������� �������: ";
			ticketsCount = intInput();
			cout << "����������� �����" << endl;
			cout << ticket->toString() << endl;
			cout << "����������: " << ticketsCount << endl;
			cout << "�����: " << Order::calculateTotalPrice(ticket->getPrice(), ticketsCount) << endl;

			int id = App::getOrders()->size();
			Order order(id + 1, ticket->getId(), this->getId(), getTimeStr(time(NULL)), ticketsCount);

			string choice;
			do
			{
				cout << "������� '��' ��� �� ����������� �����, '���' - ��� ������" << endl;
				cin >> choice;
				if (choice == "��")
				{
					App::getOrders()->push_back(order);
					cout << "������ ���������!" << endl;
					ok = true;
				}
				else if (choice == "���")
				{
					cout << "����� �������" << endl;
					ok = true;
				}
				else
				{
					cout << "�������� ����! ����������� ��� ���!" << endl;
				}
			} while (!ok);
		}
	} while (!ok);
}
