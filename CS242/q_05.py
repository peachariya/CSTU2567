def triangle_type(a, b, c):
  """
  Determines the type of a triangle based on side lengths.
  """
  if a + b <= c or a + c <= b or b + c <= a:
    return "Not a valid triangle"

  if a == b == c:
    return "Equilateral"
  elif a == b or a == c or b == c:
    return "Isosceles"
  else:
    return "Scalene"

if __name__ == "__main__":
  print(triangle_type(5, 5, 5))
  print(triangle_type(5, 5, 6))
  print(triangle_type(5, 6, 7))
  print(triangle_type(1, 2, 5))