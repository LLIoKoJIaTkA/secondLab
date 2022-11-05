#include <iostream>
#include "logic.hpp"

using namespace std;

char change;

void endOfProgram()
{
	cout << "Вы вышли из программы. Всего хоро-ше-го :)" << endl;
	system("pause");
	exit(0);
}

int main()
{
	setlocale(LC_ALL, "ru");

	creationSelection:

	cout << "Вы хотите создать новый класс?" << endl << "Если да, нажмите 'y', если нет, то 'n'" << endl;
	while (change != 'y' && change != 'n')
	{
		cin >> change;
		if (change == 'n')
			endOfProgram();
	}
	car* Car = new car;
	Car->create();
	int amount;

	while (true) {
		do
		{
			change = menu();
		} while (change < 1 || change > 9);
		switch (change)
		{
		case 1:
			Car->emptyCar();
			break;
		case 2:
			amount = Car->amountOfObjects();
			cout << "Существует " << amount << " объекта(ов) класса" << endl;
			break;
		case 3:
			Car->addAnObject();
			break;
		case 4:
			Car->insertAnObject();
			break;
		case 5:
			Car->deleteAnObject();
			break;
		case 6:
			Car->~car();
			goto creationSelection;
			break;
		case 7:
			Car->moveNext();
			break;
		case 8:
			Car->getCarInfo();
			break;
		default:
			endOfProgram();
			break;
		}
	}
	/*while (true)
	{
		std::cout << "char-----------------------:\n";
		char c;        cin_fool >> "c = " >> c;
		std::cout << "validator: " << c << "\n\n";

		std::cout << "unsigned char-----0,...,255:\n";
		unsigned char u; cin_fool >> "u = " >> u;
		std::cout << "validator: '" << u << "'\n\n";

		std::cout << "int------------------------:\n";
		int n;         cin_fool >> "n = " >> n;
		std::cout << "validator: " << n << "\n\n";

		std::cout << "float----------------------:\n";
		float f;       cin_fool >> "f = " >> f;
		std::cout << "validator: " << f << "\n\n";

		std::cout << "string----------------:\n";
		std::string s; cin_fool >> "s = " >> s;
		std::cout << "validator: " << s << "\n\n";
	}*/
}