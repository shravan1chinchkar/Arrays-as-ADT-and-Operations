#include <iostream>
#include <string>
using namespace std;
//  Parenthesis Checking Program
class stack1
{
    int size;
    int top;
    char *arr;

public:
    stack1(string str)
    {
        size = str.length();
        top = -1;
        arr = new char[size];//an character array is created in heap
    }
    int isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(char c)
    {
        if (isFull() == 1)
        {
            cout << "stack OverFlow" << endl;
        }
        else
        {
            top++;
            arr[top] = c;
            // cout << "pushed : " << arr[top] << endl;
        }
    }
    void pop()
    {
        if (isEmpty() == 1)
        {
            cout << "Stack underFlow" << endl;
        }
        else
        {
            top--;
        }
    }
    int paraenthisMatch(string str)
    {
        
         char ch;
        for (int i = 0; i <= size; i++)
        {
            if (str[i] == '(')
            {
                ch = str[i];
                push(ch);
            }
            else if (str[i] == ')')
            {
                if (isEmpty()==1)
                {
                    cout<<"Stack underFlow"<<endl;
                    return 0;            
                }
                else
                {
                    pop();
                }
            }
        }
        if(isEmpty()==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    string str = "7*4(10-9)";
    stack1 s(str);
    if(s.paraenthisMatch(str)==1)
    {
        cout<<"Parenthesis are balanced"<<endl;
    }
    else
    {
        cout<<"Parenthesis are not balanced"<<endl;
    }
    return 0;
}