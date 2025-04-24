#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::vector numericShift{ ')', '!', '\"', '#', '$', '%', '^', '&','*', '(' };
	while (1) {

		bool shift = GetKeyState(VK_SHIFT) < 0;
		bool caps = (GetKeyState(VK_CAPITAL) & 1) == 1;
		for (int i = 'A'; i <= 'Z'; ++i) {
			if (GetKeyState(i) < 0) {
				std::cout << (shift ^ caps ? static_cast<char>(i) : static_cast<char>(i | 0x20));
				Sleep(80);
				break;
			}

		}

		if (GetKeyState(VK_SPACE) < 0) {
			std::cout << " ";
			Sleep(80);
			continue;
		}
		if (GetKeyState(VK_RETURN) < 0) {
			std::cout << "\n";
			Sleep(80);
			continue;
		}

		for (int i = '0'; i <= '9'; ++i) {
			if (GetKeyState(i) < 0) {
				std::cout << (shift ? static_cast<char>(numericShift.at(i - '0')) : static_cast<char>(i));
				Sleep(80);
				break;
			}

		}

		Sleep(20);

	}

}
