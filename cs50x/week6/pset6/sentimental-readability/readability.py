def main():

    # get input from user
    text = input("Text: ")
    count_letters(text)


def count_letters(text):

    letters = 0
    words = 1
    sentences = 0

    for i in range(len(text)):
        if (text[i].isalpha()):
            letters += 1
        elif (text[i] == ' '):
            words += 1
        elif (text[i] == '.' or text[i] == '!' or text[i] == '?'):
            sentences += 1
    L = (letters * 100) / float(words)
    S = (sentences * 100) / float(words)
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if (index < 1):
        print("Before Grade 1")
    elif (index > 16):
        print("Grade 16+")
    else:
        print("Grade " + str(index))


main()
 