import sys
input = sys.stdin.readline
T = int(input())
while(T>0):
    k,x = map(int, input().split())
    for i in range(0,k):
        # print((x-1)%3==0 and ((x-1)//3)%2==1)
        if((x-1)%3==0 and ((x-1)//3)%2==1):
            x=((x-1)//3)
        else: x = 2*x
    print(x)
    T-=1