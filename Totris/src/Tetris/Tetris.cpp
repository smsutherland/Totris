#include "Tetris.h"

Tetris::Tetris() {
	gravity = 1.0f;
	setCurrentTetramino(queue.dequeue());
}

Tetris::Tetris(const Tetris& other) {
	board = other.board;
}

Tetris& Tetris::operator=(const Tetris& rhs) {
	board = rhs.board;
	return *this;
}

void Tetris::pollKeys(GLFWwindow* window) {
	for (int i = 0; i < 8; i++) {
		int keyState = glfwGetKey(window, controlScheme[i]);
		if (keyState == GLFW_PRESS) {
			currentButtons |= (1 << i);
		}
		else if (keyState == GLFW_RELEASE) {
			currentButtons &= ~(1 << i);
			processedPresses &= ~(1 << i);
		}
	}
}

void Tetris::nextFrame(GLFWwindow* window, float timeStep) {
	pollKeys(window);
	computeFrame(timeStep);
	renderFrame();
}

void Tetris::computeFrame(float timeStep) {
	if (currentButtons & (1 << CW_ROT) && !(processedPresses & (1 << CW_ROT))) {
		activePiece->rotate(ROTATE_CW);
		processedPresses |= (1 << CW_ROT);
	}
	else if (currentButtons & (1 << ONE_EIGHTY_ROT) && !(processedPresses & (1 << ONE_EIGHTY_ROT))) {
		activePiece->rotate(ROTATE_ONE_EIGHTY);
		processedPresses |= (1 << ONE_EIGHTY_ROT);
	}
	else if (currentButtons & (1 << CCW_ROT) && !(processedPresses & (1 << CCW_ROT))) {
		activePiece->rotate(ROTATE_CCW);
		processedPresses |= (1 << CCW_ROT);
	}
	if (currentButtons & (1 << HD) && !(processedPresses & (1 << HD))) {
		cycleTetramino();
		processedPresses |= (1 << HD);
	}
	if (currentButtons & (1 << Hold) && !(processedPresses & (1 << Hold))) {
		Tetramino prevHold = hold;
		hold = activePiece->getPiece();
		if (prevHold != TetraminoNone) {
			activePiece = createActivePiece(prevHold);
		}
		else {
			cycleTetramino();
		}
		processedPresses |= (1 << Hold);
	}
}

void Tetris::setCurrentTetramino(Tetramino newCurrentTetramino) {
	delete activePiece;
	activePiece = createActivePiece(newCurrentTetramino);
}

ActivePiece* Tetris::createActivePiece(Tetramino pieceName) {
	switch (pieceName) {
	case TetraminoO:
		return new ActivePieceO();
	case TetraminoI:
		return new ActivePieceI();
	case TetraminoT:
		return new ActivePieceT();
	case TetraminoL:
		return new ActivePieceL();
	case TetraminoJ:
		return new ActivePieceJ();
	case TetraminoS:
		return new ActivePieceS();
	case TetraminoZ:
		return new ActivePieceZ();
	case TetraminoNone:
	default:
		break;
	}
	return nullptr;
}

void Tetris::renderFrame() {
	if(activePiece != nullptr)
		activePiece->render();



	board.render();
}

void Tetris::cycleTetramino() {
	setCurrentTetramino(queue.dequeue());
}

void Tetris::rotate() {
	activePiece->rotate(ROTATE_CCW);
}
