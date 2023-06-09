#include <iostream>
using namespace std;
// Heap Sort using Mix-Heap (Sorts the data in ascending order)
class heap
{
public:
    //                          5        2
    void heapify(int arr[], int size, int i)
    {
        int smallest = i;//2
        int leftChild = 2 * i;//4
        int rightChild = 2 * i + 1;//5
        //  4<=5                    arr[2]>arr[4]
        if (leftChild <= size && arr[smallest] > arr[leftChild])
        {
            smallest = leftChild;
        }
        if (rightChild <= size && arr[smallest] > arr[rightChild])
        {
            smallest = rightChild;
        }
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]); // swaps the two nodes according to the Min-heap function
            heapify(arr, size, smallest);
        }
    }
    void heapSort(int arr[], int size)
    {
        int n = size;
        cout << "After Heap Sort data is: " << endl;
        while (n >= 1)
        {
            cout << arr[1] << " ";
            // Step 1: Swap the root node and the last node
            arr[1] = arr[n]; 
            // Step 2: Decrement the size of the array
            n--;
            // Step 3: Place the root node at the right Position
            heapify(arr, n, 1);
        }
    }
};
int main()
{
    heap h;
    int arr[100], size;
    cout << "Enter Size of the array: ";
    cin >> size;//6
    size = size - 1;
    arr[0] = -1;
    cout << "BY DEFAULT 0th INDEX OF ARRAY WILL BE UNUSED" << endl;
    // Entering element in array
    //            1<=5
    for (int i = 1; i <= size; i++)
    {
        int value;
        cin >> value;
        arr[i] = value;
    }

    // creating heap of the given data
    //              5/2       2>=1
    for (int i = size / 2; i >= 1; i--)
    {
        //              5    2
        h.heapify(arr, size, i);
    }
    // Heap Sort Function
    h.heapSort(arr, size);
    return 0;
}