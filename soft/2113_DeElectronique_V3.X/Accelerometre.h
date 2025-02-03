/* 
 * File:   Accelerometre.h
 * Author: maxcolloud
 *
 * Created on October 20, 2021, 10:06 AM
 */

#ifndef ACCELEROMETRE_H
#define	ACCELEROMETRE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#define addr_GPIO_CTRL          0x33      // Configuration Interupt
#define addr_DEV_STAT           0x05
#define addr_INTR_CTRL          0x06
#define addr_MODE               0x07
#define addr_SR                 0x08
#define addr_MOTION_CTRL        0x09
#define addr_FIFO_STAT          0x0A
#define addr_FIFO_R_P           0x0B
#define addr_FIFO_W_P           0x0C
#define addr_Xout_Ex_L          0x0D
#define addr_Xout_Ex_H          0x0E
#define addr_Yout_Ex_L          0x0F
#define addr_Yout_Ex_H          0x10
#define addr_Zout_Ex_L          0x11
#define addr_Zout_Ex_H          0x12
#define addr_Status             0x13
#define addr_INTR_STAT          0x14
#define addr_Chip_ID            0x18
#define addr_Reset              0x1C
#define addr_Range              0x20
#define addr_XOFFL              0x21
#define addr_XOFFH              0x22
#define addr_XGAIN8             0x22
#define addr_XGAIN              0x27
#define addr_YOFFL              0x23
#define addr_YOFFH              0x24
#define addr_YGAIN8             0x24
#define addr_YGAIN              0x28
#define addr_ZOFFL              0x25
#define addr_ZOFFH              0x26
#define addr_ZGAIN8             0x26
#define addr_ZGAIN              0x29
#define addr_FIFO_CTRL          0x2D
#define addr_FIFO_CTRL_TR       0x2E
#define addr_FIFO_INTR          0x2F
#define addr_FIFO_CTRL2_SR2     0x30
#define addr_COMM_CTRL          0x31
#define addr_TF_LSB             0x40
#define addr_TF_MSB             0x41
#define addr_TF_SB              0x42
#define addr_AM_LSB             0x43
#define addr_AM_MSB             0x44
#define addr_AM_DB              0x45
#define addr_SHK_LSB            0x46
#define addr_SHK_MSB            0x47
#define addr_PK_P2P_DUR_LSB     0x48
#define addr_PK_P2P_DUR_MSB     0x49
#define addr_TIMER_CTRL         0x4A
#define addr_RD_CNT             0x4B
    
    // GPIO Control Register (Read / Write)
typedef enum
{
    GPIO1_INTN1_IAH   = 0x04,      // 1 = acitf haut
    GPIO1_INTN1_IPP   = 0x08,      // 0 = open-drain, 1 = push-pull
    GPIO2_INT2_IAH    = 0x40,
    GPIO2_INTN2_IPP   = 0x80,
    Mask_GPIO_CTRL    = 0x33,
} MC3419_GPIO_CTRL;
    
    // Device Status Register (Read)
typedef enum
{
    STANDBY_STAT    = 0x00,
    WAKE_STAT       = 0x01,
    RES_MODE        = 0x04,
    I2C_WDT         = 0x10,
    OTP_BUSY        = 0x80,
} MC3419_DeviceStat;

    // Interrupt enable register (Write)
typedef enum
{
    INTR_Desable    = 0x00,
    TILT_INT_EN     = 0x01,
    FLIP_INT_EN     = 0x02,
    ANYM_INT_EN     = 0x04,
    SHAKE_INT_EN    = 0x08,
    TILT_35_INT_EN  = 0x10,
    AUTO_CLR_EN     = 0x40,
    ACQ_INT_EN      = 0x80,
    Mask_INT_CTRL   = 0x20,
} MC3419_INTR_CTRL;
    
    // Mode Register (Write Only)
typedef enum
{
    SLEEP           = 0x00,
    STANDBY         = 0x03,
    WAKE            = 0x01,
//    I2C_WDT_NEG     = 0x10,
//    I2C_WDT_POS     = 0x20,
    Mask_Mode       = 0xF0,
} MC3419_Mode;
    
    // Sample Rate Register (For SPI <= 4MHz) (Read / Write)
typedef enum
{
    ODR25_Hz       = 0x10,
    ODR50_Hz       = 0x11,
    ODR62_5_Hz     = 0x12,
    ODR100_Hz      = 0x13,
    ODR125_Hz      = 0x14,
    ODR250_Hz      = 0x15,
    ODR500_Hz      = 0x16,
    ODR1000_Hz     = 0x17,
} MC3419_SamplRate;
    
    // Motion Control Register
typedef enum
{
    TF_ENABLE           = 0x01,
    MOTION_LATCH        = 0x02,
    ANYM_EN             = 0x04,
    SHAKE_EN            = 0x08,
    TILT_35_EN          = 0x10,
    Z_AXIS_ORT          = 0x20,
    RAW_PROC_STAT       = 0x40,
    MOTION_RESET        = 0x80,
} MC3419_MotionControl;

    
    // FIFO Status Register (Read Only)
typedef enum
{
    EMPTY           = 0x01,
    FULL            = 0x02,
    TRESH           = 0x04,
} MC3419_FIFO_Stat;
    
    // FIFO Read Pointer Register (Read Only)
typedef enum
{
    FIFO_RD_PTR     = 0x1F,
    FIFO_RD_PTR5    = 0x20,
} MC3419_FIFO_ReadPointer;

    
    // FIFO Write Pointer Register (Read Only)
typedef enum
{
    FIFO_WR_PTR     = 0x1F,
    FIFO_WR_PTR5    = 0x20,
} MC3419_FIFO_WPointer;

    // Status Register (Read)
typedef enum
{
    TILT_FLAG       = 0x01,
    FLIP_FLAG       = 0x02,
    ANYM_FLAG       = 0x04,
    SHAKE_FLAG      = 0x08,
    TILT_35_FLAG    = 0x10,
    FIFO_FLAG       = 0x20,
    NEW_DATA        = 0x80,
} MC3419_Status;
    
    // Interrupt Satus Register (Read / Write)
typedef enum
{
    TILT_INT            = 0x01,
    FLIP_INT            = 0x02,
    ANYM_INT            = 0x04,
    SHAKE_INT           = 0x08,
    TILT_35_INT         = 0x10,
    FIFO_INT            = 0x20,
    ACQ_INT             = 0x80,
    Mask_INTR_STATUS    = 0x60,
} MC3419_INTR_Status;

    // Reset Control (Read / Write)
typedef enum
{
    Reset           = 0x40, // 0 = normal operation 1 = force reset
} MC3419_Reset_CTRL;

    // Range And Scale Control Register (Write)
typedef enum
{
    Range2g     = 0x00,
    Range4g     = 0x10,
    Range8g     = 0x20,
    Range16g    = 0x30,
    Range12g    = 0x40,
    Mask_Range  = 0x07,
    Range       = 0x70,
    LPF_EN      = 0x08,
    LPF         = 0x07,
} MC3419_Range;
    
    // X-AXIS Digital Offset Register (Write)
typedef enum
{
    MASK_XOFFH_DOR  = 0x80,
} MC3419_XOFF;

    // X-AXIS Digital Gain Register (Write)
typedef enum
{
    MASK_XOFFH8     = 0x80,
} MC3419_XGAIN;

    // Y-AXIS Digital Offset Register (Write)
typedef enum
{
    MASK_YOFFH_DOR  = 0x80,
} MC3419_YOFF;

    // Y-AXIS Digital Gain Register (Write)
typedef enum
{
    MASK_YOFFH8     = 0x80,
} MC3419_YGAIN;
    
    // Z-AXIS Digital Offset Register (Write)
typedef enum
{
    MASK_ZOFFH_DOR  = 0x80,
} MC3419_ZOFF;

    // Z-AXIS Digital Gain Register (Write)
typedef enum
{
    MASK_ZOFFH8     = 0x80,
} MC3419_ZGAIN;

    
    // FIFO Control Register (Read / Write)
typedef enum
{
    ALL_FIFO_CTRL_DIS   = 0x00,
    FIFO_EMPTY_INT_EN   = 0x01,
    FIFO_FULL_INT_EN    = 0x02,
    FIFO_TH_INT_EN      = 0x04,
    COMB_INT_EN         = 0x08,
    FIFO_RESET          = 0x10,
    FIFO_EN             = 0x20,
    FIFO_MODE           = 0x40,
} MC3419_FIFO_CTRL;
    
    // FIFO Threshold Register (Read / Write)
typedef enum
{
    Mask_FIFO_TH        = 0xE0,
} MC3419_FIFO_THRESH_CTRL;

    
    // FIFO Interrupt Status Register (Read Only)
typedef enum
{
    EMPTY_INT           = 0x01,
    FULL_INT            = 0x02,
    TRESH_INT          = 0x40,
} MC3419_FIFO_INTR;

    
    // FIFO Controle Register2, Sample Rate Register2 (Read / Write)
typedef enum
{
    DEC_MODE_RATE           = 0x1F,
    ENABLE_WRAP_N           = 0x10,
    SELECT_WRAP_ADDR        = 0x20,
    FIFO_BURST_MODE         = 0x80,
} MC3419_FIFO_CTRL_2;

    
    // Communication Control Register (Read / Wrtie)
typedef enum
{
    INT1_INT2_REQ_SWAP  = 0x10,
    SPI_3WIRE_EN        = 0x20,
    INDIV_INTR_CLR      = 0x40,
} MC3419_COMM_CTRL;

    
    // TILP/FLIP Threshold register (Write)
typedef enum
{
    Mask_THRESH_TF_MSB  = 0x80,
} MC3419_TF_THRESH;

    // Anymotion Threshold Register (Write)
typedef enum
{
    Mask_THRESH_AM_MSB  = 0x80,
} MC3419_AM_THRESH;
    
    // Shake Duration, Peak-To_Peak Register (Write)
typedef enum
{
    Mask_PK_P2P_DUR_MSB      = 0x80,
} MC3419_PK_TRESH;
    
    // Timer Control register (Write)
typedef enum
{
    TILT_35             = 0x07,
    TEMP_PERIOD         = 0x70,
    TEMP_PER_INT_EN     = 0x80,
} MC3419_TIMER_CTRL;
    
    // Fonctions
    void MC3419_SetMode (MC3419_Mode Mode);
    void MC3419_SetRangleCtrl (MC3419_Range Range);
    void MC3419_SetSampleRate(MC3419_SamplRate SampleRate);
    void MC3419_wake(void);
    void MC3419_stop(void);
    void MC3419_reset(void);
    void MC3419_start(void);
    uint8_t MC3419_ID (void);
    uint8_t ReadRegister8(uint8_t address);
    void writeRegister8 (uint8_t address, uint8_t data);
    void delay(uint8_t Xms);
    void MC3419_Pol_INT(MC3419_GPIO_CTRL GPIO_CTRL);
    void MC3419_INT_Enable (MC3419_INTR_CTRL INTR_CTRL);
    void MC3419_MotionCTRL (MC3419_MotionControl Motion);
    uint8_t MC3419_ReadStatusRegister (void);
    uint8_t MC3419_ReadIntStatusRegisterAndAck (void);
    uint8_t MC3419_FiFo_CTRL_REG (MC3419_FIFO_CTRL ValCTRL);
    void MC3419_FIFO_TRESHOLD (uint8_t Fifo_Tresh);
    void MC3419_WriteShakeThresholdRegister (uint16_t Value);
    void MC3419_WriteShakeDurationAndP2PRegister (uint8_t shakeDuration, uint16_t shakeP2P);
    void MC3419_WriteAnyMotionDebounceRegister (uint8_t tresholda);
    
#ifdef	__cplusplus
}
#endif

#endif	/* ACCELEROMETRE_H */