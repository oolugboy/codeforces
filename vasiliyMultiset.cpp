#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    public:
        Node * left;
        Node * right;
        int lCount;
        int rCount;
        Node():left(NULL), right(NULL), lCount(0), rCount(0){}
};
int getInt(bool bin[])
{
    int res = 0;
    for(int i = 0; i < 30; i++)
    {
        if(bin[i] == 1)
        {
            res += pow(2, (29 - i));
        }
    }
    return res;
}
void getBin(int n, bool bin[])
{
    for(int i = 0; i < 30; i++)
        bin[i] = 0;
    int ind = 29;
    while(n > 0)
    {
        bin[ind] = n % 2;
        n /= 2;
        ind--;
    }
}
void insert(Node & root,bool bin[])
{
    Node * curr = &(root);
    for(int i = 0; i < 30; i++)
    {        
        if(bin[i] == 1)
        {
            curr->lCount++;
            if(curr->left)
            {
                curr = (curr->left);
            }
            else
            {
                curr->left = Node();
                curr = (curr->left);
            }
        }
        if(bin[i] == 0)
        {
            curr->rCount++;
            if(curr->right)
                curr = (curr->right);
            else
            {
                curr->right = Node();
                curr = (curr->right);
            }
        }
    }
}
void del(Node & root, bool bin[])
{
    Node * curr = &(root);
    for(int i = 0; i < 30; i++)
    {        
        if(bin[i] == 1)
        {
            curr->lCount--;
            if(curr->lCount == 0)
            {
                curr->left = NULL;
                break;
            }
            else
                curr = (curr->left);
        }
        if(bin[i] == 0)
        {
            curr->rCount--;
            if(curr->rCount == 0)
            {
                curr->right = NULL;
                break;
            }
            else
                curr = (curr->right);
        }
    }
}
int getMax(Node & root, bool bin[])
{
    Node * curr = &(root);
    bool res[30];
    for(int i = 0; i < 29; i++)
        res[i] = 0;

    for(int i = 0; i < 30; i++)
    {
        if(bin[i] == 0)
        {
            if(curr->left)
            {
                res[i] = 1; 
                curr = &(curr->left);
            }
            else if(curr->right)
            {
                curr = &(curr->right);
            }
        }
        if(bin[i] == 1)
        {
            if(curr->right)
            {
                res[i] = 1;
                curr = &(curr->right);
            }
            else if(curr->left)
            {
                curr = &(curr->left)
            }
        }
    }
    return getInt(res);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    bool bin[30];
    getBin(0,bin);
    Node root = Node();
    insert(root,bin);
    int q = 0;
    cin >> q;
    while(q--)
    {
        string sign = "";
        int x = 0;
        cin >> sign >> x;
        getBin(x, bin);
        if(sign[0] == '+')
            insert(root, bin);
        else if (sign[0] == '-')
            del(root, bin);
        else 
            cout << getMax(root, bin) << endl;

    }


    return 0;
}
