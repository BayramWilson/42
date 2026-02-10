from random import randint
import time
from typing import Any


def game_event_stream(game_events: list, players: list) -> Any:
    # high_level = 0
    for i in range(1001):
        level = randint(1, 100)
        yield {
            "id": i,
            "player": players[randint(0, len(players) - 1)],
            "level": level,
            "event": game_events[randint(0, len(game_events) - 1)]
        }


def processor_level(event: dict) -> bool:
    print(
        f'Event {event["id"]}: '
        f'Player {event["player"]}'
        f' (level {event["level"]})'
        f' {event["event"]}'
        )
    return event["level"] > 30


def processor_treasure(event: dict) -> bool:
    return event["event"] == game_events[1]


def processor_levelup(event: dict) -> bool:
    return event["event"] == game_events[2]


def fib(n: int) -> Any:
    a, b = 0, 1
    count = 0
    while count < n:
        yield a
        a, b = b, a + b
        count += 1


def print_fib() -> list:
    fibo = fib(10)
    fibo_list = []
    while True:
        try:
            value = next(fibo)
            fibo_list = fibo_list + [value]
        except StopIteration:
            break
    return fibo_list


def prime_generator() -> Any:
    num = 2
    while True:
        for i in range(2, num):
            if num % i == 0:
                break
        else:
            yield num
        num += 1


def prime_list() -> list:
    primes = []
    gen = prime_generator()
    for _ in range(5):
        primes = primes + [next(gen)]
    return primes


if __name__ == "__main__":

    print("=== Game Data Stream Processor ===")
    game_events = [
        "killed monster",
        "found treasure",
        "leveled up",
        "completed quest",
        "defeated boss",
        "discovered secret area",
        "crafted item",
        "joined guild"
    ]
    player = [
        "alice",
        "bob",
        "charlie",
        "dave",
        "eve",
        "frank"
    ]
    t0 = time.perf_counter()
    stream = game_event_stream(game_events, player)
    high_level_count = 0
    treasure_count = 0
    leveled_up_count = 0
    while True:
        try:
            event = next(stream)

            if processor_level(event):
                high_level_count += 1
            if processor_treasure(event):
                treasure_count += 1
            if processor_levelup(event):
                leveled_up_count += 1
            if event["id"] == 1000:
                break

        except StopIteration:
            break

    elapsed = time.perf_counter() - t0

    print("\n=== Stream Analytics ===")
    print(f"Total events processed: {event["id"]}")
    print(f"High level players (30+): {high_level_count}")
    print(f"Treasure events: {treasure_count}")
    print(f"Level-up events: {leveled_up_count}\n")
    print("Memory usage: Constant (streaming)")
    print(f"Processing time: {round(elapsed, 4)} seconds")
    print("\n=== Generator Demonstration ===")
    print(f"Fibonacci sequence (first 10): {print_fib()}")
    print(f"prime numbers: (first 5): {prime_list()}")
