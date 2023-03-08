#include <iostream>
#include <string>
using namespace std;
//  MultiParenthesis Checking Program 
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
    int isEmpty()//checks whether the stack is empty or not
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
    int isFull()//checks whether the stack is full or not
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
    void push(char c)//insert the given character into the stack
    {
        if (isFull() == 1)
        {
            cout << "stack OverFlow" << endl;
        }
        else
        {
            top++;
            arr[top] = c;
        }
    }
    char pop(char ch)//delets the topmost character
    {
        if (isEmpty() == 1)
        {
            cout << "Stack underFlow" << endl;
        }
        ch=arr[top];
        top--;
        return ch;
    }
    int match (char ch1,char ch)//checks whether the char in string and the character which is poped are similar or not
    {
        if(ch1=='(' && ch==')')
        {
            return 1;
        }
        if(ch1=='[' && ch==']')
        {
            return 1;
        }
        if(ch1=='{' && ch=='}')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int paraenthisMatch(string str)//main function which decides what to push and what to pop
    {
        int flag=0;
        char ch,popelement,chr1;
        for (int i = 0; i <= size; i++)
        {
            if (str[i] == '(' or str[i]=='[' or str[i]=='{')
            {
                ch =str[i];
                push(ch);
            }
            else if (str[i] == ')' or str[i]==']' or str[i]=='}')
            {
                if (isEmpty())
                {
                    cout<<"Stack empty"<<endl;
                }
                else
                {
                    ch=str[i];
                    ch=pop(ch);
                    if(!match(ch,str[i]))
                    {
                        return 0;
                    }
                }
            }
        }
    }
};
int main()
{
    string str = "((8)(*--$$9))";//string which is given for testing
    stack1 s(str);
    if(s.paraenthisMatch(str))
    {
        cout<<"The Parenthesis are balanced"<<endl;
    }
    else
    {
        cout<<"The Parenthesis are not balanced"<<endl;
    }
    return 0;
}