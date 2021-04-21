#!/bin/python3

import sys

fib_cache = [0 for _ in range(100)]

fib_cache =[0, 2]
sum_cache = [[2,2]]

while fib_cache[-1] <= (4  * 1e16):
    fib_cache.append(4*fib_cache[-1] + fib_cache[-2])
    if fib_cache[-1] % 2 == 0:
        sum_cache.append([fib_cache[-1], sum_cache[-1][1] + fib_cache[-1]])

def find_sum(n):
    lo = 0
    hi = len(sum_cache)
    while lo < hi:
        mid = (hi-lo)//2 + lo
        if sum_cache[mid][0] == n:
            return sum_cache[mid][1]
        elif sum_cache[mid][0] < n:
            lo = mid + 1
        else:
            hi = mid
    return sum_cache[lo-1][1]

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(find_sum(n))
