#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

// Función para contar edificios visibles desde una dirección
// row/col: índice inicial
// step: dirección (-1 o 1)
// type: 0 para fila, 1 para columna
int countVisible(int grid[SIZE][SIZE], int index, int step, int type) {
    int visible = 0;
    int maxHeight = 0;
    
    for (int i = index; i >= 0 && i < SIZE; i += step) {
        int height = (type == 0) ? grid[i][index] : grid[index][i]; // Ajuste de índice según tipo
        // Nota: La lógica exacta de iteración depende de cómo se almacenan las pistas
        // Esta es una simplificación para ilustrar el concepto de visibilidad
        if (height > maxHeight) {
            visible++;
            maxHeight = height;
        }
    }
    return visible;
}

// Verifica si es válido colocar 'height' en 'row', 'col'
bool isValid(int grid[SIZE][SIZE], int row, int col, int height, int clues[4][4]) {
    // 1. Verificar duplicados en fila y columna
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == height || grid[i][col] == height) return false;
    }
    
    // 2. Verificar pistas de visibilidad (simplificado)
    // En una implementación completa, se verifica la visibilidad parcial
    // y se asegura que no se excedan las pistas fijas.
    
    grid[row][col] = height;
    // Aquí se llamaría a una función para verificar consistencia con clues
    // Si es inconsistente, backtracking lo maneja en el llamador
    
    return true;
}

bool solve(int grid[SIZE][SIZE], int row, int col, int clues[4][4]) {
    // Caso base: si llegamos al final de la cuadrícula
    if (row == SIZE) {
        // Verificar si la solución completa es válida respecto a todas las pistas
        // Si lo es, retornar true
        return true; 
    }

    // Calcular siguiente celda
    int nextRow = (col == SIZE - 1) ? row + 1 : row;
    int nextCol = (col == SIZE - 1) ? 0 : col + 1;

    // Si la celda ya tiene un valor fijo (pista inicial si hubiera), saltar
    if (grid[row][col] != 0) {
        return solve(grid, nextRow, nextCol, clues);
    }

    // Probar alturas del 1 al 4
    for (int h = 1; h <= SIZE; h++) {
        if (isValid(grid, row, col, h, clues)) {
            if (solve(grid, nextRow, nextCol, clues)) {
                return true;
            }
            grid[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int grid[SIZE][SIZE] = {0}; // 0 indica celda vacía
    int clues[4][4] = {0};      // Estructura para almacenar pistas (Top, Right, Bottom, Left)

    // Inicializar grid con algunas pistas si es necesario, o dejar todo en 0 para solver genérico
    // Nota: Este ejemplo requiere una lógica de validación de pistas más robusta en 'isValid'
    // para funcionar con pistas específicas.

    if (solve(grid, 0, 0, clues)) {
        printf("Solución encontrada:\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No se encontró solución.\n");
    }

    return 0;
}   
