#include <map>

class Grid {
private:
	int width;
	int height;
	std::map<std::pair<int, int>, std::pair<bool, bool>> cells;
	bool get_active(int x, int y);
	bool get_next(int x, int y);
	int get_count_active_neighbours(int x, int y);
	void update_cell_next(int x, int y);
	void update_cell_active(int x, int y);
public:
	Grid(int width, int height);
	void activate_cell(int x, int y);
	void deactivate_cell(int x, int y);
	void update_cells();
	void clear_grid();
	void randomize();
	void draw_cells();
};