#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define LEN sizeof(struct linknode)
typedef struct linknode{//������ջ�Ľڵ�ṹ 
	int elem;
	struct linknode *next;
}linknode;

typedef struct linkstack{//������ջ�ṹ 
	linknode *top;
}linkstack;

void initstack(linkstack *s){//��ʼ����ջ 
	s->top=NULL;
}

int is_empty(linkstack s){//�ж���ջ�Ƿ�Ϊ�� 
	return(s.top==NULL);
} 

void push(linkstack *s,int e){//��ջ���� 
	linknode *p=(linknode*)malloc(LEN);
	if (p==NULL){return;//malloc�����ڷ����ڴ�ʱ�����ϵͳ��ǰû���㹻���ڴ棬�᷵��NULLָ�� 
	}
	p->elem=e;
	p->next=s->top;
	s->top=p;
}

int pop(linkstack *s,int*e){//��ջ���� 
	if(is_empty(*s)){return 0;
	}
	linknode *p=s->top;
	*e=p->elem;
	s->top=p->next;
	free(p);
	return 1;
}

int gettop(linkstack *s){//��ȡջ��Ԫ��
	if(is_empty(*s)){return 0;
	} 
	int e=s->top->elem;
	return e;
}

void destroy(linkstack *s){//������ջ
	linknode *p,*q;
	p=s->top;
	while (p!=NULL){
		q=p;
		p=p->next;
		free(q);
	} 
	s->top=NULL;
}

int le(linkstack *s){//���ջ���� 
	if(s->top==NULL){
		return 0;
	}
	int sum=0;
	linknode *p;
	p=s->top;
	while(p!=NULL){
		p=p->next;
		sum+=1;
	}
	return(sum);
}

int print(linkstack *s){//��ӡջ 
	if(s->top==NULL){
		printf("nothing");
	}
	linknode *p;
	p=s->top;
	while(p!=NULL){
		printf("%d\t",p->elem);
		p=p->next;
	}
	printf("\n");
	return 0;
}

int main(){
	printf("*************************************************\n");
	printf("*                 1.Ԫ����ջ                    *\n");
	printf("*                 2.Ԫ�س�ջ                    *\n");
	printf("*              3.�ж�ջ�Ƿ�Ϊ��                 *\n");
	printf("*                4.ȡջ��Ԫ��                   *\n");
	printf("*                  5.����ջ                     *\n");
	printf("*               6.���ջ�ĳ���                  *\n");
	printf("*                 7.��ʼ��ջ                    *\n");
	printf("*                  8.��ӡջ                     *\n");
	printf("*                 9.�˳�����                    *\n");
	printf("*************************************************\n");
	int g;
	linkstack w;
	initstack(&w);
	while(1){
		printf("��ѡ����Ҫ�Ĺ��ܣ�");
		scanf("%d",&g);
		switch(g){
			case 1:
				printf("��������Ҫ��ջ��Ԫ�أ�"); 
				int h;
				scanf("%d",&h);
				push(&w,h);
				break;
			case 2:
				int e;
				if(pop(&w,&e)){
					printf("��ջԪ��Ϊ��%d\n",e);
				}else{printf("ջΪ�գ��޷���ջ��\n");
				}
				break;
			case 3:
			 	if(is_empty(w)){
			 		printf("yes\n");
				 }
				 else{printf("there is something in it...\n");}
				 break;
			case 4:
				int j;
				j=gettop(&w);
				printf("ջ��Ԫ��Ϊ��%d\n",j);
				break;
			case 5:
				destroy(&w);
				break;
			case 6:
				int lent;
				lent=le(&w);
				printf("ջ����Ϊ��%d\n",lent);
				break;
			case 7:
				initstack(&w);
				break;
			case 8:
				print(&w);
				break;
	}
	if(g==9){break;
	}
	}
	system("pause");
	return 0;
}
