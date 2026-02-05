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


class CoordinateError(Exception):
    def __init__(self, message: "str"):
        super().__init__(message)
        self.message = message


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    try:
        argc = len(sys.argv)
        if (argc < 4):
            raise CoordinateError(f"Too less coordinates: {argc - 1} / 3")
        elif (argc > 4):
            raise CoordinateError(f"Too much coordinates: {argc - 1} / 3")

        # pos1 = (sys.argv[4], sys.argv[5], sys.argv[6])
        pos = (10, 20, 5)
        pos1 = (0, 0, 0)
        pos2 = (sys.argv[1], sys.argv[2], sys.argv[3])

        print(f"position created: ({pos[0]}, {pos[1]}, {pos[2]})")
        dist = calculat_distance(pos, pos1)
        dist = round(dist, 2)
        print(f"distance between ({pos1[0]}, {pos1[1]}, {pos1[2]}) "
              f"and ({pos[0]}, {pos[1]}, {pos[2]}): {dist}\n")

        try:
            pos2_x = int(pos2[0])
            pos2_y = int(pos2[1])
            pos2_z = int(pos2[2])
            print(f'Parsing coordinates: "{pos2[0]},{pos2[1]},{pos2[2]}"')
            print(f"Parsed position: ({pos2[0]}, {pos2[1]}, {pos2[2]})")
            dist1 = calculat_distance(pos1, pos2)
            dist1 = round(dist1, 2)
            print(f"Distance between ({pos1[0]}, {pos1[1]}, {pos1[2]}) and"
                  f"({pos2[0]}, {pos2[1]}, {pos2[2]}): {dist1}\n")

            print("Unpacking demonstration:")
            print(f"player at x: {pos2[0]}, y: {pos2[1]}, z: {pos2[2]}")
            print(f"Coordinates x: {pos2[0]}, y: {pos2[1]}, z: {pos2[2]}")
        except ValueError as e:
            print(f'Parsing invalid coordinates: "{pos2[0]},'
                  f'{pos2[1]},{pos2[2]}"')
            print(e)
            print(f'Error details - Type: ValueError, Args: ({e})\n')

    except CoordinateError as e:
        print(e)
    except TypeError as e:
        print(e)
    finally:
        print("\nCoordination Manager closed")
