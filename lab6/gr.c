#include<stdio.h>
#include<stdlib.h>

int find_production(char p[1000][1000],int n,char k)
{
    for(int i=0;i<n;i++)
    {
        if(p[i][0] == k)
            return i;
    }
    return -1;
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
    for(int i=0;i<n;i++)
    {
            if(p[i][3]>='a' && p[i][3]<='z')
            {
                 printf("follow of %c is %c\n",p[i][0],p[i][3]);
            }
            else{
                int index = find_production(p,n,p[i][3]);
                printf("follow of %c is %c\n",p[i][0],p[index][3]);
            }
    
    }
    return 0;
}