#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *parent = NULL;
    node *left = NULL;
    node *right = NULL;
    int data = 0;
    node(int value)
    {
        data = value;
    }
    void push(node *prev, int value)
    {
        if (data < value)
        {
            if (right == NULL)
                right = makenode(value);
            else
                right->push(this, value);
        }
        else if(data>value)
        {
            if (left == NULL)
                left = makenode(value);
            else
                left->push(this, value);
        }
        else cout<<"이미 존재합니다."<<endl;
    }
    void delete_(int value) //root제거할경우는 왼쪽자식이있을경우 왼쪽중 가장큰값을 채워넣음, 왼쪽없을경우 오른쪽이 루트가됨
    {
        if (data < value)
        {   
            if( right == NULL) cout << "존재하지않음" << endl; //비어있지않을때
            else right->delete_(value);
        }
        else if (data < value)
        {   
            if( left == NULL) cout << "존재하지않음" << endl; //비어있지않을때
            else left->delete_(value);
        }
        else
        {
            node *removenow = this;
            left->parent = parent;
            right->parent = parent;
            parent->left = this->left;
            parent->right = this->right;
            delete removenow;
        }
    }
    void preorder()
    {
        cout << data << " ";
        if (left != NULL)
            left->preorder();
        if (right != NULL)
            right->preorder();
    }
    node *makenode(int value)
    {
        node *new_node = new node(value);
        new_node->parent = this;
        return new_node;
    }
};
struct BinarySearchTree
{
    node *root = NULL;
    void push(int value);
    void delete_(int value);
    void clear();
    void preorder();
};
void BinarySearchTree::push(int value)
{
    if (root == NULL)
        root = new node(value);
    else
        root->push(root, value);
}
void BinarySearchTree::delete_(int value)
{
    if (root == NULL)
        cout << "empty";
    else
        root->delete_(value);
}
void BinarySearchTree::preorder()
{
    if (root != NULL)
        root->preorder();
}
int main()
{
    BinarySearchTree tree;
    for (int i = 0; i < 15; i++)
    {
        tree.push(rand() % 15 + 1);
    }
    tree.preorder();
    cout << "";
    return 0;
}