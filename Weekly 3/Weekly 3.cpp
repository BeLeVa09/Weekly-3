#include <iostream>
#include <string>
#include <vector>

struct HighScore {
	std::string name{ 0 };
	int guessAmount{ 0 };
};

void game(int upperLimit) {
	system("cls");

	static std::string name{ " " };
	int nameValue{ 0 };
	int number{ std::rand() };

	std::cout << "What is your name? (For the HighScore board)\n";
	std::cin >> name;
	
	for (int i{ 0 }; i < name.size(); i++) {
		nameValue += name[i];
		number = number % name[i];
		number *= nameValue;
	}
	number = number % upperLimit;
	
	std::cout << "A number from 0 to " << upperLimit << " has been chosen\n";
	std::cout << "Can you guess which number it is?\n";

	static int guessAmount{ 1 };
	int choice{ 0 };

	do {

		std::cin >> choice;

		if (choice == number) {
			std::cout << "Correct! The number was " << number << '\n';
			std::cout << "You got it in " << guessAmount << " tries!\n";
			system("pause");
		} else if (choice > number) {
			std::cout << "Too high\n";
			std::cout << "Try again: ";
			guessAmount++;
		}
		else {
			std::cout << "Too low\n";
			std::cout << "Try again: ";
			guessAmount++;
		}
	} while (choice != number);
	std::vector <HighScore> playerScore{ name, guessAmount };
}

int options() {
	std::cout << "Choose a number to be the upper limit of number generation: ";

	int chosenLimit{ 0 };
	std::cin >> chosenLimit;

	return chosenLimit;
}

void menu() {
	bool stay{ 1 };
	int upperLimit{ 10 };

	do {
		system("cls");

		std::cout << "	 _____ _   __ _____ _____ _____     _____ _   _  _____     _   _ _   ____  _________ ___________  \n";
		std::cout << "	|  __ \\ | |  |  ___/ ____/ ____|   |_   _| | | ||  ___|   | \\ | | | | |  \\/  || ___ \\  ___| ___ \\ \n";
		std::cout << "	| |  \\/ | |  | |__ \\ `--.\\ `--.      | | | |_| || |__     |  \\| | | | | .  . || |_/ / |__ | |_/ / \n";
		std::cout << "	| | __| | |  |  __| `--. \\`--. \\     | | |  _  || __|     | . ` | | | | |\\/| || ___ \\  __||    /  \n";
		std::cout << "	| |_\\ \\ |_|  | |___/ \\_/ /\\__/ /     | | | | | || |___    | |\\  | |_| | |  | || |_/ / |___| |\\ \\  \n";
		std::cout << "	\\_____/\\___ /\\____/\\____/\\____/      \\_/ \\_| |_/\\____/    \\_| \\_/\\___/\\_|  |_/\\____/\\____/\\_| \\_| \n\n";
		std::cout << "						1. Play Game\n";
		std::cout << "						2.  Options\n";
		std::cout << "						3.   Exit\n\n";

		int input{ 0 };
		std::cin >> input;

		switch (input) {
		case 1:
			game(upperLimit);
			break;

		case 2:
			upperLimit = options();
			break;

		case 3:
			stay = 0;
			break;

		default:
			std::cout << "Invalid Input!\n";
			break;
		}
	} while (stay == 1);
}

int main() {
	std::srand(82615);
	menu();

	return 0;
}
