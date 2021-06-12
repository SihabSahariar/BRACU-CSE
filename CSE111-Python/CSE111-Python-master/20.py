#Basic Math
import math
from math import *

'''
#Write a program to calculate factorial
#Manual System
n = int(input("Please Enter N To Calculate Factorial :"))
mul = 1
for i in range(1,n+1,1):
    mul = mul*i

print('Factorial of',n,'=',mul)

# Function System
function_factorial=factorial(n)
print('Factorial of',n,'=',function_factorial)

'''


#Write a program to check prime number
while True:
    n = int(input("Please Enter a number to check primality :"))
    result = True
    for i in range(2,int(sqrt(n))+1,1):
        if n%i == 0:
            result = False
            break

    if result and n>1:
        print(n,'is a Prime Number')
    else:
        print(n,'is not a Prime number')

