#Guessing Game
import random

n = random.randint(0,100)
attempt = 0
while True:
    t = int(input("\nPlease Enter a Number :"))
    if t == n:
        if attempt == 0:
            print("You're the guessing boss!")
        else:
            print("Congratulations!\n"+"Succeed after :",attempt,"attempts")
        exit()
    elif t > n:
        print("Try Smaller\n")
    else:
        print("Try Bigger\n")
    attempt += 1
