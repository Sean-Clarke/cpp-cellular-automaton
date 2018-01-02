#include <string>
#include "Grid.h"

class CellGame {
private:
	Grid grid;
	void update_game();
	void run_game(int cycles, float delay);
public:
	CellGame(int size);
	std::string get_input();
	bool process_input(std::string input);
	void draw_game();
};