#include <iostream>
#include <queue>
using namespace std;
// Binary Tree basic program
// SOME CONCEPT NOT UNDERSTOOD

// node as an abstract Data type
class node
{
public:
    int data;
    node *leftchild;
    node *rightchild;
    // creating actual node here
    node(int data)
    {
        this->data = data;
        this->leftchild = NULL;
        this->rightchild = NULL;
    }
};

// Building Binary tree using the concept of recursion
node *BuildTree(node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new node(data); // calls the constructor i.e officially creates the node dynamically

    if (data == -1)
    {
        return NULL; // if true comes out of the recursive call and goes to the next side child
    }

    cout << "Enter the data for inserting in the left of " << data << endl;
    root->leftchild = BuildTree(root->leftchild);
    cout << "Enter the data for inserting in the right of " << data << endl;
    root->rightchild = BuildTree(root->rightchild);

    return root;
}

// Building the levelwise using queue STL
void buildforlevelorder(node *&root)
{
    queue<node *> q;
    cout << "Enter Data for root node: " << endl;
    int data;
    cin >> data;
    root = new node(data); // creating root node dynamically
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter Left node for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->leftchild = new node(leftdata);
            q.push(temp->leftchild);
        }

        cout << "Enter Right node for: " << temp->data << endl;
        int Rightdata;
        cin >> Rightdata;
        if (Rightdata != -1)
        {
            temp->rightchild = new node(Rightdata);
            q.push(temp->rightchild);
        }
    }
}


//Following are the function for Traversals

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

int main()
{
    node *root = NULL;
    while (true)
    {
        cout << "**********************************MENU**************************" << endl;
        cout << "1:To create the Binary tree using recursion concept" << endl;
        cout << "2:To create the Binary tree level wise" << endl;
        cout << "3:To apply Level Order Traversal" << endl;
        cout << "4:To apply Preorder Traversal on Binary Trre" << endl;
        cout << "5:To apply Inorder Traversal on Binary Tree" << endl;
        cout << "6:To apply Postorder Traversal on Binary Tree" << endl;
        cout << "7:To exit" << endl;
        cout << "*****************************************************************" << endl;
        cout << "Enter Your Choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = BuildTree(root);
            break;
        case 2:
            buildforlevelorder(root);
            break;
        case 3:
            cout << "Printing the level order traversal" << endl;
            levelorderTraversal(root);
            break;
        case 4:
            cout << "preorder traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Inorder traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 6:
            cout << "postorder traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}