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


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory = parse_items()
    print(inventory)
    sum_values = sum_dict_values(inventory)
    print(sum_values)
