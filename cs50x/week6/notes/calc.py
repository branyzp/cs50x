
x = int(input("Input the first number: "))
operation = input("What is the operation? (add, subtract, multiply, divide): ")
y = int(input("Input the second number: "))


def calculate(num1,num2,operation):
    if (operation == 'add'):
        print(x + y)
    elif (operation == 'subtract'):
        print(x - y)
    elif (operation == 'multiply'):
        print(x * y)
    elif (operation == 'divide'):
        print(x / y)
    else:
        print("You must use a valid operation (add, subtract, multiply, divide).")

calculate(x,y,operation)
