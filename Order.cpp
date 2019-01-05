#include "pch.h"
#include "Order.h"

Order::Order()
{

}

Order::Order(int p_id, int p_ticketId, int p_userId, string p_created, int p_quantity)
{
	id = p_id;
	ticketId = p_ticketId;
	userId = p_userId;
	created = p_created;
	quantity = p_quantity;
}

int Order::getId()
{
	return id;
}
void Order::setId(int p_id)
{
	id = p_id;
}
int Order::getTicketId()
{
	return ticketId;
}
void Order::setTicketId(int p_ticketId)
{
	ticketId = p_ticketId;
}
int Order::getUserId()
{
	return userId;
}
void Order::setUserId(int p_userId)
{
	userId = p_userId;
}
string Order::getCreated()
{
	return created;
}
void Order::setCreated(string p_created)
{
	created = p_created;
}
int Order::getQuantity()
{
	return quantity;
}
void Order::setQuantity(int p_quantity)
{
	quantity = p_quantity;
}

float Order::calculateTotalPrice(float price, int quantity)
{
	return (price * quantity);
}
