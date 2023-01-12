#include <iostream>
using namespace std;

class node
{
    public:
        node(int x1, int y1)
        {
            x = x1;
            y = y1;
            distance = (x*x) + (y*y);
        }
        int x,y,distance;
};

class heap
{
    public:
        heap(int n)
        {
            size = n;
            que = new node *[n] ;
        }
        void insert(int,int);
        bool compare(node*,node*);
        void check(int);
        void check2(int);
        node* delete_root();
    private:
        int size = 0;
        int temp = 0;
        node **que;
};

int main()
{
    int n,k,x_,y_;
    cin >> n >> k;
    heap result(n);
    node* print;
    for(int i=0 ; i<n ; i++)
    {
        cin >> x_ >> y_;
        result.insert(x_,y_);
    }
    for(int i=0 ; i<k ; i++)
    {
        print = result.delete_root();
        cout<< print->x << " " << print->y << endl;
    }
}

void heap :: insert(int x, int y)
{
    if(temp == 0)
        que[++temp] = new node(x,y); 

    else
    {
        que[++temp] = new node (x,y);
        check(temp);
    }

}

bool heap :: compare(node *child , node *father)
{
    if(child->distance < father->distance)
        return true;
    if(child->distance > father->distance)
        return false;
    if(child->distance == father->distance)
    {
        if(child->x < father->x)
            return true;
        if(child->x > father->x)
            return false;
        if(child->x == father->x)
        {
            if(child->y <= father->y)
                return true;
            else
                return false;
        }
    }
    return false;
}

void heap :: check(int a)
{
    if(a <= 1)
        return;
    if(compare(que[a],que[a/2]))
    {
        swap(que[a],que[a/2]);
        check (a/2);
    }
}

node* heap :: delete_root()
{
    swap(que[1],que[temp]);
    temp--;
    check2(1);
    return que[temp+1];
}

void heap :: check2(int a)
{
    if((2*a)+1 <= temp)
    {
        if(compare(que[a],que[a*2]) && compare(que[a],que[(a*2)+1]) )
        {
            return;
        }
        if(compare(que[2*a],que[(2*a)+1]))
        {
            swap(que[a],que[2*a]);
            check2(2*a);
        }
        else
        {
            swap(que[a],que[(2*a)+1]);
            check2((2*a)+1);
        }   
    }

    else if( 2*a <= temp)
    {
        if(compare(que[2*a],que[a]))
        {
            swap(que[a],que[2*a]);
            check2(2*a); 
        }     
    }
}


