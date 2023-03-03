#include<iostream>
using namespace std;
//singly linked list
//Linked List dynamic creation and display
int count = 0,data;
struct Node
{
    int data;
    struct Node *next;
};
class Linked_List
{
    public:
    //Creating node dynamically by excepting information about Linked List from user  
    struct Node *createLinkedlist(struct Node *a, int n)
    {
        struct Node *head1;       // start node
        struct Node *headAddress; // pointer that moves throughout the Linked List
        int nodeCount = 1;
        //int data;
        head1 = new struct Node;
        cout << "Enter data in " << count << "th node" << endl;
        cin >> data;
        head1->data = data;
        head1->next = NULL;
        nodeCount++;
        headAddress = head1;
        count++;
        // here nodecount=2 because a linked list one node as declared above
        for (nodeCount = 2; nodeCount <= n; nodeCount++)
        {
            struct Node *nextNode = new struct Node;
            if (nextNode == NULL)
            {
                cout << "Memory cannot be allocated" << endl;
            }
            else
            {
                cout << "Enter data in " << count << "th node" << endl;
                cin >> data;
                nextNode->data = data;
                nextNode->next = NULL;
                headAddress->next = nextNode;
                headAddress = headAddress->next; // It means nextNode and headAddress are at same location
            }
            count++;
        }
        return head1;
    }
    void display_Linked_List(struct Node *a)
    {
        int counter = 0;
        while(a!=NULL)
        {
            cout<<endl;
            cout << "Element :" << a->data << endl;
            cout << "Address of its successive node :" << a->next << endl;
            cout << "Address of present " << counter << "th node is:" << a << endl;
            cout << endl;
            a = a->next;
            counter++;
        }

    }
};
int main(){
    struct Node *head;
    Linked_List ll;
    int n;
    cout << "Enter Number of nodes you want in the Linked List" << endl;
    cin >> n;
    head=ll.createLinkedlist(head,n);
    ll.display_Linked_List(head);

    return 0;
}