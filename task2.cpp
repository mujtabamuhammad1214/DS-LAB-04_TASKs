#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node* next;
    Node* prev;
};
class double_ll
{
private:
    Node* head;
public:
    double_ll() : head(NULL) {}
    void insertCoach( int id)
{
    Node* newNode = new Node;

    newNode->id = id;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;
}

Node* findNode( int id)
{
    if (head == NULL)
        return NULL;

    Node* current = head;

    do
    {
        if (current->id == id)
            return current;

        current = current->next;

    } while (current != head);

    return NULL;
}

    void display()
    {
        if (head == NULL)
        {
            cout << "Empty";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->id << " <-> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "HEAD";
    }



void detachNode( int id)
{
    Node* node = findNode( id);

    if (node == NULL)
    {
        cout << "Coach " << id << " not found." << endl;
        return;
    }

    if (node->next == node && node->prev == node)
    {
        head = NULL;
        return;
    }

 
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (head == node)
    {
        head = node->next;
    }

    node->next = NULL;
    node->prev = NULL;
}

void moveRight( int id)
{
    Node* node = findNode( id);

    if (node == NULL)
    {
        cout << "Coach " << id << " not found." << endl;
        return;
    }

    if (head->next == node)
        return;


    if (node == head)
        return;

    node->prev->next = node->next;
    node->next->prev = node->prev;


    Node* right = head->next;

    node->prev = head;
    node->next = right;

    head->next = node;
    right->prev = node;
}


void moveLeft(int id)
{
    Node* node = findNode( id);

    if (node == NULL)
    {
        cout << "Coach " << id << " not found." << endl;
        return;
    }

    if (head->prev == node)
        return;

    if (node == head)
        return;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    Node* left = head->prev;

    node->next = head;
    node->prev = left;

    left->next = node;
    head->prev = node;
}

void deleteCoach( int id)
{
    Node* node = findNode(id);

    if (node == NULL)
    {
        cout << "Coach " << id << " not found." << endl;
        return;
    }

    if (node->next == node)
    {
        delete node;
        head = NULL;
        return;
    }

    Node* nextNode = node->next;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node == head)
    {
        head = nextNode;
    }

    delete node;
}

void setHead( int id)
{
    Node* node = findNode(id);

    if (node == NULL)
    {
        cout << "Coach " << id << " not found." << endl;
        return;
    }

    head = node;
}



void searchCoach( int id)
{
    if (head == NULL)
    {
        cout << "Train is empty." << endl;
        return;
    }

    Node* target = findNode( id);

    if (target == NULL)
    {
        cout << "Coach " << id << " not found." << endl;
        return;
    }

   
    int nextSteps = 0;
    Node* current = head;

    while (current != target)
    {
        current = current->next;
        nextSteps++;
    }

    
    int prevSteps = 0;
    current = head;

    while (current != target)
    {
        current = current->prev;
        prevSteps++;
    }

    
    if (nextSteps <= prevSteps)
    {
        cout << "Direction: NEXT" << endl;
        cout << "Path: ";

        current = head;

        while (true)
        {
            cout << current->id;

            if (current == target)
                break;

            cout << " -> ";
            current = current->next;
        }

        cout << endl;
        cout << "Steps: " << nextSteps << endl;
    }
    else
    {
        cout << "Direction: PREV" << endl;
        cout << "Path: ";

        current = head;

        while (true)
        {
            cout << current->id;

            if (current == target)
                break;

            cout << " -> ";
            current = current->prev;
        }

        cout << endl;
        cout << "Steps: " << prevSteps << endl;
    }
}
};



int main()
{
    double_ll train;

    int n;

    cout << "Enter number of coaches: ";
    cin >> n;

    

    for (int i = 0; i < n; i++)
    {
        int id;
        cout << "Enter coach "<<i+1 <<" ID:";
        cin >> id;

        train.insertCoach( id);
    }
    train.display();
    cout<<endl;

    int commands;

    cout << "Enter number of commands: ";
    cin >> commands;

    for (int i = 0; i < commands; i++)
    {
        char command;
        int id;
        cout<<"Enter command:";
        cin>>command;
        cout<<"Enter ID:";
        cin >> id;

        if (command == 'R' || command == 'r')
        {
            train.moveRight( id);

            cout << "After R " << id << ": "<<endl;
            train.display();
            cout<<endl;
        }

        else if (command == 'L' || command == 'l')
        {
            train.moveLeft(id);

            cout << "After L " << id << ": "<<endl;
            train.display();
            cout<<endl;
        }

        else if (command == 'D'|| command == 'd')
        {
            train.deleteCoach(id);

            cout << "After D " << id << ": "<<endl;
            train.display();
            cout<<endl;
        }

        else if (command == 'S' || command == 's')
        {
            train.setHead( id);

            cout << "After S " << id << ": "<<endl;
            train.display();
            cout<<endl; 
        }

        else if (command == 'F' ||command == 'f')
        {
            cout << endl;
            cout << "F " << id << ":" << endl;

            train.searchCoach( id);
        }

        else
        {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
