#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Capacidad máxima de la pila

// Estructura de la pila
typedef struct {
    int datos[MAX]; // Array para almacenar elementos
    int tope;       // Índice del elemento superior
} Pila;

// 1. Inicializar pila
void inicializar(Pila *p) {
    p->tope = -1; // -1 indica pila vacía
}

// 2. Verificar si está vacía
int estaVacia(Pila *p) {
    return p->tope == -1;
}

// 3. Verificar si está llena
int estaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

// 4. Apilar (push)
void push(Pila *p, int valor) {
    if(estaLlena(p)) {
        printf("Error: Pila llena\n");
        return;
    }
    p->datos[++p->tope] = valor;
}

// 5. Desapilar (pop)
int pop(Pila *p) {
    if(estaVacia(p)) {
        printf("Error: Pila vacía\n");
        exit(EXIT_FAILURE);
    }
    return p->datos[p->tope--];
}

// 6. Ver elemento superior (peek)
int peek(Pila *p) {
    if(estaVacia(p)) {
        printf("Error: Pila vacía\n");
        exit(EXIT_FAILURE);
    }
    return p->datos[p->tope];
}

// 7. Mostrar pila
void mostrar(Pila *p) {
    if(estaVacia(p)) {
        printf("Pila vacía\n");
        return;
    }
    
    printf("Contenido de la pila (tope -> base):\n");
    for(int i = p->tope; i >= 0; i--) {
        printf("| %5d |\n", p->datos[i]);
    }
    printf("---------\n");
}

int main() {
    Pila miPila;
    inicializar(&miPila);
    
    printf("=== Operaciones con pila ===\n");
    
    push(&miPila, 10);
    push(&miPila, 20);
    push(&miPila, 30);
    
    printf("Elementos apilados:\n");
    mostrar(&miPila);
    
    printf("Elemento superior: %d\n", peek(&miPila));
    
    printf("\nPop: %d\n", pop(&miPila));
    printf("Pop: %d\n", pop(&miPila));
    
    printf("\nEstado final:\n");
    mostrar(&miPila);
    
    return 0;
}