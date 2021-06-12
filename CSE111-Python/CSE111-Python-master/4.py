while True:
    check = input("Press 1 to enter and 0 to exit: ")
    if check== "0":break
    else:
        name,year,gpa = input("Nick Name, Year, GPA: ").split()

        print("Student Information")
        print("-------------------")
        print(f"Name: {name}")
        print(f"Class: {year}")
        print(f"CGPA : {gpa}")
        print("-------------------")



