def get_sum_of_divisors(num):
  """
  Calculates the sum of all divisors of a number, excluding the number itself.

  Args:
    num: The integer to find the sum of divisors for.

  Returns:
    The sum of the divisors of num (excluding num).
  """
  sum_of_divisors = 0
  for i in range(1, num):
    if num % i == 0:
      sum_of_divisors += i
  return sum_of_divisors

# Example Usage
print("get_sum_of_divisors(6)", get_sum_of_divisors(6))
print("get_sum_of_divisors(24)", get_sum_of_divisors(24))
print("get_sum_of_divisors(25)", get_sum_of_divisors(25))
print("get_sum_of_divisors(5628)", get_sum_of_divisors(5628))