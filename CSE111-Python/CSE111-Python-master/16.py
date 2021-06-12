#List
#LIST is an object

subjects = ['CSE111','CSE110','CSE220','CSE221','Sihab','Sihab']
print(subjects,"  Length: ",len(subjects))

print(subjects[0],subjects[-1])

subjects.append('MAT120')
print(subjects)
subjects.pop()
subjects.sort()
print(subjects)

subjects.reverse()
print(subjects)

print(subjects.count('Sihab'))

subjects.insert(2,'ENG111')
print(subjects)
print('\n\n\n')


#      0        1      2       3      4
lst=['rakib','hasan','sizan','mahi','test']
print(lst[2:]) # 2 number index theke bakigula print hbe
print('\n')


#checking an element exists in a list or not
lst=['rakib','hasan','sizan','mahi','sihab']
if 'sihab' in lst:
    x=lst.index('sihab') #Find index of element 'sihab' in the list
    print('Found :',lst[x])
else:
    print('Not Found')

print('nai' not in lst)

print('\n')
#Adding two list
lst1 = ['sihab','sahariar']
lst2 = ['sarkar','sizan']
l = lst1 + lst2
print(l)
print(l*3) # l list print 3 times together

for i in range(len(l)-1):
    if l[i]=='sihab':
        l.remove(l[i])

print(l)