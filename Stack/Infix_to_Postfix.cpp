#include<iostream>
#include<string.h>
using namespace std;
//Infix to postfix conversion using stack(some improvements can be done in the program)
class Stack1
{
    int top,i,j,size1,size2;
    char *stack1;
    char *arr2;
    public:
    Stack1(string str)
    {
        size1=str.length();
        top=-1;
        size2=size1+1;
        stack1=new char[size1]; //array for stack in heap
        arr2=new char[size2]; //array for postfix expression in heap
        i=0;  //track the string
        j=0;  //Track Postfix expression array
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
        if (top == size1 - 1)
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
            stack1[top] = c;
        }
    }
    char pop()//delets the topmost character
    {
        char ch;
        if (isEmpty() == 1)
        {
            cout << "Stack underFlow" << endl;
        }
        ch=stack1[top];
        top--;
        return ch;
    }
    char peek()
    {
        if(isEmpty())
        {
            cout<<"Stack Empty"<<endl;
        }
        else
        {
            return stack1[top];
        }
    }
    int precedence(char str)
    {
        if(str=='*' or str=='/')
        {
            return 3;
        }
        else if(str=='+' or str=='-')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    int isOperator(char str)
    {
        if(str=='*' or str=='/' or str=='+' or str=='-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    char *infix_to_Postfix(string str)
    {
        while(i<=size1)
        {
            if(isOperator(str[i])==0)//if the its not operator then push it into arr2
            {
                arr2[j]=str[i];
                i++;
                j++;
            }
            else
            {
                if(isEmpty()==1)//at starting stack is empty so directly push the operator into stack
                {
                    push(str[i]);
                    i++;
                }
                //              
                else if(precedence(str[i])>precedence(peek()))//checks the precedence of the operator before pushing into stack
                {
                    push(str[i]);
                    i++;
                }
                else{   //if precedence of incomming operator is small or equal to the top operator
                    arr2[j]=pop();
                    j++;
                }
            }
        }
        while(isEmpty()==0)//at last pop all the operators remaining into stack into the arr2
        {
            arr2[j]=pop();
            j++;
        }
        return arr2;
    }
};
int main(){
    string str="a+b";
    int size=str.length();
    cout<<"Infix expression is: "<<str<<endl;
    Stack1 s(str);  
    char *arr;
    arr=s.infix_to_Postfix(str);
    cout<<"Prefix expression of Infix expression ("<<str<<") is: ";
    for(int i=0;i<=size;i++)
    {
        cout<<arr[i]<<"";
    }
    return 0;
}