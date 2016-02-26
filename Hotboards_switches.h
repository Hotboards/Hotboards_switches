/*
  Hotboards_switches.h - Driver to control interrupts
  Hotboards Dip-switch board (http://hotboards.org)
  Created by Diego Perez, January 16, 2016.
  Released into the public domain.
*/
#ifndef Hotboards_switches_h
#define Hotboards_switches_h

#include <Arduino.h>

class Hotboards_switches
{
    public :
        Hotboards_switches( int sw0, bool close=LOW );
        Hotboards_switches( int sw1, int sw0, bool close=LOW );
        Hotboards_switches( int sw2, int sw1, int sw0, bool close=LOW );
        Hotboards_switches( int sw3, int sw2, int sw1, int sw0, bool close=LOW );
        Hotboards_switches( int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );
        Hotboards_switches( int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );
        Hotboards_switches( int sw6, int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );
        Hotboards_switches( int sw7, int sw6, int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );
        uint8_t read( uint8_t sw=0xff );
        bool hasItChange( uint8_t sw=0xff );

    private :
        void begin( uint8_t sw, uint8_t pin );
        bool readSw( uint8_t sw );
        bool hasItChangeSw( uint8_t sw );
        uint8_t _sw[ 8 ];
        uint8_t _sws;
        uint8_t _lastSwState;
        bool _close;
};

#endif
