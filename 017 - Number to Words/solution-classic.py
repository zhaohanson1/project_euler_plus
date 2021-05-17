# Enter your code here. Read input from STDIN. Print output to STDOUT
segment = ["", "Thousand", "Million", "Billion", "Trillion"]
tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
single = ["", "One", "Two", "Three","Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
    
def g(N):
    letter_count = 0
    #word = []
    if N // 100 > 0:
        #word.append(single[N // 100])
        #word.append("Hundred")
        letter_count += len(single[N // 100])
        letter_count += len("Hundred")

        N -= (N // 100) * 100
        if N > 0:
            letter_count += len("And")
    
    if N >= 20:
        #word.append(tens[N // 10])
        #word.append(single[N % 10])
        letter_count += len(tens[N // 10])
        letter_count += len(single[N % 10])
    else:
        #word.append(single[N])
        letter_count += len(single[N])
    #ans = " ".join(word).strip()
    ans = letter_count
    return ans
        
    
def f(N):
    if N == 0:
        return "Zero"
    
    idx = 0
    #word = []
    count = 0
    while N >= 1000:
        if N % 1000 > 0:
            #word.insert(0, g(N % 1000) + ' ' + segment[idx])
            count += g(N % 1000) + len(segment[idx])
        N //= 1000
        idx += 1
    if N > 0:
        #word.insert(0, g(N) + ' ' + segment[idx])
        count += g(N) + len(segment[idx])
    #ans = " ".join(word).strip()
    ans = count
    return ans

"""
T = int(input())
for _ in range(T):
    N = int(input())
    print(f(N))
"""
total = 0
for i in range(1, 1001):
    total += f(i)
print(total)
