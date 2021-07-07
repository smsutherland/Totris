#pragma once

#include <algorithm>

#include "FixedSizeQueue.h"

#define TetraminoO 0
#define TetraminoI 1
#define TetraminoT 2
#define TetraminoL 3
#define TetraminoJ 4
#define TetraminoS 5
#define TetraminoZ 6
#define TetraminoNone 7

typedef unsigned char Tetramino;

class BagQueue {
private:
	FixedSizeQueue<Tetramino> queue;
	Tetramino hold;
	FixedSizeQueue<Tetramino> nextBag;

	void fillQueue();
	void addPiece();
	void fillNextBag();
public:
	BagQueue();

	Tetramino* getQueue();
	Tetramino getHold();
	Tetramino dequeue();
	Tetramino switchHold(Tetramino newHold);
};
