#include<stdio.h>

int rank(int a)
{
    if(a==6)
    {
        return 1;
    }

    else if(a==5)
    {
        return 2;
    }

    else if(a==4)
    {
        return 3;
    }

    else if(a==3)
    {
        return 4;
    }

    else if(a==2)
    {
        return 5;
    }

    else
    {
        return 6;
    }
}

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*2);
    int number_of_zero = 0;
    int number_of_match = 0;

    int bef_max;
    int bef_min;

    for(int i=0;i<6;i++)
    {
        if(!lottos[i])
        {
            number_of_zero++;
        }
    }

    for(int i=0;i<6;i++)
    {
        if(!lottos[i])
        {
            continue;
        }
        else
        {
            for(int j=0;j<6;j++)
            {
                if(lottos[i]==win_nums[j])
                {
                    number_of_match++;
                }
            }
        }
    }

    bef_max = number_of_zero+ number_of_match;
    bef_min = number_of_match;

    answer[0] = rank(bef_max);
    answer[1] = rank(bef_min);


    return answer;
}