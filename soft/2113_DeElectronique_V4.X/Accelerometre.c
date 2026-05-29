#include "Accelerometre.h"
#include "main.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/pin_manager.h"
#include "Mc32Delays.h"
#include "DeElectronique.h"
#define DUMMY 0xA5



/**
 * @brief √âcrit la valeur du seuil AnyMotion dans le registre du capteur.
 * @param treshold Seuil AnyMotion (16 bits)
 */
void MC3419_WriteAnyMotionRegister (uint16_t treshold)
{
    uint8_t Value_8Bits;
  
    
    //ÔøΩcriture LSBs
    Value_8Bits = treshold & 0x00FF;
    writeRegister8(addr_AM_LSB, Value_8Bits);

    //ÔøΩcriture MSBs
    Value_8Bits = treshold >> 8;
    writeRegister8(addr_AM_MSB, Value_8Bits);
}

/**
 * @brief √âcrit la valeur de debounce AnyMotion dans le registre du capteur.
 * @param tresholda Valeur de debounce
 */
void MC3419_WriteAnyMotionDebounceRegister (uint8_t tresholda)
{
   
    
    writeRegister8(addr_AM_DB, tresholda);

   
}

/**
 * @brief Initialise le capteur MC34X9 avec la configuration par d√©faut.
 * @details Effectue un reset, configure la plage, la fr√©quence, les interruptions et met le capteur en mode actif.
 */
void MC3419_start()
{
  //Init Reset
  MC3419_reset();
 
  MC3419_stop();
 
  //Range: 2g
  MC3419_SetRangleCtrl(Range2g);
  //Sampling Rate: 50Hz by default
  MC3419_SetSampleRate(ODR50_Hz);
  // Set polarity for INT1
  MC3419_Pol_INT(GPIO1_INTN1_IAH | GPIO1_INTN1_IPP);
  // All interrupt on INT1
  //MC3419_FiFo_CTRL_REG(COMB_INT_EN);
  // Set active interrupt
  MC3419_INT_Enable(SHAKE_INT_EN|ANYM_INT_EN);
  // Set motion control
  MC3419_MotionCTRL(SHAKE_EN | ANYM_EN);
  // set pending
  MC3419_ReadIntStatusRegisterAndAck();
  // Set de Shake threshold
  MC3419_WriteShakeThresholdRegister(2000);
  MC3419_WriteAnyMotionRegister(2000);
  // Set de AnyMotion debounce 
  MC3419_WriteAnyMotionDebounceRegister(100);
  // Set de Shake Duration and P2P
  MC3419_WriteShakeDurationAndP2PRegister(1,10);
  
  //Mode: Active
  MC3419_wake();
  APP_WaitStart(50);
 
}

/**
 * @brief Initialise le capteur MC34X9 avec la configuration par d√©faut.
 * @details Effectue un reset, configure la plage, la fr√©quence, les interruptions et met le capteur en mode actif.
 */
void MC3419_start2()
{
  //Init Reset
  //MC3419_reset();
 
  MC3419_stop();
 
  //Range: 2g
  MC3419_SetRangleCtrl(Range2g);
  //Sampling Rate: 50Hz by default
  MC3419_SetSampleRate(ODR50_Hz);
  // Set polarity for INT1
  MC3419_Pol_INT(GPIO1_INTN1_IAH | GPIO1_INTN1_IPP);
  // All interrupt on INT1
  //MC3419_FiFo_CTRL_REG(COMB_INT_EN);
  // Set active interrupt
  MC3419_INT_Enable(SHAKE_INT_EN|ANYM_INT_EN);
  // Set motion control
  MC3419_MotionCTRL(SHAKE_EN | ANYM_EN);
  // set pending
  MC3419_ReadIntStatusRegisterAndAck();
  // Set de Shake threshold
  MC3419_WriteShakeThresholdRegister(2000);
  MC3419_WriteAnyMotionRegister(2000);
  // Set de AnyMotion debounce 
  MC3419_WriteAnyMotionDebounceRegister(100);
  // Set de Shake Duration and P2P
  MC3419_WriteShakeDurationAndP2PRegister(1,10);
  
  //Mode: Active
  MC3419_wake();
  APP_WaitStart(50);
 
}

/**
 * @brief D√©finit le mode de fonctionnement du capteur.
 * @param Mode Mode √† appliquer
 */
void MC3419_SetMode (MC3419_Mode Mode)
{
    uint8_t value;
    
    value = ReadRegister8(addr_MODE);
    value &= Mask_Mode;
    value |= Mode;
    
    writeRegister8(addr_MODE, value);
}

/**
 * @brief DÈfinit la plage de mesure du capteur.
 * @param Range Plage ‡ appliquer
 */
void MC3419_SetRangleCtrl (MC3419_Range Range)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_Range);
    value &= Mask_Range;
    value |= (Range << 4) & 0x70;
    writeRegister8(addr_Range, value);
}

/**
 * @brief D√©finit la frÈquence d'Èchantillonnage du capteur.
 * @param SampleRate FrÈquence ‡ appliquer
 */
void MC3419_SetSampleRate(MC3419_SamplRate SampleRate)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_SR);
    value &= 0x00;
    value |= SampleRate;
    writeRegister8(addr_SR, value);
}

/**
 * @brief Met le capteur en mode wake (actif).
 */
void MC3419_wake(void)
{
  //Set mode as wake
  MC3419_SetMode(WAKE);
}

/**
 * @brief Met le capteur en mode standby (veille).
 */
void MC3419_stop(void)
{
  //Set mode as Sleep
  MC3419_SetMode(STANDBY);
}

/**
 * @brief Effectue un reset initial du capteur.
 * @details Met le capteur en veille, attend, effectue un power-on-reset, dÈsactive les interruptions.
 */
void MC3419_reset(void)
{
  // Stand by mode
  MC3419_stop();

  APP_WaitStart(10);
 
  DISPLAYNONUM();
  // power-on-reset
  writeRegister8(addr_Reset, Reset);

  APP_WaitStart(50);
  
  // Disable interrupt
  writeRegister8(addr_INTR_CTRL, 
                 INTR_Desable);
//  delay(10);
//  // 1.00x Analog Gain
//  writeRegister8(0x2B, 0x00);
//  delay(10);
//  // DCM disable
//  writeRegister8(0x15, 0x00);

  APP_WaitStart(50);

}

/**
 * @brief Lit l'identifiant du capteur.
 * @return Valeur de l'ID
 */
uint8_t MC3419_ID (void)
{
    return ReadRegister8(addr_Chip_ID);
}

/**
 * @brief Lit un registre 8 bits du capteur.
 * @param address Adresse du registre
 * @return Valeur lue
 */
uint8_t ReadRegister8(uint8_t address)
{
    uint8_t readVal;
    
    SS1_SetValue(false);
    SPI1_Exchange8bit(0x80 | address);  //lecture (0=> premier bit ÔøΩ '1')
    SPI1_Exchange8bit(0x00);
    readVal = SPI1_Exchange8bit(DUMMY);
    SS1_SetValue(true);
    
    return (readVal);
}

/**
 * @brief √âcrit une valeur 8 bits dans un registre du capteur.
 * @param address Adresse du registre
 * @param data DonnÈe ‡†Ècrire
 */
void writeRegister8 (uint8_t address, uint8_t data)
{
    SS1_SetValue(false);
    SPI1_Exchange8bit(address);
    SPI1_Exchange8bit(data);
    SS1_SetValue(true);
}

/**
 * @brief D√©finit la polaritÈ des interruptions du capteur.
 * @param GPIO_CTRL Configuration GPIO
 */
void MC3419_Pol_INT(MC3419_GPIO_CTRL GPIO_CTRL)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_GPIO_CTRL);
    value &= Mask_GPIO_CTRL;
    value |= GPIO_CTRL;
    writeRegister8(addr_GPIO_CTRL, value);
}

/**
 * @brief Active les interruptions du capteur.
 * @param INTR_CTRL Masque d'interruptions ‡ activer
 */
void MC3419_INT_Enable (MC3419_INTR_CTRL INTR_CTRL)
{
    uint8_t value;
    MC3419_SetMode(STANDBY);
    value = ReadRegister8(addr_INTR_CTRL);
    value &= Mask_INT_CTRL;
    value |= INTR_CTRL;
    writeRegister8(addr_INTR_CTRL, value);
}

/**
 * @brief Configure le contrÙle de mouvement du capteur.
 * @param Motion Masque de configuration
 */
void MC3419_MotionCTRL (MC3419_MotionControl Motion)
{
    MC3419_SetMode(STANDBY);
    writeRegister8(addr_MOTION_CTRL, Motion);
}

/**
 * @brief Lit le registre de statut des interruptions du capteur.
 * @return Statut des interruptions
 */
uint8_t MC3419_ReadStatusRegister (void)
{
    uint8_t stats=0;
    //return ReadRegister8(addr_INTR_STAT);
    //modif pour clean interrupt
    stats  = ReadRegister8(addr_INTR_STAT);
    //writeRegister8(addr_INTR_STAT, stats);
    return stats;
}

/**
 * @brief Lit et acquitte le registre de statut des interruptions du capteur.
 * @return Valeur lue
 */
uint8_t MC3419_ReadIntStatusRegisterAndAck (void)
{
    uint8_t valueRead;
    
    valueRead = ReadRegister8(addr_INTR_STAT);
    writeRegister8(addr_INTR_STAT, 0);
    return valueRead;
}

/**
 * @brief Configure le registre de contrÙle FIFO du capteur.
 * @param ValCTRL Valeur de configuration
 * @return Valeur prÈcÈdente lue
 */
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

/**
 * @brief DÈfinit le seuil FIFO du capteur.
 * @param Fifo_Tresh Seuil FIFO
 */
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

/**
 * @brief Ècrit le seuil de dÈtection de secousse (Shake) dans le capteur.
 * @param Value Seuil Shake
 */
void MC3419_WriteShakeThresholdRegister (uint16_t Value)
{
    uint8_t Value_8Bit;
    
    Value_8Bit = Value & 0x00FF;
    writeRegister8(addr_SHK_LSB, Value_8Bit);
    Value_8Bit = Value >> 8;
    writeRegister8(addr_SHK_MSB, Value_8Bit);
}

/**
 * @brief √âcrit la dur√©e et la valeur P2P de secousse dans le capteur.
 * @param shakeDuration Dur√©e de secousse
 * @param shakeP2P Valeur P2P
 */
void MC3419_WriteShakeDurationAndP2PRegister (uint8_t shakeDuration, uint16_t shakeP2P)
{
    uint16_t value16Bits;
    uint8_t Value_8Bits;
    
    //concatÔøΩnation en une valeur 16 bits
    value16Bits = (((uint16_t)shakeDuration)<<12 | shakeP2P ) & 0x7FFF;
    
    //ÔøΩcriture LSBs
    Value_8Bits = value16Bits & 0x00FF;
    writeRegister8(addr_PK_P2P_DUR_LSB, Value_8Bits);

    //ÔøΩcriture MSBs
    Value_8Bits = value16Bits >> 8;
    writeRegister8(addr_PK_P2P_DUR_MSB, Value_8Bits);
}

/**
 * @brief Efface le registre de statut des interruptions du capteur.
 * @return Statut effac√©
 */
uint8_t MC3419_clearRegister (void)
{
    uint8_t stats=0;
    //return ReadRegister8(addr_INTR_STAT);
    //modif pour clean interrupt
    //stats  = ReadRegister8(addr_INTR_STAT);
    writeRegister8(addr_INTR_STAT, stats);
    return stats;
}

