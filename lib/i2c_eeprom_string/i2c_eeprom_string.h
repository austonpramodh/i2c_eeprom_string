#include <wire.h> // required for i2c Communication

void writeAddress(int address, char datain[])
{
  int datainlen = strlen(datain);
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  if((address+datainlen) > EEPROM_MAX_ADDRESS)
  {
    #if(debug_flag)
    Serial.println("error, string longer than available address");
    #endif
    return ;
  }
 for(int i = 0 ; i < datainlen; i++ )
 {
  Wire.write(datain[i]);
 }
 Wire.write(';');
 #if(debug_flag)
 Serial.println("Write Complete");
 #endif
 Wire.endTransmission();
 delay(5); // required for storing data as suggested by datasheet
}

char * readAddress(int address)
{
  char dataout[MAX_STR_LEN];
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
  int i = 0;
    while(true)
    {
      Wire.requestFrom(EEPROM_I2C_ADDRESS, 1);
      dataout[i] = Wire.read();
      if(dataout[i] == ';')
      {
        dataout[i] = '\0';
        #if(debug_flag)
        Serial.println("Read Completed");
        #endif
        return dataout;
      }
      else if(i == MAX_STR_LEN)
      {
        return "error no Data";
      }
      i++;
      }
}
