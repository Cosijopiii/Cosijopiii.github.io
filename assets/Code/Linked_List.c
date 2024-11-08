#include <stdio.h>
#include <stdlib.h>

// DefiniciC3n de la estructura Nodo
struct Nodo {
	int dato;
	struct Nodo* siguiente;
};

// Inicializamos la cabeza de la lista como NULL
struct Nodo* head = NULL;

// FunciC3n para insertar un nodo al inicio de la lista
void insertarInicio(int nuevoDato) {
	// Crear un nuevo nodo y asignar memoria
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = nuevoDato;
	nuevoNodo->siguiente = head; // El nuevo nodo apunta a la antigua cabeza
	head = nuevoNodo; // La cabeza ahora es el nuevo nodo
}

// FunciC3n para eliminar el primer nodo que contiene un valor especC-fico
void eliminar(int valor) {
	struct Nodo* temp = head;
	struct Nodo* anterior = NULL;

	// Si la cabeza contiene el valor a eliminar
	if (temp != NULL && temp->dato == valor) {
		head = temp->siguiente; // Cambia la cabeza
		free(temp); // Libera el nodo
		printf("Nodo con valor %d eliminado\n", valor);
		return;
	}

	// Buscar el nodo a eliminar, manteniendo el nodo anterior
	while (temp != NULL && temp->dato != valor) {
		anterior = temp;
		temp = temp->siguiente;
	}

	// Si el valor no estaba en la lista
	if (temp == NULL) {
		printf("Valor %d no encontrado en la lista\n", valor);
		return;
	}

	// Desenlazar el nodo de la lista
	anterior->siguiente = temp->siguiente;
	free(temp); // Liberar el nodo
	printf("Nodo con valor %d eliminado\n", valor);
}

// FunciC3n para buscar un nodo en la lista
void buscar(int valor) {
	struct Nodo* temp = head;
	int encontrado = 0;
	while (temp != NULL) {
		if (temp->dato == valor) {
			printf("Valor %d encontrado en la lista\n", valor);
			encontrado = 1;
			break;
		}
		temp = temp->siguiente;
	}
	if (!encontrado) {
		printf("Valor %d no encontrado en la lista\n", valor);
	}
}

// FunciC3n para imprimir la lista enlazada
void imprimirLista() {
	struct Nodo* temp = head;
	printf("Lista enlazada: ");
	while (temp != NULL) {
		printf("%d -> ", temp->dato);
		temp = temp->siguiente;
	}
	printf("NULL\n");
}

int main() {
	// Pruebas de las funciones
	insertarInicio(10);
	insertarInicio(20);
	insertarInicio(30);
	imprimirLista();

	buscar(20);
	buscar(40);

	eliminar(20);
	imprimirLista();

	eliminar(40);

	return 0;
}
