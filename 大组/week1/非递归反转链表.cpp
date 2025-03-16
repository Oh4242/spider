#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//定义一个linkedlist结构体类型,表示一个单链表节点 
int main(){
	struct linkedlist* fan(struct linkedlist *h);
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
	head=fan(head);
	p=head;//从头遍历每个节点，打印每个节点储存的字符串 
	int i=1;
	while (p!=NULL){
		printf("node %d : %s\n",i,p->a);
		i++;
		p=p->next;
	}
	return 0;
}

struct linkedlist* fan(struct linkedlist *h){//反转链表（非递归）这个过程打字的话感觉有点难以描述，所以先不作注释了 
	struct linkedlist *pre,*cur,*nextnode;
	pre=NULL;
	cur=h; 
	while(cur->next!=NULL){
		nextnode=cur->next;
		cur->next=pre;
		pre=cur;
		cur=nextnode;
	}
	return pre;
}
