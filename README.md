Hotboards_switches
===============

Genial libreria de proposito general para leer interruptores, puedes leerlos uno a la vez y/o varios a la vez. Descarga la libreria en formato [**zip**](https://github.com/Hotboards/Hotboards_switches/archive/master.zip), renombre el archivo ( _solo quita el **-master**_ ) e importala a tu Arduino IDE com dice [aqui](https://www.arduino.cc/en/Guide/Libraries).

API
---

**Hotboards_switches( int sw0, int sw1, int sw2, int sw3, int sw4, int sw5, int sw6, int sw7, bool close=LOW )**

Constructor para incializar interruptores. Puedes crear de 1 solo sw hasta 8 sw, e indicar si estos dan un valor en alto o bajo cuando se cierran.

``` cpp
/* creamos un sw en el pin 5 */
Hotboards_switches sw( 5 );
/* creamos un dip switchs de 4 sw en los pines 5, 6, 7 y 8.
   En el pin 5 esta el sw0, y en el pin 8 esta el sw3 */
Hotboards_leds dipsw( 5, 6, 7, 8 );
/* creamos un sw en el pin 9 que da un nivel alto cuando cierra */
Hotboards_leds sw( 9, LOW );
```

**uint8_t read( uint8_t sw=0xff )**

Lee el estado de los interruptores en el dip switch creado. Puede ser el valor de un solo sw o de hasta ocho, siendo un valor de uno un sw cerrado (no importa si este fucniona con pull-ups o pull-downs).

``` cpp
// creamos un sw en pin 7 and leemos su estado (0 o 1)
Hotboards_leds sw ( 7 );
bool val = sw.read( );

//  creamos un dip-sw de 8 sw (pin2->sw0 ..... pin9->sw7)
Hotboards_switches dipsw( 2, 3, 4, 5, 6, 7, 8, 9 );
// leemos el valor del dip-sw (valores de 0 a 255)
uint8_t val = dipsw.read( );

// creamos un dip-sw de 4 sw (pin2->sw0 ..... pin5->sw3)
Hotboards_switches dipsw( 2, 3, 4, 5 );
// leemos el estado del sw 1 (pin 3)
bool val1 = dipsw.write( 1 );
// leemos el estado del sw 0 (pin 2)
bool val2 = dipsw.write( 0 );
```

**bool hasItChange( uint8_t sw=0xff )**

Indica si el valor de un sw o del dip-sw completo ha cambiado. un valor 1 indica un cambio.

``` cpp
// creamos un sw en pin 7 and leemos su estado (0 o 1)
Hotboards_leds sw ( 7 );
if( sw.hasItChange( )){
    bool val = sw.read( );
}

// icreamos un dip-sw de 8 sw (pin2->sw0 ..... pin9->sw7)
Hotboards_switches dipsw( 2, 3, 4, 5, 6, 7, 8, 9 );
// leemos el valor del dip-sw (from 0 to 255) si hay un cambio
if( dipsw.hasItChange( ) ){
    uint8_t val = dipsw.read( );
}

// creamos un dip-sw de 4 sw (pin2->sw0 ..... pin5->sw3)
Hotboards_switches dipsw( 2, 3, 4, 5 );
// leemos el esatdo solo del sw 1 (pin 3) si hay un cambio
if( sw.hasItChange( 1 )){
    bool val = sw.read( 1 );
}
```

Ejemplos
--------

- [Leyendo un interruptor](https://github.com/Hotboards/Hotboards_switches/tree/master/examples/input/input.ino)
- [Leyendo un dip switch completo](https://github.com/Hotboards/Hotboards_switches/tree/master/examples/dip_switch/dip_switch.ino)
- [Leyendo un grupo de interruptores o uno solo](https://github.com/Hotboards/Hotboards_switches/tree/master/examples/inputs/inputs.ino)
- [Leyendo un solo interruptor cuando cambia de valor](https://github.com/Hotboards/Hotboards_switches/tree/master/examples/input_change/input_change.ino)
- [Leyedno un dip-switch cuando cambia su valor](https://github.com/Hotboards/Hotboards_switches/tree/master/examples/dipsw_change/dipsw_change.ino)
