#include <iostream>
using namespace std;
// heapify function using Min-Heap Property
class heap
{
public:
    void heapify(int arr[], int size, int i)
    {
        int smallest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
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
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            heapify(arr, size, smallest);
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

    cout << "Printing heap before heapify" << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << "(" << i << ")"
             << " ";
    }

    for (int i = size / 2; i >= 1; i--)
    {
        //              5    2
        h.heapify(arr, size, i);
    }

    cout << endl;
    cout << "Printing heap After heapify (Min-Heap): " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << "(" << i << ")"
             << " ";
    }
    return 0;
}