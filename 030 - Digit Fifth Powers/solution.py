import math

# Cache for each digit raised to a certain power
digit_to_power = {}
power_value = 5
for digit in range(10):
    digit_to_power[digit] = math.pow(digit, power_value)
print(digit_to_power)

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

print(sum(equal_power_sum_numbers))
