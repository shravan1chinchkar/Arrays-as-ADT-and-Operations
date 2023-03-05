#include<iostream>
using namespace std;
//implementing stack using array
class stack
{
    int top;
    int size;
    int *arr;
    public:
    stack()//creates a stack
    {
        cout<<"Enter size of the Stack you want"<<endl;
        cin>>size;
        arr=new int[size]; 
        top=-1;  
    }
    int isEmpty()//checks whether the stack is empty or not
    {
        if(top==-1)
        {
            return 1;
            cout<<endl;      
        }
        else
        {
            return 0;
            cout<<endl;
        }
    }
    int isFull()//Checks whether the stack is full or not
    {
        if(top==size-1)
        {
            return 1;
            cout<<endl;
        }
        else
        {
            return 0;
            cout<<endl;
        }
    }
    void push()//insert element in stack
    {
        if(isFull()==1)
        {
            cout<<"Stack overflow,Cant insert the element"<<endl;
            return;
        }
        else
        {
            int element;
            cout<<"Enter element to push into the stack"<<endl;
            cin>>element;
            top++;
            arr[top]=element;
        }
    }
    void pop()//delets elements in stack
    {
        if(isEmpty()==1)
        {
            cout<<"Stack underflow"<<endl;
            return;
        }
        else
        {
            cout<<arr[top];
            top--;
        }
    }
    void peek()//returns the topmost element
    {
        if(isEmpty()==1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        else
        {
            cout<<"Current topmost element in stack is: "<<arr[top]<<endl;
        }
    }
    void displayStack()//display the stack
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    stack s1;
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
                cout<<s1.isEmpty();
                break;
            case 2:
                cout<<s1.isFull();
                break;
            case 3:
                s1.push();
                break;
            case 4:
                s1.pop();
                break;
            case 5:
                s1.peek();
                break;
            case 6:
                s1.displayStack();
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