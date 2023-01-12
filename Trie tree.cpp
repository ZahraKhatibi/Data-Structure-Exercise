#include <iostream>
using namespace std;

class node
{
    public:
        int counter = 0;
        node *next_left = 0;
        node *next_right = 0;

        
};

class tree
{
    public:
        void insert(string);
        void print(node*,string);
        node *root = new node;
};

int main()
{
    int n;
    string data;
    tree Tree;
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        cin>>data;
        Tree.insert(data);
    }
    Tree.print(Tree.root , "");
}

void tree :: insert(string data)
{
    node *root_tree = root;
    for(int i=0 ; i<data.size() ; i++)
    {
        if(data[i]=='0')
        {
            if(root_tree->next_left == 0)
                {
                    root_tree->next_left = new node;
                    root_tree = root_tree->next_left;
                }
                else
                    root_tree = root_tree->next_left;
        }
        else if(data[i]=='1')
        {
            if( root_tree->next_right == 0)
            {
                root_tree->next_right = new node;
                root_tree = root_tree->next_right;
            }
            else
                root_tree = root_tree->next_right;
        }
    }
    root_tree->counter = root_tree->counter + 1;
}

void tree :: print(node*root_result , string result)
{
    while(root_result->counter > 0)
    {
        cout<< result << " ";
        root_result->counter = root_result->counter - 1;
    }
    if(root_result->next_left != 0)
    {
        print(root_result->next_left,result+'0');
    }
    if(root_result->next_right != 0)
    {
        result += '1';
        print(root_result->next_right , result);
    }
}