#include<iostream>
using namespace std;
class stack
{
    int top;
    int size;
    int *arr;
    public:
    int *createStack(int *arr)
    {
        cout<<"Enter size of the Stack you want"<<endl;
        cin>>size;
        top=-1;
        arr=new int(size); 
        return arr;
    }
    int isEmpty()
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
    int isFull()
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
    int *push(int *arr)
    {
        if(isFull()==1)
        {
            cout<<"Stack overflow"<<endl;
        }
        int element;
        cout<<"Enter element to push into the stack"<<endl;
        cin>>element;
        top++;
        arr[top]=element;
        top++;
    }
};
int main(){
    stack s1;
    int *arr,ch;
    arr=s1.createStack(arr);

    while(true)
    {
        cout<<endl;
        cout<<"**************************MENU***********************"<<endl;
        cout<<"1:To check stack is empty or not "<<endl;
        cout<<"2:To check stack is full or not "<<endl;
        cout<<"3:push element "<<endl;
        cout<<"4:pop element "<<endl;
        cout<<"5:To see which is the top most element "<<endl;
        cout<<"6:Display stacck "<<endl;
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
                arr=s1.push(arr);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                cout<<"Please enter correct choice"<<endl;
                break;
        }
    }
    return 0;
}