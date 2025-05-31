import random

def get_dice_throws_result(num_throws, dice_to_check):
  """
  Throws a number of dice and counts how often the dice value occurs.
  """
  count = 0
  for _ in range(num_throws):
    roll = random.randint(1, 6)
    if roll == dice_to_check:
      count += 1
  return count

if __name__ == "__main__":
  print("30000 throws,", get_dice_throws_result(30000, 6), "sixes")
  print("6 throws,", get_dice_throws_result(6, 6), "sixes")
  print("600000 throws,", get_dice_throws_result(600000, 5), "fives")