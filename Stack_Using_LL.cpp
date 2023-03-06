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
int isFull(Node *top)
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
    int data;
    cout<<"push data in the stack"<<endl;
    cin>>data;
    Node *newNode=new Node;
    if(isFull(top))
    {
        cout<<"Stack Overflow"<<endl;
        return newNode;
    }
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
Node *peek(Node *top)
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
void display_stack(Node *top)
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
        cout<<"7:Exit"<<endl;
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
                exit(0);
                break;
            default:
                cout<<"Please enter correct choice"<<endl;
                break;
        }
    }
    return 0;
}