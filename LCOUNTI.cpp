#include<iostream>
using namespace std;
//Find length of linked list - Non-Recursive/Iterative

struct node
{
	int value;
	struct node *next;
};
	
main()
{ 
struct node *head = NULL,*temp,*curr;
int q,c=1,i;

do {
cout<<"Enter a value to push into the list: ";
cin>>q;
temp = new node;
temp->value=q;
temp->next = NULL;
if(head==NULL)     //adding first element
	head = temp;
else				//adding consequent elements
{	
	for(curr=head;curr->next!=NULL;curr=curr->next);
	curr->next=temp;
}
cout<<"Do you want to add more elements to your list?";
cin>>c;
}while(c!=0);
cout<<endl;
//Displays the list entered
cout<<"The list input is:\t";
if(head!=NULL)
{
	for(temp=head;temp!=NULL;temp=temp->next)
		cout<<temp->value<<" ";
}
else
	cout<<"Empty list."<<endl;
//Iteration by for loop	
for(i=0, curr=head; curr!=NULL; curr=curr->next,i++);
cout<<"\nThe length of the list (found by iteration) = "<<i<<endl;
}
