#Condition
def elseif():
    marks = int(input("Please Enter Gained Marks : "))
    pass_marks = 33
    if marks >= pass_marks:
        print("You've passed")
    else:
        print("Sorry.You've Failed!")

def elseifelse():
    marks = int(input("Please Enter Gained Marks : "))
    pass_marks = 33
    if marks >= pass_marks:
        if marks == pass_marks:
            print("Passed but was too risky!")
        else:
            print("Passed Without Tension!")
    elif marks<pass_marks and marks<10:
        print("Sorry.You're a dumb!")
    else:
        print("Failed madafaka! Congrats!")

if __name__ == '__main__':
    elseif()
    print("------------------")
    elseifelse()