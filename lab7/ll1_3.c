#include <stdio.h>
#include <string.h>

char terminals[] = {'a','b','$'};
char nonTerminals[] = {'S','A','B'};

char table[3][3][5] = { {"AaAb","BbBa",""},
                        {"e","e",""},
                        {"e","e",""}};

char stack[10], input[10], cs;
int top;

int getTerminal(char c)
{
    int i;
    for (i = 0; i < 8; i++)
        if (terminals[i] == c)
            return i;
    return -1;
}

int getNonTerminal(char c)
{
    int i;
    for (i = 0; i < 5; i++)
        if (nonTerminals[i] == c)
            return i;
    return -1;
}

int main()
{
    int i, term, nonTerm;
    char temp[10];

    //table display
    printf("S\t");
    for(int i=0;i<3;i++)
        printf("%c\t",terminals[i]);
    printf("\n");
    for(int i=0;i<3;i++)
    {
        printf("%c\t",nonTerminals[i]);
        for(int j=0;j<3;j++)
        {
            if(strcmp(table[i][j],"")!=0)
                printf("%c->%s\t",nonTerminals[i],table[i][j]);
            else
                printf("%s\t",table[i][j]);
        }
        printf("\n");
    }
    //parser
    printf("Enter string:\t");
    scanf("%s", input);
    input[strlen(input)] = '$';

    cs = 0;
    strcpy(stack, "$S");
    top = strlen(stack) - 1;
    printf("\nStack\tInput\tOutput\n");

    while (stack[top] != '$')
    {
        for (i = 0; i <= top; i++)
            printf("%c", stack[i]);
        printf("\t");
        for (i = cs; i < strlen(input); i++)
            printf("%c", input[i]);
        printf("\t");
        if (input[cs] == stack[top])
        {
            top--;
            cs++;
            printf("Match");
        }
        else
        {
            term = getTerminal(input[cs]);
            nonTerm = getNonTerminal(stack[top]);
            top--;
            if (term == -1 || nonTerm == -1)
            {
                printf("Invalid string.\n");
                if (term == -1)
                    printf("Term\n");
                else
                    printf("Non Term\n");
                return 0;
            }
            strcpy(temp, table[nonTerm][term]);
            if (!strcmp(temp, ""))
            {
                printf("Invalid string.\n");
                return 0;
            }
            else if (temp[0] != 'e')
            {
                for (i = strlen(temp) - 1; i >= 0; i--)
                {
                    top++;
                    stack[top] = temp[i];
                }
            }
            printf("%c->%s", nonTerminals[nonTerm], temp);
        }
        printf("\n");
    }
    if(input[cs] == '$')
        printf("Valid string.\n");
    else
        printf("Invalid string.\n");
    return 0;
} 