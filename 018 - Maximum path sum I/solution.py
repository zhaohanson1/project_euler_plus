# Enter your code here. Read input from STDIN. Print output to STDOUT
import time
import sys
from functools import lru_cache

class TreeNode:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
    
    def __repr__(self, level=0):
        ret = " "*level+repr(self.value)+"\n"
        if self.left:
            ret += self.left.__repr__(level+1)
        if self.right:
            ret += self.right.__repr__(level+1)
        return ret
        
def buildTree(values):
    root = None
    prevRow = []
    for r in values:
        currRow = []
        for v in r:
            currRow.append(TreeNode(v))
        if len(prevRow) == 0:
            root = currRow[0]
        for i in range(len(prevRow)):
            prevRow[i].left = currRow[i]
            prevRow[i].right = currRow[i+1]
        prevRow = currRow
    return root

    
@lru_cache(maxsize=1000)
def getMaxPath(node):
    if node.left is None and node.right is None:
        return node.value
    else:
        return node.value + max(getMaxPath(node.left), getMaxPath(node.right))
        
def f(values):
    root = buildTree(values)
    start = time.time()
    ans = getMaxPath(root)
    end = time.time()
    print("Time: ", end-start, file=sys.stderr)
    return ans
    
    
        

T = int(input())
for _ in range(T):
    N = int(input())
    values = [list(map(int, input().split())) for _ in range(N)]
    print(f(values))
