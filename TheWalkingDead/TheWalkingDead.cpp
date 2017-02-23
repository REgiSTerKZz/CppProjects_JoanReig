// TheWalkingDead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<ctime>
#include <string>


enum class Weapon {
	FISTS,
	GUN, 
	SHOTGUN,
	REVOLVER, 
	SNIPER, 
	MACHINE_GUN,
	MAX
};
class Zombie;
class Player{
public:
	Weapon weapon;
	float precision; // desde 0.f hasta 1.f
	int life; // entre los 100 primeros valores
	// metodos
public:
	void attack(Zombie &p) {
	}
	bool isAlive() {
		if (life > 0) {
			return life;
		}
		else if (life <= 0) {
			return true;
		}
	}
	//Constructores
	Player::Player() : weapon{ (Weapon)(rand() % (int)Weapon::MAX) }, precision{ (float)(rand() % 19 / 10) }, life{ rand() % 101 }
		{
	}
	void attack(Zombie &p);
};

class Zombie {
public:
	int distanceToPlayer; // entre20 y 200
	float speed; // entre 0 y 20
	float damage; // entre 0 y 20
	int life; // entre 0 y 100
public:
// metodos
	void attack(Player &z) { // ataca si esta a rango
		if (distanceToPlayer <= 0) {
			z.life = z.life - (damage);
		}
		else if (distanceToPlayer > 0) { // adelanta un paso si no esta a rango
			distanceToPlayer = distanceToPlayer - 1;
		}
	}
	bool isAlive() {
		if (life > 0) {
			return life;
		}
		else if (life <= 0) {
			return false;
		}
	}
	// constructores
	Zombie::Zombie() : distanceToPlayer{ rand() % 200 + 20 }, speed{ ((float)(rand() % 21)) }, damage{ ((float)(rand() % 21)) }, life{ (rand() % 101) }
		{
	}
};

void Player::attack(Zombie &p) {
	p.life = p.life - static_cast<float>(Player::weapon) + (Player::precision);
}

int main()
{
	srand(time(nullptr));
	const int NUM_ZOMB = 10;
	Player player;
	Zombie zombies[NUM_ZOMB];
	bool zombiesAreAlive;
	int i = 0;
	do {
		std::cout << "Jugador : " << std::endl;
		std::cout << "Arma : ";
		switch (player.weapon)
		{
		case Weapon::FISTS:			std::cout << "FISTS" << std::endl;
		case Weapon::GUN:			std::cout << "GUN" << std::endl;
		case Weapon::SHOTGUN:		std::cout << "SHOTGUN" << std::endl;
		case Weapon::REVOLVER:		std::cout << "REVOLVER" << std::endl;
		case Weapon::SNIPER:		std::cout << "SNIPER" << std::endl;
		case Weapon::MACHINE_GUN:	std::cout << "MACHINE GUN" << std::endl;
		}
		std::cout << "Precision : " << player.precision << std::endl;
		std::cout << "Vida : " << player.life << std::endl;
		zombiesAreAlive = false;
		for (int i = 0; i < NUM_ZOMB; i++) {
			if (zombies[i].isAlive == true) {
				player.attack(zombies[i]);
				zombies[i].attack(player);
				zombiesAreAlive = true;
			
				std::cout << "Distancia al jugador : " << zombies[i].distanceToPlayer << std::endl;
				std::cout << "Velocidad : " << zombies[i].speed << std::endl;
				std::cout << "Ataque : " << zombies[i].attack << std::endl;
				std::cout << "Vida : " << zombies[i].life << std::endl;
			}
		}
		i++;
	} while ((player.isAlive() == true)&& (zombies[i].isAlive() == true));

	if (zombiesAreAlive == true && player.life <= 0) {
		std::cout << "GAME OVER        ZOMBIES are the WINNERS";
	}
	else if (zombiesAreAlive == false && player.life > 0) {
		std::cout << "GAME OVER        PLayer is the WINNER";
	}

    return 0;
}

