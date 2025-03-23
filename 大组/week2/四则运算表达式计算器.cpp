#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000  // 栈长度设为1000

typedef struct {
    double data[MAX];  
    int top;           
} Stack;

void init(Stack *s) { //初始化栈 
    s->top = -1;       // 初始化时将栈顶置为-1
}

int empty(Stack *s) { //查空 
    return s->top == -1; // 通过top值判断是否为空栈
}

void push(Stack *s, double v) {//入栈 
    s->data[++(s->top)] = v; // 栈顶先+1，再存入数据（已删除栈满判断）
}

double pop(Stack *s) {       //出栈 
    if (empty(s)) {          // 弹栈前必须检查栈空
        printf("栈空\n");
        exit(1);//退出程序 
    }
    return s->data[(s->top)--]; // 返回数据后top-1
}

double top(Stack *s) {       // 查看栈顶元素
    if (empty(s)) {
        printf("空栈\n");
        exit(1);
    }
    return s->data[s->top];
}

int priority(char op) {
    if (op == '+' || op == '-') return 1; // 低优先级
    if (op == '*' || op == '/') return 2; // 高优先级
    return 0;  // 括号的优先级最低
}


double calculate(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;  
        case '*': return a * b;
        case '/': 
            if (b == 0) {       // 除零警告 
                printf("除零错误\n");
                exit(1);
            }
            return a / b;
        default: return 0;      
    }
}


double evaluate(char *expr) {
    Stack nums, ops;   // 双栈：nums存数字，ops存运算符
    init(&nums);
    init(&ops);

    for (int i = 0; expr[i]; i++) {  // 遍历每个字符
        if (isspace(expr[i])) continue; // 跳过空格

        // 数字处理
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {  // 合并连续数字
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;            // 回退多读的字符
            push(&nums, num);
        }
        // 左括号直接入栈
        else if (expr[i] == '(') {
            push(&ops, expr[i]);
        }
        // 右括号：计算到左括号为止
        else if (expr[i] == ')') {
            while (top(&ops) != '(') {  // 栈顶不是左括号就计算
                double b = pop(&nums);
                double a = pop(&nums);
                char op = (char)pop(&ops);
                push(&nums, calculate(a, b, op));
            }
            pop(&ops);  // 弹出左括号
        }
        // 运算符处理
        else {
            // 比较优先级：栈顶优先级高则先计算
            while (!empty(&ops) && priority(top(&ops)) >= priority(expr[i])) {
                double b = pop(&nums);
                double a = pop(&nums);
                char op = (char)pop(&ops);
                push(&nums, calculate(a, b, op));
            }
            push(&ops, expr[i]);  // 当前运算符入栈
        }
    }

    // 处理剩余运算符
    while (!empty(&ops)) {
        double b = pop(&nums);
        double a = pop(&nums);
        char op = (char)pop(&ops);
        push(&nums, calculate(a, b, op));
    }

    return pop(&nums);  // 最终结果
}


int main() {
    char input[MAX];  // 使用1000长度的缓冲区
    while(1) {
        printf("输入表达式 (输入q退出): ");
        fgets(input, MAX, stdin);  
        if (tolower(input[0]) == 'q') break;// 退出检测
        input[strcspn(input, "\n")] = 0;  // 去除换行符
        printf("结果: %f\n", evaluate(input));
    }
    return 0;
}
