
#include "Accelerometre.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/pin_manager.h"
#include "Mc32Delays.h"
#define DUMMY 0xA5



void MC3419_WriteAnyMotionRegister (uint16_t treshold)
{
    uint8_t Value_8Bits;
  
    
    //écriture LSBs
    Value_8Bits = treshold & 0x00FF;
    writeRegister8(addr_AM_LSB, Value_8Bits);

    //écriture MSBs
    Value_8Bits = treshold >> 8;
    writeRegister8(addr_AM_MSB, Value_8Bits);
}

void MC3419_WriteAnyMotionDebounceRegister (uint8_t tresholda)
{
   
    
    writeRegister8(addr_AM_DB, tresholda);

   
}
//Initialize the MC34X9 sensor and set as the default configuration
void MC3419_start()
{
  //Init Reset
  MC3419_reset();
  MC3419_stop();
  
  //Range: 2g
  MC3419_SetRangleCtrl(Range8g);
  //Sampling Rate: 50Hz by default
  MC3419_SetSampleRate(ODR25_Hz);
  // Set polarity for INT1
  MC3419_Pol_INT(GPIO1_INTN1_IAH | GPIO1_INTN1_IPP);
  // All interrupt on INT1
  //MC3419_FiFo_CTRL_REG(COMB_INT_EN);
  // Set active interrupt
  MC3419_INT_Enable(SHAKE_INT_EN);
  // Set motion control
  MC3419_MotionCTRL(SHAKE_EN | ANYM_EN);
  // set pending
  MC3419_ReadIntStatusRegisterAndAck();
  // Set de Shake threshold
  MC3419_WriteShakeThresholdRegister(12300);
  // Set de AnyMotion debounce 
  MC3419_WriteAnyMotionDebounceRegister(0);
  //MC3419_WriteAnyMotionRegister(20);
  // Set de Shake Duration and P2P
  MC3419_WriteShakeDurationAndP2PRegister(0,6000);
  
  //Mode: Active
  MC3419_wake();
  delay_ms(50);
}

// Set the operation mode
void MC3419_SetMode (MC3419_Mode Mode)
{
    uint8_t value;
    
    value = ReadRegister8(addr_MODE);
    value &= Mask_Mode;
    value |= Mode;
    
    writeRegister8(addr_MODE, value);
}

// Set the range control
void MC3419_SetRangleCtrl (MC3419_Range Range)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_Range);
    value &= Mask_Range;
    value |= (Range << 4) & 0x70;
    writeRegister8(addr_Range, value);
}

// Set the sampling rate
void MC3419_SetSampleRate(MC3419_SamplRate SampleRate)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_SR);
    value &= 0x00;
    value |= SampleRate;
    writeRegister8(addr_SR, value);
}
// Set mode wake
void MC3419_wake(void)
{
  //Set mode as wake
  MC3419_SetMode(WAKE);
}
// Set mode Standby
void MC3419_stop(void)
{
  //Set mode as Sleep
  MC3419_SetMode(STANDBY);
}
//Initial reset
void MC3419_reset(void)
{
  // Stand by mode
  MC3419_stop();

  delay_ms(10);

  // power-on-reset
  writeRegister8(addr_Reset, Reset);

  delay_ms(50);

  // Disable interrupt
  writeRegister8(addr_INTR_CTRL, 
                 INTR_Desable);
//  delay(10);
//  // 1.00x Analog Gain
//  writeRegister8(0x2B, 0x00);
//  delay(10);
//  // DCM disable
//  writeRegister8(0x15, 0x00);

  delay_ms(50);
}

// Read ID
uint8_t MC3419_ID (void)
{
    return ReadRegister8(addr_Chip_ID);
}
// Read Register
uint8_t ReadRegister8(uint8_t address)
{
    uint8_t readVal;
    
    SS1_SetValue(false);
    SPI1_Exchange8bit(0x80 | address);  //lecture (0=> premier bit à '1')
    SPI1_Exchange8bit(0x00);
    readVal = SPI1_Exchange8bit(DUMMY);
    SS1_SetValue(true);
    
    return (readVal);
}
// write register
void writeRegister8 (uint8_t address, uint8_t data)
{
    SS1_SetValue(false);
    SPI1_Exchange8bit(address);
    SPI1_Exchange8bit(data);
    SS1_SetValue(true);
}
/*
// delay Xms
void delay(uint8_t Xms)
{
    uint32_t i;
    while (Xms--)
    {
        i = 8000;
        while (i--);
    }
}
*/
// Set the interrupts polarity
void MC3419_Pol_INT(MC3419_GPIO_CTRL GPIO_CTRL)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_GPIO_CTRL);
    value &= Mask_GPIO_CTRL;
    value |= GPIO_CTRL;
    writeRegister8(addr_GPIO_CTRL, value);
}

// Set interrupt enable
void MC3419_INT_Enable (MC3419_INTR_CTRL INTR_CTRL)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_INTR_CTRL);
    value &= Mask_INT_CTRL;
    value |= INTR_CTRL;
    writeRegister8(addr_INTR_CTRL, value);
}

// Set motion control
void MC3419_MotionCTRL (MC3419_MotionControl Motion)
{
    MC3419_SetMode(STANDBY);
    writeRegister8(addr_MOTION_CTRL, Motion);
}

// Status Register
// lecture registre bits de statuts
uint8_t MC3419_ReadStatusRegister (void)
{
    return ReadRegister8(addr_INTR_STAT);
}

// Interrupt pending
// lit le interrupt status register et quittance tous les bits
uint8_t MC3419_ReadIntStatusRegisterAndAck (void)
{
    uint8_t valueRead;
    
    valueRead = ReadRegister8(addr_INTR_STAT);
    writeRegister8(addr_INTR_STAT, 0);
    return valueRead;
}

// Set FIFO control
uint8_t MC3419_FiFo_CTRL_REG (MC3419_FIFO_CTRL ValCTRL)
{
    uint8_t value;
    uint8_t valueRead;
    
    valueRead = ReadRegister8(addr_FIFO_CTRL);
    value = valueRead;
    value |= ValCTRL;
    writeRegister8(addr_FIFO_CTRL, value);
    return valueRead;
}

void MC3419_FIFO_TRESHOLD (uint8_t Fifo_Tresh)
{
    uint8_t value;
    uint8_t valueRead;
    
    valueRead = ReadRegister8(addr_FIFO_CTRL_TR);
    value = valueRead;
    value &= Mask_FIFO_TH;
    value |= Fifo_Tresh;
    writeRegister8(addr_FIFO_CTRL_TR, value);
}

void MC3419_WriteShakeThresholdRegister (uint16_t Value)
{
    uint8_t Value_8Bit;
    
    Value_8Bit = Value & 0x00FF;
    writeRegister8(addr_SHK_LSB, Value_8Bit);
    Value_8Bit = Value >> 8;
    writeRegister8(addr_SHK_MSB, Value_8Bit);
}

void MC3419_WriteShakeDurationAndP2PRegister (uint8_t shakeDuration, uint16_t shakeP2P)
{
    uint16_t value16Bits;
    uint8_t Value_8Bits;
    
    //concaténation en une valeur 16 bits
    value16Bits = (((uint16_t)shakeDuration)<<12 | shakeP2P ) & 0x7FFF;
    
    //écriture LSBs
    Value_8Bits = value16Bits & 0x00FF;
    writeRegister8(addr_PK_P2P_DUR_LSB, Value_8Bits);

    //écriture MSBs
    Value_8Bits = value16Bits >> 8;
    writeRegister8(addr_PK_P2P_DUR_MSB, Value_8Bits);
}

