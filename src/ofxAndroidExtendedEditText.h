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

	void add();
	void add(std::string hint);
	void remove();
	std::string getText();
	bool isShown();

	//for internal use
	static std::string lasteettext;


private:
	jclass jclass_Eet;
	jobject jinstance_Eet;
	jmethodID jconstructor_Eet;
};



#endif /* OF_OFXANDROIDEXTENDEDEDITTEXT_OFXANDROIDEXTENDEDEDITTEXT_H_ */
