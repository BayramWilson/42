from ex2.ft_custom_errors import PlantError


def process_plant(plant: str) -> None:
    if not (isinstance(plant, str)):
        raise PlantError("Must be a string")
    if (plant == ""):
        raise PlantError("Can't be empty")


def water_plants(plant_list: list) -> None:
    try:
        for plant in plant_list:
            process_plant(plant)
            print(f"Watering {plant}")
    except PlantError as e:
        print(e)
    finally:
        print("closing Water system")


def test_watering_system() -> None:
    # plant_list = ["tomato", "a", 12, "weed"]
    good_plant_list = ["tomato", "tulip", "rose", "weed"]
    bad_plant_list = ["tomato", "a", 12, "weed"]
    try:
        water_plants(good_plant_list)
        water_plants(bad_plant_list)
    except PlantError:
        print("bad list")
    finally:
        ("all lists tested")


if __name__ == "__main__":
    test_watering_system()
