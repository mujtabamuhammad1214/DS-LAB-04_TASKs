#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node* head;
    Node* tail;

public:

    LinkedList()
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

    void reverseGroups(int k)
    {
        if (k <= 1 || head == NULL)
            return;

        int total = length();

        Node* current = head;
        Node* previousGroupEnd = NULL;

        while (current != NULL)
        {
            Node* check = current;
            int count = 0;

            while (check != NULL && count < k)
            {
                check = check->next;
                count++;
            }

            if (count < k)
                break;

            Node* groupStart = current;
            Node* previous = NULL;
            Node* next = NULL;

            for (int i = 0; i < k; i++)
            {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }

            if (previousGroupEnd == NULL)
            {
                head = previous;
            }
            else
            {
                previousGroupEnd->next = previous;
            }

            previousGroupEnd = groupStart;
            previousGroupEnd->next = current;
        }

        tail = head;

        while (tail != NULL && tail->next != NULL)
        {
            tail = tail->next;
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

int main()
{
    LinkedList list;

    int n;
    int k;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;

        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        list.insert(value);
    }

    cout << "Enter K: ";
    cin >> k;

    cout << "Original List: ";
    list.print();

    list.reverseGroups(k);

    cout << "After Reversing Groups: ";
    list.print();

    return 0;
}
