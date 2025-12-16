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
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *insertAtMiddle(int number)
{
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
                cout << "Enter number: ";
                cin >> number;
                insertAtMiddle(number);
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
        }
        else if (ch == 3)
        {
            cout << "\nLinked List: ";
            displayPrint(head);
        }
        else if (ch == 4)
        {
        }
        else
            cout << "Enter between 1-4";
    }
    cout << "\nSuccessfully Done\n";
}
