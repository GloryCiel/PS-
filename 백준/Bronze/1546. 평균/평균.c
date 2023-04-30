#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_subject;
    scanf("%d",&num_of_subject);

    double* score = malloc(sizeof(double)*num_of_subject);

    for(int i=0;i<num_of_subject;i++)
    {
        int tmp;
        scanf("%d ",&tmp);
        score[i]=tmp;
    }

    int max_score = score[0];

    for(int i=1;i<num_of_subject;i++)
    {
        if(max_score<=score[i])
        {
            max_score=score[i];
        }
    }

    for(int i=0;i<num_of_subject;i++)
    {
        score[i]=score[i]/max_score*100;
    }

    double mean=0;

    for(int i=0;i<num_of_subject;i++)
    {
        mean+=score[i];
    }

    printf("%f\n",mean/num_of_subject);

}