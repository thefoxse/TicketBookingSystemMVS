#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <sstream>

#include <iostream>

using namespace std;
class Order
{
public:
	Order();
	Order(int id, int ticketId, int userId, string created, int quantity);

	int getId();
	void setId(int id);
	int getTicketId();
	void setTicketId(int ticketId);
	int getUserId();
	void setUserId(int orderId);
	string getCreated();
	void setCreated(string created);
	int getQuantity();
	void setQuantity(int quantity);

	static float calculateTotalPrice(float, int);

protected:

private:
	int id;
	int ticketId;
	int userId;
	string created;
	int quantity;


};

#endif // ORDER_H
