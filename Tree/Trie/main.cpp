#include <bits/stdc++.h>
using namespace std;
//abcdefghijklmnopqrstuvwxyz
class node
{
public:
    node *child[26]; //a~z
    bool is_terminal;
    node()
    {
        is_terminal = true;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
class Tree
{
public:
    node *root;
    Tree() { root = new node(); }
    int find(const char *str)
    {
        node *curnode = root;
        int index = 0;
        while (*(str + index) != NULL)
        {
            curnode = curnode->child[*(str + index) - 'a'];
            if (curnode == NULL)
            {
                return index;
            }
            index++;
        }
        return index;
    }
    void insert(const char *str)
    {
        node *curnode = root;
        int index = 0;
        while (*(str + index) != NULL)
        {
            node *prevnode = curnode;
            curnode = curnode->child[*(str + index) - 'a'];
            if (curnode == NULL)
            {
                prevnode->is_terminal = false;
                curnode = prevnode->child[*(str + index) - 'a'] = new node();
            }
            index++;
        }
    }
    bool string_exist(const char *str)
    {
        int index = find(str);
        if (*(str + index) == NULL)
            return true;
        return false;
    }
    bool is_last(const char *str)
    {
        node *curnode = root;
        int index = 0;
        while (*(str + index) != NULL)
        {
            curnode = curnode->child[*(str + index) - 'a'];
            if (curnode == NULL)
            {
                return false;
            }
            index++;
        }
        return curnode->is_terminal;
    }
};
int main()
{
    Tree *tree = new Tree();
    tree->insert("abcdef");
    tree->insert("abef");
    tree->insert("vfdbcdef");
    if (tree->string_exist("vfdbcde")) cout << "string_exist"<<"\n";
    if (tree->is_last("abef")) cout << "last"<<"\n";
    return 0;
}