N = (int(input()))
cnt_5 = 0
for a in range (1,N+1):
    tmp = a
    while(tmp!=1):
        if(tmp%5==0):
            tmp//=5
            cnt_5+=1
        else:
            break

print(cnt_5)