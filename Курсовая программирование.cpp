#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

const int N = 4;

void computer_number(int *A);
char *number_to_string(int *A, char* comp);
char *person_number(char *B);
void congratulations(int *A);


int main() {
	int bulls, cows, i, j, k;
	char comp[N];
	int digits_number[N];
	char person[N];
	char number_1[N], number_2[N];
	
	computer_number(digits_number);
	char *word_1 = number_to_string(digits_number, comp);
	for (i = 0; i < N; i++) {
		number_1[i] = word_1[i];
	}
	cout << endl;

	do{
		cows = bulls = 0;
		char* word_2 = person_number(person);
		for (k = 0; k < N; k++) {
			number_2[k] = word_2[k];
		}
		cout << endl;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (number_1[i] == number_2[j]) {
					if (i == j) {
						bulls++;
					}
					else {
						cows++;
					}
				}		
			}
		}
		cout << endl << "Bulls = " << bulls << endl << "Cows = " << cows << endl;
	}while (bulls != 4);

	congratulations(digits_number);
	
	return 0;
}

void computer_number(int *A) {
	cout << "Loading..." << endl;
m:

	int i = N-1;
	srand(time(0));
	Sleep(1000);

	for (i = 0; i < N; i++) {
		A[i] = rand() % (9 - 0 + 1) + 0;
	}
	

	while (1) {
		if ((A[0] != A[1]) && (A[0] != A[2]) && (A[0] != A[3]) && (A[1] != A[2]) && (A[1] != A[3]) && (A[2] != A[3])) {
			break;
		}
		else {
			goto m;
		}
	}

	cout << endl << "Number has created successfully!" << endl;
}


char* number_to_string(int *A, char* comp) {
	int i;
	static char computer[N];

	for (i = 0; i < N; i++) {
		computer[i] = A[i] + '0';
	}
	cout << endl;
	return computer;
}

char* person_number(char *B) {
	int i, len = 0;
	char num[N+50];
	static char per_number[N];

m:
		i = 0;
		cout << "Enter your number: " << endl;
		gets(num);
		len = strlen(num);
		if (len != 4) {
			cout << endl << "Enter right number!" << endl;
			goto m;
		}
		while (i < N) {
			per_number[i] = num[i];
			i++;
		}
		
		if ((per_number[0] == per_number[1]) || (per_number[0] == per_number[2]) || (per_number[0] == per_number[3]) || (per_number[1] == per_number[2]) || (per_number[1] == per_number[3]) || (per_number[2] == per_number[3])) {
			cout << endl << "Enter right number!" << endl;
			goto m;
		}
		return per_number;
}


void congratulations(int *A) {
	cout << endl << "Congratulations! You guessed the number! And it was: " << endl;
	cout << "============" << endl;
	for (int i = 0; i < N; i++) {
		cout << "|" << A[i] << "|";
	}
	cout << endl << "============";
	cout << endl;
}
