#include <windows.h>  // Necesario para las funciones de consola
#include <stdio.h>    // Para printf

// Funci�n para mover el cursor a una posici�n (x,y)
void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

// Funci�n para cambiar el color del texto
void color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    // Limpiar pantalla (simulaci�n)
    system("cls");  
    
    // Ejemplo 1: T�tulo con color
    color(14); // Amarillo
    gotoxy(30, 2);
    printf("MENU PRINCIPAL");
    
    // Ejemplo 2: Opciones de men�
    color(11); // Azul claro
    gotoxy(25, 5);
    printf("1. Iniciar juego");
    
    gotoxy(25, 6);
    printf("2. Cargar partida");
    
    gotoxy(25, 7);
    printf("3. Configuraci%cn", 162); // Para la '�' en Windows
    
    gotoxy(25, 8);
    printf("4. Salir");
    
    // Ejemplo 3: Cursor interactivo
    int seleccion = 1;
    while(1) {
        // Resaltar la opci�n seleccionada
        color(10); // Verde claro
        gotoxy(23, 4 + seleccion);
        printf(">"); // Indicador de selecci�n
        
        // Leer teclado (simplificado)
        if(GetAsyncKeyState(VK_UP) & 0x8000) {
            if(seleccion > 1) seleccion--;
        }
        if(GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if(seleccion < 4) seleccion++;
        }
        if(GetAsyncKeyState(VK_RETURN) & 0x8000) {
            break; // Selecci�n confirmada
        }
        
        // Peque�a pausa para no saturar
        Sleep(100);
    }
    
    // Restaurar color normal
    color(7);
    
    // Mostrar selecci�n
    gotoxy(10, 12);
    printf("Seleccionaste la opci%cn %d", 162, seleccion);
    
    return 0;
}
