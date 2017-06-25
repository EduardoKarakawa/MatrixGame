#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	srand(time(NULL));
	tanque1 = Tanque(ofVec2f(70, 70 + rand() % (ofGetHeight() - 140)), 0);
	tanque2 = Tanque(ofVec2f(ofGetWidth() - 70, 70 + rand() % (ofGetHeight() - 140)), 180);

	tanque1.Update(deltatime);
	tanque2.Update(deltatime);
	font.loadFont("BAUHS93.TTF", 25);
}

//--------------------------------------------------------------
void ofApp::update(){
	deltatime = ofGetLastFrameTime();

	switch (estado)
	{
		case Player1:
			getValues(tanque1val);
			break;

		case Player2:
			getValues(tanque2val);
			break;

		case Define:
			tanque1.rotateBaseTo(tanque1val.angleBase);
			tanque1.rotateTowerTo(tanque1val.angleTower);
			tanque1.positionPlus(tanque1val.distance);

			tanque2.rotateBaseTo(tanque2val.angleBase);
			tanque2.rotateTowerTo(tanque2val.angleTower);
			tanque2.positionPlus(tanque2val.distance);

			estado = Executa;
			break;

		case Executa:
			tanque1.Update(deltatime);
			tanque2.Update(deltatime);

			if (tanque1.CheckCollision(tanque2.getPosition(), tanque2.getRadius()) ||
				tanque2.CheckCollision(tanque1.getPosition(), tanque1.getRadius())) 
			{
				estado = Fim;
			}

			break;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	tanque1.Draw();
	tanque2.Draw();

	switch (estado)
	{
	case Player1:
		font.drawString("Player1\n Velocidades: 1, 2 e 3 \n Rotacao Tower: W e S \n Rotacao Base: A e D\n\n Precione Enter p Terminar", ofGetWidth() / 2.0f - 200, 25);
		break;

	case Player2:
		font.drawString("Player2\n Velocidades: 1, 2 e 3 \n Rotacao Tower: W e S \n Rotacao Base: A e D\n\n Precione Enter p Terminar", ofGetWidth() / 2.0f - 200, 25);
		break;

	case Executa:
		font.drawString("EXECUTANDO", ofGetWidth() / 2.0f, 25);
			break;

	case Fim:
		font.drawString("FIM \n Precione Enter", ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') {
		key_1 = true;
	}
	if (key == '2') {
		key_2 = true;
	}
	if (key == '3') {
		key_3 = true;
	}

	if (key == 'w' || key == 'W') {
		w = true;
	}
	if (key == 's' || key == 'S') {
		s = true;
	}
	if (key == 'a' || key == 'A') {
		a = true;
	}
	if (key == 'd' || key == 'D') {
		d = true;
	}
	if (key == OF_KEY_RETURN) {
		estado = (estado + 1) % 5;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == '1') {
		key_1 = false;
	}
	if (key == '2') {
		key_2 = false;
	}
	if (key == '3') {
		key_3 = false;
	}

	if (key == 'w' || key == 'W') {
		w = false;
	}
	if (key == 's' || key == 'S') {
		s = false;
	}
	if (key == 'a' || key == 'A') {
		a = false;
	}
	if (key == 'd' || key == 'D') {
		d = false;
	}
}

void ofApp::getValues(Valores& value) {

	if (key_1) {
		value.distance = 50;
	}
	if (key_2) {
		value.distance = 120;
	}

	if (key_3) {
		value.distance = 250;
	}


	if (a) {
		value.angleBase = 30;
	}
	if (d) {
		value.angleBase = -30;
	}

	if (w) {
		value.angleTower = 30;
	}

	if (s) {
		value.angleTower = -30;
	}
}