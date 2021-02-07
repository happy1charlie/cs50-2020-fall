from cs50 import get_int

while True:
  cardNumber = get_int("Enter Card Number:")

  if cardNumber > 0:
    break

card = cardNumber
count = 0
oddSum = 0
evenSum = 0
total = 0

while card > 0.9:
  check = card % 10
  card //= 10
  count += 1

  if count % 2 == 0:
    if (check * 2) >= 10:
      evenSum = evenSum + (check * 2 // 10) + (check * 2 % 10)
    else:
      evenSum = evenSum + (check * 2)
  else:
    oddSum = oddSum + check

  total = oddSum + evenSum
  final = total % 10

  #print(f"oddsum:{oddSum} evensum{evenSum} count:{count} check{check} card:{card}")

if final == 0:
  if cardNumber >= 340000000000000 and cardNumber < 350000000000000:
    print("AMEX")

  elif cardNumber >= 370000000000000 and cardNumber < 380000000000000:
    print("AMEX")

  elif cardNumber >= 5100000000000000 and cardNumber < 5600000000000000:
    print("MASTERCARD")

  elif cardNumber >= 4000000000000 and cardNumber < 5000000000000:
    print("VISA")

  elif cardNumber >= 4000000000000000 and cardNumber < 5000000000000000:
    print("VISA")

  else:
    print("INVALID")

else:
  print("INVALID")
