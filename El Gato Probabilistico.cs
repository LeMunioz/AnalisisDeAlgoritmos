/*
 
Faltante:
1.- Completar la forma de leer la respuesta a la pregunta inicial.
2.- Crear una función en "GameManager" que verifique si hay alguna columna, fila o diagonal con el mismo valor para verificar si alguien ha ganado.
3.- Declarar el Ganador en base a lo anterior, y romper el Loop.
4.- Si hay ganador o no, ofrecer la opción de volver a intentarlo.

*/

String Choice;
Console.WriteLine("Bienvenido al Algoritmo de las vegas con Tic-Tac-Toe\n¿Desea iniciar ahora?");

Choice = Console.ReadLine().ToLower();


GameManager MiTablero = new GameManager();


while (true)
{
    var (Column, Row) = MiTablero.RandomMove();
    MiTablero.BustAMove(Column, Row);

}



class GameManager()
{
    public int[,] Tablero = new int [3, 3];
    TurnPlayer CurrentPlayer = TurnPlayer.CirclePlayer;
     enum TurnPlayer
    {
        CirclePlayer,
        CrossPlayer
    }

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
}

   