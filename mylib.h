#ifndef mylib_H
#define mylib_H
#include <Arduino.h>


class mylib {
public:
    mylib();
    void OW_Set();
    unsigned char DIRECT_MODE();
    unsigned char OW_Reset();
  	unsigned char OW_ReadBit();
  	unsigned char OW_ReadByte();
  	void OW_WriteBit();
	void OW_WriteByte();
private:
	
};
#endif
