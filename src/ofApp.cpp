#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	teste.print();
	teste = Matrix3f(2,5,3,
					 3,4,1,
					 1,1,2);

	std::cout << " --------------------------- " << std::endl;
	teste.print();
	std::cout << " --------------------------- " << std::endl;
	teste * Matrix3f(2, 5, 3,
					 3, 4, 1,
					 1, 1, 2);
	teste.print();

	/*std::cout << " --------------------------- " << std::endl;
	teste.getInverse().print();
	std::cout << " --------------------------- " << std::endl;
	teste.getTransposed().print();
	std::cout << " --------------------------- " << std::endl;
	teste += Matrix3f(	2, 5, 3,
						3, 4, 1,
						1, 1, 2);
	teste.print();
	

	std::cout << " --------------------------- " << std::endl;
	(teste + Matrix3f(	2, 5, 3,
						3, 4, 1,
						1, 1, 2)).print();



	std::cout << " --------------------------- " << std::endl;
	teste.print();*/
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
