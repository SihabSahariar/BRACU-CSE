#Stack & Queue
from collections import *


                            #STACK : boi er upor boi rakha
                #LIFO - Last in first out, zeta sobar seshe dhuke seta sobar age baray

books = []
books.append('10')
books.append('20')
books.append('30')
print(books)
books.pop()
print(books)
print('\n\n\n\n\n')

                                    # Queue : polpapan line kore daray ache
                    # FIFO - First in first out, zeta sobar agee dhuke seta sobar age baray

l = deque(['Sihab','Oyshori','Sahariar'])
print(l)
l.append('Hasan')
print(l)
l.pop()
print(l)
l.popleft()
print(l)

if l:
    print("Not Empty!")
else:
    print('Empty')

l.clear()

if l:
    print("Not Empty!")
else:
    print('Empty')