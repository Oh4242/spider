#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
		struct linkedlist *pre;
	};//定义一个linkedlist结构体类型,表示一个双链表节点 
int main(){
	struct linkedlist *head,*p,*q,*w;
	head=p=w=(struct linkedlist*)malloc(LEN);
	printf("create nodes until you write'N':\n");
	char input[100];
	int j=0;
	do{
		scanf("%99s",input);
		if(strcmp(input,"N")==0){
			break;
		}
		strcpy(p->a,input);
		q=(struct linkedlist*)malloc(LEN);
		p->next=q;
		p->pre=w;
		w=p;
		p=q;
		j++;
	}while(1);//开辟节点并存入字符串，当输入“N ”时退出循环，停止创建节点
	printf("\n");
	p->next=NULL;//让尾节点的next指针指向NULL
	head->pre=NULL; //让头节点的pre指针指向NULL
	printf("正向遍历：\n");//正向遍历 ：从头遍历每个节点，打印每个节点储存的字符串 
	p=head;
	int i=1;
	while (p->next!=NULL){
		printf("node %d : %s\n",i,p->a);
		i++;
		p=p->next;
	}
	printf("反向遍历：\n");//反向遍历 ：//从尾遍历每个节点，打印每个节点储存的字符串 
	p=w;
	while(p!=NULL){
		printf("node %d : %s\n",j,p->a);
		p=p->pre;
		j--;
	}
	return 0;
}
