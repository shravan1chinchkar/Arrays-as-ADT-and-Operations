#include<iostream>
using namespace std;

void insertion1(int arr[],int n)
{
    int element;
    cout<<"Enter "<<n<<" elements in array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        arr[i]=element;
    }
}
void insertion2(int arr[],int uSize,int tSize,int index,int ele)
{

    if(uSize>=tSize){
        cout<<"Array overflow";
    }

    //     i=4        2>=2   
    for(int i=uSize-1;i>=index;i--)
    {

        arr[i+1]=arr[i];
    }
    //arr[2]=7
    arr[index]=ele;
}

void display(int arr[],int n)
{
    cout<<"Elements of array are:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main(){
    int total_size,used_size,element,index;
    cout<<"Enter Total size of an array"<<endl;
    cin>>total_size;
    cout<<"Enter how much blocks you want to use from the array"<<endl;
    cin>>used_size;
    int arr[total_size];
    insertion1(arr,used_size);
    display(arr,used_size);

    cout<<endl;
    cout<<"Enter index where the element is to be inserted"<<endl;
    cin>>index;
    cout<<"Enter element to be inserted at index "<<index<<endl;
    cin>>element;

    insertion2(arr,used_size,total_size,index,element);//insertion at specific index
    used_size++;
    display(arr,used_size);

    return 0;
}