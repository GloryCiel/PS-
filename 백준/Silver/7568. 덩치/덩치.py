import sys

N = int(sys.stdin.readline())

height_weight=[]

for _ in range (N):
    a,b = map(int,sys.stdin.readline().split())
    tmp =[a,b]
    height_weight.append(tmp)

for i in range(N):
    bigger = 0
    for j in range(N):
        if(i==j):
            continue
        if(height_weight[i][0]<height_weight[j][0] and height_weight[i][1]<height_weight[j][1]):
            bigger+=1
    print(bigger+1,end=' ')