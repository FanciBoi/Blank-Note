#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
using namespace std;

const string KEY_LIST = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";

void initial();
void puzzle();

string matrix(string); 
char bitmove(char, int);

void setfontsize(int, int);

int main() {
	initial();
	puzzle();
	return 0;
} 

void initial() {
	srand((unsigned)time(0));
	
	setfontsize(10, 20);
	system("mode con:cols=30 lines=15");
}

void puzzle() {
	string os;
	cout << "ur string pls: ";
	cin >> os;
	
	string ans = matrix(os);
//	cout << ans;

	string input;
	cin >> input;
	
	if (input == ans) {
		cout << "Correct!";
	} else {
		while (input != ans) {
			cout << "Incorrect! Pls try again\n";
			cin >> input;
		}
		cout << "Correct!";
	}
}

string matrix(string os) {
	bool coluse[15];
	memset(coluse, false, sizeof(coluse));
	
	int key = rand() % 6;
	string ps;
	
	string ans = "";
	
	for(int i = 0; i < os.size(); i++) {
		ps[i] = bitmove(os[i], key);
		
		int pernum = rand() % (os.size() - i) + 1;
		int choice, count = 0;
		for (int j = 1; j <= os.size(); j++) {
			if (!coluse[j]) {
				count++;
				if (count == pernum) {
					choice = j;
					coluse[choice] = true;
				}
			}
		}
		
		for (int j = 1; j <= os.size(); j++) {
			if (j == choice) {
				cout << ps[i];
			} else {
				cout << KEY_LIST[rand() % 62];
			}
		}
		cout << '\n';
		
		ans += (choice + '0');
	}
	return ans;
}

char bitmove(char c, int key) {
	for (int i = 0; i < 62; i++) {
		if (KEY_LIST[i] == c) {
			return KEY_LIST[i + key];
		}
	} 
}

void setfontsize(int x, int y) {
	CONSOLE_FONT_INFOEX cfi;
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	cfi.nFont = 0;
	cfi.dwFontSize.X = x;
	cfi.dwFontSize.Y = y;
	cfi.FontFamily = TMPF_VECTOR;
	cfi.FontWeight = 400;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
