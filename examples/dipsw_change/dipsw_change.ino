/* dipsw_change.ino
 * Author Diego Perez (http://hotboards.org)
 * Read an entire dip switch compose from 8 sw, only when change its value
 */

#include <Arduino.h>
#include <Hotboards_switches.h>

// create a single sw object compose by 8 interrupts. theses interrupts will give us a LOW value
// when close because work with pull-ups.
Hotboards_switches dip_sw( 5, 6, 7, 8, 9, 10, 11, 12 );
// if your interrupt will gave you a HIGH value when close, then we need to create the sw
// object with an extra parameter: Hotboards_switches dip_sw( 5, 6, 7, 8, 9, 10, 11, 12, HIGH );
// in any case the functions will return a '1' value any time the sw is closed

void setup( void )
{
    // we require a serial port
    Serial.begin( 9600 );
}

void loop( void )
{
    // lets ask if the dip sw value has been change
    if( dip_sw.hasItChange( ) )
    {
        // lets read the entire dip switch, this will gave us the value according of the sw that are closed
        // it doesn't matter if our inputs are configured with pull-ups(LOW) or pull-downs(HIGH)
        uint8_t value = dip_sw.read( );
        // lets show the Dip-Switch value on the serial port
        Serial.print( "sw = " );
        Serial.println( value, BIN );
    }
}
