#include <iostream>
using namespace std;
/*Doubly Linked List:-means we can traverse in both the direction
 Insertion and Traversing
*/
int data, count = 0;
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
    struct Node *insert_In_Beginning(struct Node *head)
    {
        struct Node *ptr = new struct Node;
        cout << "Enter data in the new node: " << endl;
        cin >> data;
        ptr->prev = NULL;
        ptr->data = data;
        ptr->next = head;
        head->prev = ptr;
        head = head->prev;
        return head;
    }
    struct Node *insert_In_between(struct Node *head)
    {
        struct Node *ptr = new struct Node;
        struct Node *p = head;
        int index;
        cout << "Enter index where the node is to be inserted :" << endl;
        cin >> index;
        cout << "Enter data in " << index << "th node: " << endl;
        cin >> data;
        ptr->data = data;
        if (index == 1)
        {
            ptr->prev = p;
            ptr->next = p->next;
            p->next = ptr;
            display_Doubly_LL_In_FordwardDir(head);
            return head;
        }
        int i = 1;
        while (i < index)
        {
            p = p->next; // at end p will point one node before the index where the new node is to inserted
            i++;
        }
        ptr->prev = p;
        ptr->next = p->next;
        p->next = ptr;
        display_Doubly_LL_In_FordwardDir(head);
        return head;
    }
    struct Node *insert_In_end(struct Node *head)
    {
        struct Node *ptr = new struct Node;
        struct Node *p = head;
        cout << "Enter data of new node: " << endl;
        cin >> data;
        ptr->data = data;
        while (p->next != NULL)
        {
            p = p->next;
        }
        ptr->prev = p;
        ptr->next = NULL;
        p->next = ptr;
        return head;
    }
    struct Node *insert_after_specified_node(struct Node *head)
    {
        struct Node *ptr = new struct Node;
        cout << "Enter data in the new node: " << endl;
        cin >> data;
        ptr->prev = head;
        ptr->data = data;
        ptr->next = head->next;
        head->next = ptr;
        return head;
    }
};
int main()
{
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
        cout << "3:To insert node in beginning " << endl;
        cout << "4:To insert node in between " << endl;
        cout << "5:To insert node at the end " << endl;
        cout << "6:To insert node after specified node " << endl;
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
            head = dll.insert_In_Beginning(head);
            dll.display_Doubly_LL_In_FordwardDir(head);
            break;
        case 4:
            dll.insert_In_between(head);
            break;
        case 5:
            head = dll.insert_In_end(head);
            dll.display_Doubly_LL_In_FordwardDir(head);
            break;
        case 6:
            dll.insert_after_specified_node(head);
            dll.display_Doubly_LL_In_FordwardDir(head);
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