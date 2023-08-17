#include<bits/stdc++.h>
using namespace std;

unsigned long long GCD(unsigned long long A,unsigned long long B)
{
    if(B==0)
        return A;
    return GCD(B,A%B);
}

int is_int(string num)
{
    int flag = 2;//2가 일반 정수,1이 x.99999인정수,0은 그 외
    int idx = -1;
    for(int i=0;i<num.size();++i)
    {
        if(num[i]=='.')
        {
            flag = 1;
            idx = i;
            break;
        }
    }
    if(flag == 2)return 2;
    if(num[idx+1]=='(')
    {
        if(num[idx+2]=='9' && num[idx+3]==')')
            return 1;
    }
    return 0;
}

int what_fraction(string num)
{
    int idx=-1;
    for(int i=0;i<num.size();++i)
    {
        if(num[i]=='.')
        {
            idx = i;
            break;
        }
    }
    if(num[idx+1]=='(') return 2;//처음부터 순환
    for(int i=idx+2;i<num.size();++i)
    {
        if(num[i]=='(')
            return 1;//중간부터 순환
    }
    return 0;//그냥 분수
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string number;cin>>number;
    int Case = is_int(number);

    if(Case==2)
    {
        cout<<number<<"/1";
        return 0;
    }
    else if(Case==1)
    {
        string sub_string;
        int idx = 0;
        while(number[idx]!='.')
        {
            sub_string+=number[idx++];
        }
        unsigned long long tmp = stoull(sub_string);
        sub_string = to_string(tmp+1);
        cout<<sub_string<<"/1";
        return 0;
    }
    else
    {
        Case = what_fraction(number);
        if(Case == 2)//처음부터 순환
        {
            string INT,Dot;
            bool flag = false;
            for(int i=0;i<number.size();++i)
            {
                if(!flag)
                {
                    if(number[i]=='.')
                    {
                        flag = true;
                        continue;
                    }
                    INT+=number[i];
                }
                else
                {
                    if(number[i]=='(' || number[i]==')')
                        continue;
                    else
                    {
                        Dot+=number[i];
                    }
                }
            }
            string nine;
            for(int i=0;i<Dot.size();++i)
                nine+='9';
            unsigned long long up = stoull(INT+Dot)-stoull(INT),down = stoull(nine);
            unsigned long long gcd = GCD(up,down);
            cout<<to_string(up/gcd)<<'/'<<to_string(down/gcd);
            return 0;
        }
        if(Case==1)
        {
            string INT,no,yes;//정수,순환x,순환
            int flag = 0;
            for(int i=0;i<number.size();++i)
            {
                if(flag == 0)
                {
                    if(number[i]=='.')
                    {
                        flag = 1;
                        continue;
                    }
                    INT+=number[i];
                }
                else if(flag == 1)
                {
                    if(number[i]=='(')
                    {
                        flag = 2;
                        continue;
                    }
                    no+=number[i];
                }
                else
                {
                    if(number[i]=='(' || number[i]==')')
                        continue;
                    yes+=number[i];
                }
            }
            string up,down;
            for(int i=0;i<yes.size();++i) down+='9';//순환부분은 9
            for(int i=0;i<no.size();++i) down+='0';//순환아닌부분은 0
            unsigned long long UP = stoull(INT+no+yes)-stoull(INT+no);
            unsigned long long DOWN = stoull(down);
            unsigned long long gcd = GCD(UP,DOWN);
            cout<<to_string(UP/gcd)<<'/'<<to_string(DOWN/gcd);
        }

        else//그냥 소수
        {
            string INT,DOT;
            bool flag = false;
            for(int i=0;i<number.size();++i)
            {
                if(!flag)
                {
                    if(number[i]=='.')
                    {
                        flag = true;
                        continue;
                    }
                    INT+=number[i];
                }
                else
                {
                    DOT+=number[i];
                }
            }

            string up,down;
            up=INT+DOT;
            down ='1';
            for(int i=0;i<DOT.size();++i) down+='0';
            unsigned long long UP = stoull(up),DOWN=stoull(down);
            unsigned long long gcd = GCD(UP,DOWN);
            cout<<to_string(UP/gcd)<<'/'<<to_string(DOWN/gcd);
            return 0;
        }

    }

}