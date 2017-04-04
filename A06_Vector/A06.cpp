#include<vector>
#include <string>

//1;
int main() {
	enum class Nom
	{
		Gertrudiz,Pancracia,Anacleto,Hipolito,Eustaquio,Fulgencia,Maxim
	};
	struct persona
	{
		std::string nom;
		//int ran = rand() % static_cast<int>(Nom::Maxim);
		switch (rand() % static_cast<int>(Nom::Maxim))
		{
		case 0:
			std::string nom = Gertrudiz;
			break;
		case 1:
			std::string nom = Pancracia;
			break;
		case 2:
			std::string nom = Anacleto;
			break;
		case 3:
			std::string nom = hipolito;
			break;
		case 4:
			std::string nom = Eustaquio;
			break;
		case 5:
			std::string nom = Fulgencia;
			break;
		default:
			break;
		}
		int dia = rand() % 30;
		int mes = rand() % 12;
		int any = rand() % 30 + 1985;
		int dni = 39421671;
	};
	std::vector<int>v1{ 5 };
	std::vector<int>v2(10);
	std::vector<int>v3{ 10,9,8,7,6,5,4,3,2,1 };
	std::vector<std::string>v4{ "Gertrudiz", "Pancracia", "Anacleto", "Hipolito", "Eustaquio", "Fulgencia" };
	std::vector<int>v5{v3};

	std::vector<persona>v6{3};
	
	
 }