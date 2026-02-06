import sys


def parse_items() -> dict:
    inventory = []
    for i in range(1, len(sys.argv)):
        inventory += [sys.argv[i]]
    temp = ""
    amount = ""
    inventory_dict = {}
    # counter = 0
    for i in range(len(inventory)):
        for c in inventory[i]:
            if (c == ':'):
                for c in inventory[i]:
                    amount += c
                break
            temp += c
        after_column = len(amount) - len(temp) - 1
        amount = amount[-after_column:]
        inventory_dict[temp] = int(amount)
        temp = ""
        amount = ""
    return inventory_dict


def sum_dict_values(inventory: dict) -> int:
    sum = inventory.values()
    result = 0
    for i in sum:
        result += i
    return result


def current_inventory(inventory: dict) -> None:
    print("=== Current Inventory ===")
    for key, val in inventory.items():
        percentage = round(val / sum_dict_values(inventory) * 100, 1)
        print(f"{key}: {val} units "
              f"({percentage}%)")


def most_abundant(inventory: dict) -> dict:
    value_list = []
    key_list = []
    result = {}
    for key, val in inventory.items():
        key_list += [key]
        value_list += [val]
    most_abundant_value = value_list[0]
    most_abundant_key = key_list[0]
    # print(value_list)
    for i in range(len(value_list)):
        if (int(value_list[i]) > most_abundant_value):
            most_abundant_value = value_list[i]
            most_abundant_key = key_list[i]
    result[most_abundant_key] = most_abundant_value
    units = "units"
    if (most_abundant_value == 1):
        units = "unit"
    print(f"Most abundant: {most_abundant_key} "
          f"({most_abundant_value} {units})")
    return result


def least_abundant(inventory: dict) -> dict:
    value_list = []
    key_list = []
    result = {}
    for key, val in inventory.items():
        key_list += [key]
        value_list += [val]
    most_abundant_value = value_list[0]
    most_abundant_key = key_list[0]
    # print(value_list)
    for i in range(len(value_list)):
        if (int(value_list[i]) < most_abundant_value):
            most_abundant_value = value_list[i]
            most_abundant_key = key_list[i]
    result[most_abundant_key] = most_abundant_value
    units = "units"
    if (most_abundant_value == 1):
        units = "unit"
    print(f"Least abundant: {most_abundant_key} "
          f"({most_abundant_value} {units})")
    return result


def check_restock(inventory: dict) -> list:
    restock = []
    for key, val in inventory.items():
        if (val <= 1):
            restock += [key]
    return restock


def sample_lookup(inventory: dict, value: str):
    try:
        inventory[value]
        print(f"Sample lookup - {value} in inventory: True")
    except KeyError:
        print(f"Sample lookup - {value} in inventory: False")


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory = parse_items()
    sum_values = sum_dict_values(inventory)
    print(f"Total items in inventory: {sum_values}")
    print(f"Unique item types: {len(inventory)}\n")
    current_inventory(inventory)
    print("\n")
    print("=== Inventory Statistics ===")
    most_abundant(inventory)
    least_abundant(inventory)
    print("\n")
    print("=== Item Categories ===")
    moderate = ["potion", "arrow"]
    scarce = ["sword", "shield", "armor", "helmet"]
    nested_dict = {
        "moderate": {item: inventory[item] for item in moderate},
        "scarce": {item: inventory[item] for item in scarce}
    }
    print(f"Moderate: {nested_dict["moderate"]}")
    print(f"Scarce: {nested_dict["scarce"]}\n")

    print("=== Management Suggestions ===")
    print(f"Restock needed: {check_restock(inventory)}\n")

    print("=== Dictionary Properties Demo ===")
    keys = []
    vals = []
    for key, val in inventory.items():
        keys += [key]
        vals += [val]
    print(f"Dictionary keys: {keys}")
    print(f"Dictionary values: {vals}")
    sample_lookup(inventory, "swored")
