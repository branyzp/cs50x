height = -1

# get user input
while True:
    try:
        height = int(input("Height: "))
        if (height > 0 and height < 9):
            break
    except ValueError:
        print("Not an integer")


# build the mario stairs
rows = height
space = height-1
hash = 1

for i in range(height):
    for k in range(space):
        print(" ", end="")
    for l in range(hash):
        print("#", end="")

    space -= 1
    hash += 1
    print()
