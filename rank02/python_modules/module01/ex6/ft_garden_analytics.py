from ex1.ft_garden_data import Plant


class GardenManager:
    def __init__(self: "GardenManager",
                 garden_name: str,
                 ) -> None:
        self.garden_name = garden_name
        # print(f"Added {name} to {garden_name}'s garden")

        @classmethod
        def create_garden_network(cls):
            print()
            pass

    class GardenStats:
        def __init__(self: "GardenManager",
                     score: int,
                     plant: object,
                     amount_plants: int,
                     growth_plants: int,
                     gardens_managed: int,
                     ) -> None:
            self.score = score
            self.plant = plant
            self.amount_plants = amount_plants
            self.growth_plants = growth_plants
            self.gardens_managed = gardens_managed

        @staticmethod
        def owner_report(owner: str, plant: object, first_call: bool) -> None:
            if first_call:
                print(f"=== {owner}'s Garden Report")
                print("Plants in garden:")

            # color, prize flower, blooming
            if (plant.color != ""
                and isinstance(plant, PrizeFlower)
                    and plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color} (blooming), "
                      f"Prize points: {plant.prize_points}")

            # no color, prize flower, blooming
            elif (plant.color == ""
                    and isinstance(plant, PrizeFlower)
                    and plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm (blooming), "
                      f"Prize points: {plant.prize_points}")

            # color, NOT prize flower, blooming
            elif (plant.color != ""
                    and not isinstance(plant, PrizeFlower)
                    and plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color} (blooming)")

            # no color, NOT prize flower, blooming
            elif (plant.color == ""
                    and not isinstance(plant, PrizeFlower)
                    and plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm (blooming)")

            # color, prize flower, NOT blooming
            elif (plant.color != ""
                    and isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color}, "
                      f"Prize points: {plant.prize_points}")

            # no color, prize flower, NOT blooming
            elif (plant.color == ""
                    and isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm, "
                      f"Prize points: {plant.prize_points}")

            # color, NOT prize flower, NOT blooming
            elif (plant.color != ""
                    and not isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color}")

            # no color, NOT prize flower, NOT blooming
            elif (plant.color == ""
                    and not isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                print(f"- {plant.name}: "
                      f"{plant.height}cm")

        @staticmethod
        def print_owner_report(list_of_plants: list, owner: str) -> None:
            first_call = True
            fn = GardenManager.GardenStats
            for plant in list_of_plants:
                fn.owner_report(owner, plant, first_call)
                first_call = False


class FloweringPlant(Plant):
    def __init__(self: "Plant",
                 name: str,
                 height: int,
                 age: int,
                 color: str,
                 blooming: bool,
                 garden: GardenManager
                 ) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.blooming = blooming
        self.garden = garden
        print(f"Added {name} to {garden.garden_name}'s garden")

    @staticmethod
    def print_flowering(list_of_plants: list) -> None:
        first_call = True
        for plant in list_of_plants:
            FloweringPlant.flowering(plant, first_call)
            first_call = False

    @staticmethod
    def flowering(plant: object, first_call: bool) -> None:
        garden_name = plant.garden.garden_name
        if first_call:
            print(f"{garden_name} is helping all Plants grow...")
        print(f"- {plant.name} grew 1cm")
        plant.height += 1


class PrizeFlower(FloweringPlant):
    def __init__(self: "FloweringPlant",
                 name: str,
                 height: int,
                 age: int,
                 color: str,
                 blooming: bool,
                 garden: GardenManager,
                 prize_points: int) -> None:
        super().__init__(name, height, age, color, blooming, garden)
        self.prize_points = prize_points


if __name__ == "__main__":
    print("=== Garden Management System Demo ===")
    # first_call = True
    g0 = GardenManager("Alice")
    p0 = FloweringPlant(name="Rose",
                        height=22,
                        age=13,
                        color="red flowers",
                        blooming=True,
                        garden=g0)
    p1 = FloweringPlant(name="Oak Tree",
                        height=187,
                        age=1337,
                        color="",
                        blooming=False,
                        garden=g0)
    p2 = PrizeFlower(name="Sunflower",
                     height=90,
                     age=33,
                     color="yellow flowers",
                     blooming=True,
                     garden=g0,
                     prize_points=10)
    list_of_plants = [p0, p1, p2]
    FloweringPlant.print_flowering(list_of_plants)

    GardenManager.GardenStats.print_owner_report(list_of_plants,
                                                 g0.garden_name)
    # g1 = GardenManager("Alice")
    # g1_stats = g1.GardenStats(22)
    # p1 = GardenManager.FloweringPlant("Rose", 30, 12)
    # print(p1.height)
    # print(g1.name)
    # print(g1_stats.score)
