n = int(input())

stack=[]
result=[]

now = 1
for i in range(1,n+1):
    num = int(input())

    while(now<=num):
        stack.append(now)
        result.append('+')
        now+=1
    if(stack[-1]==num):
        stack.pop()
        result.append('-')
    else:
        print("NO")
        exit(0)

for x in result:
    print(x)