#!/bin/python3

import sys


#include <iostream>
def gsum(n):
    return (n*(n+1)) // 2

for a0 in range(int(input())):
    n = int(input()) - 1
    print((3*gsum(n//3))+(5*gsum(n//5))-(15*gsum(n//15)))