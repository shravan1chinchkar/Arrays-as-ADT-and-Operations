#include <iostream>
#include <queue>
using namespace std;
/*
Program of practical 4th BST and its operations
Time complexity of   Avg
insertion in BST       O(h)
Searching in BST       O(h)
*/
int i;
class node
{
public:
    int data;
    node *leftchild;
    node *rightchild;
    node *parent;
    node(int data) // officially creates the node in the heap
    {
        this->data = data;
        leftchild = NULL;
        rightchild = NULL;
        parent = NULL;
    }
};
// creating the BST
//                        root      8
node *insertIntoBST(node *root, int data) //
{
    if (root == NULL) // t
    {
        root = new node(data); //8 
        return root;           //10
    }
    // if data is greater then the root node insert into right subtree
    else if (data > root->data)//8>10
    {

        node *rchild = insertIntoBST(root->rightchild, data);
        root->rightchild = rchild;
        rchild->parent = root;
    }
    // if the data is less than the root node insert into left subtree
    else if (data < root->data)//8<10
    {
        //                                    null    8                    
        node *lchild = insertIntoBST(root->leftchild, data);
        root->leftchild = lchild;//r;
        lchild->parent = root;
    }
    return root;//
}
// function to take inputs for BST
void takeInput(node *&root)
{
    int data;
    cin >> data; //10      
    while (data != -1) 
    {
        //                    root 8
        root = insertIntoBST(root, data); 
        cin >> data;//8
    }
}
// Searching intO  BST
//  approach 1st  to search the data using concept of recursion
void searchInBST(node *root, int search)
{
    // execute if data is not present
    if (root == NULL)
    {
        cout << search << " not present" << endl;
        return;
    }
    // execute when data is present
    if (search == root->data)
    {
        cout << search << " found" << endl;
        return;
    }
    // execute if data to be search is less than root node
    else if (search < root->data)
    {
        searchInBST(root->leftchild, search);
    }
    // execute if data to be search is greater than root node
    else if (search > root->data)
    {
        searchInBST(root->rightchild, search);
    }
}
// approach 2nd to search the data uisng iterative method
void searchInBST2(node *root, int search)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (search == temp->data)
        {
            cout << search << " found";
            return;
        }
        if (search < temp->data)
        {
            temp = temp->leftchild;
        }
        if (search > temp->data)
        {
            temp = temp->rightchild;
        }
    }
    cout << search << " not present in the given BST" << endl;
}
// Printing the tree level wise
void levelorderTraversal(node *root)
{
    queue<node *> q;
    q.push(root); //
    q.push(NULL); // since one level gets complete  q-> 1 NULL

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // This code is written to print the tree in its actual format
        if (temp == NULL)
        {
            cout << endl; // indicate that old level is completely traversed
            if (!q.empty())
            {
                q.push(NULL); // Indicate that queue has some child node
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->leftchild)
            {
                q.push(temp->leftchild);
            }
            if (temp->rightchild)
            {
                q.push(temp->rightchild);
            }
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return; // because of this the program comes out of the recursive call and print the node
    }
    inorder(root->leftchild);
    cout << root->data << " ";
    inorder(root->rightchild);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->leftchild);
    preorder(root->rightchild);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->leftchild);
    postorder(root->rightchild);
    cout << root->data << " ";
}
// Returns the minimum value from the above BST
node *minVal(node *root)
{
    node *temp = root;
    while (temp->leftchild != NULL)
    {
        temp = temp->leftchild;
    }
    return temp;
}
// Returns the maximum value from the above BST
node *maxVal(node *root)
{
    node *temp = root;
    while (temp->rightchild != NULL)
    {
        temp = temp->rightchild;
    }
    return temp;
}
node *deletefromBST(node *root, int val)
{
    // base case
    if (root == NULL)
    {
        cout << val << " not present in the BST" << endl;
        return root;
    }
    if (root->data == val)
    {
        // delete node having 0 child
        if (root->leftchild == NULL && root->rightchild == NULL)
        {
            delete root;
            return NULL;
        }
        // delete node having 1 child
        // having only leftchild
        if (root->leftchild != NULL && root->rightchild == NULL)
        {
            node *temp = root->leftchild;
            delete root;
            return temp;
        }
        // having only rightchild
        if (root->leftchild == NULL && root->rightchild != NULL)
        {
            node *temp = root->rightchild;
            delete root;
            return temp;
        }
        // delete node having 2 child
        if (root->leftchild != NULL && root->rightchild != NULL)
        {
            int minvalue = minVal(root->rightchild)->data;                // find the minimum value from right subtree of the root
            root->data = minvalue;                                        // replace the data in the root node with the minimum value
            root->rightchild = deletefromBST(root->rightchild, minvalue); // delete the node containing minval from right subtree
            return root;                                                  // return root
        }
    }
    else if (val < root->data)
    {
        root->leftchild = deletefromBST(root->leftchild, val);
        return root;
    }
    else
    {
        root->rightchild = deletefromBST(root->rightchild, val);
        return root;
    }
}
int heightOfBST(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int heightofleftsubtree = heightOfBST(root->leftchild);
    int heightofrightsubtree = heightOfBST(root->rightchild);
    int heightoftree = max(heightofleftsubtree, heightofrightsubtree) + 1;
    return heightoftree;
}
// node *inorderSuccessor(node *root, node *n)
// {
//     if (n->rightchild != NULL)
//     {
//         return minVal(n->rightchild);
//     }
//     node *p = n->parent;
//     while (p != NULL && n == p->rightchild)
//     {
//         n = p;
//         p = p->parent;
//     }
//     return p;
// }
int main()
{
    // creating a BST
    node *root = NULL;
    cout << "Enter data for BST" << endl;
    takeInput(root);
    cout << "Printing the BST" << endl;
    levelorderTraversal(root);

    // Updating BST
    cout << "Insert any new node in the BST: " << endl;
    takeInput(root);
    cout << "Printing the BST after updating" << endl;
    levelorderTraversal(root);

    // Searching data in BST
    cout << "Enter data to be searched in the BST" << endl;
    int search;
    cin >> search;
    cout << "Searched using 1st approach" << endl;
    searchInBST(root, search);
    cout << "Searched using 2nd approach" << endl;
    searchInBST2(root, search);

    // Finding min and max value from the BST
    cout << endl
         << "Minimum value in the above BST is: ";
    node *root1 = minVal(root);
    cout << root1->data;
    cout << endl
         << "Maximum value in the above BST us:";
    node *root2 = maxVal(root);
    cout << root2->data;

    // Finding height of BST
    cout << endl
         << "Height of the BST is: " << endl;
    int ans = heightOfBST(root);
    cout << ans;

    // Deleting node from BST
    cout << endl;
    deletefromBST(root, 100);
    cout << "Printing BST after deletion operation" << endl;
    levelorderTraversal(root);

    // node *temp = root->leftchild->rightchild->rightchild;
    // cout << "Parent node of " << temp->data << " is " << temp->parent->data << endl;
    // node* succ=inorderSuccessor(root,temp);
    // if(succ!=NULL)
    // {
    //     cout<<"InorderSuccessor of "<<temp->data<<" is "<<succ->data<<endl;

    // }
    // else
    // {
    //     cout<<"Inorder Successor doesn't exist "<<endl;
    // }

    // Traversing a BST
    //  cout << endl
    //       << "Preorder Traversal of BST " << endl;
    //  preorder(root);
    //  cout << endl
    //       << "Inorder Traversal of BST " << endl;
    //  inorder(root);
    //  cout << endl
    //       << "Postorder Traversal of BST " << endl;
    //  postorder(root);
    return 0;
}