#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string expression;cin>>expression;

    vector<int> string_num_to_int;
    vector<int> op;
    op.push_back(1);

    string tmp;
    bool first_not_0 = false;

    for(int i=0;i<expression.size();++i)
    {
        if(expression[i]=='-')
        {
            op.push_back(-1);
            string_num_to_int.push_back(stoi(tmp));
            tmp ="";
            first_not_0=false;
        }
        else if(expression[i]=='+')
        {
            op.push_back(1);
            string_num_to_int.push_back(stoi(tmp));
            tmp="";
            first_not_0=false;
        }
        else
        {
            if(expression[i]==0)
            {
                if(first_not_0)
                {
                    tmp+=expression[i];
                    if(+1==expression.size())
                        string_num_to_int.push_back(stoi(tmp));
                }
            }
            else
            {
                first_not_0=true;
                tmp+=expression[i];
                if(i+1==expression.size())
                    string_num_to_int.push_back(stoi(tmp));
            }
        }
    }

    int to_minus=-1;
    for(int i=0;i<op.size();++i)
    {
        if(op[i]==-1)
        {
            to_minus=i;
            break;
        }
    }

    int result = 0;
    if(to_minus == -1)
    {
        for(int i=0;i<string_num_to_int.size();++i)
            result+=string_num_to_int[i];
    }
    else
    {
        int op_cnt=1;
        for(int i=0;i<string_num_to_int.size();++i)
        {
            if(op_cnt>=to_minus+1)
            {
                result-=string_num_to_int[i];
            }
            else
            {
                result+=string_num_to_int[i];
                op_cnt++;
            }

        }
    }

    cout<<result;

}