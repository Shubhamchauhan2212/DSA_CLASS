#include <iostream>
using namespace std;

class Node
{
public:
    int data;   // Store element
    Node *next; // Store address

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *insertAtFront(Node *head, int number)
{
    Node *newNode = new Node(number);
    newNode->next = head;
    return newNode;
}

Node *insertAtEnd(Node *head, int number)
{
    Node *newNode = new Node(number);
    if (head == nullptr)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *insertAtMiddle(Node *head, int number, int loc)
{
    Node *newNode = new Node(number);
    if (loc == 0)
    {
        newNode->next = head;
        return newNode;
    }
    if (head == nullptr)
        return newNode;
    Node *temp = head;
    int k = 0;
    while (k < loc - 1 && temp != NULL)
    {
        temp = temp->next;
        k++;
    }

    if (temp == NULL)
    {
        cout << "\nLocation is invalid";
        delete newNode;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node *deleteAtFront(Node *head)
{
    if (head == nullptr)
    {
        cout << "\nLinked list is EMPTY";
        return head;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    cout << temp->data << " is deleted successfully";
    delete temp;
    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (head == nullptr)
    {
        cout << "\nLinked list is EMPTY";
        return head;
    }
    Node *temp = head;
    Node *curr = head;
    while (temp->next != NULL)
    {
        curr = temp;
        temp = temp->next;
    }
    cout << temp->data << " is deleted successfully";
    curr->next = NULL;
    delete temp;
    return head;
}

Node *deleteAtMiddle(Node *head, int loc)
{
    if (head == nullptr)
    {
        cout << "\nLinked list is EMPTY";
        return head;
    }
    if (loc == 0)
    {
        Node *temp = head;
        head = head->next;
        cout << temp->data << " is deleted successfully\n";
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *curr = head;
    int k = 0;
    while (k < loc && temp != nullptr)
    {
        curr = temp;
        temp = temp->next;
        k++;
    }
    if (temp == nullptr)
    {
        cout << "\nInvalid location";
        return head;
    }
    cout << temp->data << " is deleted successfully";
    curr->next = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}

void displayPrint(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        int num = curr->data;
        cout << num << " -> ";
        curr = curr->next;
    }
    cout << "NULL";
}

void searchFun(Node *head, int number)
{
    Node *curr = head;
    int index = 0;
    while (curr != NULL)
    {
        if (curr->data == number)
        {
            cout << "Availabe on: " << index << "th index";
            return;
        }
        curr = curr->next;
        index++;
    }
    if (curr == NULL)
    {
        cout << "\nNumber is not available";
    }
}

int main()
{
    Node *head = nullptr;
    cout << "\nEnter your choice";
    while (1)
    {
        int ch, number;
        cout << "\n\n0. BREAK\n1. Insertion\n2. Deletion\n3. Display(Print)\n4. Seach\nEnter here: ";
        cin >> ch;
        if (ch == 0)
            break;
        else if (ch == 1)
        {
            int ch1;
            cout << "\n1.Insertion At Front\n2.Insertion At Middle\n3.Insertion At End\nEnter here: ";
            cin >> ch1;
            if (ch1 == 1)
            {
                cout << "Enter number: ";
                cin >> number;
                head = insertAtFront(head, number);
            }
            else if (ch1 == 2)
            {
                int loc;
                cout << "Enter number: ";
                cin >> number;
                cout << "Enter location: ";
                cin >> loc;
                head = insertAtMiddle(head, number, loc);
            }
            else if (ch1 == 3)
            {
                cout << "Enter number: ";
                cin >> number;
                head = insertAtEnd(head, number);
            }
            else
                cout << "Enter between 1-3";
        }
        else if (ch == 2)
        {
            int ch2;
            cout << "\n1.Deletion At Front\n2.Deletion At Middle\n3.Deletion At End\nEnter here: ";
            cin >> ch2;
            if (ch2 == 1)
            {
                head = deleteAtFront(head);
            }
            else if (ch2 == 2)
            {
                int loc;
                cout << "Enter location: ";
                cin >> loc;
                head = deleteAtMiddle(head, loc);
            }
            else if (ch2 == 3)
            {
                head = deleteAtEnd(head);
            }
            else
                cout << "Enter between 1-3";
        }
        else if (ch == 3)
        {
            cout << "\nLinked List: ";
            displayPrint(head);
        }
        else if (ch == 4)
        {
            int number;
            cout << "\nWhich number you wanna search: ";
            cin >> number;
            searchFun(head, number);
        }
        else
            cout << "Enter between 1-4";
    }
    cout << "\nSuccessfully Done\n";
}