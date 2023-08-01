K = int(input())
number=[]
for _ in range(0,K):
    tmp = int(input())
    if(tmp!=0):
        number.append(tmp)
    else:
        del number[-1]

print(sum(number))