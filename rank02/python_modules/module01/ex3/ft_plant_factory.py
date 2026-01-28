from ex1.ft_garden_data import Plant

p0 = Plant("Roses", 25, 30)
p1 = Plant("Oak", 200, 365)
p2 = Plant("Cactus", 5, 90)
p3 = Plant("Sunflower", 80, 45)
p4 = Plant("Fern", 15, 120)
i = 0
plants = [p0,p1,p2,p3,p4]
if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    for plant in plants:
        i = i + 1
        print(f"Created: {plant.name} ({plant.height}cm, {plant.age} days)")
    print(f"Total plants created: {i}")
