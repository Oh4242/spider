#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//����һ��linkedlist�ṹ������,��ʾһ��������ڵ� 
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
		
	}while(1);//���ٽڵ㲢�����ַ����������롰N ��ʱ�˳�ѭ����ֹͣ�����ڵ� 
	printf("\n");
	p->next=NULL; //��β�ڵ��nextָ��ָ��NULL 
	pan(head);
	return 0;
}

int pan(struct linkedlist *h){//�ж��Ƿ�ɻ� 
	struct linkedlist *b;
	b=h->next;
	b=b->next;//��bָ��ָ��hָ����ָ�ڵ�ĺ������ڵ� 
	int sum=0;
	while(sum<100 && b->next!=NULL){
		if(h==b){printf("yes");//������ָ��ָ��ͬһ���ڵ�ʱ���жϳɻ� 
		}
		h=h->next;
		for(int i=0;i<2;i++)b=b->next;
		sum+=1;
	}
	printf("no");
}
