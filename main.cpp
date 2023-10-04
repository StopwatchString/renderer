#include <iostream>

const int WIDTH = 6;
const int HEIGHT = 6;

class Color {
public:
	uint8_t _red;
	uint8_t _green;
	uint8_t _blue;

	Color() {
		_red = 0;
		_green = 0;
		_blue = 0;
	}

	Color(uint8_t red, uint8_t green, uint8_t blue) {
		_red = red;
		_green = green;
		_blue = blue;
	}

	void scaleIntensity(float scale) {
		if (scale < 0) return;
		short newRed = _red * scale;
		if (newRed > 255) {
			_red = 255;
		}
		else {
			_red = newRed;
		}
		short newGreen = _green * scale;
		if (newGreen > 255) {
			_green = 255;
		}
		else {
			_green = newGreen;
		}
		short newBlue = _blue * scale;
		if (newBlue > 255) {
			_blue = 255;
		}
		else {
			_blue = newBlue;
		}
	}
	
private:

};

class Canvas {
public:
	Canvas() {
		for (int x = 0; x < WIDTH; x++) {
			for (int y = 0; y < HEIGHT; y++) {
				canvas[x][y] = Color();
			}
		}
	}

	void putPixel(int x, int y, Color color) {
		canvas[convertXCoordinate(x)][convertYCoordinate(y)] = color;
	}

	void printCanvas() {
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				Color c = canvas[x][y];
				std::cout << "(" << c._red << ":" << c._green << ":" << c._blue << ") ";
			}
			std::cout << std::endl;
		}
	}

	int getWidth() { return WIDTH; }
	int getHeight() { return HEIGHT; }

private:
	Color canvas[WIDTH][HEIGHT];

	int convertXCoordinate(int x) {
		int converted = x + WIDTH / 2;
		if (converted >= WIDTH) {
			converted = WIDTH - 1;
		}
		return converted;
		
	}
	int convertYCoordinate(int y) {
		int converted = HEIGHT / 2 - y;
		if (converted >= HEIGHT) {
			converted = HEIGHT - 1;
		}
		return converted; 
	}
};

int main() {
	Canvas canvas;
	Color green = Color(0, 0, 0);
	canvas.putPixel(0, 0, green);
	canvas.putPixel(0, 1, green);
	canvas.printCanvas();

	return 0;
}