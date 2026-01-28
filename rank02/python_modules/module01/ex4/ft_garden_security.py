from ex1.ft_garden_data import Plant


class SuperPlant(Plant):
    def __init__(self: "SuperPlant", name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age
        print("=== Garden Security System ===")
        print(f"Plant created: {name}")
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm"
                  " [REJECTED]")
            return None
        self._height = height
        if age < 0:
            print(f"Invalid operation attempted: height {age} days"
                  " [REJECTED]")
            return None
        self._age = age
        print(f"Current plant: {name} ({height}cm, {age} days)")

    # @height.setter
    def set_height(self: "SuperPlant", newHeight: int) -> None:
        if newHeight < 0:
            # raise ValueError("Height can not be negative")
            print(f"Invalid operation attempted: height {newHeight}cm"
                  " [REJECTED]")
            print("Security: Negative height rejected")
            return None
        self.height = newHeight
        print(f"Height updated: {newHeight}cm [OK]")

    # @height.getter
    def get_height(self: "SuperPlant") -> int:
        return self.height

    # @age.setter
    def set_age(self: "SuperPlant", newAge: int) -> None:
        if newAge < 0:
            # raise ValueError("Age can not be negative.")
            print(f"Invalid operation attempted: height {newAge} days"
                  " [REJECTED]")
            print("Security: Negative height rejected")
            return None
        print(f"Age updated: {newAge} days [OK]")
        self.age = newAge

    # @age.getter
    def get_age(self: "SuperPlant") -> int:
        return self.age


if __name__ == "__main__":
    p0 = SuperPlant("heilungspflanze", -3, -13)
    print(p0.height)
    print(p0.age)
    p0.set_height(-42)
    p0.set_age(-42)
    height_of_plant: int = p0.get_height()
    age_of_plant: int = p0.get_age()
    print(height_of_plant)
    print(age_of_plant)
    # print(p0)
