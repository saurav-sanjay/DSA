#include<iostream>
using namespace std;

//Structure of LL
struct Node{
    int data;
    struct Node* next;

    Node(int i){
        data=i;
        next=NULL;
    }
};

//Loop detection using Floy's Cycle Detection Algorithm
bool detectLoop(Node* head){
    Node* ptr=head;
    Node *slow, *fast;
    slow=fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=head;
    cout<<detectLoop(head)<<endl;
}