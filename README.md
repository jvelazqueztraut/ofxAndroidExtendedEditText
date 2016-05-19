# ofxAndroidExtendedEditText
Android EditText addon for openFrameworks

This is an openFrameworks addon that shows an Android EditText and keyboard on the screen to enter some text value and to pass this value to openFrameworks environment.

Licence: MIT

----
HOW TO INSTALL

1. Copy the files of "src" folder to -> yourofdir/addons/ofxAndroidExtendedEditText/src
2. Copy the files of "scrJava/cc/openframeworks/ofxaddons/ofxandroidextendededittext" folder to -> yourofdir/examples/android/androidEmptyExample/srcJava/cc/openframeworks/ofxaddons/ofxandroidextendededittext
3. Copy the files of "example" folder to -> yourofdir/examples/android/androidEmptyExample/src
4. Add ofxAndroidViews to the end of the file yourofdir/examples/android/androidEmptyExample/addons.make
5. Clean&Build Project
6. Run

----
HOW TO TEST

1. Test for cancelling

a. Run the given example. An EditText should appear on the screen with a hint value "Test EditText".

b. See the logcat. On the logcat, you should see: isShown = 1, getText:"".

c. Click Back button of the device. The EditText will disappear.

d. Check the logcat again, you should see: isShown=0, getText="".

2. Test for editing

a. Run the given example. An edittext should appear on the screen with a hint value "Test EditText".

b. See the logcat. On the logcat, you should see: isShown = 1, getText:"".

c. Click DONE button on the device screen. The EditText will disappear.

d. Check the logcat again, you should see: isShown=0, getText="Test EditText".
(You can write something on the editor to see your own result)

