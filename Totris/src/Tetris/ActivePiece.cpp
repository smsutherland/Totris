#include "ActivePiece.h"

void ActivePiece::render() {
	float* offsets = getOffsets();
	rotateOffsets(offsets);

	MinoRenderer renderer;
	for (int i = 0; i < 8; i += 2) {
		float xOffset = offsets[i];
		float yOffset = offsets[i + 1];
		renderer.registerMino(getColor(), x + xOffset, y + yOffset);
	}
	renderer.renderMinos();

	delete offsets;
}

void ActivePiece::rotateOffsets(float* offsets) {
	auto cos = [](unsigned short rotationState) -> int { return (rotationState % 2 == 0) * (rotationState == 2 ? -1 : 1); };
	auto sin = [](unsigned short rotationState) -> int { return (rotationState % 2 == 1) * (rotationState == 3 ? -1 : 1); };
	unsigned char CCWRotationState = 4 - rotationState;
	for (int i = 0; i < 8; i += 2) {
		float xOffset = offsets[i];
		float yOffset = offsets[i + 1];
		offsets[i] = xOffset * cos(CCWRotationState) - yOffset * sin(CCWRotationState);
		offsets[i + 1] = xOffset * sin(CCWRotationState) + yOffset * cos(CCWRotationState);
	}
}

void ActivePiece::rotate(int rotation, Board board) {
	unsigned char testRotationState = (rotationState + rotation % 4);
	//rotationState += rotation;
	//rotationState %= 4;


}

float* ActivePiece::getRotationOffsets(unsigned char rotationState, int rotation) {
	//if(rotationState == 0 && rotation == 1)
	float offsetsStack[] = {
	-0.5f, -0.5f,
	 0.5f, -0.5f,
	 0.5f,  0.5f,
	-0.5f, 0.5f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

float* ActivePieceO::getOffsets() {
	float offsetsStack[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f, 0.5f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

glm::vec3 ActivePieceO::getColor() {
	return glm::vec3(1.0f, 1.0f, 0.0f);
}

float* ActivePieceI::getOffsets() {
	float offsetsStack[] = {
		-1.5f, 0.5f,
		-0.5f, 0.5f,
		 0.5f, 0.5f,
		 1.5f, 0.5f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

glm::vec3 ActivePieceI::getColor() {
	return glm::vec3(0.0f, 1.0f, 1.0f);
}

float* ActivePieceT::getOffsets() {
	float offsetsStack[] = {
		 0.0f,  0.0f,
		-1.0f,  0.0f,
		 0.0f,  1.0f,
		 1.0f,  0.0f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

glm::vec3 ActivePieceT::getColor() {
	return glm::vec3(0.5f, 0.0f, 1.0f);
}

float* ActivePieceL::getOffsets() {
	float offsetsStack[] = {
		 0.0f,  0.0f,
		-1.0f,  0.0f,
		 1.0f,  0.0f,
		 1.0f,  1.0f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

glm::vec3 ActivePieceL::getColor() {
	return glm::vec3(1.0f, 0.5f, 0.0f);
}

float* ActivePieceJ::getOffsets() {
	float offsetsStack[] = {
		 0.0f,  0.0f,
		-1.0f,  0.0f,
		-1.0f,  1.0f,
		 1.0f,  0.0f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

glm::vec3 ActivePieceJ::getColor() {
	return glm::vec3(0.0f, 0.0f, 1.0f);
}

float* ActivePieceS::getOffsets() {
	float offsetsStack[] = {
		 0.0f,  0.0f,
		-1.0f,  0.0f,
		 0.0f,  1.0f,
		 1.0f,  1.0f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

glm::vec3 ActivePieceS::getColor() {
	return glm::vec3(0.0f, 1.0f, 0.0f);
}

float* ActivePieceZ::getOffsets() {
	float offsetsStack[] = {
		 0.0f,  0.0f,
		-1.0f,  1.0f,
		 0.0f,  1.0f,
		 1.0f,  0.0f
	};
	float* offsets = new float[8];
	memcpy(offsets, offsetsStack, 8 * sizeof(float));
	return offsets;
}

glm::vec3 ActivePieceZ::getColor() {
	return glm::vec3(1.0f, 0.0f, 0.0f);
}
