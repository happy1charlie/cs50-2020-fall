from cs50 import get_string

article = []
article = get_string("test article:")

exclamation = 0
dot = 0
space = 0
questionmark = 0
letter = 0
i = 0

for i in range (len(article)):
  if article[i] == " ":
    space += 1
  elif article[i] == "!":
    exclamation += 1
  elif article[i] == ".":
    dot += 1
  elif article[i] == "?":
    questionmark += 1
  elif (article[i] >= 'A' and article[i] <= 'Z') or (article[i] >= 'a' and article[i] <= 'z'):
    letter += 1
  i += 1

sentence = exclamation + dot + questionmark
word = space + 1

L = letter / word * 100
S = sentence / word * 100

#print(f"word:{word} sentence{sentence} letter{letter} ")

answer = round((0.0588 * L) - (0.296 * S) - 15.8)

#print(f"answer{answer}")

if answer > 16:
  print("Grade 16+")
elif answer < 1:
  print("Before Grade 1")
else:
  print(f"Grade {answer}")
