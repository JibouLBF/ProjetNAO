#include "sensorlistener.h"
#include <alerror/alerror.h>
#include <alcommon/almodule.h>
#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <qi/log.hpp>



SensorListener::SensorListener(std::string eventName)
{
    try {
      this->eventName = eventName;
      /** Create a proxy to ALMemory.
      */
      fMemoryProxy = AL::ALMemoryProxy("192.168.0.1",9559);


      sensorValue = fMemoryProxy.getData(eventName);
      /** Subscribe to event LeftBumperPressed
      * Arguments:
      * - name of the event
      * - name of the module to be called for the callback
      * - name of the bound method to be called on event
      */
      fMemoryProxy.subscribeToEvent(eventName, "SensorListener",
                                    "actionToDo");
    }
    catch (const AL::ALError& e) {
      qiLogError("module.example") << e.what() << std::endl;
    }
}
