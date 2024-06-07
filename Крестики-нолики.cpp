// Крестики-нолики.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 


char board[3][3]; // игровая доска 

// функция отображения доски на экране 
void drawBoard() {
	std::cout << "  1 2 3" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << " ";
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// функция проверки, выигрыша 
bool checkWin(char player) {
	// проверка по горизонтали 
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
			return true;
	}
	// проверка по вертикали 
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			return true;
	}
	// проверка по диагонали 
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return true;
	return false;
}

int main() {

	setlocale(LC_ALL, "RUS");
	int row, col;
	char currentPlayer = 'X';
	
	// заполнение игровой доски начальными значениями 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	
	// игровой цикл 
	while (true) {
		drawBoard();
		std::cout << "Ход игрока " << currentPlayer << std::endl;
		
		// ввод координат клетки 
		std::cout << "Введите номер строки: ";
		std::cin >> row;
		std::cout << "Введите номер столбца: ";
		std::cin >> col;
		
		// проверка введенных координат 
		if (row < 1 || row > 3 || col < 1 || col > 3) {
			std::cout << "Некорректные координаты! Попробуйте еще раз." << std::endl;
			continue;
		}
		if (board[row - 1][col - 1] != ' ') {
			std::cout << "Эта клетка уже занята! Попробуйте еще раз." << std::endl;
			continue;
		}
		
		// установка символа на доску 
		board[row - 1][col - 1] = currentPlayer;
		
		// проверка на выигрыш 
		if (checkWin(currentPlayer)) {
			drawBoard();
			std::cout << "Игрок " << currentPlayer << " выиграл!" << std::endl;
			break;
		}

		// проверка на ничью 
		bool boardFull = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == ' ') {
					boardFull = false;
					break;
				}
			}
			if (!boardFull)
				break;
		}
		if (boardFull) {
			drawBoard();
			std::cout << "Ничья!" << std::endl;
			break;
		}

		// смена игрока 
		currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
		
	}
	return 0;
}