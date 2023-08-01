import sys

N,M,B = map(int,sys.stdin.readline().split())

land = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]

result_height=0
result_time =10000000000000

for h in range(257):
    Max = 0
    Min = 0
    for i in range(N):
        for j in range(M):
            if(land[i][j]<h):
                Min+=(h-land[i][j])
            else:
                Max+=(land[i][j]-h)
    tmp = Max+B
    if(tmp<Min):
        continue
    time = 2*Max+Min
    if(time<=result_time):
        result_height = h
        result_time=time

print(result_time,result_height)