#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000  // ջ������Ϊ1000

typedef struct {
    double data[MAX];  
    int top;           
} Stack;

void init(Stack *s) { //��ʼ��ջ 
    s->top = -1;       // ��ʼ��ʱ��ջ����Ϊ-1
}

int empty(Stack *s) { //��� 
    return s->top == -1; // ͨ��topֵ�ж��Ƿ�Ϊ��ջ
}

void push(Stack *s, double v) {//��ջ 
    s->data[++(s->top)] = v; // ջ����+1���ٴ������ݣ���ɾ��ջ���жϣ�
}

double pop(Stack *s) {       //��ջ 
    if (empty(s)) {          // ��ջǰ������ջ��
        printf("ջ��\n");
        exit(1);//�˳����� 
    }
    return s->data[(s->top)--]; // �������ݺ�top-1
}

double top(Stack *s) {       // �鿴ջ��Ԫ��
    if (empty(s)) {
        printf("��ջ\n");
        exit(1);
    }
    return s->data[s->top];
}

int priority(char op) {
    if (op == '+' || op == '-') return 1; // �����ȼ�
    if (op == '*' || op == '/') return 2; // �����ȼ�
    return 0;  // ���ŵ����ȼ����
}


double calculate(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;  
        case '*': return a * b;
        case '/': 
            if (b == 0) {       // ���㾯�� 
                printf("�������\n");
                exit(1);
            }
            return a / b;
        default: return 0;      
    }
}


double evaluate(char *expr) {
    Stack nums, ops;   // ˫ջ��nums�����֣�ops�������
    init(&nums);
    init(&ops);

    for (int i = 0; expr[i]; i++) {  // ����ÿ���ַ�
        if (isspace(expr[i])) continue; // �����ո�

        // ���ִ���
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {  // �ϲ���������
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;            // ���˶�����ַ�
            push(&nums, num);
        }
        // ������ֱ����ջ
        else if (expr[i] == '(') {
            push(&ops, expr[i]);
        }
        // �����ţ����㵽������Ϊֹ
        else if (expr[i] == ')') {
            while (top(&ops) != '(') {  // ջ�����������žͼ���
                double b = pop(&nums);
                double a = pop(&nums);
                char op = (char)pop(&ops);
                push(&nums, calculate(a, b, op));
            }
            pop(&ops);  // ����������
        }
        // ���������
        else {
            // �Ƚ����ȼ���ջ�����ȼ������ȼ���
            while (!empty(&ops) && priority(top(&ops)) >= priority(expr[i])) {
                double b = pop(&nums);
                double a = pop(&nums);
                char op = (char)pop(&ops);
                push(&nums, calculate(a, b, op));
            }
            push(&ops, expr[i]);  // ��ǰ�������ջ
        }
    }

    // ����ʣ�������
    while (!empty(&ops)) {
        double b = pop(&nums);
        double a = pop(&nums);
        char op = (char)pop(&ops);
        push(&nums, calculate(a, b, op));
    }

    return pop(&nums);  // ���ս��
}


int main() {
    char input[MAX];  // ʹ��1000���ȵĻ�����
    while(1) {
        printf("������ʽ (����q�˳�): ");
        fgets(input, MAX, stdin);  
        if (tolower(input[0]) == 'q') break;// �˳����
        input[strcspn(input, "\n")] = 0;  // ȥ�����з�
        printf("���: %f\n", evaluate(input));
    }
    return 0;
}
