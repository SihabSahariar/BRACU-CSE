def gpa():
    marks = int(input("Please Enter Your Marks: "))
    if marks >= 0 & marks < 33:
        print("Failed!")
    elif marks<60:
        print("D")
    elif marks < 65:
        print("C")
    elif marks < 70:
        print("A-")
    elif marks < 80:
        print("A")
    elif marks <= 100:
        print("A-")
    else:
        print("Invalid Marks")

if __name__ == '__main__':
    gpa()