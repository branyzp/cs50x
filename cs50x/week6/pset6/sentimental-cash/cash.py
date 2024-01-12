from math import floor


def main():

    # define cents
    cents = -1
    # ask how many cents customer is owed
    while True:
        try:
            cents = float(input("How many dollars?: "))*100
            if (cents > 0):
                break
        except ValueError:
            pass

    # calculate number of quarters to give customer
    quarters = calculate_quarters(cents)
    cents = cents - quarters*25

    # calculate number of dimes to give customer
    dimes = calculate_dimes(cents)
    cents = cents - dimes*10

    # calculate number of nickels to give customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels*5

    # calculate number of pennies to give customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies*1

    # sum coins
    coins = quarters + dimes + nickels + pennies

    print(coins)


def calculate_quarters(cents):
    return floor(cents / 25)


def calculate_dimes(cents):
    return floor(cents / 10)


def calculate_nickels(cents):
    return floor(cents / 5)


def calculate_pennies(cents):
    return floor(cents)


main()
