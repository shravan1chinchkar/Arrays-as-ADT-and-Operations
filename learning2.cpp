#include <iostream>
using namespace std;
void display(int arr[], int n);

// FUNCTION TO INSERT ELEMENT IN THE ARRAY
void insertion1(int arr[], int n)
{
    int element;
    if (n == 0)
    {
        cout << "Used Size must be greater than 0" << endl;
    }
    else
    {
        cout << "Enter " << n << " elements in array:" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> element;
            arr[i] = element;
        }
        display(arr, n);
    }
}

// FUNCTION TO INSERT AT SPECIFIC INDEX
void insertion2(int arr[], int uSize, int tSize, int index, int ele)
{

    if (uSize >= tSize)
    {
        cout << "Array overflow";
    }

    for (int i = uSize - 1; i >= index; i--)
    {

        arr[i + 1] = arr[i];
    }
    arr[index] = ele;
    uSize++;
    display(arr, uSize);
    cout << endl;
    cout << "Used size: " << uSize << endl;
}

// FUNCTION TO DELETE ARRAY ELEMENTS
void deletion(int arr[], int tSize, int uSize, int index)
{
    if (index >= tSize)
    {
        cout << "Invalid index" << endl;
        cout << "No element deleted" << endl;
    }
    else if (uSize == 0)
    {
        cout << "Array underFlow" << endl;
    }
    else
    {
        for (int i = index; i <= uSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        uSize--;
        display(arr, uSize);
        cout << endl;
        cout << "Used Sized is:" << uSize << endl;
    }
}

// linear Searching
void linearSearch(int arr[], int uSize, int element)
{
    int flag = 0;
    int i;
    for (i = 0; i < uSize; i++)
    {
        if (arr[i] == element)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << element << " element found at index " << i << endl;
    }
    else
    {
        cout << element << " is not present in the array" << endl;
    }
}

// Binary Search
int binarySearch(int arr[], int uSize, int element)
{
    int mid, high, low;
    low = 0;
    high = uSize - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// FUNCTION TO DISPLAY ARRAY
void display(int arr[], int n)
{
    cout << "Elements of array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    /*
    Formula to find size of array
    sizeof(array_name)/sizeof(array_datatype)
    */
    int total_size, used_size, ch, element, index, ch1,ans;
    cout << "Enter Total size of an array" << endl;
    cin >> total_size;
    cout << "Enter how much blocks you want to use from the array" << endl;
    cin >> used_size;
    int arr[total_size] = {10, 20, 30, 40, 50};
    insertion1(arr, used_size);
    cout << endl;

    do
    {
        cout << "1: Insertion of element at specified in array" << endl;
        cout << "2: Deletion  of element from array" << endl;
        cout << "3:Search an element in the array using Linear search" << endl;
        cout << "3:Search an element in the array using Linear search" << endl;
        cout << "4:To search elements in sorted array using binary Search\n"
                "(WARNING -->FOR THIS THE ARRAY MUST BE SORTED)"
             << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter index where the element is to be inserted" << endl;
            cin >> index;
            cout << "Enter element to be inserted at index " << index << endl;
            cin >> element;
            insertion2(arr, used_size, total_size, index, element);
            used_size++;
            break;

        case 2:
            cout << "Enter index of element to be deleted" << endl;
            cin >> index;
            deletion(arr, total_size, used_size, index);
            used_size--;
            break;

        case 3:
            cout << "Enter element to search: " << endl;
            cin >> element;
            linearSearch(arr, used_size, element);
            break;

        case 4:
            cout << "Enter element to search: " << endl;
            cin >> element;
            ans = binarySearch(arr, used_size, element);
            cout << element << " is present at index " << ans << endl;
            break;

        default:
            cout << "Enter Correct choice" << endl;
            break;
        }
        cout << "Do you want to continue (1:Yes/0:No)" << endl;
        cin >> ch1;
    } while (ch1 == 1);

    return 0;
}