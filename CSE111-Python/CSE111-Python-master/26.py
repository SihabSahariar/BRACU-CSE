#Tuples
#Immutable


std = (

      'Sihab Sahariar' ,
      'Sarkar Sizan',
      'Ahsan Rakib',

)

print(std)
print(std[0])

print('\n')


std = (

    ('Sihab ' ,
      'Sizan',
      'Rakib',),
    ('Oyshori',
     'Sadia',
     'tumi',)

)

print(std)
print(std[0][1])

for row in std:
    for col in row:
        print(col,end=" ")
    print("")

print('\n')



res = (('Sihab',21,4.00),('Oyshori',19,4.00))
print(res[0:])

