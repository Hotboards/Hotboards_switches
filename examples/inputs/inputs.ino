/* inputs.ino
 * Author Diego Perez (http://hotboards.org)
 * read the value from 4 sw (dip switch) and also read from a single one
 */

#include <Arduino.h>
#include <Hotboards_switches.h>

// create two sw objects, this interrupt will give us a LOW value when close
// because work with pull-ups.
Hotboards_switches dip( 5, 6, 7, 8 );
Hotboards_switches sw1( 12 );
// if your interrupt will gave you a HIGH value when close, then we need to create the sw
// object with an extra parameter: Hotboards_switches sw( 5, HIGH );
// in any case the functions will return a true value any time the sw is closed

void setup( void )
{
    // para este ejemplo usaremos el puerto serial, aqui lo inicializamos
    Serial.begin( 9600 );
}

void loop( void )
{
    // we can ask for the sw
    if( sw1.read( ) )
    {
        Serial.print( "sw1 = close (on):  " );
    }
    else
    {
        Serial.print( "sw1 = open (off) :  " );
    }
    // an specific sw from the dip switch
    if( dip.read( 2 ) )
    {
        Serial.print( "in dip sw2 = close (on):  " );
    }
    else
    {
        Serial.print( "in dip sw2 = open (off):  " );
    }
    // or the entire dip switch
    uint8_t value = dip.read( );
    // lets show the Dip-Switch value on the serial port
    Serial.print( "sw = " );
    Serial.println( value, BIN );

    // wait 1 second, just to not query so often
    delay( 1000 );
}
