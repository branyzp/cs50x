
import csv
import sys


def main():

    dbRows = []
    # TODO: Check for command-line usage
    # command line input required will be 1) CSV filename containing STR counts for list of individuals and 2) text filename containing DNA sequence to identify

    # check for command line correct number of arguments: 2 arguments
    if len(sys.argv) != 3:
        print("Usage: ./dna.py CSVFILE TEXTFILE")
    else:
        # TODO: Read database file into a variable
        with open(sys.argv[1]) as dbFile:
            reader = csv.DictReader(dbFile)

            for row in reader:
                dbRows.append(row)

        # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2]) as seqFile:
            readertxt = seqFile.read()

        # TODO: Find longest match of each STR in DNA sequence
        STR_dict = dict()
        compare = []

        # TODO: Check database for matching profiles

        for header in reader.fieldnames[1:]:
            STR_dict[header] = longest_match(readertxt, header)
            for row in dbRows:
                if int(row[header]) == STR_dict[header]:
                    compare.append(row["name"])
            # count how many times each person's name appears in compare list
            # if the same number of times the name appears in the compare list is equal to the amount of fieldnames, he is the guy
        for row in dbRows:
            if compare.count(row["name"]) == len(reader.fieldnames[1:]):
                print(row["name"])
                break
        else:
            print("No match")

            #         if int(row["AGATC"]) == STRcnt["AGATC"] and int(row["AATG"]) == STRcnt["AATG"] and int(row["TATC"]) == STRcnt["TATC"]:
            #             print(row["name"])
            #             break
            # else:
            #     print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
