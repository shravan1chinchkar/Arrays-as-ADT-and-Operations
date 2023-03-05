#include<iostream>
using namespace std;
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
int isFull(Node *newNode)
{
    if(newNode==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Node *push(Node *top)
{
    int data;
    cout<<"push data in the stack"<<endl;
    cin>>data;
    Node *newNode=new Node;
    if(isFull(newNode))
    {
        cout<<"Stack Overflow"<<endl;
    }
    newNode->data=data;
    newNode->next=top;
    top=newNode;
    return top;
}
void display_stack(Node *top)
{
    while(top!=NULL)
    {
        cout<<"Element: "<<top->data<<endl;
        cout<<"Address of its successive node: "<<top->next<<endl;
        cout<<"Address of the current node: "<<top<<endl;
        top=top->next;
    }
}
int main(){
    Node *top=NULL;
    top=push(top);
    display_stack(top);
    top=push(top);
    display_stack(top);
    return 0;
}