def harmonic_sum(N):
    sum_forward = sum(1/i for i in range(1,N+1))
    sum_backward = sum(1/i for i in range(N,0,-1))
    return sum_forward,sum_backward,sum_forward==sum_backward
print(harmonic_sum(1000))