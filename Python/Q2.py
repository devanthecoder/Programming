import sys
input = sys.stdin.readline
T = int(input())
while(T>0):
    n = int(input())
    arr = list(map(int, input().split()))
    for i in range(0, n):
        if(i!=n-1): print(n+1-arr[i], end=' ')
        else: print(n+1-arr[i])
    T-=1