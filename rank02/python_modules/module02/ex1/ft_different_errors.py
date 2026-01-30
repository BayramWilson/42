def garden_operations() -> None:
    pass
def helper(test: str) -> None:
    try:
        print("Testing ValueError...")
        test = int(test)
    except ValueError:
        