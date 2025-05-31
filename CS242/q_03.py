def check_perfection(num):
  """
  ตรวจสอบว่าตัวเลขเป็นจำนวนสมบูรณ์หรือไม่ และพิมพ์ผลลัพธ์

  Args:
    num: จำนวนเต็มที่ต้องการตรวจสอบ
  """
  sum_of_divisors = 0
  for i in range(1, num):
    if num % i == 0:
      sum_of_divisors += i

  if sum_of_divisors == num:
    print(f"{num} is a perfect number")
  else:
    print(f"{num} is NOT a perfect number")

check_perfection(28)
check_perfection(54)
check_perfection(496)