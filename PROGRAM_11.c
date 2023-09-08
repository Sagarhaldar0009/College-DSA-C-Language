#include <stdio.h>
int isnum(char ch);
int isoperation(char ch);
int getnumber(char temp[], int n);
int evaluate(char P[]);
void push(int arr[], int *n, int ch);
void pop(int *n);
int checkpostfix(char arr[]);
int main()
{
    char Postfix[105];
    printf("Enter Postfix expression: ");
    scanf("%s", Postfix);
    if (!checkpostfix(Postfix)){
        printf("\n\nWrong Postfix Expression entered.\n");
        return 0;
    }
    int ans = evaluate(Postfix);
    printf("Answer of Postfix expression\n\n%s\n\nafter evaluation is %d", Postfix, ans);
    return 0;
}
int evaluate(char P[]){
    int i = 0, sn = -1;
    int stack[105];
    while (P[i] != '\0'){
        int count = i;
        while (P[i] != ',' && P[i] != '\0'){
            i++;
        }
        if (P[count] >= 48 && P[count] <= 57){
            int num = getnumber(&P[count], i - count);
            push(stack, &sn, num);
        }
        else{
            int ans;
            if (P[count] == '+')
                ans = stack[sn - 1] + stack[sn];
            else if (P[count] == '-')
                ans = stack[sn - 1] - stack[sn];
            else if (P[count] == '/')
                ans = (stack[sn - 1]) / (stack[sn]);
            else if (P[count] == '*')
                ans = (stack[sn - 1]) * (stack[sn]);
            else
                ans = (stack[sn - 1]) ^ (stack[sn]);
            pop(&sn);
            pop(&sn);
            push(stack, &sn, ans);
        }
        if (P[i] == ',')
            i++;
    }
    return stack[sn];
}
int getnumber(char temp[], int n){
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = (ans * 10) + temp[i] - 48;
    }
    return ans;
}
void push(int arr[], int *n, int ch){
    (*n)++;
    arr[*n] = ch;
}
void pop(int *n){
    (*n)--;
}
int isoperation(char ch){
    if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        return 1;
    return 0;
}
int isnum(char ch){
    if (ch >= 48 && ch <= 57)
        return 1;
    return 0;
}
int checkpostfix(char arr[]){
    int operand = 0, operator= 0, i = 0;
    while (arr[i] != '\0'){
        int count = i;
        while (arr[i] != ',' && arr[i] != '\0'){
            i++;
        }
        if (!isnum(arr[count]) && !isoperation(arr[count]))
            return 0;
        if (isnum(arr[count]))
                    operand++;
        if (isoperation(arr[count]))
            operator++;
        if (!(operand >= operator+ 1))
            return 0;
        if (arr[i] == ',')
            i++;
    }
    if (operand != operator+ 1)
        return 0;
    return 1;
}
