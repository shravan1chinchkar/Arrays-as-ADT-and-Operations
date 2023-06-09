#include <iostream>
using namespace std;
// heapify function using Max-Heap Property
class heap
{
public:
    void heapify(int arr[], int size, int i)
    {
        int largest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        if (leftChild <= size && arr[largest] < arr[leftChild])
        {
            largest = leftChild;
        }
        if (rightChild <= size && arr[largest] < arr[rightChild])
        {
            largest = rightChild;
        }
        if (largest != i)
        {
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            heapify(arr, size, largest);
        }
    }
};
int main()
{
    heap h;
    int arr[100], size;
    cout << "Enter Size of the array: ";
    cin >> size;
    size = size - 1;
    arr[0] = -1;
    cout << "BY DEFAULT 0th INDEX OF ARRAY WILL BE UNUSED" << endl;
    for (int i = 1; i <= size; i++)
    {
        int value;
        cin >> value;
        arr[i] = value;
    }
    cout << "Printing the heap before heapify: " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << "(" << i << ")"
             << " ";
    }
    // since leaf node are at correct position so i=size/2
    for (int i = size / 2; i > 0; i--)
    {
        //             5  1
        h.heapify(arr, size, i);
    }
    cout << endl;
    // print the heap
    cout << "Printing the heap After heapify (Max-Heap): " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << "(" << i << ")"
             << " ";
    }
    return 0;
}