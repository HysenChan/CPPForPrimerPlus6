// list.h -- head file, class definition
#pragma once
typedef int ItemList;

class List
{
private:
    enum { MAX = 5 };
    ItemList items[MAX];
    int top = 0;
public:
    List();
    bool isempty() const;
    bool isfull() const;
    bool add(const ItemList& item);
    void visit(void(*pf)(ItemList& item));
    void showitem() const;
};

void plusOne(ItemList& item);
