import sys


def parse_items() -> dict:
    inventory = []
    for i in range(1, len(sys.argv)):
        inventory += [sys.argv[i]]
    temp = ""
    amount = ""
    dict = {}
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
        dict[temp] = int(amount)
        temp = ""
        amount = ""
    return dict


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory = parse_items()
    print(inventory)
