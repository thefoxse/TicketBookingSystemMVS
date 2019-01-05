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
			cout << "Неверный ввод целого числа! Попробуйте еще раз." << endl;
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
			cout << "Неверный ввод числа с плавающей точкой! Попробуйте еще раз." << endl;
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
	cout << "|№";
	cout.width(11);
	cout << "|Город";
	cout.width(26);
	cout << "|Место";
	cout.width(26);
	cout << "|Адрес";
	cout.width(26);
	cout << "|Название";
	cout.width(21);
	cout << "|Время";
	cout.width(7);
	cout << "|Цена";
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
	cout << "Список всех билетов" << endl;
	cout << "Сортировать по: 1 - номеру, 2 - городу, - 3 - названию" << endl;
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
			cout << "Неверный ввод! Попбробуйте еще раз!" << endl;
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
	cout << "Город: ";
	cin >> city;
	cout << "Список билетов в городе " << city << endl;
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
	cout << "Место: ";
	cin >> place;
	cout << "Список билетов по месту " << place << endl;
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
	cout << "Название: ";
	cin >> name;
	cout << "Список билетов по названию " << name << endl;
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
	cout << "Здравствуйте, " << this->getFullName() << "!" << endl;
	while (true)
	{
		cout << "Выберите один из нескольких пунктов:" << endl;
		cout << "1 - Просмотр всех билетов" << endl;
		cout << "2 - Поиск билетов по городу" << endl;
		cout << "3 - Поиск билетов по месту" << endl;
		cout << "4 - Поиск билетов по названию" << endl;

		cout << "5 - Просмотр всех пользователей" << endl;
		cout << "6 - Просмотр всех заказов" << endl;
		cout << "7 - Добавить билет" << endl;
		cout << "8 - Удалить билет" << endl;
		cout << "9 - Редактировать билет" << endl;
		cout << "0 - Выход" << endl;
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
			cout << "До свидания, " << this->getFullName() << "!" << endl;
			return;
		}
		else
		{
			cout << "Неверный ввод! Попробуйте еще раз." << endl;
		}
	}
}

void Admin::showAllUsers()
{
	cout << "Список всех пользователей" << endl;
	cout.setf(ios::left);

	cout.width(0);
	cout << "|";
	cout.width(10);
	cout << "ID";

	cout.width(0);
	cout << "|";
	cout.width(20);
	cout << "Логин";

	cout.width(0);
	cout << "|";
	cout.width(40);
	cout << "Фамилия Имя";
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
	cout << "Список всех заказов" << endl;
	vector<Order> *orders = App::getOrders();
	for (unsigned int i = 0; i < orders->size(); i++)
	{
		Order *order = &orders->at(i);
		Ticket *ticket = App::getTicketById(order->getTicketId());
		Customer *customer = App::getCustomerById(order->getUserId());
		cout << "Заказ № " << order->getId() << endl;
		cout << "Заказал: " << customer->getFullName() << " (" << customer->getUsername() << ") " << order->getCreated() << endl;
		ticket->printRow();
		cout << "Количество: " << order->getQuantity() << endl;
		cout << "Итого: " << order->calculateTotalPrice(ticket->getPrice(), order->getQuantity()) << endl;
		cout << endl;
	}
}

void Admin::createTicket()
{
	int id;
	float price;
	string city, place, address, name, time;
	cout << "Добавить новый билет" << endl;
	cout << "№ (должен быть уникальным): ";
	id = intInput();
	cout << "Город: ";
	cin >> city;
	cout << "Место: ";
	cin >> place;
	cout << "Адрес: ";
	cin >> address;
	cout << "Название: ";
	cin >> name;
	cout << "Время: ";
	cin >> time;
	cout << "Цена: ";
	price = floatInput();
	Ticket ticket(id, city, place, address, name, time, price);
	cout << ticket.toString() << endl;
	bool ok = false;
	string choice;
	vector<Ticket> *tickets = App::getTickets();
	do
	{
		cout << "Введите 'да' что бы сохранить, 'нет' - для отмены" << endl;
		cin >> choice;
		if (choice == "да")
		{
			tickets->push_back(ticket);
			cout << "Данные сохранены!" << endl;
			ok = true;
		}
		else if (choice == "нет")
		{
			cout << "Создание отменено" << endl;
			ok = true;
		}
		else
		{
			cout << "Неверный ввод! Попбробуйте еще раз!" << endl;
		}
	} while (!ok);

}

void Admin::deleteTicket()
{
	cout << "Введите № билета, который вы хотите удалить: ";
	int id = intInput();
	if (App::getTicketById(id) != NULL)
	{
		App::deleteTicketById(id);
		cout << "Билет удален" << endl;
	}
	else
	{
		cout << "Билет с номером " << id << "Не найден!" << endl;
	}
}

void Admin::editTicket()
{
	cout << "Введите № билета, который вы хотите редактировать: ";
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
			cout << "Выберите поле, которое вы хотите отредактировать " << endl;
			cout << "1 - Город" << endl;
			cout << "2 - Место" << endl;
			cout << "3 - Адрес" << endl;
			cout << "4 - Название" << endl;
			cout << "5 - Время" << endl;
			cout << "6 - Цена" << endl;
			cout << "0 - Отмена" << endl;

			cin >> input;

			float price;
			string city, place, address, name, time;

			if (input == "1")
			{
				cout << "Город: ";
				cin >> city;
				ticket->setCity(city);
			}
			else if (input == "2")
			{
				cout << "Место: ";
				cin >> place;
				ticket->setPlace(place);
			}
			else if (input == "3")
			{
				cout << "Адрес: ";
				cin >> address;
				ticket->setAddress(address);
			}
			else if (input == "4")
			{
				cout << "Название: ";
				cin >> name;
				ticket->setName(name);
			}
			else if (input == "5")
			{
				cout << "Время: ";
				cin >> time;
				ticket->setTime(time);
			}
			else if (input == "6")
			{
				cout << "Цена: ";
				price = floatInput();
				ticket->setPrice(price);
			}
			else if (input == "0")
			{
				cout << "Редактирование отменено " << endl;
				edit = false;
			}
			do
			{
				cout << "Редактировать дальше? Введите да - что бы продолжить редактирование, нет - для выхода в меню" << endl;
				cin >> choice;
				if (choice == "да")
				{
					ok = true;
				}
				else if (choice == "нет")
				{
					edit = false;
					ok = true;
				}
				else
				{
					cout << "Неверный ввод! Попбробуйте еще раз!" << endl;
				}
			} while (!ok);

		} while (edit);

	}
	else
	{
		cout << "Билет с номером " << id << "Не найден!" << endl;
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
	cout << "Здравствуйте, " << this->getFullName() << "!" << endl;
	bool ok = true;
	while (ok)
	{
		cout << "Выберите один из нескольких пунктов:" << endl;
		cout << "1 - Просмотр всех билетов" << endl;
		cout << "2 - Поиск билетов по городу" << endl;
		cout << "3 - Поиск билетов по месту" << endl;
		cout << "4 - Поиск билетов по названию" << endl;
		cout << "5 - Просмотр моих заказов" << endl;
		cout << "6 - Сделать заказ" << endl;
		cout << "0 - Выход" << endl;
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
			cout << "До свидания, " << this->getFullName() << "!" << endl;
			ok = false;
		}
		else
		{
			cout << "Неверный ввод! Попробуйте еще раз." << endl;
		}
	}
}

void Customer::showMyOrders()
{
	cout << "Список моих заказов" << endl;
	vector<Order> *oders = App::getOrders();
	for (unsigned int i = 0; i < oders->size(); i++)
	{
		Order *order = &oders->at(i);
		if (order->getUserId() == this->getId())
		{
			Ticket *ticket = App::getTicketById(order->getTicketId());
			cout << "Заказ №" << order->getId() << endl;
			cout << "От " << order->getCreated() << endl;
			ticket->printRow();
			cout << "Количество: " << order->getQuantity() << endl;
			cout << "Итого: " << order->calculateTotalPrice(ticket->getPrice(), order->getQuantity()) << endl;
			cout << endl;
		}
	}
}

void Customer::makeAnOrder()
{
	int ticketId;
	int ticketsCount;
	cout << "Введите номер билета, что бы сделать заказ." << endl;
	cout << "№: ";
	ticketId = intInput();
	bool ok = false;
	do
	{
		Ticket *ticket = App::getTicketById(ticketId);
		if (ticket == NULL)
		{
			cout << "Билет не найден" << endl;
			ok = true;
		}
		else
		{
			cout << "Введите количество билетов: ";
			ticketsCount = intInput();
			cout << "Подтвердите заказ" << endl;
			cout << ticket->toString() << endl;
			cout << "Количество: " << ticketsCount << endl;
			cout << "Итого: " << Order::calculateTotalPrice(ticket->getPrice(), ticketsCount) << endl;

			int id = App::getOrders()->size();
			Order order(id + 1, ticket->getId(), this->getId(), getTimeStr(time(NULL)), ticketsCount);

			string choice;
			do
			{
				cout << "Введите 'да' что бы подтвердить заказ, 'нет' - для отмены" << endl;
				cin >> choice;
				if (choice == "да")
				{
					App::getOrders()->push_back(order);
					cout << "Данные сохранены!" << endl;
					ok = true;
				}
				else if (choice == "нет")
				{
					cout << "Заказ отменен" << endl;
					ok = true;
				}
				else
				{
					cout << "Неверный ввод! Попбробуйте еще раз!" << endl;
				}
			} while (!ok);
		}
	} while (!ok);
}
