#include<iostream>
using namespace std;
//Segregate the even and odd values based on the data in the nodes into two linked lists.

struct node
{
	int value;
	struct node *next;
};

class list
{
	struct node *head;
	int n;
public:
	list()
	{
	 head = NULL;
	 n = 0;
    }
    
    void insEnd(int x)
    {
    	struct node  *temp,*curr;
		temp = new node;
		temp->value=x;
		temp->next = NULL;
		if(head==NULL)     //adding first element
		{ 
			head = temp;
			n++;
			return;
		}
		for(curr=head;curr->next!=NULL;curr=curr->next);
		curr->next=temp;
		n++;
    }
    
    void disp()
    {
    	struct node *temp;
		if(head!=NULL)
		{
			for(temp=head;temp!=NULL;temp=temp->next)
				cout<<temp->value<<" ";
		}
		else
			cout<<"Empty list."<<endl;
    }
    
    friend void eovalues(list l);
};
	
void eovalues(list l)
	{
	list e,o;
	struct node *p;
	for(p=l.head;p!=NULL;p=p->next)
	{
			if(p->value%2==0)
				e.insEnd(p->value);
			else
				o.insEnd(p->value);
	}
	cout<<"Even List: ";
	e.disp();
	cout<<endl;
	cout<<"Odd List: ";
	o.disp();
	cout<<endl;
	}
	
main()
{ 
list l;
int q,c=1;
do
{
cout<<"Enter a value for the list: ";
cin>>q;
l.insEnd(q);
cout<<"Do you want to add elements to your list?";
cin>>c;
}while(c!=0);
cout<<"The list entered is:";
l.disp();
cout<<endl;
eovalues(l);
}
