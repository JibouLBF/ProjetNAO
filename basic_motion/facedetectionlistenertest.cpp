#include "facedetectionlistenertest.h"

#include <althread/alcriticalsection.h>
#include <qi/log.hpp>
#include "common.h"


FaceDetectionListenerTest::FaceDetectionListenerTest(boost::shared_ptr<AL::ALBroker> broker,const std::string& name):
    FaceDetectionListener(broker, name)
{
    std::cout << "Face Dection Constructor" << std::endl;
}


void FaceDetectionListenerTest::faceDetectionHandler() {
  /** Use a mutex to make it all thread safe. */
  AL::ALCriticalSection section(fCallbackMutex);
  try {
    /** Retrieve the data raised by the event. */
    fFaces = fMemoryProxy.getData("FaceDetected");
    /** Check that there are faces effectively detected. */
    if (fFaces.getSize() < 2 ) {
      if (fFacesCount != 0) {
        qiLogInfo("module.example") << "No face detected" << std::endl;
        fTtsProxy.say("Pas de tête detectée");
        fFacesCount = 0;
      }
      return;
    }
    /** Check the number of faces from the FaceInfo field, and check that it has
    * changed from the last event.*/
    if (fFaces[1].getSize() - 1 != fFacesCount) {
      Common::scheduler.stop();
      qiLogInfo("module.name") << fFaces[1].getSize() - 1 << " face(s) detected." << std::endl;
      char buffer[50];
      //sprintf(buffer, "%d faces detected.", fFaces[1].getSize() - 1);
      //fTtsProxy.say(std::string(buffer));
      fTtsProxy.say("Les gars ? Ca benche?");
      /** Update the current number of detected faces. */
      fFacesCount = fFaces[1].getSize() - 1;
      Common::scheduler.play();
    }
  }
  catch (const AL::ALError& e) {
    qiLogError("module.name") << e.what() << std::endl;
  }
}
