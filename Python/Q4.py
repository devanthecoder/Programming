import sys
input = sys.stdin.readline
T = int(input())
while(T>0):
    n = int(input())
    arr = list(map(int, input().split()))
    freq = [0 for i in range(0,n)]
    for i in range(0,n):
        freq[i]+=1
    isPossible = True
    for i in range(0,n):
        if(freq[i]%i!=0):
            isPossible=False
            break
    if(not isPossible):
        print(-1)
        T-=1
        continue
    
    T-=1