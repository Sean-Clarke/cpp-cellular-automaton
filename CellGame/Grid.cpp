#include <iostream>
#include "Grid.h"

using namespace std;

Grid::Grid(int width, int height):width(width), height(height) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			cells[make_pair(x, y)] = make_pair(false, false);
		}
	}
}

bool Grid::get_active(int x, int y) {
	if (cells.count(make_pair(x, y)) == 1) {
		pair<bool, bool> states = cells[make_pair(x, y)];
		bool active = states.first;
		return active;
	}
	return false;
}

bool Grid::get_next(int x, int y) {
	if (cells.count(make_pair(x, y)) == 1) {
		pair<bool, bool> states = cells[make_pair(x, y)];
		bool next = states.second;
		return next;
	}
	return false;
}

int Grid::get_count_active_neighbours(int x, int y) {
	int count = 0;
	if (get_active(x + 1, y)) {
		count += 1;
		}
	if (get_active(x + 1, y + 1)) {
		count += 1;
		}
	if (get_active(x, y + 1)) {
		count += 1;
		}
	if (get_active(x - 1, y + 1)) {
		count += 1;
		}
	if (get_active(x - 1, y)) {
		count += 1;
		}
	if (get_active(x - 1, y - 1)) {
		count += 1;
		}
	if (get_active(x, y - 1)) {
		count += 1;
		}
	if (get_active(x + 1, y - 1)) {
		count += 1;
		}
	return count;
}

void Grid::update_cell_next(int x, int y) {
	if (get_active(x, y)) {
		int active_neighbours = get_count_active_neighbours(x, y);
		if ((active_neighbours == 2) || (active_neighbours == 3)) {
			cells[make_pair(x, y)] = make_pair(true, true);
		}
		else {
			cells[make_pair(x, y)] = make_pair(true, false);
		}
		return;
	}
	else if (!get_active(x, y)) {
		int active_neighbours = get_count_active_neighbours(x, y);
		if (active_neighbours == 3) {
			cells[make_pair(x, y)] = make_pair(false, true);
		}
		else {
			cells[make_pair(x, y)] = make_pair(false, false);
		}
	}
}

void Grid::update_cell_active(int x, int y) {
	if (get_next(x, y)) {
		activate_cell(x, y);
		return;
	}
	else if (!get_next(x, y)) {
		deactivate_cell(x, y);
		return;
	}
}

void Grid::activate_cell(int x, int y) {
	cells[make_pair(x, y)] = make_pair(true, false);
}

void Grid::deactivate_cell(int x, int y) {
	cells[make_pair(x, y)] = make_pair(false, false);
}

void Grid::update_cells() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			update_cell_next(x, y);
		}
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			update_cell_active(x, y);
		}
	}

}

void Grid::clear_grid() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			deactivate_cell(x, y);
		}
	}
}

void Grid::randomize() {
 // Add implementation for
}

void Grid::draw_cells() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (get_active(x, y)) {
				cout << "X ";
			}
			else if (!get_active(x, y)) {
				cout << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
