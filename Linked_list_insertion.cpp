/*
In linked List there are 4 cases of insertion
1] Inserting node at begning o(1)
2] Inserting node at middle o(n)
3] Inserting node at end o(n)
4] Inserting node after a specific node.(Here address of the node is already givn) o(1)
*/
#include <iostream>
using namespace std;
int count = 0,data;
struct Node
{
    int data;
    struct Node *next;
};
class Linked_list
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
    //  Insert Node at the begning
    struct Node *insert_in_Beginning(struct Node *a)
    {
        //int data;
        struct Node *newNode = new struct Node; // allocates memory in heap section
        cout << "Enter data to be inserted in node: " << endl;
        cin >> data;
        newNode->data = data;
        newNode->next = a;
        return newNode;
    }
    // insert in between
    struct Node *insert_in_Between(struct Node *a)
    {
        //int data;
        int i=0,index;
        struct Node *newNode = new struct Node;
        struct Node *p = a;
        cout<<"Enter index where the data is to be inserted :"<<endl;
        cin>>index;
        cout << "Enter data in node at" << index << "th index: " << endl;
        cin >> data;
        newNode->data = data;
        while (i < index-1)//index-1 because our node index starts from 0 not from 1
        {
            p = p->next;
            i++;
        }
        newNode->next = p->next;
        p->next = newNode;
        return a;
    }
    //insert at the end
    struct Node *insert_in_end(struct Node *a)
    {
        //int data;
        struct Node *newNode=new struct Node;
        struct Node *p=a;
        cout<<"Enter data to be inserted in the node :"<<endl;
        cin>>data;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        newNode->data=data;
        newNode->next=NULL;
        p->next=newNode;
        return a;
    }
    //Inserting node after specific node
    struct Node *insertion_After_Node(struct Node *a)
    {
        //int data;
        struct Node *newNode=new struct Node;
        cout<<"Enter data to be inserted in the node: "<<endl;
        cin>>data;
        newNode->data=data;
        newNode->next=a->next;
        a->next=newNode;
        return a;
    }
    // Prints the linked List
    void display_Linked_List(struct Node *a)
    {
        int counter = 0;
        while (a != NULL)
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

int main()
{
    // Created object for Structure
    struct Node *head;
    // Created object of class
    Linked_list ll;
    int n, ch1;
    cout << "Enter Number of nodes you want in the Linked List" << endl;
    cin >> n;
    head = ll.createLinkedlist(head, n);
    ll.display_Linked_List(head);
    do
    {
        cout << "***************************************MENU*******************************************" << endl;
        cout << "1: For Inserting node at starting of Linked List " << endl;
        cout << "2: For Inserting node in between of Linked List " << endl;
        cout << "3: For Inserting node at ending of Linked List " << endl;
        cout << "4: For Inserting node after specific node of Linked List " << endl;
        cout << "5: Exit" << endl;
        cout << "***************************************MENU_Ends**************************************" << endl;
        cout << "Enter Your Choice" << endl;
        cin >> ch1;

            switch (ch1)
            {
            case 1:
                head = ll.insert_in_Beginning(head);
                ll.display_Linked_List(head);
                break;
            case 2:
                head = ll.insert_in_Between(head);
                ll.display_Linked_List(head);
                break;
            case 3:
                head=ll.insert_in_end(head);
                ll.display_Linked_List(head);
                break;
            case 4:
                head=ll.insertion_After_Node(head);
                ll.display_Linked_List(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Please enter correct choice:"<<endl;
                break;
            }
    }while(true);

    return 0;
}
