#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    char string[51][51];
    char result[51];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",string[i]);
    }
    strcpy(result,string[0]);

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<strlen(result);j++)
        {
            if(string[i][j]=='0')
            {
                break;
            }

            else
            {
                if(string[i][j]!=string[0][j])
                {
                    result[j]='?';
                }
            }
        }
    }

    printf("%s",result);
}