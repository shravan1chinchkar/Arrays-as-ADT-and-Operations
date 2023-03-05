#include<iostream>
using namespace std;
int data,count=0;
struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};
class Doubly_Linked_List
{
    public:
    struct Node *create_Doubly_LL(int n)
    {
        struct Node *head = new struct Node;
        struct Node *ptr;
        int nodeCount = 1;
        cout << "Enter data in " << count << "th node :" << endl;
        cin >> data;
        head->prev = NULL;
        head->data = data;
        head->next = NULL;
        ptr = head;
        count++;
        for (nodeCount = 2; nodeCount <= n; nodeCount++)
        {
            struct Node *newNode = new struct Node;
            cout << "Enter data in " << count << "th node :" << endl;
            cin >> data;
            newNode->prev = ptr;
            newNode->data = data;
            newNode->next = NULL;
            ptr->next = newNode;
            ptr = ptr->next;
            count++;
        }
        return head;
    }
    void display_Doubly_LL_In_FordwardDir(struct Node *head)
    {
        struct Node *ptr = head;
        int nodeIndex = 0;
        cout << endl;
        while (ptr != NULL)
        {
            cout << "Address of its previous node is: " << ptr->prev << endl;
            cout << "Element of " << nodeIndex << "th node is :" << ptr->data << endl;
            cout << "Address of its successive node is: " << ptr->next << endl;
            cout << "Address of the present node is: " << ptr << endl;
            nodeIndex++;
            ptr = ptr->next;
            cout << endl;
        }
    }
    void display_Doubly_LL_In_ReverseDir(struct Node *head)
    {
        struct Node *ptr = head;
        int nodeIndex = 0;
        while (ptr->next != NULL)
        {
            ptr = ptr->next; // At the end ptr will point to the last node
        }
        cout << endl;
        while (ptr != NULL)
        {
            cout << "Address of its previous node is: " << ptr->prev << endl;
            cout << "Element of " << nodeIndex << "th node is :" << ptr->data << endl;
            cout << "Address of its successive node is: " << ptr->next << endl;
            cout << "Address of the present node is: " << ptr << endl;
            nodeIndex++;
            ptr = ptr->prev;
            cout << endl;
        }
    }
    struct Node *delete_Beginning_Node(struct Node *head)
    {
        if(head==NULL)
        {
            cout<<"Linked List UnderFlow"<<endl;
            return head;
        }
        struct Node *ptr=head;
        head=head->next;
        head->prev=NULL;
        delete ptr;
        //display_Doubly_LL_In_FordwardDir(head);
        return head;
    }
    struct Node *delete_Between_Node(struct Node *head)
    {
        struct Node *ptr=head;
        struct Node *p=head->next;
        struct Node *p1;
        int index;
        cout<<"Enter index of node which is to be inserted :"<<endl;
        cin>>index;
        if(index==1)
        {
            p1=p;
            p1=p1->next;//this pointer will be one node ahed of deletion node
            ptr->next=p->next;
            p1->prev=ptr;
            delete p;
            return head;
        }
        int i=1;
        while(i<index)
        {
            ptr=ptr->next;
            p=p->next;
            i++;
        }
        p1=p;
        p1=p1->next;
        ptr->next=p1;
        p1->prev=ptr;
        delete p;
        return head;
    }
    struct Node *delete_end_node(struct Node *head)
    {
        struct Node *ptr=head;
        struct Node *p=head->next;
        while(p->next!=NULL)
        {
            ptr=ptr->next;
            p=p->next;
        }
        ptr->next=NULL;
        delete p;
        return head;
    }
    struct Node *delete_node_of_data(struct Node *head)
    {
        struct Node *ptr=head;
        struct Node *p=head->next;
        struct Node *p1;
        cout<<"Enter data of node which is to be deleted:"<<endl;
        cin>>data;
        if(ptr->data==data)//if data is present in head node
        {
            head=head->next;
            head->prev=NULL;
            delete ptr;
            display_Doubly_LL_In_FordwardDir(head);
            return head;
        }
        while(p->data!=data && p->next!=NULL)
        {
            ptr=ptr->next;
            p=p->next;
        }
        if(p->data!=data)
        {
            cout<<"Data not present in the Linked List"<<endl;
            return head;
        }
        else if(p->data==data && p->next!=NULL)
        {
            p1=p;
            p1=p1->next;
            ptr->next=p1;
            p1->prev=ptr;
            delete p;
            display_Doubly_LL_In_FordwardDir(head);
            return head;
        }
        else if(p->data==data && p->next==NULL)
        {
            ptr->next=NULL;
            delete p;
            display_Doubly_LL_In_FordwardDir(head);
            return head;
        }
    }

};
int main(){
    int n, ch;
    cout << "Enter Number of nodes you want in a Doubly linked list:" << endl;
    cin >> n;
    struct Node *head;
    Doubly_Linked_List dll;
    if (n == 0)
    {
        cout << "Please enter number of nodes greater than 0" << endl;
        return 0;
    }
    else
    {
        head = dll.create_Doubly_LL(n);
    }
    while (true)
    {
        cout << "**********************MENU******************" << endl;
        cout << "1:To display Doubly Linked List in fordward direction " << endl;
        cout << "2:To display Doubly Linked List in reverse direction " << endl;
        cout << "3:To delete node in beginning " << endl;
        cout << "4:To delete node in between " << endl;
        cout << "5:To delete node at the end " << endl;
        cout << "6:To delete node of specified data " << endl;
        cout << "7:Exit" << endl;
        cout << "**********************MENU_Ends******************" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            dll.display_Doubly_LL_In_FordwardDir(head);
            break;
        case 2:
            dll.display_Doubly_LL_In_ReverseDir(head);
            break;
        case 3:
            head=dll.delete_Beginning_Node(head);
            dll.display_Doubly_LL_In_FordwardDir(head);
            break;
        case 4:
            head=dll.delete_Between_Node(head);
            dll.display_Doubly_LL_In_FordwardDir(head);
            break;
        case 5:
            head=dll.delete_end_node(head);
            dll.display_Doubly_LL_In_FordwardDir(head);
            break;
        case 6:
            head=dll.delete_node_of_data(head);
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Please enter correct choice" << endl;
            break;
        }
    }    
    return 0;
}