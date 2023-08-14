import sys
from collections import deque

I = [-1, 1, 0, 0]
J = [0, 0, -1, 1]

def chk(warehouse,i,j,N,M):
    if i<0 or i>=N:
        return False
    if j<0 or j>=M:
        return False
    if warehouse[i][j]==-1:
        return False
    return True

def BFS(warehouse,tomato,N,M):
    while tomato:
        now = tomato.popleft()
        for x in range (4):
            next_i = now[0]+I[x]
            next_j = now[1]+J[x]
            if chk(warehouse,next_i,next_j,N,M) and warehouse[next_i][next_j]==0:
                warehouse[next_i][next_j]= warehouse[now[0]][now[1]]+1
                tomato.append([next_i,next_j])

M,N = map(int,sys.stdin.readline().split())
warehouse = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

tomato = deque([])

for i in range (N):
    for j in range(M):
        if warehouse[i][j]==1:
            tomato.append([i,j])

BFS(warehouse, tomato, N, M)

day = 0
for i in range(N):
    for j in range(M):
        if(warehouse[i][j]==0):
            print(-1)
            exit(0)
        if(day<warehouse[i][j]):
            day = warehouse[i][j]
print(day-1)