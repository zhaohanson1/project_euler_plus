#!/bin/python3

import sys
cache = [0]
for i in range(2,int(1e4)+1):
    cache.append(cache[-1] + (i*i*(i-1)))

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(cache[n-1])