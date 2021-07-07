#include "Board.h"

Board::Board(unsigned int width_, unsigned int height_, unsigned int bufferheight_) {
	width = width_;
	height = height_;
	bufferHeight = bufferheight_;

	board = new Color[width*(height + bufferHeight)];
	for (int i = 0; i < width * (height + bufferHeight); i++)
		board[i] = 0;
}

Board::Board(const Board& other) {
	width = other.width;
	height = other.height;
	bufferHeight = other.bufferHeight;

	board = new Color[width * (height + bufferHeight)];
	for (int i = 0; i < width * (height + bufferHeight); i++) {
		board[i] = other.board[i];
	}
}

Board& Board::operator=(const Board& rhs) {
	width = rhs.width;
	height = rhs.height;
	bufferHeight = rhs.bufferHeight;

	board = new Color[width * (height + bufferHeight)];
	for (int i = 0; i < width * (height + bufferHeight); i++) {
		board[i] = rhs.board[i];
	}
	return *this;
}

Board::~Board() {
	delete[] board;
}

void Board::render() {
	MinoRenderer minoRenderer;
	for (int i = 0; i < width * (height + bufferHeight); i++) {
		if (board[i]) {
			minoRenderer.registerMino(glm::vec3(board[i]/1000.0f, 0.0f, 0.0f), i%width, i/width);
		}
	}
	minoRenderer.renderMinos();
}