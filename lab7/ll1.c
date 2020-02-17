#include <stdio.h>
#include <string.h>

char terminals[] = {'i', '+', '*', '(', ')', '$'};
char nonTerminals[] = {'E', 'X', 'T', 'Y', 'F'};

char table[5][6][4] = {{"TX", "", "", "TX", "", ""},
                       {"", "+TX", "", "", "e", "e"},
                       {"FY", "", "", "FY", "", ""},
                       {"", "e", "*FY", "", "e", "e"},
                       {"i", "", "", "(E)", "", ""}};

char stack[10], input[10], cs;
int top;

int getTerminal(char c)
{
    int i;
    for (i = 0; i < 6; i++)
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
    for(int i=0;i<6;i++)
        printf("%c\t",terminals[i]);
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("%c\t",nonTerminals[i]);
        for(int j=0;j<6;j++)
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
    strcpy(stack, "$E");
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
    printf("Valid string.\n");
    return 0;
}