// Program Of Max-Heap
/*left child= (2*1)
Right child=(2*i+1)
parent=i/2
*/
#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size, index;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertNodeInMaxHeap(int val)
    {
        size = size + 1;
        cout << "Size after insertion :" << size << endl;
        index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2; // finds the parent index
            // swaps if child is greater than parent
            if (arr[parent] < arr[index])
            {
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;
                index = parent;
            }
            // if child is smaller than parent
            else
            {
                return;
            }
        }
    }
    void deleteNodeInMaxHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        else
        {
            cout << arr[1] << " Deleted" << endl; // Display the node which is gonna be deleted
            arr[1] = arr[size];                   // replace the root node with the last node
            size = size - 1;                      // decrease the size of the array as one node is been deleted
            cout << "Size After deletion: " << size << endl;
            int i = 1; // since root is always at 1st index so i=1
            // place the root at correct position
            while (i < size) // 1<3
            {
                int leftNode = 2 * i;      // 2
                int rightNode = 2 * i + 1; // 3
                //    2<3               arr[1]<arr[2]
                if (leftNode <= size && arr[i] < arr[leftNode])
                {
                    cout << "In if" << endl;
                    int temp = arr[i];      // temp=50
                    arr[i] = arr[leftNode]; // arr[i]=52
                    arr[leftNode] = temp;   // arr[leftNode]=50
                    // i = leftNode;//i=2
                }
                //     5<4
                else if (rightNode <= size && arr[i] < arr[rightNode])
                {
                    cout << "IN else if" << endl;
                    int temp = arr[i];
                    arr[i] = arr[rightNode];
                    arr[rightNode] = temp;
                    i = rightNode;
                }
                else
                {
                    cout << "In else" << endl;
                    return;
                }
            }
        }
    }
    // prints the Max-Heap
    void printHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty.Nothing to display" << endl;
            return;
        }
        // prints the data of the node with its index number
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << "(" << i << ")"
                 << " ";
        }
    }
};
int main()
{
    heap h;
    while (true)
    {
        cout << endl;
        cout << "*******************Menu**********************" << endl;
        cout << "1: Insert value you want to insert into Heap" << endl;
        cout << "2: Display Heap" << endl;
        cout << "3: Delete Node from the heap" << endl;
        cout << "4: Exit" << endl;
        cout << "*********************************************" << endl;
        int ch, value;
        cout << "Enter Your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value you want to insert into Max-Heap: ";
            cin >> value;
            h.insertNodeInMaxHeap(value);
            break;
        case 2:
            h.printHeap();
            break;
        case 3:
            h.deleteNodeInMaxHeap();
            break;
        case 4:
            exit(0);
        default:
            cout << "Please entre correct choice";
        }
    }

    return 0;
}