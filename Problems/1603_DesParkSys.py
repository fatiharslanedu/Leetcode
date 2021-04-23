
# todo: 1603. Design Parking System
# ? Easy
class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.big = big
        self.medium = medium
        self.small = small

    def addCar(self, carType: int) -> bool:

        if carType == 1 and self.big > 0:
            self.big -= 1
            return True
        elif carType == 2 and self.medium > 0:
            self.medium -= 1
            return True
        elif carType == 3 and self.small > 0:
            self.small -= 1
            return True
        else:
            return False

        # Your ParkingSystem object will be instantiated and called as such:
        # obj = ParkingSystem(big, medium, small)
        # param_1 = obj.addCar(carType)


obj = ParkingSystem(1, 1, 0)
# print(obj.addCar(1))
# print(obj.addCar(2))
# print(obj.addCar(3))
# print(obj.addCar(1))

#todo : Better Solution
class ParkingSystem1:

    def __init__(self, big: int, medium: int, small: int):
        self.dic = {1: big, 2: medium, 3: small}

    def addCar(self, carType: int) -> bool:
        if self.dic[carType] > 0:
            self.dic[carType] -= 1
            return True
        else:
            return False
