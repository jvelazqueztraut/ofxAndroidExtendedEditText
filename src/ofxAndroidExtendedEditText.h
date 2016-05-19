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

	static std::string lasteettext;
	void update(ofEventArgs &e);


private:
	JNIEnv * env;
	jclass jclass_Eet;
	jobject jinstance_Eet;
	jmethodID jconstructor_Eet;
	std::string eettext;
};



#endif /* OF_OFXANDROIDEXTENDEDEDITTEXT_OFXANDROIDEXTENDEDEDITTEXT_H_ */
