#ifndef TABLET_PEN_STATE
#define TABLET_PEN_STATE


typedef struct
{
  int x;
  int y;
  int z;
} Position;


typedef struct
{
  double x;
  double y;
} Tilt;


typedef struct
{
  double point;
  double tangential;
} Pressure;


typedef struct
{
  Position  position;
  Tilt      tilt;
  Pressure  pressure;
  int       buttons;
  double    rotation;
} TabletPenState;


TabletPenState createTabletPenState()
{
  TabletPenState state;
  state.position.x = 0;
  state.position.y = 0;
  state.position.z = 0;
  state.tilt.x = 0.0;
  state.tilt.y = 0.0;
  state.pressure.point      = 1.0;
  state.pressure.tangential = 0.0;
  state.buttons  = 1;
  state.rotation = 0.0;
  return state;
}



#endif
