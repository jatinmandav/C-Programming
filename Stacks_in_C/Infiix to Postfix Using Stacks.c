/*
 * Jatin Kumar Mandav
 *
 * Infix to Postfix expression using Stacks
 *
 * Website : https://jatinmandav.wordpress.com
 * YouTube : https://www.youtube.com/channel/UCdpf6Lz3V357cIZomPwjuFQ?view_as=subscriber
 * 
 * Facebook : facebook.com/jatinmandav
 * Twitter : @jatinmandav
 * Gmail : jatinmandav3@gmail.com
*/

#define CAPACITY 50
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// Struct of Stack
struct stack{
    int top;
    int array[CAPACITY];
}s;

// Push new element to Stack
void Push(char val){
    if (s.top == CAPACITY - 1){
        printf("Stack is FULL!\n");
        return;
    }
    s.top ++;
    s.array[s.top] = val;
}

// Check if Stack is Empty
int isEmpty(){
    if (s.top == -1)
        return 1;
    return 0;
}

// Pop the Topmost Element in Stack
char Pop(){
    if (isEmpty()){
        printf("Stack is EMPTY!");
        return '0';
    }
    char ch;
    ch = s.array[s.top];
    s.top--;
    return ch;
}

// Look at the Topmost element in Stack
char Peek(){
    return s.array[s.top];
}

// Get the precedence order of operators
int precedence(char optr){
    if (optr == '('){
        return 0;
    }
    else if (optr == '+' || optr == '-'){
        return 1;
    }
    else if (optr == '*' || optr == '/'){
        return 2;
    }
    else if (optr == '^'){
        return 3;
    }
    return 0;
}

// Convert Infix Expression to Postfix
void infixToPostfix(char infix[], char postfix[]){
    int j = 0;
    char temp;
    s.top = -1;
    for(int i = 0, n = strlen(infix); i < n; i++){
        char ch = infix[i];
        if (isalnum(ch)){
            postfix[j] = ch;
            j++;
        }
        else{
            if (ch == '('){
                Push(ch);
            }
            else if (ch == ')'){
                while((temp = Pop()) != '('){
                    postfix[j++] = temp;
                }
            }
            else{
                while (precedence(ch) < precedence(Peek()) && !isEmpty()){
                    temp = Pop();
                    postfix[j++] = temp;
                }
                Push(ch);
            }
        }
    }

    while (!isEmpty()){
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
}

// The Main Function
int main(void){
    char infix[50], postfix[50];
    printf("Enter the Infix Expression : ");
    scanf("%[^\n]s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix epxression : %s\n", postfix);
    return 0;
}
