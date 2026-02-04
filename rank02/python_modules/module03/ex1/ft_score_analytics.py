from re import split
import sys


def ft_split(string: str, delimiters=' \t\n'):
    result = []
    word = ''
    for c in string:
        if c not in delimiters:
            word += c
        elif word:
            result.append(word)
            word = ''

    if word:
        result.append(word)

    return result


def check_input(input: str) -> None:
    try:
        input = int(input)
    except ValueError:
        print("input must be a number")
    input = int(input)
    if (input < 0):
        raise ValueError("The value must be at least 0")


def shape_data(game_scores: list) -> list:
    shaped_game_scores = []
    try:
        for i in range(len(game_scores) - 1):
            check_input(game_scores[i + 1])
            shaped_game_scores = shaped_game_scores + [game_scores[i + 1]]
    except ValueError as e:
        print(f"Error: {game_scores[i + 1]}\n{e}")
    finally:
        print("shaped data ready")
        print(shaped_game_scores)
    return shaped_game_scores


def split_shape_data(shaped_game_scores: list) -> list:
    for score in shaped_game_scores:
        split(score, "'")
    return shaped_game_scores


def parse_data(game_scores: list) -> list:
    for arg in sys.argv:
        game_scores = game_scores + [arg]
    return game_scores


if __name__ == "__main__":
    game_scores = []
    shaped_game_scores = []
    game_scores = parse_data(game_scores)
    print(game_scores)
    shaped_game_scores = shape_data(game_scores)
    more_shaped_game_scores = split_shape_data(shaped_game_scores)
    out = ""
    for x in shaped_game_scores:
        out += str(x) + ", "
    out = out[:-2]
    print(f"Scores processed: [{out}]")
    # print(more_shaped_game_scores)
