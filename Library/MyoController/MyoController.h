
#ifndef MyoController_H      //defining the MyoController lib
#define MyoController_H

#include "Arduino.h"         //Including Arduino for Serial Communication

#define DEBUG	0							//Initializing

enum Poses{                //defining enum class
	rest,
	fist,
	waveIn,
	waveOut,
	fingersSpread,
	doubleTap,
	unknown
};

class MyoController {    //defining class for lib
public:

    /* Initialization methods */
    MyoController();
    ~MyoController();
    bool initMyo();
    bool updatePose();
    Poses getCurrentPose();
private:
	Poses current_pose_;
	String storageStr;
	String msgChar;
};

#endif
