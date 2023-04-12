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
        /*
        while(ptr!=a)
        {
            cout<<"Element in "<<count<<"th node is: "<<ptr->data<<endl;
            cout<<"Address of the successive node is: "<<ptr->next<<endl;
            cout<<"Address of current node is: "<<ptr<<endl;
            cout<<endl;
            count++;
            ptr=ptr->next;
        }
        The above code will not print anything because the while condition is not true so we use do while loop
        */
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
    struct Node *insert_at_beginning(struct Node *head)
    {
        struct Node *ptr = new struct Node;
        struct Node *p = head->next;
        cout << "Enter data to be inserted in 1st the node: " << endl;
        cin >> data;
        ptr->data = data;
        while (p->next != head)
        {
            p = p->next;
        }
        // at this point p points to the last node of a Ll
        p->next = ptr;    // At this point p point to the newly created node
        ptr->next = head; // At this point ptr points to the old head node.
        head = ptr;       // At this point new head node is created
        return head;
    }
    struct Node *insert_in_between(struct Node *head)
    {
        int index;
        cout << "Enter index where you want to insert the node: " << endl;
        cin >> index;
        struct Node *ptr = new struct Node;
        struct Node *p = head;
        cout << "Enter data to be inserted in " << index << "th node: " << endl;
        cin >> data;
        ptr->data = data;
        int i = 1;
        while (i < index)
        {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
        return head;
    }
    struct Node *insert_at_end(struct Node *head)
    {
        struct Node *ptr = new struct Node;
        struct Node *p = head;
        cout << "Enter data to be insertrd in the node :" << endl;
        cin >> data;
        ptr->data = data;
        while (p->next != head)
        {
            p = p->next;
        }
        // at this point p will point to the old last node
        p->next = ptr;    // at this point p will point to the new last node
        ptr->next = head; // at this point ptr will become new last node
        return head;
    }
    struct Node *insert_after_specific_node(struct Node *head)
    {
        struct Node *ptr;
        cout << "Enter data to be inserted in the node: " << endl;
        cin >> data;
        ptr->data = data;
        ptr->next = head->next;
        head->next = ptr;
        return head;
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
        cout << "1: For Inserting node at starting of Circular Linked List " << endl;
        cout << "2: For Inserting node in between of Circular Linked List " << endl;
        cout << "3: For Inserting node at ending of Circular Linked List " << endl;
        cout << "4: For Inserting node after specific node of Circular Linked List " << endl;
        cout << "5: Exit" << endl;
        cout << "***************************************MENU_Ends**************************************" << endl;
        cout << "Enter Your Choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            head = cll.insert_at_beginning(head);
            cll.display_Circular_LL(head);
            break;
        case 2:
            head = cll.insert_in_between(head);
            cll.display_Circular_LL(head);
            break;
        case 3:
            head = cll.insert_at_end(head);
            cll.display_Circular_LL(head);
            break;
        case 4:
            head = cll.insert_after_specific_node(head);
            cll.display_Circular_LL(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Please enter correct Choice: " << endl;
            break;
        }
    }
    return 0;
}
