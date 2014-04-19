#ifndef TABLET_OSX
#define TABLET_OSX


#include <stdlib.h>
#include <ApplicationServices/ApplicationServices.h>
#include "tablet-pen-state.c"


#define TABLET_OPEN_SUCCESS 0;
#define TABLET_OPEN_ERROR   1;


// This variable is updated on tablet events, and copied on a `tablet_getState` call
TabletPenState globalState;


TabletPenState createTabletPenStateFromEvent(CGEventRef event)
{
  TabletPenState state;
  CGPoint location = CGEventGetLocation(event);

  state.position.x = location.x;
  state.position.y = location.y;
  state.position.z = CGEventGetIntegerValueField(event, kCGTabletEventPointZ);
  state.buttons = CGEventGetIntegerValueField(event, kCGTabletEventPointButtons);
  state.rotation = CGEventGetDoubleValueField(event, kCGTabletEventTangentialPressure);
  state.pressure.point = CGEventGetDoubleValueField(event, kCGTabletEventPointPressure);
  state.pressure.tangential = CGEventGetDoubleValueField(event, kCGTabletEventTangentialPressure);

  return state;
}


CGEventRef eventCallback (CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon)
{
  globalState = createTabletPenStateFromEvent(event);
  return event;
}


int tablet_open()
{
  CGEventFlags oldFlags = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);

  CGEventMask eventMask = (
    CGEventMaskBit(kCGEventLeftMouseDragged) |
    CGEventMaskBit(kCGEventLeftMouseDown)    |
    CGEventMaskBit(kCGEventTabletProximity)  |
    CGEventMaskBit(kCGEventTabletPointer)
  );

  CFMachPortRef eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, eventCallback, &oldFlags);

  if (!eventTap)
  {
    fprintf(stderr, "Failed to create event tap.\nYou need to enable \"Enable access for assitive devices\" in the Universal Access preference panel.");
    return TABLET_OPEN_ERROR;
  }

  globalState = createTabletPenState();
  CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
  CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);

  CGEventTapEnable(eventTap, true);
  CFRunLoopRun();

  return TABLET_OPEN_SUCCESS;
}



TabletPenState tablet_getState()
{
  TabletPenState state = globalState;
  return state;
}



int tablet_close()
{
  return 1;
}



#endif
