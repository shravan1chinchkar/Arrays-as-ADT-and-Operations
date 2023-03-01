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
        ptr1 = a;
        ptr2 = a->next;
        if (ptr1->data == data1) // If data1 is present in the first node
        {
            a = a->next;
            delete ptr1;
        }
        while (ptr2->data != data1 && ptr2->next != NULL) // if data1 is present in middle or end
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr2->data != data1) // if data1 is not present in the list
        {
            cout << data1 << " is not present in the list" << endl;
        }
        else
        {
            ptr1->next = ptr2->next;
            delete ptr2;
        }
        return a;
    }  
};
int main()
{
    struct Node *head;
    Linked_list ll;
    int n, ch;
    cout << "Enter number of nodes you want in the Linked list :" << endl;
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