#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
		struct linkedlist *pre;
	};//����һ��linkedlist�ṹ������,��ʾһ��˫����ڵ� 
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
	}while(1);//���ٽڵ㲢�����ַ����������롰N ��ʱ�˳�ѭ����ֹͣ�����ڵ�
	printf("\n");
	p->next=NULL;//��β�ڵ��nextָ��ָ��NULL
	head->pre=NULL; //��ͷ�ڵ��preָ��ָ��NULL
	printf("���������\n");//������� ����ͷ����ÿ���ڵ㣬��ӡÿ���ڵ㴢����ַ��� 
	p=head;
	int i=1;
	while (p->next!=NULL){
		printf("node %d : %s\n",i,p->a);
		i++;
		p=p->next;
	}
	printf("���������\n");//������� ��//��β����ÿ���ڵ㣬��ӡÿ���ڵ㴢����ַ��� 
	p=w;
	while(p!=NULL){
		printf("node %d : %s\n",j,p->a);
		p=p->pre;
		j--;
	}
	return 0;
}
