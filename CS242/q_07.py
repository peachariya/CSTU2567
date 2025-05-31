import re

def password_strength(password):
  """
  Evaluates password strength based on rules.
  """
  if len(password) < 6:
    return "Weak"

  has_letters = bool(re.search('[a-zA-Z]', password))
  has_numbers = bool(re.search('[0-9]', password))

  if len(password) >= 8 and has_letters and has_numbers:
    return "Strong"
  elif len(password) >= 6 and (has_letters or has_numbers):
    return "Medium"
  else:
    return "Weak"

if __name__ == "__main__":
  print(password_strength("Password123"))
  print(password_strength("Password"))
  print(password_strength("Pass1"))
  print(password_strength("short"))