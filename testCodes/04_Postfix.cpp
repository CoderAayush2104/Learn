#include<bits/stdc++.h>

using namespace std;

class Array
{
    protected:
        int size;
        int length;
        int * arr;
    public:

        Array(int sz = 10)
        {
            size = sz;
            length = 0;
            arr = new int[size];
        }
        ~Array()
        {
            delete []arr;
            arr = NULL;
        }
        void swap(int* x, int* y);
        void display();
        void append(int x);
        void insert(int x, int index);
        int del(int index);
        int LinearSearch(int key);
        int BinarySearch(int key);
        int Get(int index);
        void Set(int index, int x);
        int Max();
        int Min();
        int Sum();
        float Average();
        void Reverse();
        void Insert_in_Sort(int x);
        bool IsSorted();
        void Rearrange();
        Array* Merge(Array arr2);  
};

void Array::swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Array::display()
{
    for(int i=0; i<length; i++)
    {
        cout<<arr[i]<<endl;
    }
}
void Array::append(int x)
{
    if(length<=size)
    {
        arr[length] = x;
    }
    length++;
}
void Array::insert(int x, int index)
{
    if(index>=0 && index<=length)
    {
        for(int i=length-1; i>=index; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[index] = x;
    }
    length++;
}
int Array::del(int index)
{
    int x=0;
    if(index>=0 && index<=length)
    {
        x = arr[index];
        for(int i=index; i<length-1; i++)
        {
            arr[i] = arr[i+1];
        }
        length--;
        return x;
    }
    return x;
}
int Array::LinearSearch(int key)
{
    for(int i=0; i<length; i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int Array::BinarySearch(int key)
{
    int s = 0;
    int e = length-1;
    while(s<=e)
    {
        int mid = s+e/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return -1;
}
int Array::Get(int index)
{
    if(index>=0 && index<=length-1)
    {
        return arr[index];
    }
    return -1;
}
void Array::Set(int index, int x)
{
    if(index>=0 && index<length)
    {
        arr[index] = x;
    }
}
int Array::Max()
{
    int max = arr[0];
    for(int i=1; i<length; i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
int Array::Min()
{
    int min = arr[0];
    for(int i=1; i<length; i++)
    {
        if(min>arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
int Array::Sum()
{
    int sum = 0;
    for(int i=0; i<length; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
float Array::Average()
{
    float average = Sum()/(float)length;\
    return average;
}
void Array::Reverse()
{
    for(int i=0; i<length/2; i++)
    {
        swap(&arr[i], &arr[length-1-i]);
    }
}
void Array::Insert_in_Sort(int x)
{
    int i = length-1;
    if(length == size)
    {
        return;
    }
    while(i>=0 && arr[i]>x)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = x;
    length++;
}
bool Array::IsSorted()
{
    for(int i=0; i<length-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            return false;
        }
    }
    return true;
}
void Array::Rearrange()
{
    //Rearrange array such that negative remain on left and positive on right
    int i,j;
    i=0;
    j= length-1;
    while(i<j)
    {
        while( arr[i]<0)i++;
        while( arr[j]>=0)j--;
        if(i<j)swap(& arr[i],& arr[j]);
    }
}
Array* Array::Merge(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(arr[i]<arr2.arr[j])
            arr3->arr[k++]=arr[i++];
        else
            arr3->arr[k++]=arr2.arr[j++];
    }
    for(;i<length;i++)
        arr3->arr[k++]=arr[i];

    for(;j<arr2.length;j++)
        arr3->arr[k++]=arr2.arr[j];
    arr3->length=length+arr2.length;

    return arr3;
}

class Stacks: private Array
{
    protected:

    int top;

    public:

    Stacks(int size = 10)
    {
        this->size = size;
        top = size-1;
    }
    void push(int data);
    int peek();
    int pop();
    bool isEmpty();
    bool isFull();
    void print();
};

void Stacks::push(int data)
{
    insert(data, length);
    top = length-1;
}
int Stacks::peek()
{
    return arr[top];
}
int Stacks::pop()
{
    int x = arr[top];
    del(top);
    top = length-1;
    return x;
}
bool Stacks:: isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else if(top<-1)
    {
        cout<<"Stack under-flow!!";
        return true;
    }
    return false;
}
bool Stacks:: isFull()
{
    if(top==size-1)
    {
        return true;
    }
    else if(top>size-1)
    {
        cout<<"Satck overflow!";
        return true;
    }
    return false;
}
void Stacks::print()
{
    for(int i=top; i>=0; i--)
    {
        cout<<arr[i]<<endl;
    }
}   
bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    {
        return false;
    }
    return true;
}
int precedence(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    return 0;
}
string toPostfix(string s)
{
    Stacks st;
    string postfix ="";

    for(int i=0; i<s.length(); i++)
    {
        if(isOperand(s[i]))
        {
            postfix += s[i];
        }
        else
        {
            while(precedence(s[i])<=precedence(st.peek()))
            {
                postfix += st.pop();
            }
            st.push(s[i]);
            
        }
    }
    while(!st.isEmpty())
    {
        postfix += st.pop();
    }

    return postfix;
}
int main()
{
    string s;
    cin>>s;

    string postfix = toPostfix(s);

    cout<<postfix;
    
    return 0;
}