class Customer():
    def __init__ (self, name):
        self.name=name

    def greet(self, *info):
        if len(info)==0:
            print("Hello!")
        elif len(info)==1:
            self.name1=info[0]
            print("Hello ",info[0],"!")


    def purchase(self, *n):
        self.n=n
        print(self.name,",you purchased",len(n),"item(s)")
        for x in range (len(n)):
            print(n[x])


customer_1 = Customer("Sam")
customer_1.greet()
customer_1.purchase("chips", "chocolate", "orange juice")
print("-----------------------------")
customer_2 = Customer("David")
customer_2.greet("David")
customer_2.purchase("orange juice")






