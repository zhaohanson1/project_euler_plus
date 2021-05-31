months = [31,28,31,30,31,30,31,31,30,31,30,31]

def leaps(N):
    return N//4 - (N//100 - N//400)

def isLeapYear(y):
    return (y % 4 == 0 and (y % 100 != 0 or y % 400 == 0))

def advance(currD, currY, m):
    if isLeapYear(currY) and m==1:
        currD += 1
    return (currD +months[m]) % 7

def f(y1,m1,d1,y2,m2,d2):
     
    currD = 1   # 1-1-1990 is a Monday
    
    # Count years from 1900 to Y1
    L = leaps(y1-1) - leaps(1900)
    leap = 366 * L
    non_leap = 365 * (y1-1900-L)
    currD = (currD + (leap + non_leap)) % 7
    
    ans = 0
    currY = y1
    
    for m in range(m1):
        # First month edge case
        if m == m1-1 and d1 == 1 and currD == 0:
            ans += 1
        currD = advance(currD, currY, m)
    
    s = m1    
    while currY < y2:
        for m in range(s, 12):
            if currD == 0:
                ans += 1
            currD = advance(currD, currY, m)
        s = 0
        currY += 1
    
    for m in range(s,m2):
        if currD == 0:
            ans += 1
        currD = advance(currD, currY, m)

    return ans

T = int(input())
for x in range(T):
    y1, m1, d1 = map(int, input().strip().split())
    y2, m2, d2 = map(int, input().strip().split())
    print(f(y1, m1, d1, y2, m2, d2))
    