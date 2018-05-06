//#include "Wire.h"
#include <arduino.h>

#define EEPROM_I2C_ADDRESS 0x50 // Address of the i2c eeprom
#define EEPROM_MAX_ADDRESS 1000 // Maximum Address for writing to a 32Kbit CHIP eg: AT24C32
#define debug_flag         true // Debug Flag for getting output at each step
#define MAX_STR_LEN         25 // Maxium string lenght to be input or output
#include <i2c_eeprom_string.h>
//Max Address 1000


// void writeAddress(int address, char *d);
// char * readAddress(int address);


void setup()
{
  Wire.begin();
  Serial.begin(115200); // Serial Communication
  int addr = 0;  // Starting address to write
  char a[] = "Hello World"; //String
  writeAddress(addr, a ); // Write command with starting address and data
  char *b = readAddress(addr);
  Serial.print("OUTPUT String = ");
  Serial.println(b);
}

void loop()
{

}
