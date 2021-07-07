#include "BagQueue.h"

BagQueue::BagQueue() : queue(5), nextBag(7) {
	hold = TetraminoNone;
	fillQueue();
}

Tetramino* BagQueue::getQueue() {
	return queue.getData();
}

Tetramino BagQueue::getHold() {
	return hold;
}

Tetramino BagQueue::dequeue() {
	return queue.dequeue();
	addPiece();
}

Tetramino BagQueue::switchHold(Tetramino newHold) {
	Tetramino temp = hold;
	hold = newHold;
	return temp;
}

void BagQueue::fillQueue() {
	while (!queue.isFull())
		addPiece();
}

void BagQueue::addPiece() {
	queue.enqueue(nextBag.dequeue());
	if (nextBag.isEmpty())
		fillNextBag();
}

void BagQueue::fillNextBag() {
	int unsortedBag[] = { 0, 1, 2, 3, 4, 5, 6 };
	std::random_shuffle(std::begin(unsortedBag), std::end(unsortedBag));
	for (int i = 0; i < 7; i++)
		nextBag.enqueue(unsortedBag[i]);
}
