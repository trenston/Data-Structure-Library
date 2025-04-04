#include "../include/CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;

CircularDoublyLinkedList::CircularDoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    if (!head)
    {
        return;
    }

    tail->next = nullptr;

    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
}

void CircularDoublyLinkedList::print_list() const
{
    if (!head)
    {
        return;
    }

    Node *current = head;

    do
    {
        cout << current->data << endl;
        current = current->next;
    } while (current != head);
}

int CircularDoublyLinkedList::get_size() const
{
    return size;
}

int CircularDoublyLinkedList::find(int value) const
{
    if (!head)
    {
        return -1;
    }

    Node *current = head;
    int currentIndex = 0;
    do
    {
        if (current->data == value)
        {
            return currentIndex;
        }

        current = current->next;
        currentIndex++;
    } while (current != head);

    return -1;
}

void CircularDoublyLinkedList::insert_at_tail(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    size++;
}

void CircularDoublyLinkedList::insert_at_head(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

bool CircularDoublyLinkedList::insert_at_index(int value, int index)
{
    if (index < 0 || index > size)
    {
        return false;
    }

    if (index == 0)
    {
        insert_at_head(value);
        return true;
    }

    if (index == size)
    {
        insert_at_tail(value);
        return true;
    }

    Node *newNode = new Node(value);
    Node *current = head;
    int currentIndex = 0;

    while (currentIndex < index - 1)
    {
        current = current->next;
        currentIndex++;
    }

    newNode->next = current->next;
    current->next = newNode;

    size++;
    return true;
}

bool CircularDoublyLinkedList::delete_tail()
{
    if (!head)
    {
        return false;
    }

    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;

        size--;
        return true;
    }

    Node *temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete temp;

    size--;
    return true;
}

bool CircularDoublyLinkedList::delete_head()
{
    if (!head)
    {
        return false;
    }

    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;

        size--;
        return true;
    }

    Node *temp = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete temp;

    size--;
    return true;
}

bool CircularDoublyLinkedList::delete_at_index(int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }

    if (index == 0)
    {
        return delete_head();
    }

    if (index == size - 1)
    {
        return delete_tail();
    }

    Node *current = head;
    int currentIndex = 0;

    if (index < (size / 2))
    {
        current = head;
        currentIndex = 0;

        while (currentIndex < index)
        {
            current = current->next;
            currentIndex++;
        }
    }
    else
    {
        current = tail;
        currentIndex = size - 1;

        while (currentIndex > index)
        {
            current = current->prev;
            currentIndex--;
        }
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;

    size--;
    return true;
}