N = int(input())

dp=[-1,-1,-1,1,-1,1]

for x in range(6,N+1):
    if(dp[x-3]==-1 and dp[x-5]==-1):
        dp.append(-1)
    else:
        flag = False
        if(dp[x-3]!=-1):
            dp.append(dp[x-3]+1)
            flag = True
        if(dp[x-5]!=-1):
            if(flag):
                dp[x]=min(dp[x],dp[x-5]+1)
            else:
                dp.append(dp[x-5]+1)

print(dp[N])