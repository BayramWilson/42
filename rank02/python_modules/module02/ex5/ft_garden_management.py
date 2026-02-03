from ex2.ft_custom_errors import (PlantError, WaterError)


class Gardenmanager:
    class Plant():
        def __init__(self,
                     name: str,
                     height: int,
                     age: int,
                     water_level: int,
                     sun_level: int,
                     health: str,
                     color: str
                     ):
            self.name = name
            self.height = height
            self.age = age
            self.water_level = water_level
            self.sun_level = sun_level
            self.health = health
            self.color = color

        @classmethod
        def create_plant(cls,
                         name: str,
                         heigth: int,
                         age: int,
                         water_level: int,
                         sun_level: int,
                         health: str,
                         color: str
                         ) -> "Gardenmanager.Plant":
            if (name == ""):
                raise PlantError("Plant name empty")
            if not (isinstance(name, str)):
                raise PlantError("Name is not a String")
            print(f"Added {name} successfully")
            return cls(name, heigth, age, water_level,
                       sun_level, health, color)

        @staticmethod
        def water_plant(plant: object) -> None:
            if (plant.water_level >= 2):
                raise WaterError("Water level too high")
            print(f"watering {plant.name}, actual water level:"
                  f"{plant.water_level}")
            plant.water_level += 1
            print(f"new water level: {plant.water_level}")

        @staticmethod
        def check_health(plant: object) -> None:
            if (plant.water_level < 2 or
                    plant.sun_level < 6):
                raise PlantError("Water level or sun level too low")
            print(f"{plant.name} is healthy (water: {plant.water_level}"
                  f" sun: {plant.sun_level})")


if __name__ == "__main__":
    plant_list = []
    plant = Gardenmanager.Plant
    print("Adding Plants to garden...")
    try:
        # could have done a try for each plant creation
        print("Plant Manager openend")
        tomato = plant.create_plant("Tomato",
                                    20,
                                    7,
                                    0,
                                    12,
                                    "healthy",
                                    "red")
        if (tomato):
            plant_list.append(tomato)
        t1 = plant.create_plant("weed",
                                20,
                                7,
                                0,
                                12,
                                "healthy",
                                "red")
        if (t1):
            plant_list.append(t1)

        lettuce = plant.create_plant("citrone",
                                     5,
                                     6,
                                     0,
                                     2,
                                     "healthy",
                                     "green")
        if (lettuce):
            plant_list.append(lettuce)
    except PlantError as e:
        print(e)
    finally:
        print("Garden Manager closed (cleanup)")

    try:
        print("\nwater manager opened")
        for plants in plant_list:
            plant.water_plant(plants)
            plant.water_plant(plants)
            # plant.water_plant(plants)
    except WaterError as e:
        print(e)
    finally:
        print("Water manager close (cleanup)")

    try:
        print("\ntomato watering started")
        plant.water_plant(tomato)
    except WaterError as e:
        print(e)
    finally:
        print(f"water level of {tomato.name}"
              f" {tomato.water_level}")
        print("Watering stopped (cleanup)")

    try:
        print("\nHealth manager opened")
        for plants in plant_list:
            plant.check_health(plants)
    except PlantError as e:
        print(e)
    finally:
        print("Health Manager close (cleanup)")

    print("\nSystem recovered and continuing!\n")
    print("Garden managenment system test complete.")
