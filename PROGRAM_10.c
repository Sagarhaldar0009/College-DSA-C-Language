#include <stdio.h>
int ischar(char ch);
int isoperation(char ch);
void convert(char I[], char P[]);
void push(char arr[], int *n, char ch);
void pop(int *n);
int checkinfix(char arr[], int n);
int main()
{
    int i;
    char Infix[105], Postfix[105];
    printf("Enter infix expression:\n");
    scanf("%s", Infix);
    for (i = 0; Infix[i] != '\0'; i++)
        ;
    if (!checkinfix(Infix, i))
    {
        printf("\n\nWrong Infix Expression entered.\n");
        return 0;
    }
    Infix[i] = ')';
    convert(Infix, Postfix);
    Infix[i] = '\0';
    printf("\n\nInfix expression you entered:\n\n");
    printf("%s", Infix);
    printf("\n\nPostfix expression:\n\n");
    printf("%s", Postfix);
    return 0;
}
int ischar(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        return 1;
    return 0;
}
int isoperation(char ch)
{
    if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        return 1;
    return 0;
}
void convert(char I[], char P[])
{
    int sn = -1, pn = -1, i = 0;
    char stack[105];
    push(stack, &sn, '(');
    while (sn != -1)
    {
        if (ischar(I[i]))
        {
            push(P, &pn, I[i]);
        }
        else if (I[i] == '(')
        {
            push(stack, &sn, '(');
        }
        else if (isoperation(I[i]))
        {
            if (I[i] == '+' || I[i] == '-')
            {
                while (stack[sn] != '(')
                {
                    push(P, &pn, stack[sn]);
                    pop(&sn);
                }
                push(stack, &sn, I[i]);
            }
            else if (I[i] == '/' || I[i] == '*')
            {
                while (stack[sn] != '(' && stack[sn] != '+' && stack[sn] != '-')
                {
                    push(P, &pn, stack[sn]);
                    pop(&sn);
                }
                push(stack, &sn, I[i]);
            }
            else
            {
                while (stack[sn] != '(' && stack[sn] != '+' && stack[sn] != '-' && stack[sn] != '/' &&
                       stack[sn] != '*')
                {
                    push(P, &pn, stack[sn]);
                    pop(&sn);
                }
                push(stack, &sn, I[i]);
            }
        }
        else if (I[i] == ')')
        {
            while (stack[sn] != '(')
            {
                push(P, &pn, stack[sn]);
                pop(&sn);
            }
            pop(&sn);
        }
        i++;
    }
    push(P, &pn, '\0');
}
void push(char arr[], int *n, char ch)
{
    (*n)++;
    arr[*n] = ch;
}
void pop(int *n)
{
    (*n)--;
}
int checkinfix(char arr[], int n)
{
    int operator= 0, operand = 0, bracket = 0;
    if (isoperation(arr[0]) || isoperation(arr[n - 1]) || arr[n - 1] == '(' || arr[0] == ')')
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (ischar(arr[i]))
        {
            operand++;
            if (arr[i + 1] == '(' || ischar(arr[i + 1]))
                return 0;
        }
        if (isoperation(arr[i]))
        {
            operator++;
            if (arr[i + 1] == ')' || isoperation(arr[i + 1]))
                return 0;
        }
        if (arr[i] == '(')
        {
            bracket++;
            if (isoperation(arr[i + 1]))
                return 0;
        }
        if (arr[i] == ')')
            {
                bracket--;
                if (ischar(arr[i + 1]) || arr[i + 1] == '(')
                    return 0;
            }
        if (bracket < 0)
            return 0;
    }
    if (bracket != 0)
        return 0;
    if (operator+ 1 != operand)
        return 0;
    return 1;
}
