#include "Bullet.h"

Bullet::Bullet() {
	this->direction.set(0, 0);
	this->position.set(0, 0);
}

Bullet::Bullet(ofVec2f& origin, ofVec2f& direction)
{
	this->direction = direction.normalized();
	this->position = origin;
}


void Bullet::Update(float& deltatime) {
	if(onScreen())
		position += direction * VELOCITY * deltatime;
}


void Bullet::Draw() {
	if (onScreen()){
		ofSetColor(50, 50, 50);
		ofDrawCircle(position, RADIUS);
	}
}


float Bullet::getRadius() {
	return RADIUS;
}


const ofVec2f& Bullet::getPosition() const {
	return position;
}


Bullet::~Bullet()
{
}


bool Bullet::onScreen() {
	return	position.x > 0 && position.x < ofGetWidth() &&
			position.y > 0 && position.y < ofGetHeight();
}