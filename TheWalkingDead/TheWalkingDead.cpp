// TheWalkingDead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<ctime>
#include <string>

class Zombie;

enum class Weapon {
	FISTS,
	GUN, 
	SHOTGUN,
	REVOLVER, 
	SNIPER, 
	MACHINE_GUN,
	MAX
};


class Player {
public:
	Weapon weapon;
	float precision; // desde 0.f hasta 1.f
	int life; // entre los 100 primeros valores

	Player::Player() : weapon{ static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX)) }, 
		precision{0.f + ((static_cast<float>(rand() % 10) / 10)) }, life{ rand() % 100 }
	{
	}

	bool isAlive() {
		return life > 0;
	}
	void attack(Zombie &p);
};

class Zombie {
public:
	int distanceToPlayer; // entre20 y 200
	float speed; // entre 0 y 20
	float damage; // entre 0 y 20
	int life; // entre 0 y 100
	Zombie::Zombie() : distanceToPlayer{ 20 + (rand() % 180) }, speed{ static_cast<float>(rand() % 20) + ((static_cast<float>(rand() % 10) / 10)) }, damage{ static_cast<float>(rand() % 20) + ((static_cast<float>(rand() % 10) / 10)) }, life{ (rand() % 100) }
		{
		}

	void attack(Player &b) { // ataca si esta a rango
		if (distanceToPlayer <= 0) {
			b.life -= damage;
		}
		else if (distanceToPlayer > 0) { // adelanta un paso si no esta a rango
			distanceToPlayer = distanceToPlayer - 1;
		}
	}
	bool isAlive() {
		return life > 0;
	}
};
void Player::attack(Zombie &p) {
	p.life = p.life - static_cast<int>(Player::weapon) * Player::precision;
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
		if (zombiesAreAlive == true && player.life <= 0) {
			std::cout << "GAME OVER        ZOMBIES are the WINNERS";
		}
		else if (zombiesAreAlive == false && player.life > 0) {
			std::cout << "                 GAME OVER" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << "               PLayer is the WINNER" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
			
		}
		return 0;
}