#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* child;

    node(int val)
    {
        data = val;
        next = NULL;
        child = NULL;
    }
};

class linkedlist
{
public:
    node* head;

    linkedlist()
    {
        head = NULL;
    }

    node* findNode(int val)
    {
        node* temp = head;

        while (temp != NULL)
        {
            if (temp->data == val)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    void addNode(int val)
    {
        node* newNode = new node(val);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void addNext(int from, int to)
    {
        node* current = findNode(from);

        if (current == NULL)
        {
            addNode(from);
            current = findNode(from);
        }

        if (findNode(to) == NULL)
        {
            addNode(to);
        }

        current->next = findNode(to);
    }

    void addChild(int from, int to)
    {
        node* current = findNode(from);

        if (current == NULL)
        {
            addNode(from);
            current = findNode(from);
        }

        if (findNode(to) == NULL)
        {
            addNode(to);
        }

        current->child = findNode(to);
    }

    void flatten()
    {
        node* current = head;

        while (current != NULL)
        {
            if (current->child != NULL)
            {
                node* originalNext = current->next;
                node* childHead = current->child;

                current->next = childHead;
                current->child = NULL;

                node* temp = childHead;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = originalNext;
            }

            current = current->next;
        }
    }

    void print()
    {
        node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    linkedlist l1;

    int from, to, type;
    cout<<"Enter Node:";

    for (int i = 0; i < 8; i++)
    {
        cin >> from >> to >> type;

        if (type == 0)
        {
            l1.addNext(from, to);
        }
        else
        {
            l1.addChild(from, to);
        }
    }

    l1.flatten();

    l1.print();

    return 0;
}
