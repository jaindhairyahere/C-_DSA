#include <iostream>
using namespace std;

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


void InsertFront(Node** head,Node** tail, int data)
{
    if((**head).next == NULL){
         cout<<"\nMaking new Node :"<<data;
         (**head).next = GetNewNode(data);
         (**tail).prev = (**head).next;
         ((**head).next)->next=*tail;
         ((**head).next)->prev=*head;
         return ;}
    else {
        cout<<"\nMaking new Node :"<<data;
        (*((**head).next)).prev = GetNewNode(data);
        ((*(**head).next).prev)->next = (**head).next;
        (**head).next = (*(**head).next).prev;
        ((**head).next)->prev=*head;
        return;
        }
}

Node* InsertAfter(Node* target,int data);

Node* InsertBack(Node* tail,int data);


void PopBack(Node** tail);



int PopFront(Node** head)
{
}



int main(int argc, char const *argv[])
{
    Node* head = NULL;  Node* tail = NULL;
    InsertFront(&head,&tail,50);

    return 0;
}
