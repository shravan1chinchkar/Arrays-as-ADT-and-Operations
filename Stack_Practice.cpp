#include<iostream>
using namespace std;
//Implementing two stack in a single array
class Stack
{
    int size;
    int *arr;
    int top1;
    int top2;
    public:
    Stack()//create an array which consist of 2 stacks
    {
        cout<<"Enter size of the stack you want"<<endl;
        cin>>size;
        top1=-1;
        top2=size;
        arr=new int[size];//creates an array in heap
    }
    void push1(){
        if(top2-top1==1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        {
            int element;
            cout<<"Enter element to insert in stack1:"<<endl;
            cin>>element;
            top1++;
            arr[top1]=element;
        }
    }
    void push2(){
        if(top2-top1==1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        {
            int element;
            cout<<"Enter element to insert in stack2:"<<endl;
            cin>>element;
            top2--;
            arr[top2]=element;
        }
    }
    void pop1(){
        if(top1==-1)
        {
            cout<<"Stack UnderFlow"<<endl;
            return;
        }
        else
        {
            cout<<"popped "<<arr[top1]<<" from stack1 "<<endl;
            top1--;
        } 
    }
    void pop2(){
        if(top2==size)
        {
            cout<<"Stack UnderFlow"<<endl;
            return;
        }
        else{
            cout<<"popped "<<arr[top2]<<" from stack2"<<endl;
            top2++;
        }    
    }
    void peek1(){
        cout<<"Current topmost element in stack1 is: "<<arr[top1];
    }
    void peek2(){
        cout<<"Current topmost element in stack2 is: "<<arr[top2];
    }
    void display1(){
        cout<<"Elements of stack1 are:"<<endl;
        for (int i=0;i<=top1;i++)
        {
            cout<<arr[i]<<" ";
        }    
    }
    void display2(){
        cout<<"Elements of stack2:"<<endl;
        for(int i=size-1;i>=top2;i--)
        {
            cout<<arr[i]<<" "; 
        }   
    }    
};
int main(){
    Stack s;
    int ch;
    while (true)
    {
        cout<<endl;
        cout<<"************************MENU********************"<<endl;
        cout<<"1:push in stack1"<<endl;
        cout<<"2:push in stack2"<<endl;
        cout<<"3:pop in stack1"<<endl;
        cout<<"4:pop in stack2"<<endl;
        cout<<"5:Topmost element in stack1"<<endl;
        cout<<"6:Topmost element in stack2"<<endl;
        cout<<"7:Display stack1"<<endl;
        cout<<"8:Display stack1"<<endl;
        cout<<"9:Exit"<<endl;
        cout<<"************************MENU_ENDS*****************"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            s.push1();
            break;
        case 2:
            s.push2();
            break;
        case 3:
            s.pop1();
            break;
        case 4:
            s.pop2();
            break;
        case 5:
            s.peek1();
            break;
        case 6:
            s.peek2();
            break;
        case 7:
            s.display1();
            break;
        case 8:
            s.display2();
            break;
        case 9:
            exit(0);
        default:
            cout<<"Enter correct choice"<<endl;
            break;
        }
    } 
    return 0;
}