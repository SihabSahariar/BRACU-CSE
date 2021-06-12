class Panda():
    def __init__ (self,name,gender,age):
        self.name=name
        self.gender=gender
        self.age=age



    def sleep(self, hour=None):

        self.hour = hour

        if hour >=3 and hour<=5:

            print(self.name," sleeps ",hour,"hours daily and should have Mixed Veggies")
        elif hour>=6 and hour<=8:

            print(self.name," sleeps ",hour,"hours daily and should have Eggplant & Tofu")
        elif hour>=9 and hour<=11:

            print(self.name," sleeps ",hour,"hours daily and should have Broccoli Chicken")

        elif hour==None :
            print(self.name, "'s duration is unknown thus should have only bamboo leaves")










panda1 = Panda("Kunfu","Male", 5)
panda2=Panda("Pan Pan","Female",3)
panda3=Panda("Ming Ming","Female",8)
print("{} is a {} Panda Bear who is {} years old".format(panda1.name,panda1.gender,panda1.age))
print("{} is a {} Panda Bear who is {} years old".format(panda2.name,panda2.gender,panda2.age))
print("{} is a {} Panda Bear who is {} years old".format(panda3.name,panda3.gender,panda3.age))
print(panda2.sleep(10))
print(panda1.sleep(4))
print(panda3.sleep())