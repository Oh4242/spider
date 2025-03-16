#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//定义一个linkedlist结构体类型,表示一个单链表节点 
int main(){
	int zhao(struct linkedlist *h);
	struct linkedlist *head,*p,*q;
	head=p=(struct linkedlist*)malloc(LEN);
	printf("create nodes until you write'N':\n");
	char input[100];
	do{
		scanf("%99s",input);
		if(strcmp(input,"N")==0){
			break;
		}
		strcpy(p->a,input);
		q=(struct linkedlist*)malloc(LEN);
		p->next=q;
		p=q;
		
	}while(1);//开辟节点并存入字符串，当输入“N ”时退出循环，停止创建节点 
	printf("\n");
	p->next=NULL; //让尾节点的next指针指向NULL 
	zhao(head);
	return 0;
}

int zhao(struct linkedlist *h){
	struct linkedlist *k;
	k=h;//用一指针记录形参指针的初始位置 
	int sum=0;
	while(h->next!=NULL){
		h=h->next;
		sum+=1;
	}//遍历得出链表长度 
	h=k; 
	if(sum%2==0){//找到并打印中间节点（当链表长度为偶数，打印中间两个节点储存的值） 
		int end=sum/2;
		for(int i=0;i<end-1;i++)h=h->next;
		printf("链表中间节点：\n");
		printf("%s\n",h->a);
		h=h->next;
		printf("%s\n",h->a);
		}
	else if(sum%2==1){//找到并打印中间节点（当链表长度为奇数，打印中间节点储存的值）
		int end=sum/2;
		for(int i=0;i<end;i++)h=h->next;
		printf("链表中间节点：\n");
		printf("%s\n",h->a);
		}
	return 0;
}
