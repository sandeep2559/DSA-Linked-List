#include <iostream>

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
Node* reverse(Node *head2){
    if(head2==NULL || head2->next==NULL){
        return head2;
    }
    Node *sans=reverse(head2->next);
    Node *tail=head2->next;
    tail->next=head2;
    head2->next=NULL;
    return sans;
}
bool isPalindrome(Node *head)
{
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node *slow=head;
    Node *fast=head->next;
   // Node *head2=NULL;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
}
   
        Node *head2=slow->next;
        slow->next=NULL;
    Node *temp=reverse(head2);
    print(head);
    print(temp);
    while(temp!=NULL && head!=NULL){
        if(head->data!=temp->data){
            return false;
}
temp=temp->next;
        head=head->next;
}
return true;
    
}
/*void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}*/

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}