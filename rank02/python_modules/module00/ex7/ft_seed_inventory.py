def ft_seed_inventory(veg: str, qty: int, flag: str) -> None:
    veg_cap = veg.capitalize()
    if (flag == "packets"):
        start = ""
        ending = "available"
    elif (flag == "grams"):
        start = ""
        ending = "total"
    elif (flag == "area"):
        start = "covers "
        ending = "square meters"
    else:
        print("Unknown unit type")
        return None
    print(f"{veg_cap} seeds: {start}{qty} {flag} {ending}")
    return None

# ft_seed_inventory("tomato", 15, "packets")
# ft_seed_inventory("carrot", 8, "grams")
# ft_seed_inventory("lettuce", 12, "area")
