def convert_time(time_str):
  """
  Converts a 12-hour format time (AM/PM) to 24-hour format.
  """
  time_str = time_str.upper()
  if "AM" not in time_str and "PM" not in time_str:
      return "Invalid format: AM or PM missing"

  time_part, ampm = time_str.split()
  hour, minute = map(int, time_part.split(':'))

  if ampm == "PM" and hour != 12:
    hour += 12
  elif ampm == "AM" and hour == 12:
    hour = 0  # Midnight

  return "{:02d}:{:02d}".format(hour, minute)

if __name__ == "__main__":
  print(convert_time("07:15 PM"))
  print(convert_time("12:30 AM"))
  print(convert_time("11:59 AM"))