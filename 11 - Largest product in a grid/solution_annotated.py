#!/bin/python3

import sys

_N = 20
_K = 4
grid = []
maxVal = 0

def init(i, j, z, v):
    """
    Add the values of the first sequence and count the zeros.
    """
    if grid[i][j] == 0:
        z += 1
    else:
        v *= grid[i][j]
    return z, v

def step(x, y, i, j, z, v):
    """
    Remove the previous value in the sequence and add in the next value.
    """
    global maxVal
    if grid[x][y] == 0:
        z -= 1
    else:
        v //= grid[x][y]
    if grid[i][j] == 0:
        z += 1
    else:
        v *= grid[i][j]
        if z == 0:
            maxVal = max(v, maxVal)
    return z, v

# Read input
for i in range(_N):
    row = [int(x) for x in input().strip().split(' ')]
    grid.append(row)
    
# Row and Column Traversal
for i in range(_N):
    rowZeros = 0; colZeros = 0; rowVal = 1; colVal = 1
    for j in range(_K):
        rowZeros, rowVal = init(i, j, rowZeros, rowVal)
        colZeros, colVal = init(j, i, colZeros, colVal)
    maxVal = max([
            maxVal, 
            0 if rowZeros > 0 else rowVal, 
            0 if colZeros > 0 else colVal
        ])
    for j in range(_K, _N):
        rowZeros, rowVal = step(i, j-_K, i, j, rowZeros, rowVal)
        colZeros, colVal = step(j-_K, i, j, i, colZeros, colVal)

# Traversal the diagonals
for i in range(_N-_K+1):
    fRowDiagZeros = 0; fRowDiagVal = 1; fColDiagZeros = 0; fColDiagVal = 1
    bRowDiagZeros = 0; bRowDiagVal = 1; bColDiagZeros = 0; bColDiagVal = 1

    for d in range(_K):
        fRowDiagZeros, fRowDiagVal = init(d, d+i, fRowDiagZeros, fRowDiagVal)
        fColDiagZeros, fColDiagVal = init(d+i, d, fColDiagZeros, fColDiagVal)
        bRowDiagZeros, bRowDiagVal = init(d, _N-d-1-i, bRowDiagZeros, bRowDiagVal)
        bColDiagZeros, bColDiagVal = init(_N-d-1-i, d, bColDiagZeros, bColDiagVal)
        
    maxVal = max([
            maxVal, 
            0 if fRowDiagZeros > 0 else fRowDiagVal, 
            0 if fColDiagZeros > 0 else fColDiagVal,
            0 if bRowDiagZeros > 0 else bRowDiagVal, 
            0 if bColDiagZeros > 0 else bColDiagVal
        ])
        
    for d in range(_K, _N-i):
        fRowDiagZeros, fRowDiagVal = step(d-_K, d+i-_K, d, d+i, fRowDiagZeros, fRowDiagVal)
        fColDiagZeros, fColDiagVal = step(d+i-_K, d-_K, d+i, d, fColDiagZeros, fColDiagVal)
        bRowDiagZeros, bRowDiagVal = step(d-_K, _N-d-1-i+_K, d, _N-d-1-i, bRowDiagZeros, bRowDiagVal)
        bColDiagZeros, bColDiagVal = step(_N-d-1-i+_K, d-_K, _N-d-1-i, d, bColDiagZeros, bColDiagVal)

print(maxVal)