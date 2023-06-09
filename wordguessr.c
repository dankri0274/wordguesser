#include <stdio.h>
#include <string.h>

int main() {
	int counter = 0;
	char answer[128];
	char guessedLetters[29];

	printf("\e[1;1H\e[2J");
	printf("Enter a word for opponent to guess (no capital letters): ");
	scanf(" %s", answer);

	int N = strlen(answer);
	int mask[N];

	for (int i = 0; i < N; i++) {
		mask[i] = 0;
	}

	int gameOver = 0;

	while (!gameOver) {
		printf("\e[1;1H\e[2J"); // Clear screen
		printf("The word is: ");
		for (int i = 0; i < N; i++) {
			if (mask[i]) {
				printf("%c", answer[i]);
			}
			else {
				printf("*");
			}
		}

		printf("\nGuessed letters: ");
		for (int i = 0; i < strlen(guessedLetters); i++) {
			printf("%c ", guessedLetters[i]);
		}

		printf("\n");

		char guess;

		printf("Letter? ");
		scanf(" %c", &guess);

		// guessedLetters[counter] = guess;

		for (int i = 0; i < strlen(guessedLetters); i++) {
			if (guessedLetters[i] == guess) {
				printf("You have alreday guessed %c", guess);
				sleep(3);
				guessedLetters[strlen(guessedLetters)] = '\0';
			}
		}

		guessedLetters[counter] = guess;
		counter++;

		for (int i = 0; i < N; i++) {
			if (answer[i] == guess) {
				mask[i] = 1;
			}
		}

		gameOver = 1;
		for (int i = 0; i < N; i++) {
			if (!mask[i]) {
				gameOver = 0;
				break;
			}
		}
	}

	printf("\e[1;1H\e[2J");
	printf("Victory, the word is \"%s\".\n", answer);

	return 0;
}
