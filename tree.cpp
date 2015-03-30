#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node* ndptr;
ndptr insert(ndptr root,int data)
{
	ndptr temp=new node,p,q;
	temp->data=data;
	temp->right=temp->left=NULL;
	if(!root) root=temp;
	else{
		p=root;
		while(p)
		{
			q=p;
			if(p->data==data) return root;
			else if(p->data<data) p=p->right;
			else p=p->left;
		}
		if(q->data<data) q->right=temp;
		else q->left=temp;
	}
	return root;
}
void inorder(ndptr root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right);
	}
}
ndptr s[20];
int count=0;
void in(ndptr root)
{
	if(root)
	{
		bool done=false;
		ndptr temp=root;
		while(!done)
		{

			if(temp)
			{
				s[count++]=temp;
				temp=temp->left;
			}
			else if(count-1>=0)
			{
				temp=s[--count];
				cout<<temp->data<<"  ";
				temp=temp->right;
			}
			else done=true;
		}
	}
}
int main()
{
	int arr[11]={12,7,4,5,6,8,9,11,14,13,15},i=0;;
	ndptr root=NULL;
	while(i<=10)
		root=insert(root,arr[i++]);
	inorder(root);
	cout<<endl;
	in(root);
}




