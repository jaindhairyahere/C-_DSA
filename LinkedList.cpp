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
        cout<<"\nMaking First new Node at Front(DP) :"<<data;
        (**head).next = GetNewNode(data);
        (**tail).prev = (**head).next;
        ((**head).next)->next=*tail;
        ((**head).next)->prev=*head;
        return ;}
    else {
        cout<<"\nMaking new Node at Front(DP) :"<<data;
        (*((**head).next)).prev = GetNewNode(data);
        ((*(**head).next).prev)->next = (**head).next;
        (**head).next = (*(**head).next).prev;
        ((**head).next)->prev=*head;
        return;
        }
}

void InsertFront(Node* head, Node* tail, int data)
{
    if(head->next == NULL)
    {
        cout<<"\nMaking First new Node at Front(SP) :"<<data;
        head->next = GetNewNode(data);
        tail->prev = head->next;
        (head->next)->next = tail;
        (head->next)->prev = head;
        return;
    }
    else{
        cout<<"\nMaking new Node at Front(SP) :"<<data;
        (head->next)->prev = GetNewNode(data);
        ((head->next)->prev)->next = head->next;
        head->next = (head->next)->prev;
        (head->next)->prev=head;
        return;
    }
}


void InsertAfter(Node* target,int data)
{
    if(target->next == NULL)
    {
        cout<<"\nMaking First new Node at Front(SP) :"<<data;
        Node* temp = GetNewNode(data);
        temp->prev = target;
        temp->next = target->next;
        target->next = temp;
        (temp->next)->prev = temp->next;
        return;
    }
    else{
        cout<<"\nMaking new Node at Front(SP) :"<<data;
        (head->next)->prev = GetNewNode(data);
        ((head->next)->prev)->next = head->next;
        head->next = (head->next)->prev;
        (head->next)->prev=head;
        return;
    }
}

void InsertBack(Node* head,Node* tail,int data)
{
    if(tail->prev == NULL)
    {
        cout<<"\nMaking First new Node at End(SP) :"<<data;
        head->next = GetNewNode(data);
        tail->prev = head->next;
        (head->next)->next = tail;
        (head->next)->prev = head;
        return;
    }
    else{
        cout<<"\nMaking new Node at End(SP) :"<<data;
        (tail->prev)->next = GetNewNode(data);
        ((tail->prev)->next)->prev = tail->prev;
        tail->prev = (tail->prev)->next;
        (tail->prev)->next=tail;
        return;
    }
}


void PopBack(Node* tail)
{
    if(tail->prev == NULL)
    {
        cout<<"\nNo Node at End(SP) .... Aborting this Method";
        return;
    }
    else{
        ((tail->prev)->prev)->next = tail;
        Node* temp  = ((tail->prev)->prev);
        delete (tail->prev);
        tail->prev  = temp;
    }
}


void PopFront(Node* head)
{
    if(head->next == NULL)
    {
        cout<<"\nNo Node at End(SP) .... Aborting this Method";
        return;
    }
    else{
        ((head->next)->next)->prev = head;
        Node* temp  = ((head->next)->next);
        delete (head->next);
        head->next  = temp;
    }
}

int GetFront(Node* head)
{
    return (head->next)->data;
}

int GetLast(Node* tail)
{
    return (tail->prev)->data;
}

int main(int argc, char const *argv[])
{
    Node* head = new Node();  Node* tail = new Node();

    InsertFront(head,tail,50);
    InsertFront(head,tail,20);
    InsertFront(head,tail,30);
    InsertBack(head,tail,70);
    InsertBack(head,tail,10);
    InsertFront(&head,&tail,90);
    InsertFront(&head,&tail,100);
    PopBack(tail);
    PopFront(head);

    cout<<"\n Front Element : "<<GetFront(head);
    cout<<"\n Last  Element : "<<GetLast(tail)<<"\n";

    return 0;
}
