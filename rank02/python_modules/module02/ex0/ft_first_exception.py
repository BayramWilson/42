def check_temperature(temp_str: str) -> None:
    """
    takes the input checks if it is convertable to int
    if not throws an error and returns
    if yes it goes for the temp check
    """
    try:
        temp_str = int(temp_str)
    except ValueError:
        print(f"Error: {temp_str} is not a valid number\n")
        return None
    if (temp_str < 0):
        print(f"Error: {temp_str}°C is too cold for plants (min 0°C)\n")
    elif (temp_str > 40):
        print(f"Error: {temp_str}°C is too hot for plants (max 40°C)\n")
    else:
        print(f"Temperature {temp_str}°C is perfect for plants!\n")


def test_temperature_input(test_input: str) -> None:
    """testing the check temperature function"""
    check_temperature(test_input)


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===\n")
    # check_temperature(input("Testing temperature: "))
    different_inputs = ["25", "abc", "100", "-50"]
    for input in different_inputs:
        test_temperature_input(input)
    print("All tests completed - program didn't crash!")
