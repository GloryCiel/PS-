import sys

N = int(sys.stdin.readline())
a = []
for _ in range(N):
    tmp = int(sys.stdin.readline())
    a.append(tmp)

a.sort()

for i in a:
    print(i)