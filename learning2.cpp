#include<iostream>
using namespace std;
int used_size=0;
//arr ={10,20,30,40,50} usize=5
void display(int arr[],int n);
void insertion1(int arr[],int n)
{
    int element;
    if(n==0)
    {
        cout<<"Used Size must be greater than 0"<<endl;
    }
    else
    {
    cout<<"Enter "<<n<<" elements in array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        arr[i]=element;
    }
    display(arr,n);
    }
}
                        
void insertion2(int arr[],int uSize,int tSize,int index,int ele)
{

    if(uSize>=tSize){
        cout<<"Array overflow";
    } 

    for(int i=uSize-1;i>=index;i--)
    {

        arr[i+1]=arr[i];
    }
    arr[index]=ele;
    uSize++;
    display(arr,uSize);
    cout<<endl;
    cout<<"Used size: "<<uSize<<endl;

}

void deletion(int arr[],int tSize,int uSize,int index)
{
    if(index>=tSize)
    {
        cout<<"Invalid index"<<endl;
        cout<<"No element deleted"<<endl;
    }
    else if(uSize==0)
    {
        cout<<"Array underFlow"<<endl;
    }
    else
    {
        //     0  1  2  3  4
        //arr={28,10,89,78,90}
        //      i=4    4<5
        for(int i=index;i<=uSize-1;i++)
        {
            //arr[0]=10
            //arr[i]=89
            //arr[2]=78
            //arr[3]=90
            //arr[4]=
            arr[i]=arr[i+1];
        }
        uSize--;
        display(arr,uSize);
        cout<<uSize<<endl;
    }
}
//arr={20,30,40,50} usize=4;

void display(int arr[],int n)
{
    cout<<"Elements of array are:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int total_size,ch,element,index,ch1;
    cout<<"Enter Total size of an array"<<endl;
    cin>>total_size;
    cout<<"Enter how much blocks you want to use from the array"<<endl;
    cin>>used_size;
    int arr[total_size];
    insertion1(arr,used_size);
    cout<<endl;
    do
    { 
    cout<<"1: Insertion of element at specified in array"<<endl;
    cout<<"2: Deletion  of element from array"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
        cout<<"Enter index where the element is to be inserted"<<endl;
        cin>>index;
        cout<<"Enter element to be inserted at index "<<index<<endl;
        cin>>element;
        insertion2(arr,used_size,total_size,index,element);//insertion at specific index
        // used_size++;
        // display(arr,used_size);
        break;

        case 2:
        cout<<"Enter index of element to be deleted"<<endl;
        cin>>index;
        deletion(arr,total_size,used_size,index);
        // used_size--;
        // display(arr,used_size);
        break;
        default:
        cout<<"Enter Correct choice"<<endl;
        break;
    }
    cout<<endl;
    cout<<"Do you want to continue (1:Yes/0:No)"<<endl;
    cin>>ch1;
    }while(ch1==1);

    return 0;
}