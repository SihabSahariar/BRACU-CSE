#Taking list as input

'''
s = input("Please Enter a string: ")
lst = list(s)
print(lst,end='\n\n')


s = input("Please Enter a string: ")
lst1 = s.split(',')
print(lst1)


a = list(map(int,input("\nEnter some numbers : ").strip().split()))  #[:n]
print(sum(a))
'''


n = input()
count_cap = 0
count_smal = 0
count_dig = 0
for i in n:
    if i.isupper():
        count_cap += 1
    elif i.islower():
        count_smal += 1
    elif i.isdigit():
        count_dig += 1

print(count_cap,count_smal,count_dig)
