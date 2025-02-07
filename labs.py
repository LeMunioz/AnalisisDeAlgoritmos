import tkinter as tk
import random

class MazeGenerator:
    def __init__(self, width=21, height=21, cell_size=25):
        """
        Inicializa el generador de laberintos.
        Crea la ventana, el lienzo y genera el laberinto.
        """
        self.width = width
        self.height = height
        self.cell_size = cell_size
        self.grid = [[1 for _ in range(width)] for _ in range(height)]  # 1 representa paredes
        self.visited = set()
        
        self.window = tk.Tk()
        self.window.title("Laberinto")
        self.canvas = tk.Canvas(self.window, width=width * cell_size, height=height * cell_size, bg="white")
        self.canvas.pack()
        
        self.window.bind("r", self.restart)  # Asigna la tecla 'r' para reiniciar
        
        self.generate_maze(0, 0)
        self.draw_maze()
        self.solve_maze()
        
        self.window.mainloop()

    def generate_maze(self, x, y):
        """
        Genera el laberinto utilizando un algoritmo de búsqueda en profundidad.
        """
        self.grid[y][x] = 0  # 0 representa camino
        self.visited.add((x, y))
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]  # Direcciones: arriba, abajo, izquierda, derecha
        random.shuffle(directions)
        
        for dx, dy in directions:
            nx, ny = x + dx * 2, y + dy * 2
            if 0 <= nx < self.width and 0 <= ny < self.height and (nx, ny) not in self.visited:
                self.grid[y + dy][x + dx] = 0  # Abre un camino entre las celdas
                self.generate_maze(nx, ny)
    
    def draw_maze(self):
        """
        Dibuja el laberinto en el lienzo.
        """
        self.canvas.delete("all")  # Borra el laberinto anterior
        for y in range(self.height):
            for x in range(self.width):
                if self.grid[y][x] == 1:
                    self.canvas.create_rectangle(
                        x * self.cell_size, y * self.cell_size,
                        (x + 1) * self.cell_size, (y + 1) * self.cell_size,
                        fill="black"
                    )
    
    def solve_maze(self):
        """
        Resuelve el laberinto utilizando un algoritmo de backtracking.
        """
        start = (0, 0)
        goal = (self.width - 1, self.height - 1)
        path = []
        visited = set()
        if self.backtracking(start, goal, path, visited):
            self.draw_solution(path)
    
    def backtracking(self, current, goal, path, visited):
        """
        Algoritmo de backtracking para encontrar una solución al laberinto.
        Marca las celdas exploradas en amarillo y la solución en azul.
        """
        if current == goal:
            path.append(current)
            return True
        
        x, y = current
        if (x, y) in visited or not (0 <= x < self.width and 0 <= y < self.height) or self.grid[y][x] == 1:
            return False
        
        visited.add((x, y))
        self.canvas.create_rectangle(
            x * self.cell_size, y * self.cell_size,
            (x + 1) * self.cell_size, (y + 1) * self.cell_size,
            fill="yellow"  # Marca las celdas exploradas
        )
        self.window.update()
        self.canvas.after(20)
        
        path.append((x, y))
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Movimientos: abajo, derecha, arriba, izquierda
        
        for dx, dy in directions:
            if self.backtracking((x + dx, y + dy), goal, path, visited):
                return True
        
        path.pop()
        return False
    
    def draw_solution(self, path):
        """
        Dibuja la solución del laberinto en azul.
        """
        for x, y in path:
            self.canvas.create_rectangle(
                x * self.cell_size, y * self.cell_size,
                (x + 1) * self.cell_size, (y + 1) * self.cell_size,
                fill="blue"
            )
            self.window.update()
            self.canvas.after(20)
    
    def restart(self, event=None):
        """
        Reinicia el laberinto generando uno nuevo.
        """
        self.grid = [[1 for _ in range(self.width)] for _ in range(self.height)]
        self.visited.clear()
        self.generate_maze(0, 0)
        self.draw_maze()
        self.solve_maze()

if __name__ == "__main__":
    MazeGenerator(49, 49, 10)
