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
        head = NULL;
        tail = NULL;
    }

    void pushBack(int val)
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

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;

            pushBack(value);
        }
    }

    void bubbleSort()
    {
        int n = length();

        for (int i = 0; i < n - 1; i++)
        {
            Node* temp = head;

            for (int j = 0; j < n - i - 1; j++)
            {
                if (temp->data > temp->next->data)
                {
                    int x = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = x;
                }

                temp = temp->next;
            }
        }
    }

    bool hasCycle()
    {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};

class DoublyLinkedList
{
    Node* head;
    Node* tail;

public:

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void pushBack(int val)
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

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;

            pushBack(value);
        }
    }

    void bubbleSort()
    {
        int n = length();

        for (int i = 0; i < n - 1; i++)
        {
            Node* temp = head;

            for (int j = 0; j < n - i - 1; j++)
            {
                if (temp->data > temp->next->data)
                {
                    int x = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = x;
                }

                temp = temp->next;
            }
        }
    }

    bool hasCycle()
    {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};

class CircularLinkedList
{
    Node* head;
    Node* tail;

public:

    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void pushBack(int val)
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

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;

            pushBack(value);
        }
    }

    void bubbleSort()
    {
        int n = length();

        if (n <= 1)
            return;

        for (int i = 0; i < n - 1; i++)
        {
            Node* temp = head;

            for (int j = 0; j < n - i - 1; j++)
            {
                Node* nextNode = temp->next;

                if (temp->data > nextNode->data)
                {
                    int x = temp->data;
                    temp->data = nextNode->data;
                    nextNode->data = x;
                }

                temp = temp->next;
            }
        }
    }

    bool hasCycle()
    {
        if (head == NULL)
            return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "Empty";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "HEAD";
    }
};

class DoublyCircularLinkedList
{
    Node* head;
    Node* tail;

public:

    DoublyCircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void pushBack(int val)
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

    void input()
    {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;

            pushBack(value);
        }
    }

    void bubbleSort()
    {
        int n = length();

        if (n <= 1)
            return;

        for (int i = 0; i < n - 1; i++)
        {
            Node* temp = head;

            for (int j = 0; j < n - i - 1; j++)
            {
                Node* nextNode = temp->next;

                if (temp->data > nextNode->data)
                {
                    int x = temp->data;
                    temp->data = nextNode->data;
                    nextNode->data = x;
                }

                temp = temp->next;
            }
        }
    }

    bool hasCycle()
    {
        if (head == NULL)
            return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "Empty";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "HEAD";
    }
};

int main()
{
    const int totalLists = 12;

    int type[totalLists];
    int count[5] = {0};

    SinglyLinkedList* singly[totalLists];
    DoublyLinkedList* doubly[totalLists];
    CircularLinkedList* circular[totalLists];
    DoublyCircularLinkedList* doublyCircular[totalLists];

    for (int i = 0; i < totalLists; i++)
    {
        singly[i] = NULL;
        doubly[i] = NULL;
        circular[i] = NULL;
        doublyCircular[i] = NULL;
    }

    cout << "Enter 12 Linked Lists" << endl;
    cout << "Each type must occur at least 3 times." << endl;
    cout << "Two consecutive lists cannot have the same type." << endl;

    for (int i = 0; i < totalLists; i++)
    {
        cout << endl;
        cout << "Position " << i + 1 << endl;
        cout << "1. Singly" << endl;
        cout << "2. Doubly" << endl;
        cout << "3. Circular" << endl;
        cout << "4. Doubly Circular" << endl;

        while (true)
        {
            cout << "Enter type: ";
            cin >> type[i];

            if (type[i] < 1 || type[i] > 4)
            {
                cout << "Invalid type." << endl;
                continue;
            }

            if (i > 0 && type[i] == type[i - 1])
            {
                cout << "Same type cannot come consecutively." << endl;
                continue;
            }

            break;
        }

        count[type[i]]++;

        if (type[i] == 1)
        {
            singly[i] = new SinglyLinkedList();
            singly[i]->input();
        }
        else if (type[i] == 2)
        {
            doubly[i] = new DoublyLinkedList();
            doubly[i]->input();
        }
        else if (type[i] == 3)
        {
            circular[i] = new CircularLinkedList();
            circular[i]->input();
        }
        else
        {
            doublyCircular[i] = new DoublyCircularLinkedList();
            doublyCircular[i]->input();
        }
    }

    if (count[1] < 3 || count[2] < 3 ||
        count[3] < 3 || count[4] < 3)
    {
        cout << endl;
        cout << "Invalid input." << endl;
        cout << "Every type must occur at least 3 times." << endl;

        return 0;
    }

    for (int i = 0; i < totalLists; i++)
    {
        if (type[i] == 1)
            singly[i]->bubbleSort();

        else if (type[i] == 2)
            doubly[i]->bubbleSort();

        else if (type[i] == 3)
            circular[i]->bubbleSort();

        else
            doublyCircular[i]->bubbleSort();
    }

    cout << endl;
    cout << "Sorted Lists" << endl;

    for (int i = 0; i < totalLists; i++)
    {
        cout << "Position " << i + 1 << ": ";

        if (type[i] == 1)
            singly[i]->print();

        else if (type[i] == 2)
            doubly[i]->print();

        else if (type[i] == 3)
            circular[i]->print();

        else
            doublyCircular[i]->print();

        cout << endl;
    }

    int cycleCount = 0;

    cout << endl;
    cout << "Cycle Detection" << endl;

    for (int i = 0; i < totalLists; i++)
    {
        bool cycle = false;

        if (type[i] == 1)
            cycle = singly[i]->hasCycle();

        else if (type[i] == 2)
            cycle = doubly[i]->hasCycle();

        else if (type[i] == 3)
            cycle = circular[i]->hasCycle();

        else
            cycle = doublyCircular[i]->hasCycle();

        cout << "Position " << i + 1 << ": ";

        if (cycle)
        {
            cout << "Cycle Found";
            cycleCount++;
        }
        else
        {
            cout << "No Cycle";
        }

        cout << endl;
    }

    cout << endl;
    cout << "Total Number of Cycles: "
         << cycleCount << endl;

    cout << endl;
    cout << "Final Resultant Lists" << endl;

    for (int i = 0; i < totalLists; i++)
    {
        cout << "Position " << i + 1 << ": ";

        if (type[i] == 1)
            singly[i]->print();

        else if (type[i] == 2)
            doubly[i]->print();

        else if (type[i] == 3)
            circular[i]->print();

        else
            doublyCircular[i]->print();

        cout << endl;
    }

    return 0;
}
