#include "Tanque.h"
const ofVec2f& Tanque::getPosition() const { return position; }
float Tanque::getRadius() { return RADIUS; }
Tanque::Tanque()
{
	color.set(rand() % 255, rand() % 255, rand() % 255);

	position.set(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	angleBase = 0;
	angleTower = 0;
	
	next_position.set(0, 0);
	next_angleBase = 0;
	next_angleTower = 0;

	shot = false;
	shooting = false;
	bullet = nullptr;
}

Tanque::Tanque(ofVec2f position, float angle) {
	color.set(rand() % 255, rand() % 255, rand() % 255);

	this->position.set(position);
	angleBase = angle;
	angleTower = 0;

	next_position.set(0, 0);
	next_angleBase = 0;
	next_angleTower = 0;

	shot = false;
	shooting = false;
	bullet = nullptr;

}

void Tanque::Update(float &deltatime) {
	// Translacao e Rotacao --------------------------------
	if (interpolationTo(position, next_position, VELOCITY_MOVE, deltatime)	&&

	interpolationTo(angleBase, next_angleBase, VELOCITY_ROTATE, deltatime)	&&
	interpolationTo(angleTower, next_angleTower, VELOCITY_ROTATE, deltatime)&&
	shot
	)
	{
		float radian = -(angleBase + angleTower) * PI / 180.0f;
		ofVec2f dir = ofVec2f(cosf(radian), sinf(radian));
		ofVec2f pos = position + dir * TOWER_H;
		bullet = new Bullet(pos, dir);
		shot = false;
		shooting = true;
	}


	if (shooting) {
		bullet->Update(deltatime);
		if (!bullet->onScreen()) {
			bullet = new Bullet();
			shooting = false;
		}
	}


	// Matrix acumulada ------------------------------
	matrixBase = Matrix3f().translate(-TANK_W / 2.0f, -TANK_H / 2.0f) * Matrix3f(angleBase) * Matrix3f().translate(position.x, position.y);
	matrixTower = Matrix3f().rotate(angleTower) * Matrix3f().translate(TANK_W / 2.0f, (TANK_H - TOWER_H) / 2.0f);


}

void Tanque::Draw() {
	if(shooting)
		bullet->Draw();


	ofPushMatrix();
	ofMultMatrix(matrixBase.to4x4());

	ofSetColor(color);
	ofDrawRectangle(0, 0, TANK_W, TANK_H);

	ofMultMatrix(matrixTower.to4x4());
	ofSetColor(0, 0, 0);
	ofDrawRectangle(0,0, TOWER_W, TOWER_H);

	ofPopMatrix();



}

bool Tanque::CheckCollision(ofVec2f position, float radius) {
	bool out = false; 
	if (bullet != nullptr) {
		out = position.distance(bullet->getPosition()) <= bullet->getRadius() + RADIUS;
	}

	return this->position.distance(position) <= RADIUS + radius || out;
}


void Tanque::rotateBaseTo(float angle){
	next_angleBase = angle; 
	shot = true;
}


void Tanque::rotateTowerTo(float angle) {
	next_angleTower = angle;
	shot = true;
}


void Tanque::positionPlus(float distance) {
	float radian = -(angleBase + angleTower) * PI / 180.0f;
	next_position = ofVec2f(cosf(radian), sinf(radian)) * distance;
	shot = true;
}


bool Tanque::interpolationTo(float& current, float& next, float velocity, float& deltatime) {
	// Rotacao --------------------------------
	if (next > 0.0f) {
		next -= velocity * deltatime;
		current += velocity * deltatime;
		if (next < 0.0f) {
			next = 0;
			return true;
		}
		return false;
	}
	else if (next < 0.0f) {
		next += velocity * deltatime;
		current -= velocity * deltatime;
		if (next > 0.0f) {
			next = 0;
			return true;
		}
		return false;
	}
	return true;
}

bool Tanque::interpolationTo(ofVec2f& current, ofVec2f& next, float velocity, float& deltatime) {
	return	interpolationTo(current.x, next.x, velocity, deltatime) &&
			interpolationTo(current.y, next.y, velocity, deltatime);
}