#include <iostream>
using namespace std;
// queue using Linked List
// isfull condition is abstracted here

class Node
{
    int data1;
    int nodecount = 1;
    int data;
    Node *next;
    Node *front=NULL;
    Node *rear=NULL;

public:
    int isEmpty()
    {
        if (front==NULL && rear==NULL)
        {
            return 1;
        }
        return 0;
    }

    void enqueue()
    {
        Node *newNode=new Node;
        if(newNode==NULL)
        {
            cout<<"Queue overflow"<<endl;
        }
        else
        {
            cout<<"Enter data: ";
            cin>>data1;
            newNode->data=data1;
            newNode->next=NULL;
            if(front==NULL && rear==NULL)
            {
                front=rear=newNode;
            }
            else
            {
                rear->next=newNode;
                rear=newNode;
            }
        }
    }
    
    void dequeue()
    {
        if(isEmpty()==1)
        {
            cout<<"Queue underflow"<<endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            cout<<"dequeued: "<<temp->data<<endl;
            delete temp;
        }
    }

    void display_queue()
    {
        if ((isEmpty()==1) || (front==NULL))
        {
            cout << "Queue empty" << endl;
        }
        else
        {
            Node *temp1 = front;
            while (temp1 != NULL)
            {
                cout << "Element:" << temp1->data << endl;
                temp1 = temp1->next;
            }
        } 
    }
};

int main()
{
    Node n;
    int ch, a;
    while (true)
    {
        cout << "*************************MENU***********************" << endl;
        cout << "Enter 1 to enqueue" << endl;
        cout << "Enter 2 to dequeue" << endl;
        cout << "Enter 3 to display queue" << endl;
        cout << "Enter 4 to check queue is empty or not" << endl;
        cout << "Enter 5 to exit" << endl;
        cout << "*************************MENU***********************" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            n.enqueue();
            break;
        case 2:
            n.dequeue();
            break;
        case 3:
            n.display_queue();
            break;
        case 4:
            a = n.isEmpty();
            cout << a << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Please enter correct choice" << endl;
            break;
        }
    }
    return 0;
}