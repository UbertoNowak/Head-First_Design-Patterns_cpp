#ifndef FACADE_H
#define FACADE_H

#include "../Command/smarthome.h"

class facade
{
public:
  void leaving_the_house();
  void party_mode();
  void relax_mode();

private:
  Light m_Light;
  Jacuzzi m_Jacuzzi;
  StereoSystem m_Stereo;
  GarageDoor m_Door;
};

#endif // FACADE_H
