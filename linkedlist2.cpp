#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node *next;
     Node(int data){
         this->data=data;
         next=NULL;
     } 

};

/*Node* takeInput(){  //time complexity is O(n^2) for inserting n nodes.
    int data;
    cin>>data;
    Node *head=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin>>data;
    }
    return head;
}*/
Node* takeInput_better(){   //optimised code:time complexity is O(n) for inserting n nodes.
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;//tail=newNode;
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}




int main(){
      Node *head=takeInput_better();
      print(head);
}