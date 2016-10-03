/*
 * ofxAndroidExtendedEditText.h
 *
 *  Created on: May 19, 2016
 *      Author: noyan
 */

#ifndef OF_OFXANDROIDEXTENDEDEDITTEXT_OFXANDROIDEXTENDEDEDITTEXT_H_
#define OF_OFXANDROIDEXTENDEDEDITTEXT_OFXANDROIDEXTENDEDEDITTEXT_H_

#include "ofMain.h"
#include "ofxAndroid.h"


class ofxAndroidExtendedEditText {
public:
	ofxAndroidExtendedEditText();
	~ofxAndroidExtendedEditText();
	void setup();

	void add(int x, int y);
	void add(std::string text, int x, int y, float size=12, std::string hint="");
	void remove();
	std::string getText();
	bool isShown();
	
private:
	std::string javaClassName;
	jclass jclass_Eet;
	jobject jinstance_Eet;
	jmethodID jconstructor_Eet;
	bool isinitialized;
};



#endif /* OF_OFXANDROIDEXTENDEDEDITTEXT_OFXANDROIDEXTENDEDEDITTEXT_H_ */
