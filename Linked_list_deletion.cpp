/*
Singly Linked List
In linked List there are 4 cases of deletion
1] Deletion node at begning o(1)
2] Deletion node at middle o(n)
3] Deletion node at end o(n)
4] Deletion node with the given value.(firts node with that value)o(1)
*/
#include <iostream>
using namespace std;
int data, count = 0;
struct Node
{
    int data;
    struct Node *next;
};
class Linked_list
{
public:
    // Creating nodes of the Linked list
    struct Node *createLinkedListNode(int n)
    {
        int i = 0;
        struct Node *head;
        struct Node *p; // this pointer will traverse through the linked list
        int nodeCount = 1;
        head = new struct Node;
        cout << "Enter data in " << count << "th index node:" << endl;
        cin >> data;
        head->data = data;
        head->next = NULL;
        p = head; // This implies that, now p will also point to head
        count++;
        nodeCount++;
        for (nodeCount = 2; nodeCount <= n; nodeCount++)
        {
            struct Node *newNode = new struct Node;
            if (newNode == NULL)
            {
                cout << "Memory cannot be allocated" << endl;
            }
            else
            {
                cout << "Enter data in " << count << "th index node:" << endl;
                cin >> data;
                newNode->data = data;
                newNode->next = NULL;
                p->next = newNode; // p will now link to newNode
                p = p->next;       // newNode and p will point to the same node
            }
            count++;
        }
        return head;
    }

    // displaying the linked list
    void display_Linked_list(struct Node *a)
    {
        int count = 0;
        while (a != NULL) // study why we have written a insted of a->next
        {
            cout << "Data in " << count << "th index of node is: " << a->data << endl;
            cout << "Address of its successive node is: " << a->next << endl;
            cout << "Address of " << count << "th node is: " << a << endl;
            cout << endl;
            a = a->next;
            count++;
        }
    }

    // Deleting 1st node
    struct Node *deleting_Starting_Node(struct Node *a)
    {
        struct Node *p = a;
        if (a == NULL)
        {
            cout << "Linked List under flow" << endl;
            cout << "Nothing to display because only one node was present and now that also is deleted " << endl;
            return a;
        }
        a = p->next;
        delete p;
        // return a;
        cout << "Linked List after deleting 1st node: " << endl;
        display_Linked_list(a);
        return a;
    }

    // Deleting node in between                            1
    struct Node *deleting_Between_Node(struct Node *a, int index)
    {
        struct Node *ptr1, *ptr2;
        ptr1 = a;
        int i1 = 1;
        if (a == NULL)
        {
            cout << "Linked List under flow" << endl;
            return a;
        }
        while (i1 < index)
        {
            ptr1 = ptr1->next; // Because of this while loop ptr1 will point to the node, 1 before the node which is to be deleted
            i1++;
        }
        ptr2 = ptr1->next;
        ptr1->next = ptr2->next; // ptr1 will now point to the node which ptr2 points
        delete ptr2;
        display_Linked_list(a);
        return a;
    }

    // Deleting last node;
    struct Node *deleting_last_node(struct Node *a)
    {
        struct Node *ptr1, *ptr2;
        ptr1 = a;
        ptr2 = ptr1->next;
        while (ptr2->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = NULL;
        delete ptr2;
        return a;
    }

    // Deleting node of specified data
    struct Node *deleting_Node_Of_Specified_Data(struct Node *a, int data1)
    {
        struct Node *ptr1, *ptr2;
        if (a == NULL)
        {
            cout << "Linked list underflow" << endl;
            return a;
        }
        ptr1 = a;
        ptr2 = a->next;
        if (ptr1->data == data1) // If data1 is present in the first node
        {
            a = a->next;
            delete ptr1;
            cout << "Linked list after deleting node which contain " << data1 << " Element" << endl;
            display_Linked_list(a);
            return a;
        }
        while (ptr2->data != data1 && ptr2->next != NULL) // if data1 is present in middle or end
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr2->data != data1) // if data1 is not present in the list
        {
            cout << data1 << " is not present in the list" << endl;
            return a;
        }
        else
        {
            ptr1->next = ptr2->next;
            delete ptr2;
        }
        cout << "Linked list after deleting node which contain " << data1 << " Element" << endl;
        display_Linked_list(a);
        return a;
    }
};
int main()
{
    struct Node *head;
    Linked_list ll;
    int n, ch;
    cout << "Enter number of nodes you want in the Singly Linked list :" << endl;
    cin >> n;
    if (n == 0)
    {
        cout << "Please enter number of nodes greater then 0" << endl;
        exit(0);
    }
    head = ll.createLinkedListNode(n);
    cout << "Your Linked list is: " << endl;
    ll.display_Linked_list(head);
    do
    {
        cout << "***************************************MENU*******************************************" << endl;
        cout << "1: For Deleting node at starting of Linked List " << endl;
        cout << "2: For Deleting node in between of Linked List " << endl;
        cout << "3: For Deleting node at ending of Linked List " << endl;
        cout << "4: For Deleting node of specified data " << endl;
        cout << "5: Exit" << endl;
        cout << "***************************************MENU_Ends**************************************" << endl;
        cout << "Enter Your Choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            head = ll.deleting_Starting_Node(head);
            break;
        case 2:
            int index;
            cout << "Enter the index of the node to be deleted" << endl;
            cin >> index;
            head = ll.deleting_Between_Node(head, index);
            break;
        case 3:
            head = ll.deleting_last_node(head);
            cout << "Linked List after deleting last node" << index << endl;
            ll.display_Linked_list(head);
            break;
        case 4:
            int data1;
            cout << "Please enter data of node which is to be deleted" << endl;
            cin >> data1;
            head = ll.deleting_Node_Of_Specified_Data(head, data1);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Please enter correct choice";
            break;
        }
    } while (true);
    return 0;
}
