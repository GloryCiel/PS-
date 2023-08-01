def hate_python(res):
    if (res -int(res)>=0.5):
        return int(res)+1
    else:
        return(int(res))

n = int(input())

if(n==0):
    print(0)
    exit(0)

difficulty=[]

for i in range(0,n):
    tmp = int(input())
    difficulty.append(tmp)

difficulty.sort()

num = round(n*0.15+0.00000001)

sum=0

for i in range(num,n-num):
    sum+=difficulty[i]

result =hate_python(sum/(n-2*num))
print(result)