#!/bin/python3

import sys
import bisect
palindromes = []

def isPalindrome(s):
    n = len(s)
    for i in range((n//2) + 1):
        if s[i] != s[n-1-i]:
            return False
    return True

def generate_palindromes():
    for i in range(100, 1000):
        for j in range(100, 1000):
            v = i * j
            sv = str(v)
            if isPalindrome(sv):
                palindromes.append(v)
    palindromes.sort()

t = int(input().strip())
generate_palindromes()
for a0 in range(t):
    n = int(input().strip())
    idx = bisect.bisect_left(palindromes, n) - 1
    print(palindromes[idx])
    
