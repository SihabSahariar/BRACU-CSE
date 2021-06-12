#Basic Numerical Operations
#
# +
# -
# *
# /
# %
# // (Floor)
# ** (Exponentiation)

def arithmatic():
    age1 = 9
    age2 = 8
    age3 = 6
    sum_age = age1+age2+age3
    print(f"Sum of Age: {sum_age}")
    avarage_age_floor = sum_age//3
    avarage_age_frac = sum_age/3
    print(f"Average Age(int): {avarage_age_floor}\nAverage Age(fraction): {avarage_age_frac}")


def modular():
    x = 899
    y = 5
    z = (x%y)%y
    zz = x%y
    print(z,zz)

def expon():
    a,b =input().split()
    print(int(a)**int(b)) #pow(a,b)


if __name__ == '__main__':
    arithmatic()
    modular()
    expon()
