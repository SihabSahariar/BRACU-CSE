#logical operator

def max():
    num1 = 10
    num2 = 20
    num3 = 30
    if num1>num2 and num1>num3:
        mx = num1
    elif num2> num1 and num2>num3:
        mx = num2
    elif num3> num1 and num3>num2:
        mx = num3

    print("Maximum =",mx,end="\n")


def vowel():
    char = input("Please Enter a Alphabet = ")
    if char == 'a' or char == 'e' or char == 'i' or char == 'o' or char == 'u':
        print("Vowel")
    else:
        print("Consonant")



if __name__ == '__main__':
    max()
    vowel()