import sys
from collections import Counter

N = int(sys.stdin.readline())
numbers=list(map(int,sys.stdin.readline().split()))
M=int(sys.stdin.readline())
find=list(map(int,sys.stdin.readline().split()))

counter = Counter(numbers)
for x in find:
    print(counter[x],end=' ')