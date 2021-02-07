from cs50 import get_int

while True:
  height = get_int("Height:")

  if height > 0 and height < 9:
    break

for i in range(height):
  spaceNumber = height - i - 1
  hashNumber = i + 1

  print(" " * spaceNumber, end="")
  print("#" * hashNumber, end= "")

  print("  ", end="")

  print("#" * hashNumber)


