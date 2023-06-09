#include <iostream>
#include <string>
#include <vector>
#include <queue>
/*
Program of Practical 3rd General Tree
understood the logic
do dry run to recall the logic
Time Complexity O(n)
Space Complexity O(n)
*/
using namespace std;
class node // creating node as ADT
{
public:
    string data;          // 1
    vector<node *> child; // creating an vector which stores element of node datatype
};
node *createnode(string data)
{
    node *temp = new node; // officially creates a node
    temp->data = data;     // enter the data in created node
    return temp;           // returns the node back to int main()
}
// displaying the tree
void levelordertraversal(node *root)
{
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {
            node *p = q.front();
            q.pop();
            cout << p->data << " "
                 << " ";
            for (int i = 0; i < p->child.size(); i++)
            {
                q.push(p->child[i]);
            }
            n--;
        }
        cout << endl;
    }
}
int main()
{
    string str1, s1, s2, s3, sa1, sa2, sa3, sb1, sb2, sb3, sc1, sc2, sc3;
    cout << "Enter chapter number:" << endl;
    cin >> str1;
    node *root = createnode(str1);

    // sections
    cout << "Enter how many sections do you want under " << str1 << " chapter" << endl;
    int n;
    cin >> n;
    cout << "Enter " << n << " sections:";
    cin >> s1;
    cin >> s2;
    cin >> s3;
    (root->child).push_back(createnode(s1)); // 0 index
    (root->child).push_back(createnode(s2)); // 1 index
    (root->child).push_back(createnode(s3)); // 2 index
    // sub sections

    // child of the element present at 0th index
    cout << "How many subsections do you want under " << s1;
    int n1;
    cin >> n1;
    cout << "Enter " << n1 << " subsections:" << endl;
    cin >> sa1;
    cin >> sa2;
    cin >> sa3;
    (root->child[0]->child).push_back(createnode(sa1));
    (root->child[0]->child).push_back(createnode(sa2));
    (root->child[0]->child).push_back(createnode(sa3));

    // child of the element present at 1st index
    cout << "How many subsections do you want under " << s2;
    int n2;
    cin >> n2;
    cout << "Enter " << n2 << " subsections:" << endl;
    cin >> sb1;
    cin >> sb2;
    cin >> sb3;
    (root->child[1]->child).push_back(createnode(sb1));
    (root->child[1]->child).push_back(createnode(sb2));
    (root->child[1]->child).push_back(createnode(sb3));

    // child of the element present at 2nd index
    cout << "How many subsections do you want under " << s3;
    int n3;
    cin >> n3;
    cout << "Enter " << n3 << " subsections:" << endl;
    cin >> sc1;
    cin >> sc2;
    cin >> sc3;
    (root->child[2]->child).push_back(createnode(sc1));
    (root->child[2]->child).push_back(createnode(sc2));
    (root->child[2]->child).push_back(createnode(sc3));

    cout << "Level order traversal of the tree is: " << endl;
    levelordertraversal(root);
}