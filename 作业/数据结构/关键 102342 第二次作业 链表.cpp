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
   if (!p)  { printf ("���ݲ�����\n"); 
                return(0); 
              }
   else { printf ("��%d������\n",i);return (i); }
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
	cout<<"������������:������һ������n��ʾ������a�ĳ�:"<<endl;
	cin>>n;
	cout<<"������n��������ʾn��Ԫ�ص�ֵ"<<endl;
	CreateList_L(a,n);
	cout<<"���������:"<<endl;
	for (i=1;i<=n;i++)
	{
		ElemType tt;
		GetElem_L(a,i,tt);
		cout<<tt<<" ";
	}
	cout<<endl;
	cout<<"�����������ԣ�������Ҫ����Ԫ�ص�ֵx��Ҫ�����λ��y��"<<endl;
	cin>>x>>y;
	ListInsert_L(a,x,y);
	cout<<"������ɾ�����ԣ�������Ҫɾ��Ԫ�ص�λ��x��"<<endl;
	cin>>x;
	ListDelete_L(a,y,x);
	cout<<"ɾ����Ԫ���ǣ�"<<y<<endl;
	cout<<"���������������"<<endl;
	for (i=1;i<=n;i++)
	{
		ElemType tt;
		GetElem_L(a,i,tt);
		cout<<tt<<" ";
	}
	cout<<endl;
	cout<<"���Ҳ��ԣ�������Ҫ���ҵ�Ԫ�ص�ֵx"<<endl;
	cin>>x;
	LinkLocate_L(a,x);
	cout<<"������Ϊ"<<LinkLength_L(a)<<endl;
	cout<<"���Ϻϲ����ԣ�������Ҫ��֮ǰ����ϲ�����b��Ԫ�ظ���m��"<<endl;
	cin>>m;
	cout<<"������m��������ʾ����Ԫ�ص�ֵ��"<<endl;
	CreateList_L(b,m);
	UnionList_L(a,b);
	cout<<"���Ϻϲ��������a�����"<<endl;
	for (i=1;i<=LinkLength_L(a);i++)
	{
		ElemType tt;
		GetElem_L(a,i,tt);
		cout<<tt<<" ";
	}
	cout<<endl;
	cout<<"ѭ��������ԣ�������ѭ������c�ĸ���Ԫ�ص�ֵ��0������"<<endl;
	CreateList_LC(c);
	cout<<"ѭ�����������"<<endl;
	PrintList_LC(c);
	DuLinkList d;
	cout<<"˫������ԣ�������˫����d�ĸ���Ԫ�ص�ֵ��0����"<<endl;
	CrtList_DuL(d);
	cout<<"˫�������"<<endl;
	PrtList_DuL(d);
	cout<<"�ж��Ƿ���ѭ������"<<endl;
	if (checkc(a)) cout<<"a��ѭ������"<<endl;
	else cout<<"a����ѭ������"<<endl;
	if (checkc(c)) cout<<"c��ѭ������"<<endl;
	else cout<<"c����ѭ������"<<endl;
	cout<<"�ж����������Ƿ��ཻ"<<endl;
	e=a->next;
	if (checkab(a,e)) cout<<"a e�ཻ"<<endl;
	else cout<<"a e���ཻ"<<endl;
	if (checkab(a,f)) cout<<"a f�ཻ"<<endl;
	else cout<<"a f���ཻ"<<endl;
}
