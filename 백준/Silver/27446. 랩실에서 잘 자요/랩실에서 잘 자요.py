import sys

N,M = map(int,sys.stdin.readline().split())

is_in = []
for _ in range(N+1):
    is_in.append(False)
to_print = []


tmp = list(map(int,input().split()))
for i in tmp:
    is_in[i]=True

for i in range(1,N+1):
    if(not is_in[i]):
        to_print.append(i)

if(len(to_print)==0):
    print(0)

elif(len(to_print)==1):
    print(7)

else:
    dp=[0]*(N+1)
    start = to_print[0];idx = 1;cnt = 1
    dp[start] = 7

    for i in range(start+1,N+1):
        if(i != to_print[idx]):
            dp[i]=dp[i-1]
            cnt+=1
        else:
            dp[i]=min(dp[i-1]+7,dp[i-1]+2*cnt)
            cnt=1
            if(idx+1<len(to_print)):
                idx+=1
    print(dp[N])