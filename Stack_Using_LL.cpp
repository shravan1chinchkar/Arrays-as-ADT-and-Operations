#include<iostream>
using namespace std;
/*
Stack using Linked List.
here very new Node is inserted at the beginning of th LL because here 
insertion and deletion i.e push and pop operation can be performed in o(1)
*/
class Node
{
    public:
    int data;
    Node *next;
};
int isEmpty(Node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(Node *top)//if we cant allocate memory dynamically then it is full
{
   Node *newNode1=new Node;
    if(newNode1==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Node *push(Node *top)//inserting node at beginning.
{
    if(isFull(top))
    {
        cout<<"Stack Overflow"<<endl;
        return top;
    }
    int data;
    cout<<"push data in the stack"<<endl;
    cin>>data;
    Node *newNode=new Node;
    newNode->data=data;
    newNode->next=top;
    top=newNode;
    return top;
}
Node *pop(Node *top)
{
    if(isEmpty(top))
    {
        cout<<"Stack UnderFlow"<<endl;
        return top;
    }
    else
    {
        Node *ptr=top;
        int ans =ptr->data;
        cout<<"poped :"<<ans<<endl;
        top=top->next;
        delete ptr;
    }
    return top;
}
Node *peek(Node *top)//return the top most element
{
    if(isEmpty(top))
    {
        cout<<"Stack Underflow";
        return top;
    }
    else{
        cout<<"Current topmost element is: "<<top->data<<endl;    
    }
}
void return_element(Node *top)
{
    Node *ptr=top;
    int pos;
    cout<<"Enter position of element you want :"<<endl;
    cin>>pos;
    for(int i=1;(i<pos && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        cout<<"Invalid index"<<endl;
        return;
    }
    cout<<"Element at position "<<pos<<" is :"<<ptr->data<<endl;
}
Node  *bottom(Node *top)
{
    if(isEmpty(top))
    {
        cout<<"Stack UnderFlow"<<endl;
        return top;
    }
    Node *ptr=top;
    if(ptr->next==NULL)
    {
      cout<<"Bottommost Element is: "<<ptr->data;
      return top;  
    }
    while(ptr->next!=NULL)//if there are more than 1 nodes in a Linked List
    {
        ptr=ptr->next;
    }
    cout<<"Bottommost Element is: "<<ptr->data;
    return top;
}
void display_stack(Node *top)//display 
{
    if(top==NULL)
    {
        cout<<"Nothing to display"<<endl;
    }
    while(top!=NULL)
    {
        cout<<"Element: "<<top->data<<endl;
        // cout<<"Address of its successive node: "<<top->next<<endl;
        // cout<<"Address of the current node: "<<top<<endl;
        top=top->next;
    }
}
int main(){
    Node *top=NULL;
    int ch;
    while(true)
    {
        cout<<endl;
        cout<<"**************************MENU***********************"<<endl;
        cout<<"1:To check stack is empty or not "<<endl;
        cout<<"2:To check stack is full or not "<<endl;
        cout<<"3:push element "<<endl;
        cout<<"4:pop element "<<endl;
        cout<<"5:To see which is the top most element "<<endl;
        cout<<"6:Display stack "<<endl;
        cout<<"7:Bottom most element"<<endl;
        cout<<"8:Return element of specific position"<<endl;
        cout<<"9:Exit"<<endl;
        cout<<"************************MENU_ENDS*******************"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<isEmpty(top);
                break;
            case 2:
                cout<<isFull(top);
                break;
            case 3:
                top=push(top);
                break;
            case 4:
                top=pop(top);
                break;
            case 5:
                top=peek(top);
                break;
            case 6:
                display_stack(top);
                break;
            case 7:
                top=bottom(top);
                break;
            case 8:
                return_element(top);
                break;
            case 9:
                exit(0);
            default:
                cout<<"Please enter correct choice"<<endl;
                break;
        }
    }
    return 0;
}