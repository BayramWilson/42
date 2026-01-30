def ft_count_harvest_recursive() -> None:
    helper(int(input("Days until harvest: ")))
    print("Harvest time!")


def helper(days: str) -> str:
    if (days > 0):
        result = days - helper(days - 1)
        print(f"Day {days}")
    else:
        result = 0
    return result
# ft_count_harvest_recursive()
