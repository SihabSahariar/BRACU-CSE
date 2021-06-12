#Sets
#Unordered collection of items - set


num1 = {1,2,3,4,5,6}
num2 = set([17,5,6]) #Converting list to a set
print(num1 | num2) #Union
print(num1 & num2) #intersection
print(num1 - num2) #Difference


num2.add(40)
num2.add(50)
print(num2)

num2.remove(5)
print(num2)

num2.pop()
print(num2)

num2.pop()
print(num2)

print(50 in num2)


print(0 in num2)
print(len(num2))

num2.clear()
print(num2)



