#Sum of n number

def formula(n): #Complexity : O(1)
    x=int(n)*(int(n)+1)/2
    return int(x)

def normal(n):  #Complexity : O(n)
    s = 0
    i = 1
    while i <= int(n):
        s+=i
        i+=1
    return s
if __name__ == '__main__':
    n = int(input())
    print("Formula = ",formula(n))
    print("Iterate = ",normal(n))
