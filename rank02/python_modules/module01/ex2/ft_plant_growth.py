from ex1.ft_garden_data import Plant


class NewPlant(Plant):
    def __init__(self: "NewPlant",
                 name: str,
                 height: int,
                 age: int,
                 growing: int,
                 aging: int) -> None:
        self.name = name
        self.height = height
        self.age = age
        self.growing = growing
        self.aging = aging


p0 = NewPlant("Rose", 30, 7, 5, 7)
p1 = NewPlant("Kaktus", 10, 7, 1, 7)
p2 = NewPlant("Weed", 45, 7, 20, 7)


def grow(plant: object) -> None:
    plant.height += plant.growing


def age(plant: object) -> None:
    plant.age += plant.aging


def print_info(plant: object) -> None:
    print(f"{plant.name}: {plant.height}cm, {plant.age} days old")


def get_info(plant: object) -> None:
    print("=== Day 1 ===")
    print_info(plant)
    grow(plant)
    age(plant)
    print("=== Day 7 ===")
    print_info(plant)
    print(f"Growth this week: +{plant.growing}cm")


if __name__ == "__main__":
    get_info(p2)
