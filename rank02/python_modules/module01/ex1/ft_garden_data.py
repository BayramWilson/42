class Plant:
    def __init__(self: "Plant", name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age


p0 = Plant("Kaktus", 10, 360)
p1 = Plant("Palme", 187, 420)
p2 = Plant("Orchideé", 42, 36)
plants = [p0, p1, p2]

if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    for plant in plants:
        print(f"{plant.name}: {plant.height}cm, {plant.age} days old")
