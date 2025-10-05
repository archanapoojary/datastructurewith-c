#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return -1;
}

int isOperand(char c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

void infixToPostfix(char* exp) {
    int i = 0;
    while(exp[i] != '\0') {
        char c = exp[i];
        if(c == ' ') {
            i++;
            continue;
        }
        if(isOperand(c)) {
            printf("%c", c);
        } else if(c == '(') {
            push(c);
        } else if(c == ')') {
            while(top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }
            pop();
        } else {
            while(top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
        i++;
    }
    while(top != -1) {
        printf("%c", pop());
    }
}

int main() {
    char exp[MAX];
    fgets(exp, MAX, stdin);
    infixToPostfix(exp);
    return 0;
}
