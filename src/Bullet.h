#pragma once
#include "ofVec2f.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

#define RADIUS 20.0f
#define VELOCITY 300.0f

class Bullet
{
	public:
		ofVec2f position; 
		ofVec2f direction;

		Bullet();
		Bullet(ofVec2f& origin, ofVec2f& direction);
		~Bullet();

		void Update(float& deltatime);
		void Draw();
		float getRadius();
		const ofVec2f& getPosition() const;
		bool onScreen();
};

