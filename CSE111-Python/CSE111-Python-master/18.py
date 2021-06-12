#ForLoop

num = [10,20,30,40,50,60]
print(num)

'''
for x in range(start,end,difference):  ; here start is included but end in excluded
    //code


'''

def loop1():
    i=0
    while i<len(num):
        print(num[i])
        i += 1

def loop2():
    for i in range(len(num)):
        print(num[i])

def loop3():
    sum = 0
    for i in num:
        print(i)
        sum += i
    print('Sum = ',sum)


if __name__ == '__main__':
    loop3()