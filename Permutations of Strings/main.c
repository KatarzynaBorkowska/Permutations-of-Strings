#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int permutation(int n,char **s)
{
    int x = n - 1;
    while(x > 0 && strcmp(s[x-1], s[x]) >= 0)
        x--;
    if(x <= 0)
        return 0;
    
    int y = n - 1;
    while(strcmp(s[x - 1], s[y]) >= 0)
        y--;
    
    char *pom = s[x - 1];
    s[x - 1] = s[y];
    s[y] = pom;
    
    y =  n - 1;
    
    while(x < y)
    {
        pom = s[x];
        s[x] = s[y];
        s[y] = pom;
        x++;
        y--;
    }
    
    return 1;
}

int main(){
    
    char **s;
    int n;
    scanf("%d",&n);
    s = calloc(n,sizeof(char *));
    for(int i = 0;i < n;i++)
    {
        s[i] = calloc(11, sizeof(char));
        scanf("%s",s[i]);
    }
    
    do{
        for(int i = 0;i < n;i++)
        {
            printf("%s%c",s[i],i + 1 == n?'\n':' ');
        }
    }while(permutation(n, s));
    
    free(s);
    return 0;
}
