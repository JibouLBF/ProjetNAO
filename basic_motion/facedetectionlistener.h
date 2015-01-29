#ifndef FACEDETECTIONLISTENER_H
#define FACEDETECTIONLISTENER_H

#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <string>

#include <alproxies/almemoryproxy.h>
#include <alproxies/altexttospeechproxy.h>

#include <althread/almutex.h>

namespace AL
{
  class ALBroker;
}

class FaceDetectionListener : public AL::ALModule
{
  public:

    FaceDetectionListener(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

    virtual ~FaceDetectionListener();

    virtual void init();

    /**
    * Method called each time a face is detected.
    * Makes NAO say the number of detected faces.
    */
    void virtual faceDetectionHandler();

  protected:
    /** Memory proxy for event subscription and data access. */
    AL::ALMemoryProxy fMemoryProxy;
    /** TTS proxy to make NAO talk. */
    AL::ALTextToSpeechProxy fTtsProxy;

    /** ALValue containing the information on detected faces. */
    AL::ALValue fFaces;
    /** Current count of detected faces. */
    unsigned int fFacesCount;
    /** Mutex to make the callback function thread-safe. */
    boost::shared_ptr<AL::ALMutex> fCallbackMutex;

};


#endif // FACEDETECTIONLISTENER_H
