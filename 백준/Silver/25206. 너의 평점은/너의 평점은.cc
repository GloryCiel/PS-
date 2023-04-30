#include<iostream>
#include<string>
using namespace std;

int main()
{
    double multiply=0;
    int number_of_subject=0;
    for(int i=0;i<20;++i)
    {
        string name,grade;//과목명,ABCD
        double number;//학점
        double grade_number;
        cin>>name>>number>>grade;
        if(grade=="A+")
            grade_number=4.5;
        else if(grade =="A0")
            grade_number=4.0;
        else if(grade =="B+")
            grade_number=3.5;
        else if(grade =="B0")
            grade_number=3.0;
        else if(grade =="C+")
            grade_number=2.5;
        else if(grade =="C0")
            grade_number=2.0;
        else if(grade =="D+")
            grade_number=1.5;
        else if(grade =="D0")
            grade_number=1.0;
        else if(grade =="F")
            grade_number=0;
        else
            continue;
        multiply=multiply + number * grade_number;
        number_of_subject=number_of_subject+number;
    }
    cout<<multiply/number_of_subject;
}