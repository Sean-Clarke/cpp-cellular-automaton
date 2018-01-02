#include <iostream>
#include <sstream>
#include <Windows.h>
#include "CellGame.h"

using namespace std;

CellGame::CellGame(int size):grid (Grid(size, size)) {
}

void CellGame::draw_game() {
	grid.draw_cells();
}

void CellGame::update_game() {
	grid.update_cells();
	draw_game();
}

void CellGame::run_game(int cycles, float delay) {
	int cycles_left = cycles;
	while (cycles_left > 0) {
		update_game();
		cycles_left -= 1;
		Sleep(delay);
	}
}

string CellGame::get_input() {
	string input;
	getline(cin, input);
	return input;
}

bool CellGame::process_input(string input) {
	char command = input[0];
	if (command == 'a') {
		string args = input.substr(input.find_first_of(" ") + 1);
		string sxpos = args.substr(0, args.find_first_of(" "));
		string sypos = args.substr(args.find_first_of(" ") + 1);
		int xpos;
		int ypos;
		stringstream ssx(sxpos);
		ssx >> xpos ? xpos : 0;
		stringstream ssy(sypos);
		ssy >> ypos ? ypos : 0;
		grid.activate_cell(xpos, ypos);
		draw_game();
	}
	if (command == 'd') {
		string args = input.substr(input.find_first_of(" ") + 1);
		string sxpos = args.substr(0, args.find_first_of(" "));
		string sypos = args.substr(args.find_first_of(" ") + 1);
		int xpos;
		int ypos;
		stringstream ssx(sxpos);
		ssx >> xpos ? xpos : 0;
		stringstream ssy(sypos);
		ssy >> ypos ? ypos : 0;
		grid.deactivate_cell(xpos, ypos);
		draw_game();
	}
	if (command == 's') {
		string args = input.substr(input.find_first_of(" ") + 1);
		string scycles = args.substr(0, args.find_first_of(" "));
		string sdelay = args.substr(args.find_first_of(" ") + 1);
		int cycles;
		float delay;
		stringstream ssc(scycles);
		ssc >> cycles ? cycles : 0;
		stringstream ssd(sdelay);
		ssd >> delay ? delay : 0.0;
		run_game(cycles, delay);
	}
	if (command == 'r') {
		grid.randomize();
		draw_game();
	}
	if (command == 'c') {
		grid.clear_grid();
		draw_game();
	}
	if (command == '$') {
		grid.clear_grid();
		grid.activate_cell(8, 9);
		grid.activate_cell(8, 10);
		grid.activate_cell(8, 11);
		grid.activate_cell(8, 13);
		grid.activate_cell(8, 14);
		grid.activate_cell(8, 15);
		grid.activate_cell(9, 9);
		grid.activate_cell(10, 9);
		grid.activate_cell(9, 15);
		grid.activate_cell(10, 15);
		grid.activate_cell(11, 10);
		grid.activate_cell(11, 14);
		grid.activate_cell(12, 11);
		grid.activate_cell(12, 12);
		grid.activate_cell(12, 13);
		draw_game();
	}
	if (command == 'q') {
		return false;
	}
	return true;
}

int main() {
	CellGame CELL_GAME = CellGame(30);
	
	cout << "You have started playing a game!" << endl;
	CELL_GAME.draw_game();

	cout << "Enter 'a x y' to activate cell at grid position x y" << endl;
	cout << "Enter 'd x y' to deactivate cell at grid position x y" << endl;
	cout << "Enter 's n d' to iterate n game cycles with d milliseconds between each cycle" << endl;
	cout << "Enter 'r' to initialize a random game seed" << endl;
	cout << "Enter 'c' to deactivate all cells" << endl;
	cout << "Enter 'g' to create a glider on an otherwise empty grid" << endl;
	cout << "Enter 'p' to create a pulsar on an otherwise empty grid" << endl;
	cout << "Enter '$' to create a spaceship on an otherwise empty grid" << endl;
	cout << "Enter 'q' to stop playing." << endl;
	while (true) {
		string user_input = CELL_GAME.get_input();
			if (!CELL_GAME.process_input(user_input)) {
				break;
			}
	}
	cout << "Thank you for playing!" << endl;

}