/*
  Hotboards_switches.h - Driver to read interrupts
  Hotboards Dip-switch board (http://hotboards.org)
  Created by Diego Perez, January 16, 2016.
  Released into the public domain.
*/
#ifndef Hotboards_switches_h
#define Hotboards_switches_h

#include <Arduino.h>

/** Hotboards_switches class.
 *  Used to read general purpose dip switches
 *
 * Example:
 * @code
 * #include "Hotboards_switches.h"
 *
 * Hotboards_switches sw( 5 );
 *
 * int main( void )
 * {
 *     for(;;){
 *         bool var = sw.read( );
 *         delay( 200 );
 *     }
 * }
 * @endcode
 */
class Hotboards_switches
{
    public :
        /** Create Hotboards_switches instance for one sw
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one sw on pin 5
          *   Hotboards_switches sw( 5 );
          * @endcode
          */
        Hotboards_switches( int sw0, bool close=LOW );

        /** Create Hotboards_switches instance for two sw
          * @param sw1 pin where the sw 1 will be read it
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one dip-sw with 2 sw on pin 5 and 6
          *   Hotboards_switches sw( 5, 6 );
          * @endcode
          */
        Hotboards_switches( int sw1, int sw0, bool close=LOW );

        /** Create Hotboards_switches instance for three sw
          * @param sw2 pin where the sw 2 will be read it
          * @param sw1 pin where the sw 1 will be read it
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one dip-sw with 3 sw on pin 5, 6 and 7
          *   Hotboards_switches sw( 5, 6, 7 );
          * @endcode
          */
        Hotboards_switches( int sw2, int sw1, int sw0, bool close=LOW );

        /** Create Hotboards_switches instance for four sw
          * @param sw3 pin where the sw 3 will be read it
          * @param sw2 pin where the sw 2 will be read it
          * @param sw1 pin where the sw 1 will be read it
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one dip-sw with 4 sw on pin 5, 6, 7 and 8
          *   Hotboards_switches sw( 5, 6, 7, 8 );
          * @endcode
          */
        Hotboards_switches( int sw3, int sw2, int sw1, int sw0, bool close=LOW );

        /** Create Hotboards_switches instance for five sw
          * @param sw4 pin where the sw 4 will be read it
          * @param sw3 pin where the sw 3 will be read it
          * @param sw2 pin where the sw 2 will be read it
          * @param sw1 pin where the sw 1 will be read it
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one dip-sw with 5 sw on pin 5, 6, 7, 8 and 9
          *   Hotboards_switches sw( 5, 6, 7, 8, 9 );
          * @endcode
          */
        Hotboards_switches( int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );

        /** Create Hotboards_switches instance for six sw
          * @param sw5 pin where the sw 5 will be read it
          * @param sw4 pin where the sw 4 will be read it
          * @param sw3 pin where the sw 3 will be read it
          * @param sw2 pin where the sw 2 will be read it
          * @param sw1 pin where the sw 1 will be read it
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one dip-sw with 6 sw on pin 5, 6, 7, 8, 9 and 10
          *   Hotboards_switches sw( 5, 6, 7, 8, 9, 10 );
          * @endcode
          */
        Hotboards_switches( int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );

        /** Create Hotboards_switches instance for seven sw
          * @param sw6 pin where the sw 6 will be read it
          * @param sw5 pin where the sw 5 will be read it
          * @param sw4 pin where the sw 4 will be read it
          * @param sw3 pin where the sw 3 will be read it
          * @param sw2 pin where the sw 2 will be read it
          * @param sw1 pin where the sw 1 will be read it
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one dip-sw with 7 sw on pin 5, 6, 7, 8, 9, 10 and 11
          *   Hotboards_switches sw( 5, 6, 7, 8, 9, 10, 11 );
          * @endcode
          */
        Hotboards_switches( int sw6, int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );

        /** Create Hotboards_switches instance for eight sw
          * @param sw7 pin where the sw 7 will be read it
          * @param sw6 pin where the sw 6 will be read it
          * @param sw5 pin where the sw 5 will be read it
          * @param sw4 pin where the sw 4 will be read it
          * @param sw3 pin where the sw 3 will be read it
          * @param sw2 pin where the sw 2 will be read it
          * @param sw1 pin where the sw 1 will be read it
          * @param sw0 pin where the sw 0 will be read it
          * @param close logic level that gives you when the sw is closed
          *
          * Example:
          * @code
          *   // instance one dip-sw with 8 sw on pin 5, 6, 7, 8, 9, 10, 11 and 12
          *   Hotboards_switches sw( 5, 6, 7, 8, 9, 10, 11, 12 );
          * @endcode
          */
        Hotboards_switches( int sw7, int sw6, int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close=LOW );

        /** Read a single sw or the entire Dip-switch state (open=0 or close=1)
          * @return sw state(s)
          *
          * Example:
          * @code
          *   // instance one sw on pin 7 and read its state (0 o 1)
          *   Hotboards_leds sw ( 7 );
          *   bool val = sw.read( );
          *
          *   // instance an 8 sw dip-sw (pin9->sw7 ..... pin2->sw0)
          *   Hotboards_switches dipsw( 9, 8, 7, 6, 5, 4, 3, 2 );
          *   // read the sw values (from 0 to 255)
          *   uint8_t val = dipsw.read( );
          *
          *   // instance a 4 dip-sw (pin2->sw3 ..... pin5->sw0)
          *   Hotboards_switches dipsw( 2, 3, 4, 5 );
          *   // read sw 1 state (pin 4)
          *   bool val1 = dipsw.write( 1 );
          *   // read sw 0 state (pin 5)
          *   bool val2 = dipsw.write( 0 );
          * @endcode
          */
        uint8_t read( uint8_t sw=0xff );

        /** Tells you if one or more sw has been change
          * @return '1' if not changed
          *
          * Example:
          * @code
          *   // instance one sw on pin 7 and read its state (0 o 1)
          *   Hotboards_leds sw ( 7 );
          *   if( sw.hasItChange( ))
          *     bool val = sw.read( );
          *
          *   // instance an 8 sw dip-sw (pin9->sw7 ..... pin2->sw0)
          *   Hotboards_switches dipsw( 9, 8, 7, 6, 5, 4, 3, 2 );
          *   // read the sw values (from 0 to 255) if it changes
          *   if( dipsw.hasItChange( ) )
          *     uint8_t val = dipsw.read( );
          *
          *   // instance a 4 dip-sw (pin2->sw3 ..... pin5->sw0)
          *   Hotboards_switches dipsw( 2, 3, 4, 5 );
          *   // read sw 1 state (pin 4) if it changes
          *   if( sw.hasItChange( 1 ))
          *     bool val = sw.read( 1 );
          * @endcode
          */
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
