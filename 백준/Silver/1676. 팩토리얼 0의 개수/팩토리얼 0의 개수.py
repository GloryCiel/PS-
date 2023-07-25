N = (int(input()))
cnt_2 = 0
cnt_5 = 0
for a in range (1,N+1):
    tmp = a
    while(tmp!=1):
        if(tmp%2==0):
            tmp//=2
            cnt_2+=1
        elif(tmp%5==0):
            tmp//=5
            cnt_5+=1
        else:
            break

print(min(cnt_2,cnt_5))