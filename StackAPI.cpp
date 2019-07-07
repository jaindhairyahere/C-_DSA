#include <iostream>
using namespace std;

//Using Linked List
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
}

void Push(int data,Node* Top)
{
    if(Top->prev == NULL)
    {
        cout<<"\nCreating Stack with :"<<data;
        Top->prev = GetNewNode(data);
        (Top->prev)->next = Top;
        (Top->prev)->prev = NULL;
        return;
    }
    else{
        cout<<"\nInserting  :"<<data;
        (Top->prev)->next = GetNewNode(data);
        ((Top->prev)->next)->prev = Top->prev;
        Top->prev = (Top->prev)->next;
        (Top->prev)->next=Top;
        return;
    }
}

bool isEmpty(Node* Top)   { return (Top->prev==NULL);}

int Pop(Node* Top)
{
    if(isEmpty(Top))
    {
        cout<<"\nNothing to Pop";
        return 1e5;
    }
    else{
        ((Top->prev)->prev)->next = Top;
        Node* temp  = ((Top->prev)->prev);
        int popeddata = (Top->prev)->data;
        delete (Top->prev);
        Top->prev  = temp;
        return  popeddata;
    }
}

int GetTop(Node* Top)
{
    return (Top->prev)->data;
}

int main(int argc, char const *argv[])
{
    Node* Top = new Node();

    Push(50,Top);
    Push(20,Top);
    Push(30,Top);
    Push(70,Top);
    Push(10,Top);
    cout<<'\n';
    cout<<Pop(Top)<<"\n";
    cout<<Pop(Top)<<"\n";
    cout<<"\n Top Element : "<<GetTop(Top)<<"\n";

    return 0;
}
