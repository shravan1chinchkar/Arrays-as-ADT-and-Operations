#include <iostream>
using namespace std;
// Heap Sort using Max-Heap (Sorts the data in decending order)
class heap
{
public:
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        if (leftChild <= n && arr[largest] < arr[leftChild])
        {
            largest = leftChild;
        }

        if (rightChild <= n && arr[largest] < arr[rightChild])
        {
            largest = rightChild;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]); // swaps the nodes according to the rule of Max-Heap
            heapify(arr, n, largest);
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
            arr[1] = arr[n]; // arr[1]=50

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
    cin >> size;
    size = size - 1;
    arr[0] = -1;
    cout << "BY DEFAULT 0th INDEX OF ARRAY WILL BE UNUSED" << endl;
    // Entering element in array
    for (int i = 1; i <= size; i++)
    {
        int value;
        cin >> value;
        arr[i] = value;
    }

    // heapfiying the data(Creating Heap of the given data)
    for (int i = size / 2; i > 0; i--)
    {
        h.heapify(arr, size, i);
    }

    // Heap Sort Function
    h.heapSort(arr, size);

    return 0;
}