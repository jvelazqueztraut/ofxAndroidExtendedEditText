/*
 * ofxAndroidExtendedEditText.cpp
 *
 *  Created on: May 19, 2016
 *      Author: noyan
 */

#include "ofxAndroidExtendedEditText.h"

#ifndef NULL
#define NULL   ((void *) 0)
#endif

//for internal use
std::string ofxAndroidExtendedEditText::lasteettext = "";


ofxAndroidExtendedEditText::ofxAndroidExtendedEditText() {
	javaClassName = "cc/openframeworks/ofxaddons/ofxandroidextendededittext/OFXAndroidExtendedEditText";
	isinitialized = false;
}


ofxAndroidExtendedEditText::~ofxAndroidExtendedEditText() {
	if (isinitialized) {
		ofGetJNIEnv()->DeleteGlobalRef(jclass_Eet);
		ofGetJNIEnv()->DeleteGlobalRef(jinstance_Eet);
	}
}


void ofxAndroidExtendedEditText::setup() {
	char *javaclassname = new char[javaClassName.size()+1];
	strcpy(javaclassname, javaClassName.c_str());
    jclass tmp = ofGetJNIEnv()->FindClass(javaclassname);
    jclass_Eet = (jclass)ofGetJNIEnv()->NewGlobalRef(tmp);

    jconstructor_Eet = ofGetJNIEnv()->GetMethodID(jclass_Eet, "<init>", "()V");
	jinstance_Eet = ofGetJNIEnv()->NewGlobalRef(ofGetJNIEnv()->NewObject(jclass_Eet, jconstructor_Eet));

	isinitialized = true;
}


void ofxAndroidExtendedEditText::add(int x, int y) {
	add("",x,y);
}


void ofxAndroidExtendedEditText::add(std::string text, int x, int y, float size, std::string hint) {
	jstring jStringText = ofGetJNIEnv()->NewStringUTF(text.c_str());
	jstring jStringHint = ofGetJNIEnv()->NewStringUTF(hint.c_str());
	ofGetJNIEnv()->CallVoidMethod(jinstance_Eet, ofGetJNIEnv()->GetMethodID(jclass_Eet, "add", "(Ljava/lang/String;IIFLjava/lang/String;)V"), jStringText,x,y,size,jStringHint);
	ofGetJNIEnv()->DeleteLocalRef(jStringText);
	ofGetJNIEnv()->DeleteLocalRef(jStringHint);
}


void ofxAndroidExtendedEditText::remove() {
	ofGetJNIEnv()->CallVoidMethod(jinstance_Eet, ofGetJNIEnv()->GetMethodID(jclass_Eet, "remove", "()V"));
}


std::string ofxAndroidExtendedEditText::getText() {
	jstring eetext = static_cast<jstring>(ofGetJNIEnv()->GetObjectField(jinstance_Eet, ofGetJNIEnv()->GetFieldID(jclass_Eet, "text", "Ljava/lang/String;")));
	const char *resultCStr = ofGetJNIEnv()->GetStringUTFChars(eetext, NULL);
	std::string resultStr(resultCStr);
	return resultStr;
}


bool ofxAndroidExtendedEditText::isShown() {
	return ofGetJNIEnv()->CallBooleanMethod(jinstance_Eet, ofGetJNIEnv()->GetMethodID(jclass_Eet, "isShown", "()Z"));
}


