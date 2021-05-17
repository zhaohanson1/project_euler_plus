# Enter your code here. Read input from STDIN. Print output to STDOUT
segment = ["", "Thousand", "Million", "Billion", "Trillion"]
tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
single = ["", "One", "Two", "Three","Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
    
def g(N):
    
    word = []
    if N // 100 > 0:
        word.append(single[N // 100])
        word.append("Hundred")
        N -= (N // 100) * 100
    
    if N >= 20:
        word.append(tens[N // 10])
        word.append(single[N % 10])
        
    else:
        word.append(single[N])
    ans = " ".join(word).strip()
    return ans
        
    
def f(N):
    if N == 0:
        return "Zero"
    
    idx = 0
    word = []
    while N >= 1000:
        if N % 1000 > 0:
            word.insert(0, g(N % 1000) + ' ' + segment[idx])
        N //= 1000
        idx += 1
    if N > 0:
        word.insert(0, g(N) + ' ' + segment[idx])
    ans = " ".join(word).strip()
    return ans

T = int(input())
for _ in range(T):
    N = int(input())
    print(f(N))
