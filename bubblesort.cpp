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

Node* takeInput(){
    int data;
    Node *head=NULL;
    Node *tail=NULL;
    cin>>data;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;

}
int lengthofLL(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count; 
}
Node* reverse(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *smallAns=reverse(head->next);
    Node *tail=head->next;
    tail->next=head=head;
    head->next=NULL;
    return smallAns;

    }
    Node* bubblesort(Node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        int n=lengthofLL(head);
        cout<<n<<endl;
        Node *prev=NULL;
        Node *curr=NULL;
        Node *next=NULL;
        for(int i=0;i<n;i++){
             curr=head;
             prev=NULL;
             while(curr->next!=NULL){
                {
                   if()
                     prev=curr;
                     curr=curr->next;
                    // prev=curr;
                   //  temp=temp->next;
                 }
                 else{
                     next=curr->next;
                     curr->next=next->next;
                     prev->next=next;
                     next->next=curr;
                 }
             }
        }
        return head;
    }
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node *head=takeInput();
   print(head);
    //Node *temp=reverse(head);
    Node *temp=bubblesort(head);
    print(temp);
    return 0;
}