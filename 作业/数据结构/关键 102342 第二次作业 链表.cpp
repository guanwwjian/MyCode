#include<iostream>
#include<stdlib.h>
#define OK true;
#define ERROR false;
using namespace std;
typedef int ElemType;
typedef bool Status;
struct  LNode
{
        ElemType  data;
        LNode  *next;
};
typedef LNode *LinkList;
LinkList  L;
Status ListInsert_L(LinkList &L,ElemType e,int i)
{
	LinkList p;
	p=L; 
	int j=0;
   while (p && (j<i-1)) { p=p->next; ++j;}
   if(!p || j>i-1) return ERROR;
   LinkList s=(LinkList) malloc(sizeof(LNode));
   s->data=e;
   s->next=p->next;
   p->next=s;
   return OK; 
}
Status ListDelete_L(LinkList &L, ElemType &e, int i) {
   LinkList p=L; int j=0;
   while (p->next && j<i-1) { p=p->next; ++j;}
   if(!(p->next) || j>i-1) return ERROR;
   LinkList q=p->next;  p->next=q->next;
   e=q->data; free(q);
   return OK; 
}
void  CreateList_L(LinkList &L, int n)   {
  LinkList p,r;
  int i;
	L=(LinkList)malloc(sizeof(LNode));
  r=L;
  for (i=1; i<=n; ++i)  {
    p=(LinkList)malloc(sizeof(LNode));
    cin>>p->data;            
     r->next=p; r=p;
  }
  p->next=NULL;
}

Status GetElem_L(LinkList L, int i, ElemType &e)
{ LinkList p;
	p=L->next;  int j=1;
	while (p && j<i) { p=p->next; ++j; }
	if (!p || j>i) return ERROR;
	e=p->data;
	return OK;
}

int LinkLocate_L (LinkList L, int x)
{  int i;   LinkList  p;
   p=L->next;  i=1;
   while (p!=NULL && p->data != x)
            {p= p->next; i++;}
   if (!p)  { printf ("数据不存在\n"); 
                return(0); 
              }
   else { printf ("第%d个数据\n",i);return (i); }
}
int LinkLength_L (LinkList L)
{  int j;  LinkList p;
   p=L->next;  j=0;
   while (p) {p=p->next;j++;}
   return(j);
 }
void UnionList_L(LinkList &La,LinkList Lb)
{   LinkList  p,q,first;  int x;
    first = La->next;  p=Lb->next;
    while (p) {
         x=p->data;  p=p->next;  q=first;
         while (q && q->data !=x)  q=q->next;
         if (!q) { 
                    q=(LinkList)malloc(sizeof(LNode));
                    q->data = x;  q->next = La->next;
                    La->next = q; }
         }
}
void CreateList_LC(LinkList &L)
{  LinkList p;  int x;
	L= (LinkList)malloc(sizeof(LNode));
   L ->next=L;
	while (scanf("%d,",&x), x!=0 )
      { 
        p=(LinkList)malloc(sizeof(LNode));
		p->data=x;        p->next = L->next;
        L->next = p;
      }
}
void PrintList_LC(LinkList L)
 {   LinkList p;
	 p=L->next;  printf("L->");
	 while (p!=L) {
		 printf("%d->",p->data);
		 p=p->next;  }
  	printf("L\n");
}

struct  DuNode{
        ElemType  data;
        struct   DuNode  *prior;
       struct   DuNode  *next;
} ;
typedef DuNode *DuLinklist;
typedef DuNode  * DuLinkList;
DuLinklist GetElemP_DuL(DuLinklist L,int x)
{
	int i;
	DuLinklist tt=L;
	if (x>=0)
	{
		for (i=1;i<=x;i++) tt=tt->next; 
	}
	else
	{
		for (i=1;i<=-x;i++) tt=tt->prior;
	}
	return tt;
}
  Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) 
  {
	
	  DuLinkList p;
	  DuLinkList s;
	if ( ! ( p=GetElemP_DuL(L,i) ) )  return ERROR;
    if ( ! ( s=(DuLinkList)malloc(sizeof(DuNode)))) return ERROR;
    s->data=e;
    s->prior=p->prior;         p->prior->next=s; 
    s->next=p;                   p->prior=s; 
    return  OK;
 }
     Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e) 
	 {
		DuLinkList p;
    if ( ! ( p=GetElemP_DuL(L,i) ) )  return ERROR;
    e= p-> data;
    p->prior->next=p->next; 
    p->next->prior=p ->prior;                   
    free(p);    return  OK;
 }
void CrtList_DuL(DuLinkList &L)
{	DuLinkList p;    int x;
	L=p=(DuLinkList)malloc(sizeof(DuNode));
    L ->next=L;   L->prior =L;
	while (scanf("%d",&x),x!=0){
		p->next=(DuLinkList)malloc(sizeof(DuNode));
		p->next->prior =p;    p=p->next;
		p->data=x;
     	}
	p->next=L;	L->prior =p;
}

void PrtList_DuL(DuLinkList L)
{	DuLinkList p;  
	p=L->next;	printf("L->");
	while (p!=L){
		printf("%d->",p->data);
		p=p->next;
    	}
	printf("\n");
}
bool checkc(LinkList L)
{
	LinkList p=L->next;
	while (p)
	{
		if (p==L) return true;
		p=p->next;
	}
	return false;
}
LinkList last(LinkList a)
{
	LinkList ans;
	ans=a;
	while (ans->next) ans=ans->next;
	return ans;
}
bool checkab(LinkList a,LinkList b)
{
	if ((a==NULL)||(b==NULL)) return false;
	if (last(a)==last(b)) return true;
	else return false;
}
void main()
{
	LinkList a=NULL,b=NULL,c=NULL,e=NULL,f=NULL;
	int n,m,i,x,y;
	cout<<"单链表建立测试:请输入一个整数n表示单链表a的长:"<<endl;
	cin>>n;
	cout<<"请输入n个整数表示n个元素的值"<<endl;
	CreateList_L(a,n);
	cout<<"单链表输出:"<<endl;
	for (i=1;i<=n;i++)
	{
		ElemType tt;
		GetElem_L(a,i,tt);
		cout<<tt<<" ";
	}
	cout<<endl;
	cout<<"单链表插入测试：请输入要插入元素的值x与要插入的位置y："<<endl;
	cin>>x>>y;
	ListInsert_L(a,x,y);
	cout<<"单链表删除测试：请输入要删除元素的位置x："<<endl;
	cin>>x;
	ListDelete_L(a,y,x);
	cout<<"删除的元素是："<<y<<endl;
	cout<<"操作后单链表输出："<<endl;
	for (i=1;i<=n;i++)
	{
		ElemType tt;
		GetElem_L(a,i,tt);
		cout<<tt<<" ";
	}
	cout<<endl;
	cout<<"查找测试：请输入要查找的元素得值x"<<endl;
	cin>>x;
	LinkLocate_L(a,x);
	cout<<"单链表长为"<<LinkLength_L(a)<<endl;
	cout<<"集合合并测试：请输入要与之前链表合并链表b的元素个数m："<<endl;
	cin>>m;
	cout<<"请输入m个整数表示各个元素的值："<<endl;
	CreateList_L(b,m);
	UnionList_L(a,b);
	cout<<"集合合并后的链表a输出："<<endl;
	for (i=1;i<=LinkLength_L(a);i++)
	{
		ElemType tt;
		GetElem_L(a,i,tt);
		cout<<tt<<" ";
	}
	cout<<endl;
	cout<<"循环链表测试：请输入循环链表c的各个元素的值以0结束："<<endl;
	CreateList_LC(c);
	cout<<"循环链表输出："<<endl;
	PrintList_LC(c);
	DuLinkList d;
	cout<<"双链表测试：请输入双链表d的各个元素的值以0结束"<<endl;
	CrtList_DuL(d);
	cout<<"双链表输出"<<endl;
	PrtList_DuL(d);
	cout<<"判断是否是循环链表："<<endl;
	if (checkc(a)) cout<<"a是循环链表"<<endl;
	else cout<<"a不是循环链表"<<endl;
	if (checkc(c)) cout<<"c是循环链表"<<endl;
	else cout<<"c不是循环链表"<<endl;
	cout<<"判断两个链表是否相交"<<endl;
	e=a->next;
	if (checkab(a,e)) cout<<"a e相交"<<endl;
	else cout<<"a e不相交"<<endl;
	if (checkab(a,f)) cout<<"a f相交"<<endl;
	else cout<<"a f不相交"<<endl;
}
