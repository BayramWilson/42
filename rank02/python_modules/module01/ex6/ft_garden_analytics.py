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
                     regular: int,
                     flowering: int,
                     prize_flowers: int
                     ) -> None:
            self.score = score
            self.plant = plant
            self.amount_plants = amount_plants
            self.growth_plants = growth_plants
            self.gardens_managed = gardens_managed
            self.regular = regular
            self.flowering = flowering
            self.prize_flowers = prize_flowers

        @staticmethod
        def owner_report(owner: str, plant: object, first_call: bool) -> list:
            regular = 0
            flowering = 0
            prize_flowers = 0
            if first_call:
                print(f"\n=== {owner}'s Garden Report\n")
                print("Plants in garden:")

            # color, prize flower, blooming
            if (plant.color != ""
                and isinstance(plant, PrizeFlower)
                    and plant.blooming):
                flowering += 1
                prize_flowers += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color} (blooming), "
                      f"Prize points: {plant.prize_points}")

            # no color, prize flower, blooming
            elif (plant.color == ""
                    and isinstance(plant, PrizeFlower)
                    and plant.blooming):
                flowering += 1
                prize_flowers += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm (blooming), "
                      f"Prize points: {plant.prize_points}")

            # color, NOT prize flower, blooming
            elif (plant.color != ""
                    and not isinstance(plant, PrizeFlower)
                    and plant.blooming):
                flowering += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color} (blooming)")

            # no color, NOT prize flower, blooming
            elif (plant.color == ""
                    and not isinstance(plant, PrizeFlower)
                    and plant.blooming):
                flowering += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm (blooming)")

            # color, prize flower, NOT blooming
            elif (plant.color != ""
                    and isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                prize_flowers += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color}, "
                      f"Prize points: {plant.prize_points}")

            # no color, prize flower, NOT blooming
            elif (plant.color == ""
                    and isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                prize_flowers += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm, "
                      f"Prize points: {plant.prize_points}")

            # color, NOT prize flower, NOT blooming
            elif (plant.color != ""
                    and not isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                regular += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm, {plant.color}")

            # no color, NOT prize flower, NOT blooming
            elif (plant.color == ""
                    and not isinstance(plant, PrizeFlower)
                    and not plant.blooming):
                regular += 1
                print(f"- {plant.name}: "
                      f"{plant.height}cm")
            return [regular, flowering, prize_flowers]
            
        @staticmethod
        def print_owner_report(list_of_plants: list,
                               owner: str,
                               total_growth: int
                               ) -> None:
            first_call = True
            regular_sum = 0
            flowering_sum = 0
            prize_flower_sum = 0
            plants_added = 0
            fn = GardenManager.GardenStats
            for plant in list_of_plants:
                r, f, p = fn.owner_report(owner, plant, first_call)
                regular_sum += r
                flowering_sum += f
                prize_flower_sum += p
                first_call = False
                plants_added += 1
            print(f"\nPlants added: {plants_added}, "
                  f"Total growth: {total_growth}")
            print(f"Plant types: {regular_sum} regular, "
                  f"{flowering_sum} flowering, "
                  f"{prize_flower_sum} prize flowers")
            if (GardenManager.GardenStats.height_validation(list_of_plants)):
                print("Height validaton test: True")
            else:
                print("Height validaton test: False")

        def height_validation(list_of_plants: list) -> bool:
            false_counter = 0
            for plant in list_of_plants:
                if (plant.height < 0):
                    false_counter += 1
            if false_counter > 0:
                return False
            else:
                return True


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
    def print_flowering(list_of_plants: list, total_growth) -> int:
        first_call = True
        for plant in list_of_plants:
            FloweringPlant.flowering(plant, first_call)
            first_call = False
            total_growth += 1
        return total_growth

    @staticmethod
    def flowering(plant: object, first_call: bool) -> None:
        garden_name = plant.garden.garden_name
        if first_call:
            print(f"\n{garden_name} is helping all Plants grow...")
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
    print("=== Garden Management System Demo ===\n")
    # first_call = True
    g0 = GardenManager("Alice")
    p0 = FloweringPlant(name="Rose",
                        height=22,
                        age=13,
                        color="red flowers",
                        blooming=True,
                        garden=g0)
    p1 = FloweringPlant(name="Oak Tree",
                        height=-187,
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
    total_growth = 0
    total_growth = FloweringPlant.print_flowering(list_of_plants, total_growth)
    total_growth = FloweringPlant.print_flowering(list_of_plants, total_growth)
    GardenManager.GardenStats.print_owner_report(list_of_plants,
                                                 g0.garden_name, total_growth)
    # g1 = GardenManager("Alice")
    # g1_stats = g1.GardenStats(22)
    # p1 = GardenManager.FloweringPlant("Rose", 30, 12)
    # print(p1.height)
    # print(g1.name)
    # print(g1_stats.score)
