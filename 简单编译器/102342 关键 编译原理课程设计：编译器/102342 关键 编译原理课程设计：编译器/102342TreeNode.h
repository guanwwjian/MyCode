#pragma once
struct ListNode
{
	int val;
	ListNode *next;
	ListNode()
	{
		val=0;
		next=(ListNode*)0;
	}
};
class List
{
public:
	ListNode *first,*last;
	List()
	{
		first=new ListNode;
		last=first;
	}
	List(List *l)
	{
		first=new ListNode;
		last=first;
		add(l);
	}
	~List()
	{
		ListNode *pp;
		while (first->next)
		{
			pp=first;
			first=first->next;
			delete pp;
		}
		pp=first;
		delete pp;
	}
	void add(int x)
	{
		ListNode* p;
		p=new ListNode;
		p->val=x;
		last->next=p;
		last=p;
	}
	void add(List *l)
	{
		ListNode *p;
		p=l->first;
		while (p->next)
		{
			p=p->next;
			add(p->val);
		}
	}
};

class TreeNode
{
public:
	string name;
	int val;
	string place;
	int q;
	//List def;
	List *t,*f,*n;
	TreeNode()
	{
		t=new List;
		f=t;
		n=t;
		//f=new List;
		//n=new List;
	}
	/*
	~TreeNode()
	{
		delete t;
		delete f;
		delete n;
	}
	void test(TreeNode* x)
	{
		int a;
		a=0;
	}*/
};