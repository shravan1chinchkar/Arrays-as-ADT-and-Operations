#include<iostream>
using namespace std;
/*Circular queue. 
1)Front will always remain empty in circular queue.
2)Here lets say if the size of the queue is 5 then the index will be 0 to 4 and the element will be inserted from 1st index.
3)The 0th index is reserved in circular queue.
4)In short if the size of the Circular queue is 5 then you can insert only 4 elements.
*/
class Circular_Queue
{
    int front,rear,size;
    int *arr;
    public:
    Circular_Queue(int n)
    {
        size=n;
        arr=new int[size];//allocated queue in heap
        front=rear=-1;
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
        if((front==0 && rear==size-1) or (rear==(front-1)%(size-1)))
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
            return;
        }
        else if(front==-1)//enqueing 1st element into queue
        {
            front=rear=0;
            cout<<"Enter element you want to enqueue into the queue"<<endl;
            cin>>element;
            arr[rear]=element;
        }
        else if(rear==size-1 && front!=0)
        {
            rear=0;//to maintain cyclic nature
            cout<<"Enter element you want to enqueue into the queue"<<endl;
            cin>>element;
            arr[rear]=element;
        }
        else//normal enquing into the queue
        {
            cout<<"Enter element you want to enqueue into the queue"<<endl;
            cin>>element;
            rear++;
            arr[rear]=element;
        }
    }
    int rearPosition()
    {
        return rear;
    }
    int frontPosition()
    {
        return front;
    }
    void dequeue()//delets the element from the queue
    {
        int ans;
        if(isEmpty()==1)
        {
            cout<<"Queue underflow"<<endl;
            return;
        }
        else if(front==rear)//queue contains only one element
        {
            cout<<"Dequeued :"<<arr[front];
            front=rear=-1;
        }
        else if(front==size-1)//front is pointing to last index
        {
            cout<<"Dequeued: "<<arr[front];
            front=0;//to maintain cyclic nature
        }
        else
        {
            ans=arr[front];//circular increment in front and then deleting the element from queue
            cout<<"Dequeued: "<<ans<<endl;
            front++;       
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
    cout<<"Enter size of the queue you want"<<endl;
    cin>>n;
    Circular_Queue q(n);
    while (true)
    {
        cout<<endl;
        cout<<"*********************************MENU****************************"<<endl;
        cout<<"1:Checks whether Circular queue is empty or not"<<endl;
        cout<<"2:Checks whether Circular queue is full or not"<<endl;
        cout<<"3:enqueue the element"<<endl;
        cout<<"4:dequeue the element"<<endl;
        cout<<"5:Display the Circular queue"<<endl;
        cout<<"6:Show rear and front position"<<endl;
        cout<<"7:exit"<<endl;
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
            q.dequeue();
            break;
        case 5:
            q.display();
            break;
        case 6:
            ans3=q.rearPosition();
            cout<<"current rear position: "<<ans3<<endl;
            ans4=q.frontPosition();
            cout<<"current front position: "<<ans4<<endl;
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