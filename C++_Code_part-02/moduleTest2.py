def calculateTotal(exp):
    total=0
    for item in exp:
        total=total+item
    return total

tomExpense = [100,200,300,400]
joeExpense=[200,300,400,700]

tomTotal=calculateTotal(tomExpense)
joeTotal=calculateTotal(joeExpense)

print("Tom's total expense ",tomTotal)
print("joe's total expense ",joeTotal)


# Another function
total=10 #Global variable
def sum(a,b=0): #b=0 is a default argument . if we don't pass any argument that it use
    total=a+b #local variable
    return total

n=sum(4,5)
print(n)
print("Global variable : ",total)

# Documentation string

def sub(a,b):
    '''
    This is a function that suntract two integer
    and return the value.

    :param a: 10
    :param b:2
    :return: 8
    '''
    n = a-b
    return n

# name argument.it does not follow order
n=sub(b=10,a=20)
print(n)
