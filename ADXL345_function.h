

#ifndef ADXL345_H_
#define ADXL345_H_
#include"I2CDevice.h"
#define BUFFER_SIZE 0x40

namespace exploringRPi {


class ADXL345_functionL345:protected I2CDevice{

public:

	/// An enumeration to define the gravity range of the sensor
	enum RANGE {
		PLUSMINUS_2_G 		= 0,//!< plus/minus 2g
		PLUSMINUS_4_G 		= 1,//!< plus/minus 4g
		PLUSMINUS_8_G 		= 2,//!< plus/minus 8g
		PLUSMINUS_16_G 		= 3 //!< plus/minus 16g
	};
	/// The resolution of the sensor. High is only available in +/- 16g range.
	enum RESOLUTION {
		NORMAL = 0,//!< NORMAL 10-bit resolution
		HIGH = 1   //!< HIGH 13-bit resolution
	};

private:
	unsigned int I2CBus, I2CAddress;
	unsigned char *registers;
	ADXL345_function::RANGE range;
	ADXL345_function::RESOLUTION resolution;
	short accelerationX, accelerationY, accelerationZ; // raw 2's complement values
	float pitch, roll;                                 // in degrees
	short combineRegisters(unsigned char msb, unsigned char lsb);
	void calculatePitchAndRoll();
	virtual int updateRegisters();

public:
	ADXL345_function(unsigned int I2CBus, unsigned int I2CAddress=0x53);
	virtual int readSensorState();

	virtual void setRange(ADXL345_function::RANGE range);
	virtual ADXL345_function::RANGE getRange() { return this->range; }
	virtual void setResolution(ADXL345_function::RESOLUTION resolution);
	virtual ADXL345_function::RESOLUTION getResolution() { return this->resolution; }

	virtual short getAccelerationX() { return accelerationX; }
	virtual short getAccelerationY() { return accelerationY; }
	virtual short getAccelerationZ() { return accelerationZ; }
	virtual float getPitch() { return pitch; }
	virtual float getRoll() { return roll; }

	virtual void displayPitchAndRoll(int No_iterations = 6);
	
    virtual int Publish_Message(int No_of_iterations = 20);


	virtual ~ADXL345_function();
};

} /* namespace exploringRPi */

#endif /* ADXL345_H_ */
