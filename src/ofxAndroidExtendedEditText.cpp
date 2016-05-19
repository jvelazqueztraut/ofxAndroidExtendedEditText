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

std::string ofxAndroidExtendedEditText::lasteettext = "";

ofxAndroidExtendedEditText::ofxAndroidExtendedEditText() {
	eettext = "";

	env = ofGetJNIEnv();
	std::string javaClassName = "cc/openframeworks/ofxaddons/ofxandroidextendededittext/OFXAndroidExtendedEditText";
	char *javaclassname = new char[javaClassName.size()+1];
	strcpy(javaclassname, javaClassName.c_str());
    jclass tmp = ofGetJNIEnv()->FindClass(javaclassname);
    jclass_Eet = (jclass)ofGetJNIEnv()->NewGlobalRef(tmp);

    jconstructor_Eet = ofGetJNIEnv()->GetMethodID(jclass_Eet, "<init>", "()V");
	jinstance_Eet = ofGetJNIEnv()->NewGlobalRef(ofGetJNIEnv()->NewObject(jclass_Eet, jconstructor_Eet));

	ofAddListener(ofEvents().update, this, &ofxAndroidExtendedEditText::update);
}


ofxAndroidExtendedEditText::~ofxAndroidExtendedEditText() {
	ofRemoveListener(ofEvents().update, this, &ofxAndroidExtendedEditText::update);
	ofGetJNIEnv()->DeleteGlobalRef(jclass_Eet);
	ofGetJNIEnv()->DeleteGlobalRef(jinstance_Eet);
}


void ofxAndroidExtendedEditText::add() {
	ofGetJNIEnv()->CallVoidMethod(jinstance_Eet, ofGetJNIEnv()->GetMethodID(jclass_Eet, "add", "()V"));
}


void ofxAndroidExtendedEditText::add(std::string hint) {
	jstring jStringParam = ofGetJNIEnv()->NewStringUTF(hint.c_str());
	ofGetJNIEnv()->CallVoidMethod(jinstance_Eet, ofGetJNIEnv()->GetMethodID(jclass_Eet, "add", "(Ljava/lang/String;)V"), jStringParam);
	ofGetJNIEnv()->DeleteLocalRef(jStringParam);
}


void ofxAndroidExtendedEditText::remove() {
	ofGetJNIEnv()->CallVoidMethod(jinstance_Eet, ofGetJNIEnv()->GetMethodID(jclass_Eet, "remove", "()V"));
}


std::string ofxAndroidExtendedEditText::getText() {
	return eettext;
}


bool ofxAndroidExtendedEditText::isShown() {
	return ofGetJNIEnv()->CallBooleanMethod(jinstance_Eet, ofGetJNIEnv()->GetMethodID(jclass_Eet, "isShown", "()Z"));
}


void ofxAndroidExtendedEditText::update(ofEventArgs &e) {
	eettext = lasteettext;
}


extern "C"{

void Java_cc_openframeworks_ofxaddons_ofxandroidextendededittext_OFXAndroidExtendedEditText_setEditorText( JNIEnv*  env, jobject  thiz, jstring eetext ) {
	const char *resultCStr = ofGetJNIEnv()->GetStringUTFChars(eetext, NULL);
	std::string resultStr(resultCStr);
	ofxAndroidExtendedEditText::lasteettext = resultStr;
}

}


