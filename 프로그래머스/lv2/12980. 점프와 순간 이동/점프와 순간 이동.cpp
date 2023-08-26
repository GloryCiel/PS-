int solution(int n)
{
    int cnt = 1;
    while(n!=1)
    {
        if(n%2==0)
            n/=2;
        else
        {
            n--;
            cnt++;
        }
    }
    return cnt;
}