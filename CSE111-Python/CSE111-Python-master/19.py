#Series

#Series 1 : 1+2+3+...+n =?
#Series 2 : 1+3+5+...+n =?
#Series 3 : 2+4+6+...+n =?
#Series 4 : 4+8+12+...+n =?
#Series 5 : 1^2 + 2^2 + 3^2 +...+n =?
#Series 6 : 2^2 + 4^2 + 6^2 +...+n =?
#Series 5 : 1 + 1/2 + 1/3 + 1/4 +...+1/n =?

'''
def sum1():
    n = 10
    print('Normal sum =',n*(n+1)/2)

def sum2():
    n = 10
    print('ODD SUM = ',n*n)

def sum3():
    n = 10
    print('Even Sum = ',n*(n+1))


if __name__ == '__main__':
    sum1()
    sum2()
    sum3()

'''

#1+2+3+4+...+n
n = int(input('Please Enter N = '))
s = 0
           #start end diff
for x in range(1, n+1, 1):
    s = s+x

print(s)

#1+3+5+7+...+n
n = int(input('Please Enter N = '))
s = 0
           #start end diff
for x in range(1, n+1, 2):
    s = s+x

print(s)


#4+8+12+16+...+n
n = int(input('Please Enter N = '))
s = 0
           #start end diff
for x in range(4, n+1, 4):
    s = s+x

print(s)



#1^2 + 2^2 + 3^2 +4^2+...+n
# 1+4+9+16
n = int(input('Please Enter N = '))
s = 0
           #start end diff
for x in range(1, n+1, 1):
    s = s+(x**2)

print(s)



#2^2 + 4^2 + 6^2 +8^2+...+n
# 4+16+36+64
n = int(input('Please Enter N = '))
s = 0
           #start end diff
for x in range(2, n+1, 2):
    s = s+(x**2)

print(s)




#1 + 1/2 + 1/3 + 1/4 +...+1/n =?
n = int(input('Please Enter N = '))
s = 0
           #start end diff
for x in range(1, n+1, 1):
    s = s+(1/x)

print(s)


