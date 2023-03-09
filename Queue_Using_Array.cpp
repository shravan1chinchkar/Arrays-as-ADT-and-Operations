#include<iostream>
using namespace std;
//Normal queue
class Queue
{
    int front,rear,size;
    int *arr;
    public:
    Queue(int n)
    {
        size=n;
        arr=new int[size];//allocated queue in heap
        front=-1;
        rear=-1;
    }
    int isEmpty()//checks whether queue is empty or not
    {
        if(front==rear)
        {
            return 1;
        }
        return 0;
    }
    int isFull()//checks whether queue is full or not
    {
        if(rear==size-1)
        {
            return 1;
        }
        return 0;
    }
    void enqueue()//insert the element into the queue
    {
        int element;
        if(isFull()==1)
        {
            cout<<"Queue overflow"<<endl;
        }
        else{
            cout<<"Enter element you want to enqueue into the queue"<<endl;
            cin>>element;
            rear++;
            arr[rear]=element;
        }
    }
    int dequeue()//delets the element from the queue
    {
        int ans;
        if(isEmpty()==1)
        {
            cout<<"Queue underflow"<<endl;
        }
        else
        {
            front++;
            ans=arr[front];
            return ans;
        }
    }
    void display()//displaying the queue
    {
        if(isEmpty()==1)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        if(front==-1)
        {
            for(int i=0;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        if(front!=-1)
        {
            for(int i=front+1;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    }
};
int main(){
    int n,ch,ans1,ans2,ans3;
    cout<<"Enter size of the queue you want"<<endl;
    cin>>n;
    Queue q(n);
    while (true)
    {
        cout<<endl;
        cout<<"*********************************MENU****************************"<<endl;
        cout<<"1:Checks whether queue is empty or not"<<endl;
        cout<<"2:Checks whether queue is full or not"<<endl;
        cout<<"3:enqueue the element"<<endl;
        cout<<"4:dequeue the element"<<endl;
        cout<<"5:Display the queue"<<endl;
        cout<<"6:exit"<<endl;
        cout<<"*********************************MENU_ENDS************************"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            ans1=q.isEmpty();
            cout<<ans1;
            break;
        case 2:
            ans2=q.isFull();
            cout<<ans2;
            break;
        case 3:
            q.enqueue();
            break;
        case 4:
            ans3=q.dequeue();
            cout<<"dequeued: "<<ans3<<endl;
            break;
        case 5:
            q.display();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"Please enter correct choice"<<endl;
            break;
        }
    }  
    return 0;
}