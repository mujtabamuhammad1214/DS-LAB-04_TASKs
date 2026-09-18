#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class SinglyLinkedList
{
    Node* head;
    Node* tail;

public:
    SinglyLinkedList()
    {
        head = tail = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int length()
    {
        int count = 0;
        Node* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Node* temp = head;

            head = head->next;
            temp->next = NULL;

            tail->next = temp;
            tail = temp;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Node* temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }

            temp->next = NULL;
            tail->next = head;
            head = tail;
            tail = temp;
        }
    }

    void print()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

class DoublyLinkedList
{
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = tail = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int length()
    {
        int count = 0;
        Node* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Node* temp = head;

            head = head->next;
            head->prev = NULL;

            temp->next = NULL;
            temp->prev = tail;

            tail->next = temp;
            tail = temp;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            Node* temp = tail;

            tail = tail->prev;
            tail->next = NULL;

            temp->prev = NULL;
            temp->next = head;

            head->prev = temp;
            head = temp;
        }
    }

    void print()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

class CircularLinkedList
{
    Node* head;
    Node* tail;

public:
    CircularLinkedList()
    {
        head = tail = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    int length()
    {
        if (head == NULL)
            return 0;

        int count = 0;
        Node* temp = head;

        do
        {
            count++;
            temp = temp->next;
        }
        while (temp != head);

        return count;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            head = head->next;
            tail = tail->next;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            tail = head;

            while (tail->next != head)
            {
                tail = tail->next;
            }

            head = tail;
        }
    }

    void print()
    {
        if (head == NULL)
            return;

        Node* temp = head;

        do
        {
            cout << temp->data;

            temp = temp->next;

            if (temp != head)
                cout << " -> ";
        }
        while (temp != head);

        cout << " -> HEAD" << endl;
    }
};

class DoublyCircularLinkedList
{
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList()
    {
        head = tail = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;

            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->prev = tail;
            newNode->next = head;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }
    }

    int length()
    {
        if (head == NULL)
            return 0;

        int count = 0;
        Node* temp = head;

        do
        {
            count++;
            temp = temp->next;
        }
        while (temp != head);

        return count;
    }

    void rotateLeft(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            head = head->next;
            tail = tail->next;
        }
    }

    void rotateRight(int k)
    {
        int n = length();

        if (n == 0)
            return;

        k = k % n;

        for (int i = 0; i < k; i++)
        {
            tail = tail->prev;
            head = head->prev;
        }
    }

    void print()
    {
        if (head == NULL)
            return;

        Node* temp = head;

        do
        {
            cout << temp->data;

            temp = temp->next;

            if (temp != head)
                cout << " <-> ";
        }
        while (temp != head);

        cout << " <-> HEAD" << endl;
    }
};

int main()
{
    int choice;
    int n;
    int k;
    char direction;

    cout << "1. Singly Linked List" << endl;
    cout << "2. Doubly Linked List" << endl;
    cout << "3. Circular Linked List" << endl;
    cout << "4. Doubly Circular Linked List" << endl;

    cout << "Enter list type: ";
    cin >> choice;

    cout << "Enter number of elements: ";
    cin >> n;

    if (choice == 1)
    {
        SinglyLinkedList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> direction;

        if (direction == 'L' || direction == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else if (choice == 2)
    {
        DoublyLinkedList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> direction;

        if (direction == 'L' || direction == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else if (choice == 3)
    {
        CircularLinkedList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> direction;

        if (direction == 'L' || direction == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else if (choice == 4)
    {
        DoublyCircularLinkedList list;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            list.insert(value);
        }

        cout << "Enter K: ";
        cin >> k;

        cout << "Enter direction (L/R): ";
        cin >> direction;

        if (direction == 'L' || direction == 'l')
            list.rotateLeft(k);
        else
            list.rotateRight(k);

        cout << "Result: ";
        list.print();
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
