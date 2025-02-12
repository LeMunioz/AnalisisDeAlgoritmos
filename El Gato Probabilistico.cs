/*
 
Faltante:
1.- Dibujar el Tablero al final de la partida.
2.- Verificar si es posible forzar un empate, si no, buscar la forma en que sean posibles.

*/

String Choice;
Console.WriteLine("Bienvenido al Algoritmo de las vegas con Tic-Tac-Toe\n¿Desea iniciar ahora?\nSi/No");

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
    Console.WriteLine("Quiere volver a intentarlo?\nSi/No");
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
        var (Column, Row) = MiTablero.RandomMove();
        MiTablero.BustAMove(Column, Row);

        if (MiTablero.CheckForWinner() && MiTablero.CurrentPlayer == GameManager.TurnPlayer.CirclePlayer)
        {
            Console.WriteLine("Ganan las O");
            break;
        }
        else if (MiTablero.CheckForWinner() && MiTablero.CurrentPlayer == GameManager.TurnPlayer.CrossPlayer)
        {
            Console.WriteLine("Ganan las X");
            break;
        }

        if (Iteraciones >= 9)
        {
            Console.WriteLine("No Hubo Ganador");
            break;
        }
    }
}



class GameManager()
{
    public int[,] Tablero = new int [3, 3];
    public TurnPlayer CurrentPlayer = TurnPlayer.CirclePlayer;
    public enum TurnPlayer
    {
        CirclePlayer,
        CrossPlayer
    }

    //Estructura que contiene las condiciones de victoria


    List<(int, int)[]> WinConditions = [
    [(0, 0), (0, 1), (0, 2)],
    [(1, 0), (1, 1), (1, 2)],
    [(2, 0), (2, 1), (2, 2)],
    [(0, 0), (1, 0), (2, 0)],
    [(1, 0), (1, 1), (1, 2)],
    [(2, 0), (2, 1), (2, 2)],
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

        //Regresa una tupla de valores con los valores aleatorios
        return (movX, movY);

    }

    //Función que revisa si es posible hacer un movimiento en una posición del tablero
    private bool canMakeAMove(int X, int Y)
    {
        if (Tablero[X, Y] == 0) //en caso de que la posición del tablero sea 0, significa que está libre, y es posible mover
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
            //Escribe 1 y pasa el turno al jugador de las cruces
            Tablero[X, Y] = 1; 
            CurrentPlayer = TurnPlayer.CrossPlayer;

        }
        //Lo mismo pero para el jugador de las cruces
        else if (canMakeAMove(X, Y) && CurrentPlayer == TurnPlayer.CrossPlayer)
        {

            Tablero[X, Y] = 2;
            CurrentPlayer = TurnPlayer.CirclePlayer;
        }
    }

    //Mira quien es el ganador de la partida
    public bool CheckForWinner()
    {
        int Suma = 0;

        foreach (var Caja in WinConditions){
            foreach (var Tupla in Caja){
                Suma += Tablero[Tupla.Item1, Tupla.Item2];
                }

            if(Suma == 3 || Suma == 6){
                return true;
            }
            Suma = 0;
        }
        return false;
    }

    string drawEndBoard()
    {
        string board = "";




        return board;
    }
}

   