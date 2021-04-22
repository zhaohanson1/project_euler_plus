#!/bin/python3

import sys

# Define constants to show this can be done for arbitrary grid size and sequence length
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
    grid[x][y] will contain the last value in the sequence.
    grid[i][j] will contain the next value in the sequence.
    """
    global maxVal
    # If last value is 0, simply decrement number of zeros
    # Otherwise, divide out the last value
    if grid[x][y] == 0:
        z -= 1
    else:
        v //= grid[x][y]

    # if next value is 0, increment zeros
    # otherwise update value and if no zeros, product is nonzero
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
    
# Synchronous Row and Column Traversal
for i in range(_N):
    # Initialize number of zeros and current product
    rowZeros = 0; colZeros = 0; rowVal = 1; colVal = 1

    # Update variables with the first K values
    for j in range(_K):
        rowZeros, rowVal = init(i, j, rowZeros, rowVal)
        colZeros, colVal = init(j, i, colZeros, colVal)

    #Update maxValue with initial sequence 
    maxVal = max([
            maxVal, 
            0 if rowZeros > 0 else rowVal, 
            0 if colZeros > 0 else colVal
        ])

    # see step
    for j in range(_K, _N):
        rowZeros, rowVal = step(i, j-_K, i, j, rowZeros, rowVal)
        colZeros, colVal = step(j-_K, i, j, i, colZeros, colVal)

# Traversal the diagonals
# only the first 17 row/cols will contain enough values in the diagonals to form a 4 length sequence
for i in range(_N-_K+1):
    # Initialize number of zeros and current product
    fRowDiagZeros = 0; fRowDiagVal = 1; fColDiagZeros = 0; fColDiagVal = 1
    bRowDiagZeros = 0; bRowDiagVal = 1; bColDiagZeros = 0; bColDiagVal = 1

    """
    To traverse diagonals,
    standard diagonal: diagonal where row and col idx are the same
    backward diagonal: diagonal is the reflected version of the standard

    fRow -> diagonals that start on the first row
        Similar to the standard diagonal, except we vary the column by adding an offset i
    fCol -> diagonals that start on the first col
        Similar to the standard diagonal, except we vary the row by adding an offset i
    bRow -> diagonals that start on first row, but we traverse backwards with respect to the column
        by iterating through N-i-1 for all i
    bCol -> diagonals that start on the first col, but we traverse backwards with respect to the row
        by iterating through N-i-1 for all i
    """

    # Update variables with the first K values
    for d in range(_K):
        fRowDiagZeros, fRowDiagVal = init(d, d+i, fRowDiagZeros, fRowDiagVal)
        fColDiagZeros, fColDiagVal = init(d+i, d, fColDiagZeros, fColDiagVal)
        bRowDiagZeros, bRowDiagVal = init(d, (_N-i-1)-d, bRowDiagZeros, bRowDiagVal)
        bColDiagZeros, bColDiagVal = init((_N-i-1)-d, d, bColDiagZeros, bColDiagVal)
        
    #Update maxValue with initial sequences
    maxVal = max([
            maxVal, 
            0 if fRowDiagZeros > 0 else fRowDiagVal, 
            0 if fColDiagZeros > 0 else fColDiagVal,
            0 if bRowDiagZeros > 0 else bRowDiagVal, 
            0 if bColDiagZeros > 0 else bColDiagVal
        ])
    
    # see step
    for d in range(_K, _N-i):
        fRowDiagZeros, fRowDiagVal = step(d-_K, d+i-_K, d, d+i, fRowDiagZeros, fRowDiagVal)
        fColDiagZeros, fColDiagVal = step(d+i-_K, d-_K, d+i, d, fColDiagZeros, fColDiagVal)
        bRowDiagZeros, bRowDiagVal = step(d-_K, (_N-i-1)-d+_K, d, (_N-i-1)-d, bRowDiagZeros, bRowDiagVal)
        bColDiagZeros, bColDiagVal = step((_N-i-1)-d+_K, d-_K, (_N-i-1)-d, d, bColDiagZeros, bColDiagVal)

print(maxVal)