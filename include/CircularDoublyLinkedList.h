#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

class CircularDoublyLinkedList
{
public:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;

        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

private:
    Node *head;
    Node *tail;
    int size;

public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    void print_list() const;
    int get_size() const;
    int find(int value) const;

    void insert_at_tail(int value);
    void insert_at_head(int value);
    bool insert_at_index(int value, int index);

    bool delete_tail();
    bool delete_head();
    bool delete_at_index(int index);
};

#endif