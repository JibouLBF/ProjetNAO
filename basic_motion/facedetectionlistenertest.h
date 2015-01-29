#ifndef FACEDETECTIONLISTENERTEST_H
#define FACEDETECTIONLISTENERTEST_H

#include "facedetectionlistener.h"

class FaceDetectionListenerTest : public FaceDetectionListener
{
public:
    FaceDetectionListenerTest(boost::shared_ptr<AL::ALBroker> broker,const std::string& name);
    void faceDetectionHandler();
};

#endif // FACEDETECTIONLISTENERTEST_H
