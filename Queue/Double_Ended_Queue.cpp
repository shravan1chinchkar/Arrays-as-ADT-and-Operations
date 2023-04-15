#include<iostream>
using namespace std;
class DEqueue
{
    int front,rear,size,data;
    int *arr;
    public:
    DEqueue(){}
    DEqueue(int n)
    {
        arr=new int[n];
        front=-1;
        rear=-1;
        size=n;
    }
    int isEmpty()//checks whether queue is empty or not
    {
        if(front==-1 && rear==-1)//empty condition is same in linear and circular queue
        {
            return 1;
        }
        return 0;
    }
    int isFull()//checks whether Circular queue is full or not
    {
        if((front==0 && rear==size-1) or (front!=0 && rear==(front-1)%(size-1)))
        {
            return 1;
        }
        return 0;
    }
    int rearPosition()
    {
        return rear;
    }
    int frontPosition()
    {
        return front;
    }
    void enqueueF()
    {
        if(isFull()==1)
        {
            cout<<"Queue overflow"<<endl;
        }
        else if(isEmpty()==1)
        {
            front=rear=0;
        }
        else if(front==0 && rear!=size-1)
        {
            front=size-1;
        }
        else
        {
            front--;
        }
        cout<<"Enter data: ";
        cin>>data;
        arr[front]=data;
    }
    void enqueueR()
    {
        if(isFull()==1)
        {
            cout<<"Queue overflow"<<endl;
        }
        else if(isEmpty()==1)
        {
            front =rear=0;
        }
        else if (rear==size-1 && front!=0)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        cout<<"Enter data: ";
        cin>>data;
        arr[rear]=data;
    }
    void dequeueF(){
        if(isEmpty()==1)
        {
            cout<<"Queue Underflow"<<endl;
        }
        else if(front==rear)
        {
            cout<<"Dequeued: "<<arr[front];
            front=rear=-1;
        }
        else if(front==size-1)
        {
            cout<<"Dequeued: "<<arr[front];
            front=0;
        }
        else
        {
            cout<<"dequeued :"<<arr[front];
            front++;
        }
    }
    void dequeueR(){
        if(isEmpty()==1)
        {
            cout<<"Queue Underflow"<<endl;
        }
        else if(front==rear)
        {
            cout<<"Dequeued: "<<arr[rear];
            front=rear=-1;
        }
        else if(rear==0)
        {
            cout<<"Dequeued: "<<arr[rear];
            rear=size-1;
        }
        else
        {
            cout<<"Dequeued: "<<arr[rear];
            rear--;
        }
    }
    void display()//displaying the queue
    {
        if(isEmpty()==1)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        else if(front==0)
        {
            for(int i=0;i<=rear;i++)//prints the queue linearly till the end
            {
                cout<<arr[i]<<" ";
            }
        } 
        else if(front!=0 and front<=rear)
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else if(front!=0 and rear<front)
        {
            int i=front;
            do
            {
                cout<<arr[i]<<" "; 
                i= ((i+1)%size);
            } while (i!=front);    
        } 
    }
};
int main(){
    int n,ch,ans1,ans2,ans3,ans4;
    cout<<"Enter size of the array ";
    cin>>n;
    DEqueue de(n);
    while(true)
    {
        cout<<endl;
        cout<<"*********************************MENU****************************"<<endl;
        cout<<"1:Checks whether Double Ended  queue is empty or not"<<endl;
        cout<<"2:Checks whether Double Ended  queue is full or not"<<endl;
        cout<<"3:enqueue the element from front"<<endl;
        cout<<"4:enqueue the element from rear"<<endl;
        cout<<"5:dequeue the element from front"<<endl;
        cout<<"6:dequeue the element from rear"<<endl;
        cout<<"7:Display the Elements of queue"<<endl;
        cout<<"8:Show rear and front position"<<endl;
        cout<<"9:exit"<<endl;
        cout<<"*********************************MENU_ENDS************************"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            ans1=de.isEmpty();
            cout<<ans1;
            break;
        case 2:
            ans2=de.isFull();
            cout<<ans2;
            break;
        case 3:
            de.enqueueF();
            break;
        case 4:
            de.enqueueR();
            break;
        case 5:
            de.dequeueF();
            break;
        case 6:
            de.dequeueR();
            break;
        case 7:
            de.display();
            break;
        case 8:
            ans3=de.rearPosition();
            cout<<"current rear position: "<<ans3<<endl;
            ans4=de.frontPosition();
            cout<<"current front position: "<<ans4<<endl;
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"Please enter correct choice"<<endl;
            break;
        }
    }    
    return 0;
}