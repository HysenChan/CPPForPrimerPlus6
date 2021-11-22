// list.cpp -- class member functions' definition
#include <iostream>
#include "list10.h"

List::List()
{
    top = 0;
}

bool List::isempty() const
{
    return top == 0;
}

bool List::isfull() const
{
    return top == MAX;
}

bool List::add(const ItemList& item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

void List::visit(void(*pf)(ItemList& item))
{
    for (int i = 0; i < top; i++)
    {
        pf(items[i]);
    }
}

void List::showitem() const
{
    for (int i = 0; i < top; i++)
    {
        std::cout << "#" << i + 1 << ": " << items[i] << std::endl;
    }
}

void plusOne(ItemList& item)
{
    item += 100;
}