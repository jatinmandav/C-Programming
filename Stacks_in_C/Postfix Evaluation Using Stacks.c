/*
 * Jatin Kumar Mandav
 *
 * Postfix expresion evaluation using Stacks
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

// Push new element to the Stack
void Push(int val){
    if (s.top == CAPACITY-1){
        printf("Stack is FULL!\n");
        return;
    }
    s.top ++;
    s.array[s.top] = val;
}

// Check if Stack is Empty
int isEmpty(){
    if (s.top == -1){
        return 1;
    }
    return 0;
}

// Pop the Topmost element from the Stack
int Pop(){
    if (isEmpty()){
        printf("Stack is EMPTY!\n");
        return -1;
    }
    int val = s.array[s.top];
    s.top--;
    return val;
}

// Evaluation of Postfix Expression
void postfixEvaluation(char postfix[]){
    for(int i = 0, n = strlen(postfix);i < n;i++){
        if (isdigit(postfix[i])){
            Push(postfix[i] - '0');
        }
        else{
            int val1 = Pop();
            int val2 = Pop();
            ]switch(postfix[i]){
                case '+':{
                    Push(val1 + val2);
                    break;
                }
                case '-':{
                    Push(val1 - val2);
                    break;
                }
                case '*':{
                    Push(val1 * val2);
                    break;
                }
                case '/':{
                    Push(val1 / val2);
                    break;
                }
                default:{
                    printf("Invalid operator!\n");
                    return;
                }
            }
        }
    }
    int result = Pop();
    printf("Value : %d\n", result);
}

// The Main Function
int main(void){
    s.top = -1;
    char postfix[50];
    printf("Postfix Expression : ");
    scanf("%[^\n]s", postfix);
    postfixEvaluation(postfix);
    return 0;
}
