N = int(input())

words=[]

for i in range (0,N):
    word = input()
    words.append((len(word),word))

words = set(words)

result = sorted(words)

for x in range(0,len(result)):
    print(result[x][1])