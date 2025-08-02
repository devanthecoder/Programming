def factorial(n):
    fact = 1
    while n>1:
        fact*=n
        n-=1
    return fact

e = 0
i = 0
while i<=100:
    e = e + 1/factorial(i)
    i+=1
    print(e)


