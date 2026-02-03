from ex2.ft_custom_errors import (WaterError,
                                  PlantError,
                                  GardenError)


def check_plant_health(plant_name: str,
                       water_level: int,
                       sunlight_hours: int
                       ) -> None:
    if (plant_name == ""):
        raise PlantError("Plant name is empty")
    if not (water_level > 0 and water_level <= 10):
        raise WaterError("Water level is not between 1 and 10")
    if not (sunlight_hours >= 2 and sunlight_hours <= 12):
        raise GardenError(f"{sunlight_hours} Sunlight hours are not "
                          f"between 2 and 12")


def testing() -> None:
    try:
        check_plant_health("", -2, 12)
    except WaterError as e:
        print(e)
    except GardenError as e:
        print(e)
    except PlantError as e:
        print(e)


if __name__ == "__main__":
    testing()
