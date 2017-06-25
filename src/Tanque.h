#pragma once
#include "ofVec2f.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "Matrix3x3.h"
#include "Bullet.h"


#define RADIUS 50.0f

#define TOWER_W 100.0f
#define TOWER_H 40.0f


#define TANK_W 100.0f
#define TANK_H 100.0f


#define VELOCITY_ROTATE 50.0f
#define VELOCITY_MOVE   200.0f


class Tanque {
	private:
		float next_angleBase;
		float next_angleTower;
		float angleBase;
		float angleTower;
		ofVec2f position;
		ofVec2f next_position;
		ofVec2f nextPosition;
		ofColor color;

		Matrix3f matrixBase;
		Matrix3f matrixTower;

		Bullet *bullet;
		bool shooting;
		bool shot;

	private:
		bool interpolationTo(float& current, float& next, float velocity, float& deltatime);
		bool interpolationTo(ofVec2f& current, ofVec2f& next, float velocity, float& deltatime);

	public:
		Tanque();
		Tanque(ofVec2f position, float angle);
		void Update(float &deltatime);
		void Draw();
		bool CheckCollision(ofVec2f position, float radius);
		void rotateBaseTo(float angle);
		void rotateTowerTo(float angle);
		void positionPlus(float distance);
		const ofVec2f& getPosition() const;
		float getRadius();
};
