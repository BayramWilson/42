import sys

if __name__ == "__main__":
    game_scores = []
    i = 0
    j = 1
    for arg in sys.argv:
        game_scores.append(arg)
    game_scores.pop(0)

    for score in game_scores:
        print(score)