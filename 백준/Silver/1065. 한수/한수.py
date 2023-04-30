def find(N):
    temphund=0
    tempten=0
    tempone=0
    cnt=0

    for x in range (1,N+1):
        y=x
        temphund=y//100
        y=y%100
        tempten=y//10
        y=y%10
        tempone=y
        if(temphund==0):
            if(tempten==0):
                cnt+=1
            else:
                cnt+=1
        else:
            if((temphund-tempten)==(tempten-tempone)):
                cnt+=1
    return cnt


N=int(input())
print(find(N))