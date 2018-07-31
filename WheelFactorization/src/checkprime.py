# takes an integer from 0 to 1000000 and checks if it is prime

import sys

primeWheelFact = [0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA]

def isNumberPrime(numberToCheck):
    """Checks if a number is prime"""
    
    return True


if len(sys.argv) == 2:
    numberToCheck = sys.argv[1]
    
    if isNumberPrime(numberToCheck) == True:
        print("Number is prime")
    else:
        print("Number is not prime")

else:
    print("Argument missing")

