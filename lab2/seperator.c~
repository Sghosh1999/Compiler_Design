#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int keyword_find(char str[1000],char *c,int k)
{
	 int len = strlen(c);
	 int flag = -1;
	 int count = 0;
	for(int i=0;i<k;i++)
	{
		char p[30];
		memset(p,'\0',30);
		int j = 0;
		while((str[i] >='a'&& str[i]<='z')||(str[i] >='A'&& str[i]<='Z'))
		{
			if(str[i] == '\0')
				return count;
			p[j] = str[i];
			j++;i++;
		}
		if(strcmp(p,c) == 0)
			count+=1;
	}
	return count;
}


void identifier_find(char str[1000],int k,FILE *g,int start)
{
	for(int i=start;i<k;i++)
	{
		char p[30];
		memset(p,'\0',30);
		int j = 0;
		while((str[i] >='a'&& str[i]<='z')||(str[i] >='A'&& str[i]<='Z'))
		{
			if(str[i] == '\0')
				return ;
			p[j] = str[i];
			j++;i++;
		}
		/*"char", "const", "printf", "default" , "scanf" , "break", "case", "do", "double" ,"else","enum", "extern", "float", "for" ,"main","if", "int", "long", "register" ,"return","short", "signed", "sizeof", "static" ,"struct", "switch" ,"typedef","union", "unsigned", "void", "volatile" ,"while" */
		if(strcmp(p,"char") != 0 && strcmp(p,"const") != 0 && strcmp(p,"printf") != 0 && strcmp(p, "default" ) != 0 && strcmp(p,"scanf") != 0 && strcmp(p,"break") != 0 && strcmp(p,"case") != 0 && strcmp(p, "do") != 0 && strcmp(p, "double" ) != 0 && strcmp(p,"else") != 0 && strcmp(p,"enum") != 0 && strcmp(p,"extern") != 0 && strcmp(p,"float") != 0 && strcmp(p,"for") != 0 && strcmp(p,"main") != 0 && strcmp(p,"if") != 0 && strcmp(p,"int") != 0 && strcmp(p,"long") != 0 && strcmp(p,"register") != 0&& strcmp(p,"return") != 0 && strcmp(p,"short") != 0 && strcmp(p,"signed") != 0 && strcmp(p,"sizeof") != 0 && strcmp(p,"static") != 0 && strcmp(p,"struct") != 0 && strcmp(p,"switch") != 0 && strcmp(p,"typedef") != 0 && strcmp(p,"union") != 0 && strcmp(p, "unsigned") != 0 && strcmp(p,"void") != 0 && strcmp(p,"volatile") != 0 && strcmp(p,"while") != 0 && p[0]!='\n' && p[0]!='\t' && p[0]!=' ' && p[0]!='\0')
		{
			fprintf(g,"%s\n",p);
			printf("%s\n",p);
		}
	}
}

void literal_find(char str[1000],FILE *g,int k){
	for(int i=0;i<k;i++)
	{
		char p[100];
		memset(p,'\0',100);
		if(str[i] == '\"')
		{
			i+=1;
			int j = 0;
			while(str[i]!='\"'){
			if(i == k)
				return ;
				p[j++] = str[i++];
			}
			i++;
		}
		if(p[0]!='\0')
		{
			fprintf(g,"%s\n",p);
			printf("%s\n",p);
		}
	}
}

void operator_find(char str[1000],FILE *p,int k,int start)
{
	for(int i=start;i<k;i++)
	{
		if(i<k && str[i] == '+' && str[i+1] == '+')
		{
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		}
		else if(i<k && str[i] == '<' && str[i+1] == '=')
		{
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		}
		else if(i<k && str[i] == '>' && str[i+1] == '=')
		{
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		}
		else if(i<k && str[i] == '=' && str[i+1] == '=')
		{
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		}
		else if(i<k && str[i] == '&' && str[i+1] == '&')
		{
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		}
		else if(i<k && str[i] == '|' && str[i+1] == '|')
		{
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		}
		else if(i<k && str[i] == '!' && str[i+1] == '=')
		{
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		}
		else if(i<k && (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%' || str[i] == '='|| str[i] == '<'||str[i] == '>'|| str[i] == '!'))
		{
			fprintf(p,"%c\n",str[i]);
			printf("%c\n",str[i]);
		}
	}
}


void delimiter_find(char str[1000],FILE *p,int k)
{
	for(int i=0;i<k;i++)
	{
		if(str[i] == '<' ||str[i] == '>' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']' )
		{
			fprintf(p,"%c\n",str[i]);
			printf("%c\n",str[i]);
		}
		else if((str[i] == '\\' && str[i] == '*') || (str[i] == '*' && str[i] == '\\'))
		{
			
			fprintf(p,"%c%c\n",str[i],str[i+1]);
			printf("%c%c\n",str[i],str[i+1]);
			i+=1;
		} 
	}  
}


int main(){
	FILE *prog, *id,*key, *sep, *del,*lit;
	prog = fopen("File.c","r");
	id = fopen("identifier.txt","w");
	key = fopen("keywords.txt","w");
	sep = fopen("operator.txt","w");
	del = fopen("delimiter.txt","w");
	lit = fopen("literal.txt","w");
	char *keys[] = { "char", "const", "printf", "default" , "scanf" , "break", "case", "do", "double" ,"else","enum", "extern", "float", "for" ,"main","if", "int", "long", "register" ,"return","short", "signed", "sizeof", "static" ,"struct", "switch" ,"typedef","union", "unsigned", "void", "volatile" ,"while" };
	char c;
	char literal_string[1000];
	literal_string[0] = '\0';
	memset(literal_string,'\0',1000);
	int k = 0;
	while((c=fgetc(prog)) != EOF)
	{
		literal_string[k++] = c;
	}
	printf("%s\n",literal_string);
	printf("identifiers:\n");
	for(int i=0;i<32;i++)
	{
		int count =0;
		if((count = keyword_find(literal_string,keys[i],k)) > 0)
		{
			printf("%s::%d\n",keys[i],count);
			for(int j = 0;j<count;j++){
				fprintf(key,"%s\n",keys[i]);
			}
		}
	}
	printf("operators:\n");
	operator_find(literal_string,sep,k,17);
	printf("delimiters:\n");
	delimiter_find(literal_string,del,k);
	printf("identifiers:\n");
	identifier_find(literal_string,k,id,17);
	printf("literal:\n");
	literal_find(literal_string,lit,k);
}
