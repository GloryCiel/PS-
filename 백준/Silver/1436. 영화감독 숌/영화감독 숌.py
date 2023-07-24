N = int(input())
cnt = 0
result = 0

while cnt != N:
    result+=1
    tmp = result
    while tmp!=0:
        if(tmp%1000==666):
            cnt+=1
            break
        else:
            tmp//=10

print(result)