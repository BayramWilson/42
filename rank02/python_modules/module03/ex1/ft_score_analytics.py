import sys


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
        return shaped_game_scores


def parse_data(game_scores: list) -> list:
    for arg in sys.argv:
        game_scores = game_scores + [arg]
    return game_scores


def list_to_str(game_score_shaped: list) -> str:
    result = ""
    for i in game_score_shaped:
        result += i + ", "
    result = result[:-2]
    return result


def count_player() -> int:
    return len(sys.argv) - 1


def calculate_total_score(scores: list) -> int:
    total = 0
    for score in scores:
        total += int(score)
    return total


def get_high_score(scores: list) -> int:
    high_score = 0
    for score in scores:
        if (int(score) > high_score):
            high_score = int(score)
    return high_score


def get_lowest_score(scores: list) -> int:
    try:
        lowest_score = int(scores[0])
        for score in scores:
            if (int(score) < lowest_score):
                lowest_score = int(score)
        return lowest_score
    except IndexError:
        print("No scores provided. Usage: python3 ft_score_analytics.py "
              "<score1> <score2> ...")


def calculate_average_score(scores: list) -> int:
    total = calculate_total_score(scores)
    player = count_player()
    try:
        return total / player
    except ZeroDivisionError:
        pass


if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    game_scores = []
    shaped_game_scores = []
    player_count = count_player()
    game_scores = parse_data(game_scores)
    shaped_game_scores = shape_data(game_scores)
    total_score = calculate_total_score(shaped_game_scores)
    high_score = get_high_score(shaped_game_scores)
    lowest_score = get_lowest_score(shaped_game_scores)
    try:
        average_score = round(calculate_average_score
                              (shaped_game_scores), 2)
    except TypeError:
        pass
    scores_str = list_to_str(shaped_game_scores)
    try:
        if not (scores_str == ""):
            print(f"Scores processed: [{scores_str}]")
        if not (player_count == 0):
            print(f"Total players: {player_count}")
        if not (total_score == 0):
            print(f"Total score: {total_score}")
        print(f"Average score: {average_score}")
        print(f"High score: {high_score}")
        print(f"Low score: {lowest_score}")
        print(f"Score range: {high_score - lowest_score}")
    except NameError:
        pass
