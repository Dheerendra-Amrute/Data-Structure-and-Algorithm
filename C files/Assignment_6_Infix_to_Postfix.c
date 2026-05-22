#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push character to stack
void push(char c) {
    top = top + 1;
    stack[top] = c;
}

// Pop character from stack
char pop() {
    char temp = stack[top];
    top = top - 1;
    return temp;
}

// Operator precedence
int precedence(char op){
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0;
    int k = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

        if (isdigit(c)) {
            postfix[k] = c;
            k = k + 1;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k] = pop();
                k = k + 1;
            }
            pop(); // remove '('
        } 
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k] = pop();
                k = k + 1;
            }
            push(c);
        }

        i = i + 1;
    }

    while (top != -1) {
        postfix[k] = pop();
        k = k + 1;
    }

    postfix[k] = '\0';
}

// Evaluate postfix expression
int evalPostfix(char* postfix) {
    int valStack[MAX];
    int valTop = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            valTop = valTop + 1;
            valStack[valTop] = postfix[i] - '0';
        } else {
            int b = valStack[valTop];
            valTop = valTop - 1;
            int a = valStack[valTop];
            valTop = valTop - 1;

            int result;
            if (postfix[i] == '+') result = a + b;
            else if (postfix[i] == '-') result = a - b;
            else if (postfix[i] == '*') result = a * b;
            else if (postfix[i] == '/') result = a / b;

            valTop = valTop + 1;
            valStack[valTop] = result;
        }

        i = i + 1;
    }

    return valStack[valTop];
}

// Main function
int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression (single-digit operands): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Evaluated result: %d\n", evalPostfix(postfix));

    return 0;
}
