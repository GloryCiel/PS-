#include<iostream>

using namespace std;

void print(int n)
{
    int v[13],s,i,t,c,rn; char r[40];
    for(s=0,t=n,rn=0;t>0;s++,t-=8) if(t>=8) v[s]=255; else v[s]=(1<<t)-1;
    while(s)
    {
        for(i=s-1,c=0;i>=0;i--) v[i]+=c<<8,c=v[i]%10,v[i]/=10;
        while(s>0&&!v[s-1]) s--;
        r[rn++]=c+'0';
    }
    while(--rn>=0) putchar(r[rn]); putchar('\n');
}
void hanoi(int n, int a, int b, int c)
{
    if(n==1) {printf("%d %d\n", a, b); return;}
    hanoi(n-1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n-1, c, b, a);
}
int main()
{
    int n;cin>>n;
    print(n);
    if(n<=20) hanoi(n, 1, 3, 2);
}