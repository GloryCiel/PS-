import sys
from collections import deque

T = int(sys.stdin.readline())

while(T>0):
    N,M = map(int,sys.stdin.readline().split())
    priority = deque(list(map(int,sys.stdin.readline().split())))
    document = deque([0]*N)
    document[M]=1

    cnt = 0
    while True:
        if priority[0]==max(priority):
            cnt+=1

            if document[0]==1:
                print(cnt)
                break
            else:
                priority.popleft()
                document.popleft()
        else:
            priority.append(priority.popleft())
            document.append(document.popleft())
    T-=1