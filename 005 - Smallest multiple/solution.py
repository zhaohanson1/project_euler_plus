#!/bin/python3

import sys
import math

N = 40

def lcm(a,b):
    return int((a*b) / math.gcd(a,b))

sm = [1]
for i in range(1,N+1):
    sm.append(lcm(sm[-1], i))
    
t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(sm[n])
