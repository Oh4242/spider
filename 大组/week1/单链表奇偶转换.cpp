#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//����һ��linkedlist�ṹ������,��ʾһ��������ڵ� 
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
		
	}while(1);//���ٽڵ㲢�����ַ����������롰N ��ʱ�˳�ѭ����ֹͣ�����ڵ� 
	printf("\n");
	p->next=NULL; //��β�ڵ��nextָ��ָ��NULL 
	huan(head);
	p=head;//��ͷ����ÿ���ڵ㣬��ӡÿ���ڵ㴢����ַ��� 
	int i=1;
	while (p->next!=NULL){
		printf("node %d : %s\n",i,p->a);
		i++;
		p=p->next;
	}
	return 0;
}
int huan(struct linkedlist *h){//��������żת�� 
	struct linkedlist *b;
	b=h->next;//��һ��ָ��ָ���β�ָ����ָ�ڵ����һ���ڵ� 
	char tem[100];
	while(b!=NULL){
		strcpy(tem,h->a);
		strcpy(h->a,b->a);
		strcpy(b->a,tem);//�����������ڵ㴢���ֵ 
		h=b->next;
		b=h->next;//������ָ��ͬʱ����ƶ����� 
	}
}
