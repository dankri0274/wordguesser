#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

bool isDuplicate(char* guessedLetters, int counter, char guess) {
	for (int i = 0; i < counter; i++) {
		if (guessedLetters[i] == guess) {
			return true;
		}
	}
	return false;
}

void sleepFor(int milliseconds) {
#ifdef _WIN32
	Sleep(milliseconds);
#else
	usleep(milliseconds * 1000);
#endif
}

int main() {
	char answer[128];
	char guessedLetters[29] = {'\0'};  // Initialize guessedLetters array

	printf("\e[1;1H\e[2J");
	printf("Enter a word for opponent to guess (no capital letters): ");
	scanf("%127s", answer);  // Limit input length to prevent buffer overflow

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

		printf("\nGuessed letters: %s\n", guessedLetters);

		char guess;

		printf("Letter? ");
		scanf(" %c", &guess);

		int counter = strlen(guessedLetters);
		if (isDuplicate(guessedLetters, counter, guess)) {
			printf("You have already guessed %c\n", guess);
			sleepFor(3000); // Sleep for 3 seconds
		} else {
			guessedLetters[counter] = guess;
			guessedLetters[counter + 1] = '\0';
			counter++;
		}

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
