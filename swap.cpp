#include <iostream>
#include<math.h>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *swapNodes(Node *head, int i, int j)
{
	if(i==0||j==0){
        Node *c1=head;
        Node *p1=head->next;
        int count=0;
        while(count<j-1){
            head=head->next;
            count++;
        }
        Node *p2=head;
        Node *c2=head->next;
        p2->next=c1;
        c1->next=c2->next;
        c2->next=p1;
        return c2;
}
   if(abs(i-j)==1){
        int x=min(i,j);
        int count=0;
        Node *temp=head;
        while(count<x-1){
            head=head->next;
            count++;
        }
        Node *p1=head;
        Node *c1=head->next;
        Node *c2=head->next->next;
        Node *p2=head->next->next->next;
        p1->next=c2;
        c2->next=c1;
        c1->next=p2;
        return temp;
        
}
    /*if(i==0||j==0 && abs(i-j)==1){
        Node *c1=head;
        Node *c2=head->next;
        Node *p2=head->next->next;
        c2->next=c1;
        c1->next=p2;
        return c2;
    }*/
    else{
        Node *temp=head;
        Node *curr=head;
        int count=0;
        while(count<i-1){
            count++;
            temp=temp->next;
        }
        Node *p1=temp;
        cout<<p1->data<<endl;
        Node *c1=temp->next;
        cout<<c1->data<<endl;
        count=0;
        while(count<j-1){
            count++;
            curr=curr->next;
        }
        Node *p2=curr;
        Node *c2=curr->next;
        cout<<p2->data<<endl;
        cout<<c2->data<<endl;
        p1->next=c2;
        p2->next=c1;
        c1->next=c2->next;
        c2->next=p2;

        return head;
    }
    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}