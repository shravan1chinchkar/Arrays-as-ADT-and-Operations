#include<iostream>
using namespace std;
//Array as an ADT
class myArray
{
    int arr_size;
    int used_size;
    int *ptr;
    public:
    myArray(myArray *a,int tsize,int usize)
    {
        a->arr_size=tsize;
        a->used_size=usize;
        a->ptr=new int(tsize);//this will create array in heap memory
    }
    void insertElements(myArray *a)
    {
        int element;
        cout<<"Enter "<<used_size<<" students marks of maths subject in array: "<<endl;
        for(int i=0;i<a->used_size;i++)
        {
            cin>>element;
            (a->ptr)[i]=element;
        }
    }
    void displayArray(myArray *a)
    {
        cout<<"Marks acchieved by"<<used_size<<" students in maths subject are: "<<endl;
        for (int i = 0; i < a->used_size; i++)
        {
            cout<<(a->ptr)[i]<<endl;
        }  
    }

};
int main(){
    int total_size,used_size;
    cout<<"Enter Total size of an array"<<endl;
    cin>>total_size;
    cout<<"Enter how much blocks you want to use from the array"<<endl;
    cin>>used_size;

    myArray marks(&marks,total_size,used_size);
    marks.insertElements(&marks);
    marks.displayArray(&marks);

    return 0;
}