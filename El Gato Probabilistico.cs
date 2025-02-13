String Choice;
Console.WriteLine("Bienvenido al Algoritmo de las vegas con Tic-Tac-Toe\n" +
    "¿Desea iniciar ahora?\n" +
    "Si/No");

Choice = Console.ReadLine().ToLower();

switch (Choice)
{
    case "si":
        StartGame();
        break;
    case "no":
        return;
}

while (true)
{
    Console.WriteLine("Quiere volver a intentarlo?\n" +
        "Si/No");
    Choice = Console.ReadLine().ToLower();

    if (Choice == "si")
    {
        StartGame();
    }
    else
    {
        return;
    }
}

void StartGame() {
    GameManager MiTablero = new GameManager();
    int Iteraciones = 1;

    while (true)
    {
        //Obtiene 2 valores de la función de Movimiento Aleatorio
        var (Column, Row) = MiTablero.RandomMove();
        //Los usa para hacer un Movimiento en el tablero
        MiTablero.BustAMove(Column, Row);
        
        //Si ya se ha repetido el proceso 5 veces, empieza a verificar las condiciones de victoria
        if (Iteraciones >= 5)
        {
            if (MiTablero.CheckForWinner() && MiTablero.CurrentPlayer == GameManager.TurnPlayer.CirclePlayer)
            {
                Console.WriteLine(MiTablero.drawEndBoard());
                Console.WriteLine("Ganan las O");
                break;
            }
            else if (MiTablero.CheckForWinner() && MiTablero.CurrentPlayer == GameManager.TurnPlayer.CrossPlayer)
            {
                Console.WriteLine(MiTablero.drawEndBoard());
                Console.WriteLine("Ganan las X");
                break;
            }
            //Si ya han pasado 9 turnos y nadie ha ganado, se declara empate
            else if (Iteraciones >= 9)
            {
                Console.WriteLine(MiTablero.drawEndBoard());
                Console.WriteLine("No Hubo Ganador");
                break;
            }
        }
        MiTablero.changeTurn();
        
        Iteraciones++;
    }
}


class GameManager()
{
    //Tablero
    public string[,] Tablero = { { "-", "-", "-" }, { "-", "-", "-" }, { "-", "-", "-" } };
    //Pequeña Maquina de estado
    public TurnPlayer CurrentPlayer = TurnPlayer.CirclePlayer;
    public enum TurnPlayer
    {
        CirclePlayer,
        CrossPlayer
    }

    //Lista que contiene las condiciones de victoria
    //3 filas, 3 columnas, 2 diagonales, en ese orden
    List<(int, int)[]> WinConditions = [
    [(0, 0), (0, 1), (0, 2)], 
    [(1, 0), (1, 1), (1, 2)],
    [(2, 0), (2, 1), (2, 2)],
    [(0, 0), (1, 0), (2, 0)],
    [(0, 1), (1, 1), (2, 1)],
    [(0, 2), (1, 2), (2, 2)],
    [(0, 0), (1, 1), (2, 2)],
    [(0, 2), (1, 1), (2, 0)]
    ];

    //Función que determina de forma aleatoria donde realizará su siguiente movimiento, por defecto, su argumento es siempre 3
    public (int, int) RandomMove(int Rango = 3)
    {
        int movX;
        int movY;

        Random randomizer = new Random();

        //Se crea un número aleatorio entre 0 y 2 para cada dimensión del array
        movX = randomizer.Next(0, Rango);
        movY = randomizer.Next(0, Rango);

        while (!canMakeAMove(movX, movY))
        {
            movX = randomizer.Next(0, Rango);
            movY = randomizer.Next(0, Rango);;
        }

        //Regresa una tupla de valores con los valores aleatorios
        return (movX, movY);

    }

    //Función que revisa si es posible hacer un movimiento en una posición del tablero
    private bool canMakeAMove(int X, int Y)
    {
        if (Tablero[X, Y] == "-") //en caso de que la posición del tablero sea -, significa que está libre, y es posible mover
        {
            return true;
        }
        return false; //De otra forma, no está disponible, y no es posible mover
    }

    //Función que permite realizar un movimiento en el tablero
    public void BustAMove(int X, int Y)
    {
        if (canMakeAMove(X, Y) && CurrentPlayer == TurnPlayer.CirclePlayer) //Si es posible hacer un movimiento en un lugar del tablero, y es turno de los circulos
        {
            //Escribe O
            Tablero[X, Y] = "O";

        }
        //Lo mismo pero para el jugador de las cruces
        else if (canMakeAMove(X, Y) && CurrentPlayer == TurnPlayer.CrossPlayer)
        {
            //Escribe X
            Tablero[X, Y] = "X";
        }
    }

    //Mira quien es el ganador de la partida
    public bool CheckForWinner()
    {
        //Itera a través de cada Array de la Lista
        foreach (var Caja in WinConditions) {

            int cantidadO = 0;
            int cantidadX = 0;

            //Itera a través de cada tupla del Array
            foreach (var Tupla in Caja) {

                //Asigna los valores de la tupla cómo Indices del tablero y revisa si son X u O
                if (Tablero[Tupla.Item1, Tupla.Item2] == "O")
                {
                    cantidadO++;
                }
                else if (Tablero[Tupla.Item1, Tupla.Item2] == "X") {
                    cantidadX++;
                }
            }
            //Si cualquiera de los 2 llega a 3, regresa Cierto
            if (cantidadO == 3 || cantidadX == 3) {
                return true;
            }
        }
        return false;
    }

    //Dibuja el Tablero de juego
    public string drawEndBoard()
    {
        string board = $"{Tablero[0, 0]}|{Tablero[0, 1]}|{Tablero[0, 2]}\n" +
            $"{Tablero[1, 0]}|{Tablero[1, 1]}|{Tablero[1, 2]}\n" +
            $"{Tablero[2, 0]}|{Tablero[2, 1]}|{Tablero[2, 2]}";
        return board;
    }

    //Se asegura de cambiar el jugador en turno al ser llamado
    public void changeTurn()
    {
        if (CurrentPlayer == TurnPlayer.CrossPlayer) {
            CurrentPlayer = TurnPlayer.CirclePlayer;
        }
        else if (CurrentPlayer == TurnPlayer.CirclePlayer) {
            CurrentPlayer = TurnPlayer.CrossPlayer;
        }
    }
}
   