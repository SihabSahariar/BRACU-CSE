class Calculator():
    def __init__(self, a, b):
         self.a=a
         self.b=b
    def add(self):
          return self.a+self.b
    def substract(self):
          return (self.a - self.b)
    def multiply(self):
          return self.a*self.b
    def divide(self):
          return self.a/self.b
print("Let's calculate.")
a=int(input("Value 1:"))
c=(input("Operator:"))
b=int(input("Value 2:"))
obj=Calculator(a,b)
if c=="+":
    print("Result: ",obj.add())
elif c=="-":
    print("Result: ",obj.substract())
elif c=="*":
    print("Result: ",obj.multiply())
elif c=="/":
    print("Result: ",obj.divide())