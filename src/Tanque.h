#pragma once
#include "ofVec2f.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "Matrix3x3.h"


#define RADIUS 50.0f

#define TOWER_W 40.0f
#define TOWER_H 40.0f

class Tanque {
	private:
		ofVec2f position;
		ofVec2f direction;
		ofVec2f nextDirect;
		ofColor color;

		Matrix3f matrix;

	public:
		Tanque ();
		void Update(float &deltatime);
		void Draw();
		bool CheckCollision(ofVec2f position, float radius);
};
