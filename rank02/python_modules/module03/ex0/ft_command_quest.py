import sys

if __name__ == "__main__":
    print("=== Command Quest ===")
    amt_args = len(sys.argv)
    name_program = sys.argv[0]
    i = 1
    if (amt_args == 1):
        print("No arguments provided!")
    print(f"Program name: {name_program}")
    if (amt_args > 1):
        print(f"Arguments received: {amt_args}")
        for arg in sys.argv:
            print(f"Argument {i}: {arg}")
            i += 1
        print(f"Total arguments: {amt_args}")
