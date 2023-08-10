import sys

N,K = map(int,sys.stdin.readline().split())
people =[]
to_print = []

for i in range(N):
    people.append(i+1)

pop_idx = K-1

while(len(people)!=0):
    if(pop_idx>=len(people)):
        pop_idx%=len(people)
    to_print.append(people[pop_idx])
    people.pop(pop_idx)
    pop_idx+=K-1

print("<",end='')
for i in range(N-1):
    print("{num}, ".format(num=to_print[i]),end='')
print("{num}>".format(num=to_print[-1]))
