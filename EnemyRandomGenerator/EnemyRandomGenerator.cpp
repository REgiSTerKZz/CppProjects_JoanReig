// RandomEnemyGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> // si ponemos el sdt::string no hance falta que incluyamoa la libreria del string para economizar el codigo.( cada vez que usamos el string habra que "incluirlo" )
#include <ctime>
const int NUM = 5;
enum class EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH, MAX }; // constante MAX se usa para saber la mida del struct... como empieza por 0 tenemos el numero de elementos que tenemos dentro del struct

struct Enemy {
	EnemyType type;
	std::string name;
	int health;

	std::string getEnemyTypesString() {
		switch (type)
		{
		case EnemyType::ZOMBIE: return "ZOMBIE"; // esto es un literal string( no hace falta crear una variable para retornar algo)
		case EnemyType::VAMPIRE: return "VAMPIRE";
		case EnemyType::WITCH: return "WITCH";
		case EnemyType::GHOST: return "GHOST";
		default: return " ";
		}
	}
};

bool operator==(const Enemy &a, const Enemy &b) // si ponemos un ampersan se puede modificar porque accedemos a la memoria pero si le ponemos el const accedemos a la memoria igual(sin gastar mas variables en copias) y a la vez denegamnos cualquier possible cambio del valor de la variable
{
	return a.name == b.name && a.type == b.type; // si los dos Enemy( a y b ) tienen el mismo name y el mismo type, devuelve TRUE
} // al ser las dos variables bool se puede hacer directamente una expresion sin un if que te devuelva un TRUE o un FALSE

static Enemy CreateRandomEnemy()
{
	static const int MAX_LIFE{ 500 };
	static const std::string NAMES[]{
		"Joan",
		"Xavi O",
		"Marcel",
		"Xavi",
		"Martino",
		"Marshall"
	};
	return Enemy{// retorna un enemigo random
		static_cast<EnemyType> (rand() % static_cast<int>(EnemyType::MAX)),// usamos el modulo MAX para que el random me tenga la mida correcta de los elementos del struct
																		   // Hacemos que el rand me haga un tipo int (MAX) pero con el cast<EnemyType> hacemos que me lo comvierta en un EnemyType
																		   NAMES[rand() % (sizeof NAMES / sizeof std::string)], // sizeof NAMES( me lo devuelve en numero de bytes y si lo divido en lo que me ocupa un string( sizeof sdt::string) me dara el numero de elementos que tiene el struct de strings( mas o menos la trampa del MAX pero bien )
																		   rand() % MAX_LIFE// me da un valor entre 0 y 499 ( la vida del enemigo )
	};
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr))); // nullptr es el null de c++ , el NULL es el null de C (ahora usaremos classes y tendremos que usar el nullptr)
	const int MAX_ENEMIES{ 5 };
	Enemy enemies[MAX_ENEMIES];

	{ // inicialitzacio de cada enemic a l'array
		int i{ 0 };
		while (i < MAX_ENEMIES) {
			enemies[i] = CreateRandomEnemy(); // crea el enemigo
			int j{ i - 1 };
			while (j >= 0) {
				if (enemies[i] == enemies[j]) { // comprueva que el enemigo no este ya repetido en otra posicion del array
					--i;
					break; // decrementamos uno la i para que el programa vuelva a hacer el enemigo
				};
				j--;
			};
			i++;
		}
	}
	// print el array de los enemies
	std::cout << "List of Enemies: \n";
	for (auto &enemy : enemies) // &enemy es el nombre de una variable y enemies es el nombre de la array que queramos recorrer
	{
		std::cout << enemy.name <<
			" is a " << enemy.getEnemyTypesString() <<
			" whose life is " << enemy.health << std::endl;
	}

	return 0;
}