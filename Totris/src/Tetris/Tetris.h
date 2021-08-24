#pragma once

#include "Renderer/Renderer.h"
#include "Board.h"
#include "BagQueue.h"
#include "ActivePiece.h"
#include <GLFW/glfw3.h>

// Controls (for use in controlScheme array):
#define LEFT 0
#define RIGHT 1
#define CW_ROT 2
#define CCW_ROT 3
#define ONE_EIGHTY_ROT 4
#define HD 5
#define SD 6
#define Hold 7

class Tetris {
private:
	Board board;

	void computeFrame(float timeStep);
	void renderFrame();
	void pollKeys(GLFWwindow* window);

	BagQueue queue;
	ActivePiece* activePiece;
	Tetramino hold = TetraminoNone;

	float gravity;
	int controlScheme[8] {
		GLFW_KEY_LEFT,
		GLFW_KEY_RIGHT,
		GLFW_KEY_D,
		GLFW_KEY_A,
		GLFW_KEY_S,
		GLFW_KEY_SPACE,
		GLFW_KEY_DOWN,
		GLFW_KEY_LEFT_SHIFT
	};
	unsigned char currentButtons = 0;
	unsigned char processedPresses = 0;

	void setCurrentTetramino(Tetramino newCurrentTetramino);
	ActivePiece* createActivePiece(Tetramino pieceName);

public:
	Tetris();
	Tetris(const Tetris& other);
	Tetris& operator=(const Tetris& rhs);
	~Tetris() { delete activePiece; }

	void nextFrame(GLFWwindow* window, float timeStep);


	void cycleTetramino();
	void rotate();
};