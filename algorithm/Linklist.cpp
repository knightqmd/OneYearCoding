#include<iostream>
using namespace std;

typedef struct Node 
{
    int val;
    struct Node* ne;
}Node;

Node* head;

void Insert(int index ,int val)
{
    Node* temp = head;
    while(index--)
    {
        temp = temp->ne;
    }
    Node* newnode = new Node();
    newnode->val = val;
    newnode->ne = temp->ne;
    temp->ne = newnode;
}
void remove(int index)
{
    index = index-1;
    Node* ptr = head;
    while(index--)
    {
        ptr = ptr->ne;
    }
    Node* x = ptr->ne;
    ptr->ne = ptr->ne->ne;
    delete x;
}

void head_insert(int val)
{
    Node* temp = new Node();
    temp->val = val;
    temp->ne = head->ne;
    head->ne = temp;
}

int main()
{
    head = new Node();
    head->ne = NULL;
    int m;
    cin>>m;
    while(m--)
    {
        char cmd;
        if(cmd == 'H')
        {
            int val;
            cin>>val;
            head_insert(val);
        }
        else if(cmd == 'I')
        {
            int index,val;
            cin>>index>>val;
            Insert(index,val);
        }
        else
        {
            int index;
            cin>>index;
            remove(index);
        }
    }
    Node* ptr = head;
    while(ptr->ne)
    {
        cout<<ptr->val<<" ";
        ptr = ptr->ne;
    }
    cout<<endl;
    return 0;
}