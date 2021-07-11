/*
// AXP192 have a 6 byte storage, when the power is still valid, the data will not be lost
void AXP192::Read6BytesStorage( uint8_t *bufPtr )
{
    // Address from 0x06 - 0x0B
    Wire1.beginTransmission(0x34);
    Wire1.write(0x06);
    Wire1.endTransmission();
    Wire1.requestFrom(0x34, 6);
    for( int i = 0; i < 6; ++i )
    {
        bufPtr[i] = Wire1.read();
    }
}

// AXP192 have a 6 byte storage, when the power is still valid, the data will not be lost
void AXP192::Write6BytesStorage( uint8_t *bufPtr )
{
    // Address from 0x06 - 0x0B
    Wire1.beginTransmission(0x34);
    Wire1.write(0x06);
    Wire1.write(bufPtr[0]);
    Wire1.write(0x07);
    Wire1.write(bufPtr[1]);
    Wire1.write(0x08);
    Wire1.write(bufPtr[2]);
    Wire1.write(0x09);
    Wire1.write(bufPtr[3]);
    Wire1.write(0x0A);
    Wire1.write(bufPtr[4]);
    Wire1.write(0x0B);
    Wire1.write(bufPtr[5]);
    Wire1.endTransmission();
}
*/
