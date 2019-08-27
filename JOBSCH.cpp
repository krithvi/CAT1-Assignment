#include<iostream>
using namespace std;
//Job Scheduling - minimization of average completion time

struct node
{
	string j;
	float p;
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
    
    void addJob(string s,float f)   //insEnd
    {
    	struct node  *temp,*curr;
		temp = new node;
		temp->j=s;
		temp->p=f;
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
    
    void disp() 			//displays the list in Tabular form
    {
    	struct node *temp;
		if(head!=NULL)
		{
			cout<<"\tJob Name\tProcessing time"<<endl;
			for(temp=head;temp!=NULL;temp=temp->next)
				cout<<"\t"<<temp->j<<"\t\t"<<temp->p<<endl;
		}
		else
			cout<<"Empty list."<<endl;
    }
    
    void split(struct node *source, struct node **frontRef, struct node **backRef)    //function to split list into two
	{ 
	struct node *mid,*curr; 
    mid = source; 
    curr = source->next; 
    /*when 'curr' runs past two nodes,'mid' runs past one node */
    while (curr != NULL) 
	{ 
        curr = curr->next; 
        if (curr != NULL) 
		{ 
            mid = mid->next; 
            curr = curr->next; 
        } 
    } 
    *frontRef = source; 
    *backRef = mid->next;
	mid->next = NULL; 
	} 
	
	struct node* merger(struct node *a, struct node *b)        //Function to merge lists
	{ 
		struct node *result = NULL; 
    	if (a == NULL) 
    	{	
			return b;
		}
    	else if (b == NULL) 
    	{	
			return a; 
		}
		if (a->p <= b->p) 
		{ 
    		result = a; 
    		result->next = merger(a->next, b); 
    	} 
    	else 
		{ 
    		result = b; 
    		result->next = merger(a, b->next); 
    	} 
    	return result; 
	}
	
	void sort(struct node **headr)                 //function to perform MergeSort
	{
		if(*headr==NULL||(*headr)->next==NULL)
			return;
		struct node *a=NULL;
		struct node *b=NULL; 
		split(*headr,&a,&b);
		sort(&a); 
    	sort(&b); 
    	*headr = merger(a,b);
	}
	
	void Schedule()
	{ 
		sort(&head);      //average time can be minimized when work is done in the order of increasing processing time
	}
};

main()
{
	list s;
	int ch=1;
	string n;
	float t; 
	while(ch!=3)
	{
		cout<<"*# JOB SCHEDULING #*"<<endl;
		cout<<" 1. Add Job\n 2. Print Schedule\n 3. Exit\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter Name of job: ";
				cin>>n;
				cout<<"Enter Processing time: ";
				cin>>t;
				s.addJob(n,t);
				s.disp();
			break;
			case 2:
				s.Schedule();
				s.disp();
			break;
			case 3: break;
			default: "Invalid Choice..try again..";
		}
	}
}

