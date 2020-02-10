#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find_first(char p[1000][1000],int n,char k,int g)
{
    if(k>='a'&& k<='z')
    {
        printf("%c\t",k);
        return 1;
    } 
    if(k=='.')
    {
        return 0;
    }
    if(k == '\0')
        return 0;
    else{
        for(int i=0;i<n;i++)
        {
            if(p[i][0] == k)
            {
                int gg = 1;
                gg = find_first(p,n,p[i][3],k);
                for(int j=4;j<strlen(p[i]);j++)
                {
                    if(p[i][j] == '|')
                    {
                        gg = find_first(p,n,p[i][j+1],p[i][0]);
                        if(gg==0)
                        {  
                            gg = find_first(p,n,p[i][j+2],p[i][0]);
                        }
                    }
                    
                }
                return gg;
            }
        }
        return 0;
    }
}




int main(){
    int n;
    printf("Enter the no. of productions:");
    scanf("%d",&n);
    char p[n][1000];
    for(int i=0;i<n;i++)
        scanf("%s",p[i]);
    printf("User given grammer is:\n");
    for(int i=0;i<n;i++)
        printf("%s\n",p[i]);
    for(int i=n-1;i>-1;i--)
    {
        printf("the first of %c:\n",p[i][0]);
        int o = find_first(p,n,p[i][3],p[i][0]);
        if(o == 0 && p[i][4] == '\0')
                    printf("ep\t");
        else if(o==0)
        {
            int o = find_first(p,n,p[i][4],p[i][0]);
            if(o == 0 && p[i][5] == '\0')
                    printf("ep\t");
        }
        for(int j=0;j<strlen(p[i]);j++)
        {
            if(p[i][j] == '|'){
                o = find_first(p,n,p[i][j+1],p[i][0]);
                if(o == 0 && p[i][j+2] == '\0')
                    printf("ep\t");
                else if(o==0)
                {
                    find_first(p,n,p[i][j+2],p[i][0]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}