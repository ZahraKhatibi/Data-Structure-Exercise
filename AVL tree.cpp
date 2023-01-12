#include<iostream>
#include<string>
using namespace std;

int convert_to_int(string str);

class node
{
public:
    node(int d)
    {
        data=d;
    }
    int data, height=0,num=1;
    int count=1;
    node *left=0, *right=0;
};

class avl_tree{
public:
    node *root = 0;
    node *insert(node*,int);
    int height_calc(node *);
    int get_balance(node *);
    node *rebalance(node*);
    node *rotate_left(node*);
    node *rotate_right(node*);
    int find_n(node*,int n);
    int node_counter(node*);
};


int main(){
    double *result = new double [100000];
    avl_tree my_tree;
    string s="";
    int c=0;
    while(s!="q")
    {
        cin>>s;
        if(s=="q")
            break;
        c++;
        my_tree.root = my_tree.insert(my_tree.root,convert_to_int(s));
        if(c%2==1)
        {
            result[c-1] = my_tree.find_n(my_tree.root,c/2+1);
        }
        else
        {
            result[c-1] = (my_tree.find_n(my_tree.root,c/2+1) + my_tree.find_n(my_tree.root,c/2))/2.0;
        }
    }
    for(int i=0;i<c;i++)
        cout<<result[i]<<endl;

    return 0;
}

int avl_tree :: find_n(node* q,int n){
    if(node_counter(q->left) >= n)
        return find_n(q->left,n);

    else if(node_counter(q->left) + q->num < n)
        return find_n(q->right,n-node_counter(q->left) - q->num);

    else
        return q->data;
}

int avl_tree :: node_counter(node* q){
    if(q==0)
        return 0;
    else return q->count;
}

node* avl_tree :: rotate_right(node* q)
{
    node* p = q->left;
    q->left = p->right;
    p->right = q;
    q->height = max(height_calc(q->left), height_calc(q->right))+1;
    p->height = max(height_calc(p->left), height_calc(p->right))+1;

    q->count = q->num + node_counter(q->left) + node_counter(q->right);
    p->count = p->num + node_counter(p->left) + node_counter(p->right);

    return p;
}

node* avl_tree :: rotate_left(node* q)
{
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    q->height=max(height_calc(q->left), height_calc(q->right))+1;
    p->height=max(height_calc(p->left), height_calc(p->right))+1;

    q->count = q->num + node_counter(q->left) + node_counter(q->right);
    p->count = p->num + node_counter(p->left) + node_counter(p->right);

    return p;
}

node* avl_tree :: rebalance(node* q)
{

    q->height=max(height_calc(q->right),height_calc(q->left)) + 1;

    if (get_balance(q) == 2)
    {
        if(get_balance(q->left) == 1)
            return rotate_right(q);

        if( get_balance(q->left) == -1)
        {
            q->left = rotate_left(q->left);
            return rotate_right(q);
        }
    }

    if (get_balance(q) == -2)
    {
        if(get_balance(q->right) == -1)
            return rotate_left(q);

        if(get_balance(q->right) == 1)
        {
            q->right = rotate_right(q->right);
            return rotate_left(q);
        }
    }
    
    return q;
}

node* avl_tree :: insert(node* new_root, int data)
{
    if(!new_root)
        return new node(data);

    new_root->count++;

    if(data < new_root->data)
        new_root->left = insert(new_root->left, data);

    else if(data > new_root->data)
        new_root->right = insert(new_root->right, data);

    else
    {
        new_root->num++;
        return new_root;
    }

    return rebalance(new_root);
}

int convert_to_int(string str)
{
    string dict="0123456789";
    int a=0;
    if(str[0]=='-')
    {
        return -1 * convert_to_int(str.substr(1,str.size()-1));
    }
    for(int b=0 ; b<str.size() ; b++)
    {
        for(int i=0;i<10;i++)
        {
            if(dict[i]==str[b])
                a = (a*10) + i ;
        }
    }
    return a;
}

int avl_tree :: get_balance(node *q)
{
    if(q == 0)
        return 0;
    else
        return height_calc(q->left) - height_calc(q->right);
}

int avl_tree :: height_calc(node *q)
{
    if(q == 0)
        return -1;
    else
    {
        q->height = max(height_calc(q->left), height_calc(q->right)) + 1;
    }
    return q->height;
}

