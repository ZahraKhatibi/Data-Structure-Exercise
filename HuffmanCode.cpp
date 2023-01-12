#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        char letter;
        node *left = 0;
        node *right = 0;
};

class queue
{
    public:
        queue(int n)
        {
            size = n;
            que = new node *[n] ;
            for(int i=0 ; i<n ; i++)
                que[i] = 0;
        }
        node* pop();
        void insert(node*);
        void tree();
        void hufman(string);
    private:
        int size = 0;
        int temp = -1;
        node **que;
};

int main()
{
    int n,counter;
    cin >> n;
    char A;
    string code;
    queue result_que(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> A ;
        cin >> counter ;
        node *List = new node ;
        List->data = counter;
        List->letter = A;
        result_que.insert(List);
    }
    cin>> code;
    result_que.tree();
    result_que.hufman(code);
    
}

void queue :: insert(node* List)
{
    if(temp == -1)
        que[0] = List;
    for(int i=temp ; i>=0 ; i--)
    {
        if((que[i]->data) <= List->data)
        {
            for(int j=temp ; j>i ;j--)
                que[j+1] = que[j];   
            que[i+1] = List;
            break;
        }
        if(i==0)
        {
            for(int j=temp ; j>=0 ;j--)
                que[j+1] = que[j];   
            que[0] = List;
        }
    }
    temp++;
}

node * queue :: pop()
{
    node *a = que[0];
    for(int i=0 ; i<temp ; i++)
        que[i]= que[i+1];
    temp--;
    return a;
}

void queue :: tree()
{
    while(temp>0)
    {
        int a = que[0]->data;
        int b = que[1]->data;
        node *list = new node;
        list->left = pop();
        list->right = pop();
        list->letter = '*';
        list->data = a+b;
        insert(list);
    }
}

void queue :: hufman(string str)
{
    node *x = que[0] ;
    for(int i=0 ; i<str.size() ; i++)
    {
        if(str[i]=='1')
        {
            que[0]= que[0]->left;
        }
        if(str[i]=='0')
        {
            que[0]= que[0]->right;
        }
        if(que[0]->letter != '*')
        {
            cout<<que[0]->letter;
            que[0] = x;
        }
    }
}