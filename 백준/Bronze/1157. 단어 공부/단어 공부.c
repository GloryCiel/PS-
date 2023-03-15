#include <stdio.h>

int character_converter(char a)
{
    int result = a;
    if(a>90)
    {
        result = a-32;
    }
    return result;
}

int main()
{
    char word[1000000];
    scanf("%s",word);
    int count[26][2];
    int result;

    for(int i=0;i<26;i++)
    {
        count[i][0]=i+65;
    }
    for(int i=0;i<26;i++)
    {
        count[i][1]=0;
    }

    int recur=0;

    while(word[recur]!='\0')
    {
        int character = character_converter(word[recur]);

        count[character-65][1]++;
        recur++;
    }
    result = 0;//결과의 인덱스
    int result_num = count[0][1];//인덱스의 반복횟수
    for(int i=1;i<26;i++)
    {
        if(result_num<count[i][1])
        {
            result_num = count[i][1];
            result = i;
        }
    }

    int cnt = 0;

    for(int i=0;i<26;i++)
    {
        if(result_num == count[i][1] && result!=i)
        {
            cnt++;
        }
    }
    if(cnt==0)
    {
        printf("%c",result+65);
    }
    else
    {
        printf("?");
    }

}