class GardenError(Exception):
    """
    Mother object for all garden related errors.
    A basic error for garden problems
    """
    def __init__(self: "GardenError", message: str) -> None:
        self.message = message
        super().__init__(self.message)

    def __str__(self: "GardenError") -> str:
        return f"{self.message}"


class PlantError(GardenError):
    """ For problems with plants"""
    def __init__(self: "PlantError", message: str) -> None:
        self.message = message
        super().__init__(self.message)

    def __str__(self: "PlantError") -> str:
        return f"{self.message}"


class WaterError(GardenError):
    """Use if the days of watering is below 2"""
    def __init__(self: "WaterError", message: str) -> None:
        self.message = message
        super().__init__(self.message)


def process_water_item(item: int) -> None:
    if (item < 0):
        raise WaterError("Shouldnt be nagative")


def process_plant_item(item: str) -> None:
    if (item == ""):
        raise PlantError("name is empty")


def process_garden_error(item: str) -> None:
    if (item == "garden" or item == "Garden"):
        raise GardenError("Garden or garden is an invalid name")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")

    try:
        process_water_item(1)
        process_water_item(-1)
    except WaterError as e:
        print(e)

    try:
        process_plant_item("Rose")
        process_plant_item("")
    except PlantError as e:
        print(e)

    try:
        process_garden_error("Foo")
        process_garden_error("garden")
        process_garden_error("Garden")
        print("Bar")
        process_garden_error("Bar")
    except GardenError as e:
        print(e)

    # def water_plants(watered_ago):
    #     try:
    #         watered_ago > 2
    #     except WaterError("not long enough ago"):
    #         print("wait more longer")
    # water_plants(watered_ago)
