#!/usr/bin/python3
"""5-island_perimeter module"""

def island_perimeter(grid):
    """Returns the perimeter of the island described in grid"""
    c = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] != 1:
                    c += 1
                if j == 0 or grid[i][j - 1] != 1:
                    c += 1
                if j == cols - 1 or grid[i][j + 1] != 1:
                    c += 1
                if i == rows - 1 or grid[i + 1][j] != 1:
                    c += 1
    return c
