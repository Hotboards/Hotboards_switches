/*
  Hotboards_switches.cpp - Driver to control interrupts
  Hotboards Dip-switch board (http://hotboards.org)
  Created by Diego Perez, January 16, 2016.
  Released into the public domain.
*/

#include "Hotboards_switches.h"

Hotboards_switches::Hotboards_switches( int sw0, bool close )
{
    _sws = 1;
    _close = close;
    begin( 0, sw0 );
}

Hotboards_switches::Hotboards_switches( int sw1, int sw0, bool close )
{
    _sws = 2;
    _close = close;
    begin( 0, sw0 );
    begin( 1, sw1 );
}

Hotboards_switches::Hotboards_switches( int sw2, int sw1, int sw0, bool close )
{
    _sws = 3;
    _close = close;
    begin( 0, sw0 );
    begin( 1, sw1 );
    begin( 2, sw2 );
}

Hotboards_switches::Hotboards_switches( int sw3, int sw2, int sw1, int sw0, bool close )
{
    _sws = 4;
    _close = close;
    begin( 0, sw0 );
    begin( 1, sw1 );
    begin( 2, sw2 );
    begin( 3, sw3 );
}

Hotboards_switches::Hotboards_switches( int sw4, int sw3, int sw2, int sw1, int sw0, bool close )
{
    _sws = 5;
    _close = close;
    begin( 0, sw0 );
    begin( 1, sw1 );
    begin( 2, sw2 );
    begin( 3, sw3 );
    begin( 4, sw4 );
}

Hotboards_switches::Hotboards_switches( int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close )
{
    _sws = 6;
    _close = close;
    begin( 0, sw0 );
    begin( 1, sw1 );
    begin( 2, sw2 );
    begin( 3, sw3 );
    begin( 4, sw4 );
    begin( 5, sw5 );
}

Hotboards_switches::Hotboards_switches( int sw6, int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close )
{
    _sws = 7;
    _close = close;
    begin( 0, sw0 );
    begin( 1, sw1 );
    begin( 2, sw2 );
    begin( 3, sw3 );
    begin( 4, sw4 );
    begin( 5, sw5 );
    begin( 6, sw6 );
}

Hotboards_switches::Hotboards_switches( int sw7, int sw6, int sw5, int sw4, int sw3, int sw2, int sw1, int sw0, bool close )
{
    _sws = 8;
    _close = close;
    begin( 0, sw0 );
    begin( 1, sw1 );
    begin( 2, sw2 );
    begin( 3, sw3 );
    begin( 4, sw4 );
    begin( 5, sw5 );
    begin( 6, sw6 );
    begin( 7, sw7 );
}

uint8_t Hotboards_switches::read( uint8_t sw )
{
    uint8_t i;
    uint8_t val = 0;

    if( sw == 0xff )
    {
        for( i=0 ; i<_sws ; i++ )
        {
            bitWrite( val, i, readSw( i ) );
        }
    }
    else
    {
        val = readSw( sw );
    }
    return val;
}

bool Hotboards_switches::hasItChange( uint8_t sw )
{
    uint8_t i;
    bool isChanged = 0;

    if( sw == 0xff )
    {
        for( i=0 ; i<_sws ; i++ )
        {
            isChanged |= hasItChangeSw( i );
        }
    }
    else
    {
        isChanged = hasItChangeSw( sw );
    }

    return isChanged;
}

void Hotboards_switches::begin( uint8_t sw, uint8_t pin )
{
    _sw[ sw ] = pin;
    pinMode( pin, INPUT );
}

bool Hotboards_switches::readSw( uint8_t sw )
{
    bool val = digitalRead( _sw[ sw ] );
    if( _close == LOW ) val = !val;
    return val;
}

bool Hotboards_switches::hasItChangeSw( uint8_t sw )
{
    bool swState;
    bool isChanged = 0;
    // leemos el boton de la tarjeta
    swState = read( sw );

    // comparemos el estado actual con la anterior lectura
    if( swState != bitRead( _lastSwState, sw ) )
    {
        // si el estado cambio esque recien se presiono
        isChanged = 1;
    }
    // respaldamos el esatdo actual para compararlo la siguiente vez que preguntemos
    bitWrite( _lastSwState, sw, swState );
    return isChanged;
}
