import sys
import bisect
from bisect import bisect_left

N = int(sys.stdin.readline())
A=list(map(int,sys.stdin.readline().split()))
A.sort()

M = int(sys.stdin.readline())
B = list(map(int,sys.stdin.readline().split()))

for i in B:
    if(bisect.bisect_right(A,i)-bisect_left(A,i)!=0):
        print(1)
    else:
        print(0)