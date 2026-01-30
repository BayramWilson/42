from typing import TextIO

def garden_operations() -> None:
    a_str = "abc"
    value(a_str)
    a_zero = 0
    zero_division(a_zero)
    a_file = "tess.txt"
    file_not_found(a_file)
    a_dict = {"a": 1, "b": 2}
    key(a_dict, "c")
    
    

def test_error_types() -> None:
    pass

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
def file_not_found(test: TextIO) -> None:
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
    pass