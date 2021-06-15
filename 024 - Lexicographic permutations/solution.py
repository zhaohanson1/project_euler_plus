# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

def f(N, K):
    bag = [chr(i + ord('a')) for i in range(K)]
    indicies = []
    choices = K
    currLo = 1
    currSeg = math.factorial(K-1)
    while choices > 1:
        seg = 0
        while not ( (seg * currSeg)+currLo <= N and N < ((seg+1) * currSeg)+currLo ):
            seg += 1
        indicies.append(seg)
        currLo = (seg * currSeg)+currLo
        choices -= 1
        currSeg //= choices
    
    ans = []
    while indicies:
        idx = indicies.pop(0)
        ans.append(bag.pop(idx))
    ans.append(bag[0])
    return "".join(ans)

T = int(input())
for _ in range(T):
    N = int(input())
    print(f(N, 13))