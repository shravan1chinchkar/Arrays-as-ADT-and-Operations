/*
In linked List there are 4 cases of insertion
1] Deleting  node at begning o(1)
2] Deleting  node at middle o(n)
3] Deleting  node at end o(n)
4] Deleting  node after a specific node.(Here address of the node is already givn) o(1)
*/
#include<iostream>
using namespace std;
int data,count=0;
struct Node
{
    int data;
    struct Node *next;
};
class Linked_list
{
    public:
    //Creating a node
    struct Node *create_Node(struct Node *head,int n);
    {
        struct Node *duplicate_head;
        int nodeCounter=1;
        head=new struct Node;
        cout<<"Enter the data in "<<count<<"th node: "<<endl;
        cin>>data;
        head->data=data;
        head->next=NULL;
        count++;
        duplicate_head=a;
        nodeCounter++;
        for(nodeCounter=2;nodeCounter<=n-1;nodeCounter++)
        {
            
        }






    }


};
int main(){
    struct Node *head;
    Linked_list ll;
    int n;
    cout<<"Enter number of nodes you want in your Linked list: "<<endl;
    cin>>n;
    head=ll.create_Node(head,n);
    ll.display(head);

    
    return 0;
}