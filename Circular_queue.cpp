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
        front=0;
        rear=0;
    }
    int isEmpty()//checks whether queue is empty or not
    {
        if(front==rear)//empty condition is same in linear and circular queue
        {
            return 1;
        }
        return 0;
    }
    int isFull()//checks whether Circular queue is full or not
    {
        if((rear+1)%size==front)
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
        else if(rear=front=size-1)
        {
            cout<<"Enter element you want to enqueue into the queue"<<endl;
            cin>>element;
            rear=(rear+1)%size;//0
            arr[rear]=element;//circular increment in rear and then inserting into the queue

        }
        else{
            cout<<"Enter element you want to enqueue into the queue"<<endl;
            cin>>element;
            rear=(rear+1)%size;//0
            arr[rear]=element;//circular increment in rear and then inserting into the queue
        }
    }
    void dequeue()//delets the element from the queue
    {
        int ans;
        if(isEmpty()==1)
        {
            cout<<"Queue underflow"<<endl;
            return;
        }
        else
        {
            front=(front+1)%size;
            ans=arr[front];//circular increment in front and then deleting the element from queue
            cout<<"Dequeued: "<<ans<<endl;
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
            for(int i=1;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else if(front!=0 && rear>front)
        {
            for(int i=front+1;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        } 
        else if(rear<front)
        {
            int i=front+1;
            while (i!=front)
            {
                cout<<arr[i]<<" ";
                i=(i+1)%size;
            } 
        } 
    }
};
int main(){
    int n,ch,ans1,ans2;
    cout<<"Enter size of the queue you want"<<endl;
    cin>>n;
    cout<<"That means now you can insert only "<<(n-1)<<" elements in the Circular queue"<<endl;
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
            q.dequeue();
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