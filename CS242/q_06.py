def rps_winner(player1, player2):
  """
  Determines the winner of a Rock-Paper-Scissors game.
  """
  player1 = player1.lower()
  player2 = player2.lower()

  if player1 not in ["rock", "paper", "scissors"] or player2 not in ["rock", "paper", "scissors"]:
    return "Invalid input"

  if player1 == player2:
    return "Tie"
  elif (player1 == "rock" and player2 == "scissors") or \
       (player1 == "paper" and player2 == "rock") or \
       (player1 == "scissors" and player2 == "paper"):
    return "Player 1 wins"
  else:
    return "Player 2 wins"

if __name__ == "__main__":
  print(rps_winner("rock", "scissors"))
  print(rps_winner("paper", "rock"))
  print(rps_winner("scissors", "paper"))
  print(rps_winner("rock", "rock"))