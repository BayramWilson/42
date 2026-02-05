import inspect
import re


def varname(p):
    for line in inspect.getframeinfo(inspect.currentframe().f_back)[3]:
        m = re.search(r'\bvarname\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)', line)
    if m:
        return m.group(1)


def print_player_achievements(playername: str, player: set) -> None:
    player = sorted(player)
    print(f"Player {playername} achievements: {player}")


if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")
    alice = {'first_kill', 'level_10', 'treasure_hunter', 'speed_demon'}
    bob = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
    charlie = {'level_10', 'treasure_hunter', 'boss_slayer', 'speed_demon',
               'perfectionist'}
    player = ['Alice', 'Bob', 'Charlie']
    unique_achievements = set.union(alice, bob, charlie)
    common = set.intersection(alice, bob, charlie)
    rare = set.difference(alice, bob)
    more_rare = set.difference(bob, charlie)
    more_more_rare = set.symmetric_difference(alice, charlie, bob)
    print_player_achievements(player[0], alice)
    print_player_achievements(player[1], bob)
    print_player_achievements(player[2], charlie)
    print("\n")
    print("=== Achievement Analytics ===")
    print(f"All unique achievements {unique_achievements}")
    print(f"Total unique achievements: {len(unique_achievements)}\n")
    print(f"Common to all players: {common}")
    print(rare)
    print(more_rare)
    print(more_more_rare)
    # print(f"Rare achievements (1 Player): {more_rare}")
    first_kill = False
