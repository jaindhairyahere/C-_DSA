#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* ahead;
    Node* before;
};

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->ahead = NULL;
    newNode->before = NULL;
}


Node* InsertNode(Node* head, int data){
    if(head == NULL){ head = GetNewNode(data); return head;}
    else if(head->before != NULL){
        InsertNode(head->before,data);}
    else{
        head->before = GetNewNode(data);
        (head->before)->ahead = head;
    }
}

int PopNode(Node** head)
{
    if(*head==NULL){cout<<((**head).ahead)->data; return ((**head).ahead)->data;}
    else{
        PopNode(&(**head).before);
    }
}



int main(int argc, char const *argv[])
{
    Node* front = NULL;
    Node* end = NULL;
    front = InsertNode(front,10);
    front = InsertNode(front,20);
    front = InsertNode(front,30);
    front = InsertNode(front,40);
    front = InsertNode(front,50);
    front = InsertNode(front,60);
    front = InsertNode(front,70);

    PopNode(&front);
    PopNode(&front);
    return 0;
}
