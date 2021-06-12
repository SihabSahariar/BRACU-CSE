#Matrix

matrix = [[1,2,3],[4,5,6]]
print(matrix)
print(matrix[0][1])

print("------------")

for row in matrix:
    for col in row:
        print(col,end=" ")
    print("")