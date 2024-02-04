text = input("What is the answer to the Great Question of Life, the Universe and Everything?: ").replace(" ","").lower()
if (text == '42' or text == 'forty-two' or text == 'fortytwo'):
    print("Yes")
else:
    print("No")

