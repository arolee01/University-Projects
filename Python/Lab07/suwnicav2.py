class Suwnica:
    def __init__(self, rows, cols):
        self.grid = [[0 for _ in range(cols)] for _ in range(rows)]  # Reprezentacja kontenerów
        self.x, self.y, self.z = 0, 0, 10  # Początkowa pozycja suwnicy (x, y, z)
        self.has_container = False  # Czy suwnica trzyma kontener

    def show_grid(self):
        for row in self.grid:
            print(row)

    def containers_at(self, row, col):
        return self.grid[row][col]

    def move(self, direction):
        if direction == "forward" and self.y > 0:
            self.y -= 1
        elif direction == "backward" and self.y < len(self.grid) - 1:
            self.y += 1
        elif direction == "left" and self.x > 0:
            self.x -= 1
        elif direction == "right" and self.x < len(self.grid[0]) - 1:
            self.x += 1
        elif direction == "up" and self.z < 10:
            self.z += 1
        elif direction == "down" and self.z > 0:
            self.z -= 1
        else:
            print("Nie można się przesunąć w tym kierunku!")

    def grab(self):
        if self.z == self.grid[self.y][self.x] + 1 and not self.has_container:
            if self.grid[self.y][self.x] > 0:
                self.has_container = True
                self.grid[self.y][self.x] -= 1
                print("Podniesiono kontener.")
            else:
                print("Brak kontenerów do podniesienia!")
        else:
            print("Suwnica musi być 10 cm nad kontenerem.")

    def release(self):
        if self.z == self.grid[self.y][self.x] + 1 and self.has_container:
            if self.grid[self.y][self.x] < 9:
                self.has_container = False
                self.grid[self.y][self.x] += 1
                print("Kontener został opuszczony.")
            else:
                print("Nie można tutaj umieścić więcej kontenerów!")
        else:
            print("Suwnica musi być 10 cm nad powierzchnią.")

    def laser_check(self, direction):
        if direction == "forward":
            return all(self.grid[row][self.x] == 0 for row in range(0, self.y))
        elif direction == "backward":
            return all(self.grid[row][self.x] == 0 for row in range(self.y + 1, len(self.grid)))
        elif direction == "left":
            return all(self.grid[self.y][col] == 0 for col in range(0, self.x))
        elif direction == "right":
            return all(self.grid[self.y][col] == 0 for col in range(self.x + 1, len(self.grid[0])))
        else:
            print("Nieprawidłowy kierunek lasera!")
            return False

# Przykład użycia
suwnica = Suwnica(5, 5)  # 5x5 siatka
suwnica.grid[3][4] = 3  # Dodanie 3 kontenerów na polu (3, 4)
suwnica.show_grid()

suwnica.move("backward")
suwnica.move("right")
suwnica.move("right")
suwnica.move("down")
suwnica.grab()
suwnica.move("forward")
suwnica.release()
suwnica.show_grid()

print("Laser check forward:", suwnica.laser_check("forward"))
