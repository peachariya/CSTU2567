def mood_detector(message):
  """
  Analyzes a text message and classifies the mood.
  """
  message = message.lower()
  happy_words = ["happy", "joy", "excited", "great", "fun"]
  sad_words = ["sad", "depressed", "bad", "terrible", "cry"]

  if any(word in message for word in happy_words):
    return "Happy"
  elif any(word in message for word in sad_words):
    return "Sad"
  else:
    return "Neutral"

if __name__ == "__main__":
  print(mood_detector("I am so happy today!"))
  print(mood_detector("This is terrible."))
  print(mood_detector("The weather is okay."))