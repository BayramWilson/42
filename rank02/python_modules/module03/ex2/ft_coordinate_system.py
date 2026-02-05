import math
import sys


def calculat_distance(coordinate1: tuple,
                      coordinate2: tuple
                      ) -> float:
    try:
        dist_x = float(coordinate2[0]) - float(coordinate1[0])
        dist_x = dist_x * dist_x

        dist_y = float(coordinate2[1]) - float(coordinate1[1])
        dist_y = dist_y * dist_y

        dist_z = float(coordinate2[2]) - float(coordinate1[2])
        dist_z = dist_z * dist_z

        result = dist_x + dist_y + dist_z
        return math.sqrt(result)
    except ValueError as e:
        print(e)
    except TypeError as e:
        print(e)

def parse_arguments(coordinate: tuple)

class CoordinateError(Exception):
    def __init__(self, message: "str"):
        super().__init__(message)
        self.message = message


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    try:
        argc = len(sys.argv)
        if (argc < 7):
            raise CoordinateError(f"Too less coordinates: {argc - 1} / 6")
        elif (argc > 7):
            raise CoordinateError(f"Too much coordinates: {argc - 1} / 6")

        pos = (sys.argv[1], sys.argv[2], sys.argv[3])
        pos1 = (sys.argv[4], sys.argv[5], sys.argv[6])
        print(f"position created: ({pos[0]}, {pos[1]}, {pos[2]})")
        dist = calculat_distance(pos, pos1)
        dist = round(dist, 2)
        print(f"distance between {pos} and {pos1}: {dist}")
        print("Unpacking demonstration:")
        print(f"player at x: {pos[0]}, y: {pos[1]}, z: {pos[2]}")
        print(f"Coordinates x: {pos1[0]}, y: {pos1[1]}, z: {pos1[2]}")
    except CoordinateError as e:
        print(e)
    except TypeError as e:
        print(e)
    finally:
        print("Coordination Manager closed")
