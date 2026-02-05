import inspect
import re
from collections import Counter


def varname(p):
    for line in inspect.getframeinfo(inspect.currentframe().f_back)[3]:
        m = re.search(r'\bvarname\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)', line)
    if m:
        return m.group(1)


def print_player_achievements(playername: str, player: set) -> None:
    player = sorted(player)
    print(f"Player {playername} achievements: {player}")


def unique(s: list) -> set:
    temp = []
    for i in s:
        temp.extend(list(i))

    c = Counter(temp)
    result = set()
    for k, v in c.items():
        if v == 1:
            result.add(k)
    return result


if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")
    alice = {'first_kill', 'level_10', 'treasure_hunter', 'speed_demon'}
    bob = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
    charlie = {'level_10', 'treasure_hunter', 'boss_slayer', 'speed_demon',
               'perfectionist'}
    player = ['Alice', 'Bob', 'Charlie']
    all_sets = [alice, bob, charlie]

    unique_achievements = set.union(alice, bob, charlie)
    common = set.intersection(alice, bob, charlie)
    alice_bob_common = set.intersection(alice, bob)
    alice_vs_bob_unique = set.difference(alice, bob)
    bob_vs_alice_uique = set.difference(bob, alice)
    rare = unique(all_sets)

    print_player_achievements(player[0], alice)
    print_player_achievements(player[1], bob)
    print_player_achievements(player[2], charlie)
    print("\n")
    print("=== Achievement Analytics ===")
    print(f"All unique achievements {unique_achievements}")
    print(f"Total unique achievements: {len(unique_achievements)}\n")
    print(f"Common to all players: {common}")
    print(f"Rare achievements (1 player): {rare}\n")
    print(f"Alice vs Bob common: {alice_bob_common}")
    print(f"alice unique: {alice_vs_bob_unique}")
    print(f"bob unique: {bob_vs_alice_uique}")
