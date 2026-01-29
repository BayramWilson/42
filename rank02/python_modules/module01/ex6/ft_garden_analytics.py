from ex1.ft_garden_data import Plant


class GardenManager():
    def __init__(self: "GardenManager", 
                 name: str,
                 ) -> None:
        self.name = name

        def create_garden_network():
            pass

    class GardenStats:
        def __init__(self, score):
            self.score = score

    class FloweringPlant(Plant):
        def __init__(self, name, height, age):
            super().__init__(name, height, age)

    class PrizeFlower(FloweringPlant):
        def __init__(self, name, height, age):
            super().__init__(name, height, age)


g1 = GardenManager("Alice")
g1_stats = g1.GardenStats(22)
print(g1.name)
print(g1_stats)