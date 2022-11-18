#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:

    int data;
    Node * next;
};
class LinkedList
{
    protected:

    Node* Head;

    public:

    int length()
    {
        int length = 0;
        Node* temp = Head;
        while(temp != nullptr)
        {
            length++;
            temp = temp->next;
         }
        return length;
    }

    void insert(int index, int value)
    {
        if(index>=0 && index<=length())
        {
            if(index == 0)
            {
                Node* x = new Node;
                x->data = value;
                x->next = Head;
                Head = x;
                // display(Head);
            }
            else
            {
                Node* temp = Head;
                for(int i= 1; i<=index-1; i++)
                {
                    temp = temp->next;
                }
                Node* new_temp;
                new_temp = new Node;
                new_temp->data = value;
                new_temp->next = temp->next;
                temp->next = new_temp;
            }
        }
    }
    void remove(int index)
    {
        if(index == 0)
        {
            Node* p = Head;
            p = p->next;
            Head = p;
        }
        else
        {
            Node* temp = Head;
            for(int i=0; i<index-1; i++)
            {
                temp = temp->next;
            }
            Node* p = temp->next;
            temp->next = temp->next->next;
            p->next = NULL;
            delete p;
        }
    }
};

class Stacks: private LinkedList
{
    protected:

    Node* top;

    public:

    Stacks()
    {
        Head = NULL;
        top = Head;
    }
    void push(int data);
    void peek();
    void pop();
    bool isEmpty();
    bool isFull();
    void print();
};

void Stacks::push(int data)
{
    insert(0,data);
    top = Head;
}
void Stacks::peek()
{
    cout<<top->data<<endl;
}
void Stacks::pop()
{
    remove(0);
    top = Head;
}

void Stacks::print()
{
    Node* temp = top;

    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next; 
    }
}   

int main()
{
    Stacks S1;
    S1.push(5);
    S1.push(12);
    S1.push(13);
    S1.push(14);
    S1.push(20);
    S1.print();
    
    S1.pop();
    S1.print();

    return 0;
}