import random

def user_number_guess(secret_number):
  """
  Prompts the user to guess a hidden number until they guess correctly.
  """
  guesses = 0

  while True:
    try:
      guess = int(input("Enter your guess (1 - 99): "))
    except ValueError:
      print("Invalid input. Please enter a number.")
      continue

    guesses += 1

    if guess < secret_number:
      print("Too low")
    elif guess > secret_number:
      print("Too high")
    else:
      print("Correct! Number of guesses:", guesses)
      break


if __name__ == "__main__":
  secret_number = random.randrange(1, 100)  # Generates a random number
  user_number_guess(secret_number)