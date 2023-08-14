import sys

N = int(sys.stdin.readline())
age_name=[]

for _ in range(N):
    a,b = sys.stdin.readline().split()
    a=int(a)
    tmp = (a,b)
    age_name.append(tmp)

result = sorted(age_name,key=lambda x:x[0])
for i in result:
    print(i[0],end=' ')
    print(i[1])