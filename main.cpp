#include <iostream>
#include <string>

class Player
{

public:
	Player(int positionX, int positionY, int currentVelocitiy, int hitPoints)
	{
		x = positionX;
		y = positionY;
		velocity = currentVelocitiy;
		hp = hitPoints;
	}

	int x;
	int y;
	int velocity;
	int hp;
	int strength;
	std::string playerName;

	void move()
	{
		x += velocity;
		y += velocity;
	}

	void damage(int ammount)
	{
		hp -= ammount;
	}
};

void move(int& x, int& y, int& velocity)
{
	x += velocity;
	y += velocity;
}

int main()
{
	Player playerOne = Player(0, 0, 10, 30);
	playerOne.playerName = "Chaos";
	playerOne.strength = 12;

	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.playerName = "robi256";
	playerTwo.strength = 11;

	playerOne.move();
	playerTwo.move();
	std::string losingPlayer;
	std::string winPlayer;

	while (playerOne.hp > 0 && playerTwo.hp > 0)
	{
		int check;
		std::cout << "Choose player you want to hit :";
		std::cin >> check;
		std::cout << std::endl;
		std::cin.ignore(1000, '\n');

		switch (check)
		{
		case 1:
			playerOne.damage(playerTwo.strength);
			std::cout << "Player one lost 5 hitpoits" << std::endl;
			break;
		case 2:
			playerTwo.damage(playerOne.strength);
			std::cout << "Player two lost 5 hitpoits" << std::endl;
			break;
		default:
			break;
		}

		std::cout << "Player one hitpoints: " << playerOne.hp << std::endl;
		std::cout << "Player two hitpoints: " << playerTwo.hp << std::endl;

		if (playerOne.hp <= 0)
		{
			losingPlayer = playerOne.playerName;
			winPlayer = playerTwo.playerName;
		}
		else if (playerTwo.hp <= 0)
		{
			losingPlayer = playerTwo.playerName;
			winPlayer = playerOne.playerName;
		}
	}

	std::cout << winPlayer << " wins!" << std::endl;
	std::cout << losingPlayer << " lost" << std::endl;
	std::cin.get();
}