#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//定义一个linkedlist结构体类型,表示一个单链表节点 
int main(){
	int pan(struct linkedlist *h); 
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
	pan(head);
	return 0;
}

int pan(struct linkedlist *h){//判断是否成环 
	struct linkedlist *b;
	b=h->next;
	b=b->next;//让b指针指向h指针所指节点的后两个节点 
	int sum=0;
	while(sum<100 && b->next!=NULL){
		if(h==b){printf("yes");//当两个指针指向同一个节点时，判断成环 
		}
		h=h->next;
		for(int i=0;i<2;i++)b=b->next;
		sum+=1;
	}
	printf("no");
}
