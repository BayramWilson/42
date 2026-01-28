from ex1.ft_garden_data import Plant


class Flower(Plant):
    def __init__(self: "Flower",
                 name: str,
                 height: int,
                 age: int,
                 color: str,
                 ) -> None:
        super().__init__(name, height, age)
        self.color = color

    def bloom(name: str) -> None:
        print(f"{name} is blooming beautifully!")
        return None


class Tree(Plant):
    def __init__(self: "Tree",
                 name: str,
                 height: int,
                 age: int,
                 trunk_diameter: int,
                 ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(name: str, value: int) -> None:
        print(f"{name} provides {value} square meters of shade")
        return None


class Vegetable(Plant):
    def __init__(self: "Vegetable",
                 name: str,
                 height: int,
                 age: int,
                 harvest_season: str,
                 nutritional_value: str
                 ) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("\n")
    f0 = Flower("Rose", 10, 12, "Red")
    f1 = Flower("Tulip", 8, 5, "Yellow")
    f2 = Flower("Lily", 15, 20, "White")

    t0 = Tree("Oak", 866, 1927, 97)
    t1 = Tree("Pine", 420, 850, 60)
    t2 = Tree("Birch", 300, 120, 40)

    v0 = Vegetable("Tomato", 30, 32, "Summer", "rich in Vitamin C")
    v1 = Vegetable("Carrot", 25, 60, "Autumn", "rich in Vitamin A")
    v2 = Vegetable("Spinach", 20, 40, "Spring", "high in Iron")

    def print_flower(name: str, height: int, age: int, color: str) -> None:
        print(f"{name} (Flower): {height}cm, "
              f"{age} days, {color} color")

    def print_tree(name: str, height: int, age: int, diameter: int) -> None:
        print(f"{name} (Tree): {height}cm, "
              f"{age} days, {diameter}cm diameter")
        
    def print_veg(name: str, height: int, age: int, season: str,
                  prov: str) -> None:
        print(f"{name} (Vegetable): {height}cm, "
              f"{age} days, {season} harvest")
        print(f"{name} is {prov}")

    print_flower(f0.name, f0.height, f0.age, f0.color)
    Flower.bloom(f0.name)
    print("\n")
    print_tree(t0.name, t0.height, t0.age, t0.trunk_diameter)
    Tree.produce_shade(t0.name, 128)
    print("\n")
    print_veg(v0.name, v0.height, v0.age, v0.harvest_season,
              v0.nutritional_value)