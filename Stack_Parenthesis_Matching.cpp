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
        arr = new char[size];
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
            cout << "pushed : " << arr[top] << endl;
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
            char ch = arr[top];
            cout << "popped : " << ch << endl;
            top--;
        }
    }
    void paraenthisMatch(string str)
    {
        int flag=0;
        for (int i = 0; i <= size; i++)
        {
            if (str[i] == '(')
            {
                char ch = '(';
                push(ch);
            }
            else if (str[i] == ')')
            {
                if (isEmpty())
                {
                    flag=1;
                }
                else
                {
                    pop();
                }
            }
        }
        if (flag==1)
        {
            cout<<"The Parenthesis is not matching"<<endl;
        }
        else{
            cout<<"Parenthesis are matching"<<endl;
        }
    }
};
int main()
{
    string str = "7*4(10-9)";
    stack1 s(str);
    s.paraenthisMatch(str);
    return 0;
}