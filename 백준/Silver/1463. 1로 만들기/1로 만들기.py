X = (int(input()))

dp=[0,0,1,1]
if(X<4):
    print(dp[X])
else:
    for a in range(4,X+1):
        dp.append(dp[a-1]+1)
        if(a%2==0):
            dp[a]=min(dp[a],dp[a//2]+1)
        if(a%3==0):
            dp[a]=min(dp[a],dp[a//3]+1)

    print(dp[X])