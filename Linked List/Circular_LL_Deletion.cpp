#include <iostream>
using namespace std;
int data, count = 0;
struct Node
{
    int data;
    struct Node *next;
};
class Circular_Linked_List
{
public:
    struct Node *create_Circular_LL(int n)
    {
        struct Node *head;
        struct Node *ptr;
        int nodeCount = 1;
        head = new struct Node;
        if (head == NULL)
        {
            cout << "Memory not allocated" << endl;
        }
        else
        {
            cout << "Enter data in " << count << "th node:" << endl;
            cin >> data;
            head->data = data;
            head->next = NULL;
            ptr = head;
            count++;
            nodeCount++;
        }
        for (nodeCount = 2; nodeCount <= n; nodeCount++)
        {
            struct Node *newNode = new struct Node;
            if (newNode == NULL)
            {
                cout << "Memory Cannot be allocated to newNode" << endl;
            }
            else
            {
                cout << "Enter data in " << count << "th node:" << endl;
                cin >> data;
                newNode->data = data;
                newNode->next = head;
                ptr->next = newNode;
                ptr = ptr->next;
            }
            count++;
        }
        return head;
    }
    void display_Circular_LL(struct Node *a)
    {
        struct Node *ptr = a;
        int count = 0;
        do
        {
            cout << "Element in " << count << "th node is: " << ptr->data << endl;
            cout << "Address of the successive node is: " << ptr->next << endl;
            cout << "Address of current node is: " << ptr << endl;
            cout << endl;
            count++;
            ptr = ptr->next;
        } while (ptr != a); // print until address of ptr and a becomes same
    }
    struct Node *delete_beginning(struct Node *head)
    {
        struct Node *ptr, *p;
        ptr = head;
        p = head->next;
        if (head == NULL)
        {
            cout << "Linked List underFlow :";
            return head;
        }
        while (p->next != head)
        {
            p = p->next;
        }
        head = ptr->next;
        p->next = head;
        delete ptr;
        display_Circular_LL(head);
        return head;
    }
    struct Node *deleting_Between_node(struct Node *head)
    {
        int index;
        cout << "Enter index of node to be deleted: " << endl;
        cin >> index;
        struct Node *ptr = head;
        struct Node *p = head->next;
        if (index == 1)
        {
            ptr->next = p->next;
            delete p;
            return head;
        }
        int i = 1;
        while (i < index)
        {
            ptr = ptr->next;
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        delete p;
        return head;
    }
    struct Node *delete_Last_Node(struct Node *head)
    {
        struct Node *ptr = head;
        struct Node *p = head->next;
        while (p->next != head)
        {
            ptr = ptr->next;
            p = p->next;
        }
        ptr->next = head;
        delete p;
        return head;
    }
    struct Node *delete_Node_of_data(struct Node *head)
    {
        struct Node *ptr = head;
        struct Node *p1 = head->next;
        struct Node *p2 = head->next;
        cout << "Enter the data of node which is to be deleted: " << endl;
        cin >> data;
        while (p2->next != head)
        {
            p2 = p2->next; // At the end of loop p2 will point to the last node;
        }
        if (ptr->data == data) // if data is present in 1st node
        {
            head = ptr->next;
            p2->next = head; // last node will link to the new head;
            delete ptr;
            display_Circular_LL(head);
            return head;
        }
        while (p1->data != data && p1->next != head) // if data is present in between or last of the node
        {
            ptr = ptr->next;
            p1 = p1->next;
        }
        if (p1->data != data)
        {
            cout << "Data is not present in the Linked List" << endl;
            return head;
        }
        else
        {
            ptr->next = p1->next;
            delete p1;
            display_Circular_LL(head);
        }
    }
};
int main()
{
    Circular_Linked_List cll;
    struct Node *head;
    int n, ch;
    cout << "Enter Number of nodes you want in a Circular linked list:" << endl;
    cin >> n;
    if (n == 0)
    {
        cout << "Plz enter number gerater than 0" << endl;
    }
    else
    {
        head = cll.create_Circular_LL(n);
        cll.display_Circular_LL(head);
    }
    while (true)
    {
        cout << "***************************************MENU*******************************************" << endl;
        cout << "1: For Deleting node at starting of Circular Linked List " << endl;
        cout << "2: For Deleting node in between of Circular Linked List " << endl;
        cout << "3: For Deleting node at ending of Circuler Linked List " << endl;
        cout << "4: For Deleting node of specified data in Circular Linked List " << endl;
        cout << "5: Exit" << endl;
        cout << "***************************************MENU_Ends**************************************" << endl;
        cout << "Enter Your Choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            head = cll.delete_beginning(head);
            break;
        case 2:
            head = cll.deleting_Between_node(head);
            cll.display_Circular_LL(head);
            break;
        case 3:
            head = cll.delete_Last_Node(head);
            cll.display_Circular_LL(head);
            break;
        case 4:
            head = cll.delete_Node_of_data(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Please Enter correct choice" << endl;
            break;
        }
    }
    return 0;
}