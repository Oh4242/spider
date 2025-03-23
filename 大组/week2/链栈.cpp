#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define LEN sizeof(struct linknode)
typedef struct linknode{//定义链栈的节点结构 
	int elem;
	struct linknode *next;
}linknode;

typedef struct linkstack{//定义链栈结构 
	linknode *top;
}linkstack;

void initstack(linkstack *s){//初始化链栈 
	s->top=NULL;
}

int is_empty(linkstack s){//判断链栈是否为空 
	return(s.top==NULL);
} 

void push(linkstack *s,int e){//入栈操作 
	linknode *p=(linknode*)malloc(LEN);
	if (p==NULL){return;//malloc函数在分配内存时，如果系统当前没有足够的内存，会返回NULL指针 
	}
	p->elem=e;
	p->next=s->top;
	s->top=p;
}

int pop(linkstack *s,int*e){//出栈操作 
	if(is_empty(*s)){return 0;
	}
	linknode *p=s->top;
	*e=p->elem;
	s->top=p->next;
	free(p);
	return 1;
}

int gettop(linkstack *s){//获取栈顶元素
	if(is_empty(*s)){return 0;
	} 
	int e=s->top->elem;
	return e;
}

void destroy(linkstack *s){//销毁链栈
	linknode *p,*q;
	p=s->top;
	while (p!=NULL){
		q=p;
		p=p->next;
		free(q);
	} 
	s->top=NULL;
}

int le(linkstack *s){//检测栈长度 
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

int print(linkstack *s){//打印栈 
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
	printf("*                 1.元素入栈                    *\n");
	printf("*                 2.元素出栈                    *\n");
	printf("*              3.判断栈是否为空                 *\n");
	printf("*                4.取栈顶元素                   *\n");
	printf("*                  5.销毁栈                     *\n");
	printf("*               6.检测栈的长度                  *\n");
	printf("*                 7.初始化栈                    *\n");
	printf("*                  8.打印栈                     *\n");
	printf("*                 9.退出程序                    *\n");
	printf("*************************************************\n");
	int g;
	linkstack w;
	initstack(&w);
	while(1){
		printf("请选择需要的功能：");
		scanf("%d",&g);
		switch(g){
			case 1:
				printf("请输入需要入栈的元素："); 
				int h;
				scanf("%d",&h);
				push(&w,h);
				break;
			case 2:
				int e;
				if(pop(&w,&e)){
					printf("出栈元素为：%d\n",e);
				}else{printf("栈为空，无法出栈。\n");
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
				printf("栈顶元素为：%d\n",j);
				break;
			case 5:
				destroy(&w);
				break;
			case 6:
				int lent;
				lent=le(&w);
				printf("栈长度为：%d\n",lent);
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
