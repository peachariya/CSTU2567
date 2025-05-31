def validate_credit_card(card_number):
  """
  Checks if a credit card number is valid using the Luhn Algorithm.
  """
  card_number = str(card_number)  # Ensure it's a string
  digits = [int(d) for d in card_number]
  digits.reverse()

  doubled_digits = []
  for i, digit in enumerate(digits):
    if i % 2 != 0:  # Double every second digit
      doubled = digit * 2
      if doubled > 9:
        doubled -= 9
      doubled_digits.append(doubled)
    else:
      doubled_digits.append(digit)

  total = sum(doubled_digits)
  return total % 10 == 0


if __name__ == "__main__":
  print(validate_credit_card(79927398713))
  print(validate_credit_card(1234567890123456))