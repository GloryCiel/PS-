#include<stdio.h>
#include<string.h>
#include<stdio.h>

int main()
{
    char Sentence[1000000];
    int result = 0;
    
    scanf("%[^\n]s",&Sentence);

    int i=0;
    char tmp = Sentence[i];

    while(tmp!='\0')
    {
        if((tmp == 32) && i!=0)
        {
            result++;
        }
        tmp = Sentence[++i];
    }
    tmp = Sentence[--i];
    if(tmp !=32)
        result++;
    printf("%d",result);
}