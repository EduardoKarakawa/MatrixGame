#include "Tanque.h"
Tanque::Tanque()
{
	color.set(rand() % 255, rand() % 255, rand() % 255);
	position.set(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	direction.set(1.0f, 0);
}

void Tanque::Update(float &deltatime) {
	direction = Matrix3f(50.0f * deltatime).transform(direction);
}

void Tanque::Draw() {
	ofPushMatrix();
	ofTranslate(position);

	ofSetColor(color);
	ofDrawCircle(0, 0, RADIUS);

	ofSetColor(0, 0, 0);
	ofDrawRectangle(direction * RADIUS, TOWER_W, TOWER_H);

	ofPopMatrix();
}

bool Tanque::CheckCollision(ofVec2f position, float radius) {
	return this->position.distance(position) <= RADIUS + radius;
}