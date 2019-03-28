/*=============================================================================
 |      Editors:  Martyn Fitzgerald - 16025948
 |                Dawid Koleczko    - 17024154
 |
 |  Module Code:  UFCFVK-15-2
 | Module Title:  Internet Of Things
 |
 |   Instructor:  Benedict R. Gaster
 |     Due Date:  29/03/2019
 |
 |  Description: This file enables the Accelerometer serivce so that we can send
 |  the data over Bluetooth
 |
 *===========================================================================*/

#include "MicroBit.h"

MicroBit uBit;

// Display C or D on the MicroBit depending if the microbit is connected to any device
void onConnected(MicroBitEvent)
{
    uBit.display.print("C");
}

void onDisconnected(MicroBitEvent)
{
    uBit.display.print("D");
}

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();




    // Services/Pairing Config/Power Level
    uBit.display.scroll("BLE ABDILMT/P/0");

    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);

    //enables Services
    new MicroBitAccelerometerService(*uBit.ble, uBit.accelerometer);
    new MicroBitLEDService(*uBit.ble, uBit.display);

    //new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);

    release_fiber();
}
