#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct linkedlist)
struct linkedlist{
		char a[100];
		struct linkedlist *next;
	};//����һ��linkedlist�ṹ������,��ʾһ��������ڵ� 
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
		
	}while(1);//���ٽڵ㲢�����ַ����������롰N ��ʱ�˳�ѭ����ֹͣ�����ڵ� 
	printf("\n");
	p->next=NULL; //��β�ڵ��nextָ��ָ��NULL 
	head=fan(head);
	p=head->next;//��ͷ����ÿ���ڵ㣬��ӡÿ���ڵ㴢����ַ��� 
	int i=1;
	while (p!=NULL){
		printf("node %d : %s\n",i,p->a);
		i++;
		p=p->next;
	}
	return 0;
}

struct linkedlist* fan(struct linkedlist *h){//��ת�����ݹ飩
	if(h==NULL||h->next==NULL){return h;
	}
	struct linkedlist *fan2=fan(h->next);//�������� 
	h->next->next=h;
	h->next=NULL;
	return fan2;
}
