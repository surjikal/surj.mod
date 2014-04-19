
#include <stdio.h>

#include "tablet-pen-state.c"
#include "tablet-osx.c"


int TabletOpen()
{
    fprintf(stdout, "Opening tablet.\n");
    return tablet_open();
}



int TabletClose()
{
    return tablet_close();
}



int TabletButtons()
{
    TabletPenState state = tablet_getState();
    return state.buttons;
}



float TabletPressure()
{
    TabletPenState state = tablet_getState();
    return (float) state.pressure.point;
}
