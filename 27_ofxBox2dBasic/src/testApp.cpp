#include "testApp.h"

void testApp::setup() {
	ofSetVerticalSync(true);
	ofBackgroundHex(0x000000);
	
	box2d.init(); // Box2Dの世界の初期化
	box2d.setGravity(0, 10); // 重力を下向きに10
	box2d.createBounds(); // 地面を生成
	box2d.setFPS(30.0); // Box2Dの世界でのFPS
	box2d.registerGrabbing(); // 物体に接触可能に
}

void testApp::update() {
	box2d.update(); // Box2Dの更新
}

void testApp::draw() {
	// circlesを描く
	for(int i=0; i<circles.size(); i++) {
		ofSetHexColor(0x3366ff);
		circles[i].draw();
	}
}

void testApp::keyPressed(int key) {
	// [c]キーを押すと、Circleを追加
	if(key == 'c') {
		float r = ofRandom(4, 20); //半径をランダムに
		ofxBox2dCircle circle; //円
		circle.setPhysics(3.0, 0.53, 0.1); //物理法則を追加
		// Box2dの世界に生成した円を追加
        circle.setup(box2d.getWorld(), mouseX, mouseY, r);
		circles.push_back(circle); // 動的配列に追加
	}
}