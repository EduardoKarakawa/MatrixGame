#pragma once

#include "ofMain.h"
#include "Tanque.h"
#include <time.h>


enum Estado {
	Player1,
	Player2,
	Define,
	Executa,
	Fim
};

struct Valores {
	float angleBase;
	float angleTower;
	float distance;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);


		float deltatime;
		Tanque tanque1;
		Tanque tanque2;
		Valores tanque1val;
		Valores tanque2val;

		ofTrueTypeFont font;

		int estado;
		bool key_1, key_2, key_3;
		bool w, s, a, d;

		void getValues(Valores& value);

};
