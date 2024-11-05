#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int find_the_word(char* str);
char* Change(char* str, int n);

int main() {

	char* str = new char[31];
	cout << "enter the text" << endl;
	cin.getline(str, 30);

	int count = find_the_word(str);
	cout << "there are " << count << " words of \"while\"" << endl;

	cout << Change(str, count);
	return 0;
}
int find_the_word(char* str) {
	size_t len = strlen(str);
	if (len < 5) {
		cout << "not enough letters " << endl;
		return 0;
	}
	int count = 0;
	for (int i = 0; i <= len && i + 4 != '\0'; i++) {
		if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e') {
			count++;
		}
	}
	return count;
}

char* Change(char* str, int n) {
	size_t len = strlen(str);
	size_t new_len = len - 3 * n + 1;	//-3 * n тому що я 5 символів
	// заміняю на 2	

	char cr[3] = { '*', '*', '\0' };
	char* tmp = new char[new_len];

	tmp[0] = '\0';
	int i = 0;
	int t = 0;
	while(i < len) {
		if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e') {
			tmp[t++] = '*';
			tmp[t++] = '*';
			i += 5;
		}
		else {
			tmp[t++] = str[i++];;
		}

	}

	tmp[t] = '\0';

	cout << tmp << endl;

	return tmp;
}