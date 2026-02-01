from typing import Any


def garden_operations() -> None:
    a_str: str = "abc"
    value(a_str)
    a_zero: int = 0
    zero_division(a_zero)
    a_file: Any = "tess.txt"
    file_not_found(a_file)
    a_dict: dict = {"a": 1, "b": 2}
    key(a_dict, "c")


def test_error_types() -> None:
    print("Testing multiple errors together...")
    a_str: str = "abc"
    a_zero: int = 0
    a_file: Any = "tess.txt"
    a_dict: dict = {"a": 1, "b": 2}

    try:
        int(a_str)
    except ValueError:
        print("Caught an error, but program continues!")
    try:
        a_zero = 10 / a_zero
    except ZeroDivisionError:
        print("Caught an error, but program continues!")

    try:
        f = open(a_file, "r")
        f.close()
    except FileNotFoundError:
        print("Caught an error, but program continues!")

    try:
        print(a_dict[key])
    except KeyError:
        print("Caught an error, but program continues!")


# ERROR FUNCTIONS
# ValueError
def value(test: str) -> None:
    print("Testing ValueError...")
    try:
        test = int(test)
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")


# ZeroDivisionError
def zero_division(test: int) -> None:
    print("Testing ZeroDivisionError...")
    try:
        test = 10 / test
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")


# FileNotFoundError
def file_not_found(test: Any) -> None:
    print("Testing FileNotFoundError...")
    try:
        f = open(test, "r")
        f.close()
    except FileNotFoundError:
        print(f"Caught FileNotFoundError: No such file {test}\n")


# KeyError
def key(test: dict[str, int], key: str) -> None:
    print("Testing KeyError...")
    try:
        print(test[key])
    except KeyError:
        print(f"Caught KeyError: {key}\n")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    garden_operations()
    test_error_types()
    pass
