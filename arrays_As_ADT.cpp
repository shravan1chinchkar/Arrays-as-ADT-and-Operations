#include <iostream>
using namespace std;
// Array as an ADT
// Creating Array in Heap section
class myArray
{
    int arr_size;
    int used_size;
    int *ptr;

public:
    myArray(myArray *a, int tsize, int usize)
    {
        a->arr_size = tsize; // meaning marks.arr_size
        a->used_size = usize;
        a->ptr = new int(tsize); // this will create array in heap memory i.e dynamically
    }

    void insertElements(myArray *a)
    {
        int element;
        cout << "Enter " << used_size << " students marks of maths subject in array: " << endl;
        for (int i = 0; i < a->used_size; i++)
        {
            cin >> element;
            (a->ptr)[i] = element; // i.e the array which is stored at address a and the name of arrray is ptr(just for understanding)
        }
    }

    void displayArray(myArray *a)
    {
        cout << "Marks acchieved by " << used_size << " students in maths subject are: " << endl;
        for (int i = 0; i < a->used_size; i++)
        {
            cout << (a->ptr)[i] << endl;
        }
    }
};
int main()
{
    /*The program will start from here
    Initially we will enter the total size of an array
    Then we will enter the size that we want to use
    */
    int total_size, used_size;
    cout << "Enter Total size of an array" << endl;
    cin >> total_size;
    cout << "Enter how much blocks you want to use from the array" << endl;
    cin >> used_size;
    // Here the object of Abstract data type is created
    myArray marks(&marks, total_size, used_size);
    marks.insertElements(&marks);
    marks.displayArray(&marks);
    return 0;
}