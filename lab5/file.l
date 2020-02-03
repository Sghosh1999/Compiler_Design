%{
    #include<stdio.h>
    #include<string.h>
    int count_identifiers = 0;
    int count_keywords = 0;
    int sum = 0;
    int idx = 0;
    char s[1000];
%}

%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {printf("keyword:%s\n",yytext);count_keywords++;idx+=yyleng+1;}
[a-zA-Z]+[a-zA-Z0-9]* {printf("identifier::%s\n",yytext);count_identifiers++;for(int i=idx;i<idx+yyleng;i++) s[i] = ' '; s[idx+yyleng-1] = 'i';s[idx+yyleng] = 'd';idx+=yyleng+1; }
[0-9]* {sum+=atoi(yytext);idx+=yyleng;}
%%

int main()
{
    
    int i=0;
    char c;
    yyin = fopen("file.txt","r");
    while((c=fgetc(yyin))!=EOF)
        s[i++] = c;
    printf("%s\n",s);
    yy_scan_string(s);
    yylex();
    printf("The no. of keywords::%d\n",count_keywords);
    printf("The no. of identifiers::%d\n",count_identifiers);
    yyin = fopen("file_ch.txt","w");
    fprintf(yyin,s,sizeof(s));
    printf("The sum is %d\n",sum);
    return 0;
}