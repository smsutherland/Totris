#pragma once

#include "BagQueue.h"
#include "MinoRenderer.h"
#include "Board.h"

#define ROTATE_CW 1
#define ROTATE_ONE_EIGHTY 2
#define ROTATE_CCW 3

class ActivePiece {
protected:
	Tetramino piece;
	unsigned char rotationState;

	float x, y;

	virtual float* getOffsets();
	virtual glm::vec3 getColor() = 0;
	virtual float* getRotationOffsets(unsigned char rotationState, int rotation) = 0;
	void rotateOffsets(float*);
public:
	ActivePiece(Tetramino piece_ = TetraminoNone, float x_ = 4.0f, float y_ = 20.0f) : piece(piece_), rotationState(0), x(x_), y(y_) {}
	virtual ~ActivePiece() = 0 {};

	void render();
	void rotate(int rotation, Board board);
	Tetramino getPiece() { return piece; }
};

class ActivePieceO : public ActivePiece {
private:
public:
	ActivePieceO() : ActivePiece(TetraminoO, 4.5f, 20.5f) {}
	float* getOffsets() override;
	glm::vec3 getColor() override;
	float* getRotationOffsets(unsigned char rotationState, int rotation) override;
};

class ActivePieceI : public ActivePiece {
private:
public:
	ActivePieceI() : ActivePiece(TetraminoI, 4.5f, 19.5f) {}
	float* getOffsets() override;
	glm::vec3 getColor() override;
	float* getRotationOffsets(unsigned char rotationState, int rotation) override;
};

class ActivePieceT : public ActivePiece {
private:
public:
	ActivePieceT() : ActivePiece(TetraminoT) {}
	float* getOffsets() override;
	glm::vec3 getColor() override;
	float* getRotationOffsets(unsigned char rotationState, int rotation) override;
};

class ActivePieceL : public ActivePiece {
private:
public:
	ActivePieceL() : ActivePiece(TetraminoL) {}
	float* getOffsets() override;
	glm::vec3 getColor() override;
	float* getRotationOffsets(unsigned char rotationState, int rotation) override;
};

class ActivePieceJ : public ActivePiece {
private:
public:
	ActivePieceJ() : ActivePiece(TetraminoJ) {}
	float* getOffsets() override;
	glm::vec3 getColor() override;
	float* getRotationOffsets(unsigned char rotationState, int rotation) override;
};

class ActivePieceS : public ActivePiece {
private:
public:
	ActivePieceS() : ActivePiece(TetraminoS) {}
	float* getOffsets() override;
	glm::vec3 getColor() override;
	float* getRotationOffsets(unsigned char rotationState, int rotation) override;
};

class ActivePieceZ : public ActivePiece {
private:
public:
	ActivePieceZ() : ActivePiece(TetraminoZ) {}
	float* getOffsets() override;
	glm::vec3 getColor() override;
	float* getRotationOffsets(unsigned char rotationState, int rotation) override;
};
