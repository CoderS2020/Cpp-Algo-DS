#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
};

void insertAtHEad(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deleteNode(node *&head, int val)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
    node *&todelete = temp->next;
    delete todelete;
}

//To reverse a node we have two methods: Iterative and recursive
node *reverseIterative(node *&head)
{
    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

node * reverseRecursive(node * & head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    node * newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

//reverse k nodes
node * reversekNodes(node * & head,int k){
    node * prevPtr=NULL;
    node * currPtr=head;
    node * nextPtr;

    int count=0;
    while(currPtr!=NULL && count<k){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }

    if(nextPtr!=NULL){
        head->next=reversekNodes(nextPtr,k);
    }

    return prevPtr;

}

//For display and search we pass pointer as argument unlike insertion of nodes at start/end
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    { //Not temp->data!=NULL
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    { //Not temp->data!=NULL
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
};


void makeCycle(node * & head,int pos){
    node * temp=head;
    node * startNode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}


bool detectCycle(node * & head){
    node * slow=head;
    node * fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
        return true;
    }
    }
    
    return false;
}

void removeCycle(node * & head){
    node * slow=head;
    node * fast=head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    
    slow->next=NULL;
}

//Put Even Position NOdes after Odd Position Nodes
void evenAfterOdd(node * & head){
    node * odd=head;
    node * even=head->next;
    node * evenStart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    // insertAtHEad(head, 5);
    // display(head);
    // cout<<search(head,2)<<endl;
    // cout<<search(head,7);
    // deleteNode(head,3);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    // node *newhead = reverseIterative(head);
    // node *newhead = reverseRecursive(head);
    // node * newhead= reversekNodes(head,2);
    // display(newhead);
    // makeCycle(head,3)   ;
    // cout<<detectCycle(head);
    // removeCycle(head);
    evenAfterOdd(head);
    display(head);

    return 0;
}