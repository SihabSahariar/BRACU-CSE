#Dictionary || Map

"""
KEY : VALUE
Name : 'Sizan'
Email: 'sihabsahariarcse@gmail.com'
Age: 21
1 : 10
"""

studentID = {

     '1' : 'A',
     '2' : 'B',
     '3' : 'C',
}

print(studentID['2'])
print(studentID.get('2'))
print(studentID.get('6','Not a valid key'))

print('')
for i in studentID:
    print(i,studentID[i])