#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//����һ��linkedlist�ṹ������,��ʾһ��������ڵ� 
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
		
	}while(1);//���ٽڵ㲢�����ַ����������롰N ��ʱ�˳�ѭ����ֹͣ�����ڵ� 
	printf("\n");
	p->next=NULL; //��β�ڵ��nextָ��ָ��NULL 
	zhao(head);
	return 0;
}

int zhao(struct linkedlist *h){
	struct linkedlist *k;
	k=h;//��һָ���¼�β�ָ��ĳ�ʼλ�� 
	int sum=0;
	while(h->next!=NULL){
		h=h->next;
		sum+=1;
	}//�����ó������� 
	h=k; 
	if(sum%2==0){//�ҵ�����ӡ�м�ڵ㣨��������Ϊż������ӡ�м������ڵ㴢���ֵ�� 
		int end=sum/2;
		for(int i=0;i<end-1;i++)h=h->next;
		printf("�����м�ڵ㣺\n");
		printf("%s\n",h->a);
		h=h->next;
		printf("%s\n",h->a);
		}
	else if(sum%2==1){//�ҵ�����ӡ�м�ڵ㣨��������Ϊ��������ӡ�м�ڵ㴢���ֵ��
		int end=sum/2;
		for(int i=0;i<end;i++)h=h->next;
		printf("�����м�ڵ㣺\n");
		printf("%s\n",h->a);
		}
	return 0;
}
