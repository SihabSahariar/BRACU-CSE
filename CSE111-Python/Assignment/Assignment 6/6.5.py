class Vehicle():
    def __init__ (self, x=0, y=0):
        self.x=x
        self.y=y

    def moveUp(self,):
         self.y=self.y+1
    def moveLeft(self):
        self.x = self.x - 1
    def moveDown(self):
        self.y = self.y - 1
    def moveRight(self):
        self.x = self.x + 1
    def print_position(self):
        print(self.x,self.y)


car = Vehicle()
car.print_position()
car.moveUp()
car.print_position()
car.moveLeft()
car.print_position()
car.moveDown()
car.print_position()
car.moveRight()


