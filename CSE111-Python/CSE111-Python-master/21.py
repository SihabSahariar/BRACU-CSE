#Pattern

'''
*             *
**            ***
***           *****
****          *******
'''


n = int(input("Please Enter N: "))
for i in range(n+1):
    for j in range(i+1):
        print('*',end='')
    print('')

print('')


n = int(input("Please Enter N: "))
for i in range(1,n+1):
    for j in range(1,2*i):
        print('*',end='')
    print('')



n = int(input("Please Enter N: "))
for i in range(1,n+1):

    for x in range(1,n-i+1):
        print(' ',end="")

    for j in range(1,i+1):
        print('*',end='')
    print('')