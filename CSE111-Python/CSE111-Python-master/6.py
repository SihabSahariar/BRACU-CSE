#AreaCalculator
import math
def Area_Triangle():
    b,h=input("Enter Base & Height: ").split()
    print("Area Of The Triangle: ",0.5*int(b)*int(h))

def Area_Rectangle():
    w,h=input("Enter Width & Height: ").split()
    print("Area Of The Rectangle: ",0.5*int(w)*int(h))

def Area_Trapezium():
    a,b,h=input("Enter length of a,b & height: ").split()
    print("Area Of The Trapezium: ",0.5*(int(a)+int(b))*int(h))

def Area_Circle():
    r = input("Enter radius: ")
    print("Area Of The Circle: ",math.pi*float(r)*float(r))

def Area_Ellipse():
    b,h=input("Enter a & b: ").split()
    print("Area Of The Ellipse: ",math.pi*int(b)*int(h))

def Area_Square():
    a=input("Enter Length of side: ")
    print("Area Of The Triangle: ",int(a)(int(a)))

def Area_Parallelogram():
    b,h=input("Enter Base & Vertical Height: ").split()
    print("Area Of The Triangle: ",int(b)*int(h))

def Area_Sector():
    r,a=input("Enter radius and angle in radians: ").split()
    print("Area Of The Triangle: ",0.5*int(r)*int(r)*int(a))

if __name__ == '__main__':

        print("Area Calculator")
        print("---------------")
        print("1.Triangle\n2.Rectangle\n3.Trapezium\n4.Circle\n5.Ellipse\n6.Square\n7.Parallelogram\n8.Sector\n0 to exit")
        print("Please Enter A Number To Calculate Area:")
        n = int(input())
        if n == 1:
            Area_Triangle()
        elif n == 2:
            Area_Rectangle()
        elif n == 3:
            Area_Trapezium()
        elif n == 4:
            Area_Circle()
        elif n == 5:
            Area_Ellipse()
        elif n == 6:
            Area_Square()
        elif n == 7:
            Area_Parallelogram()
        elif n == 8:
            Area_Sector()
        elif n == 0:exit
