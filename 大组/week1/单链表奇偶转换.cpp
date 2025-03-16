#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//定义一个linkedlist结构体类型,表示一个单链表节点 
int main(){
	int huan(struct linkedlist *h);
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
	huan(head);
	p=head;//从头遍历每个节点，打印每个节点储存的字符串 
	int i=1;
	while (p->next!=NULL){
		printf("node %d : %s\n",i,p->a);
		i++;
		p=p->next;
	}
	return 0;
}
int huan(struct linkedlist *h){//单链表奇偶转换 
	struct linkedlist *b;
	b=h->next;//用一个指针指向形参指针所指节点的下一个节点 
	char tem[100];
	while(b!=NULL){
		strcpy(tem,h->a);
		strcpy(h->a,b->a);
		strcpy(b->a,tem);//交换相邻两节点储存的值 
		h=b->next;
		b=h->next;//让两个指针同时向后移动两次 
	}
}
