# Enter your code here. Read input from STDIN. Print output to STDOUT

import math

def f(N):
    # Cache for each digit raised to a certain power
    digit_to_power = {}
    power_value = N
    for digit in range(10):
        digit_to_power[digit] = int(math.pow(digit, power_value))

    # List to store numbers equal to sum of their digits raised to a certain power
    equal_power_sum_numbers = []

    # Maximum limit for the range of numbers
    range_limit = pow(10, power_value+1)
    for number in range(9, range_limit):
        power_sum = 0
        temp_number = number
        while number > 0:
            power_sum += digit_to_power[number%10]
            number //= 10
        if power_sum == temp_number:
            equal_power_sum_numbers.append(power_sum)

    return sum(equal_power_sum_numbers)

N = int(input())
print(f(N))
