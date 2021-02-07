import sys
import csv

if __name__ == "__main__":

  if len(sys.argv) is not 3:
    print("missing file")
    sys.exit(1)

  csv_database = sys.argv[1]
  csv_sequences = sys.argv[2]

  with open(csv_database, "r") as input_data, \
    open(csv_sequences, "r") as test_data:

    database = csv.DictReader(input_data)
    test = csv.reader(test_data)

    for rows in database:
      print(database[1])

    # for row in test:
    # test_dna = test


    # print(database[0][1:])
      # print(f"code{dna_code}")

  # for dna in database[0][1:]:
  #   if
