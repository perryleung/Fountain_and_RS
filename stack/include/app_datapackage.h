#include <stdint.h>
#ifndef _APP_DATAPACKAGE  
#define _APP_DATAPACKAGE
#define PACKAGE_SIZE 1000
#define PICTUER_PACKAGE_SIZE 980
#define PICTUERHEADER_PACKAGE_SIZE 972
#define PICTUERDATA_PACKAGE_SIZE 980
/* struct App_DataPackage { */
  // uint8_t data_size;
  // uint8_t Package_type; //0 is set ID; 1 is config ID suscess
  // uint8_t DestinationID;
  // uint8_t SourceID;
  // char data_buffer[PACKAGE_SIZE];
  // uint16_t SerialNum;
/* }; */
struct App_DataPackage {
  uint8_t Package_type; //0：向协议栈设置节点ID；1：协议栈向客户端确认节点ID；2：询问其他节点ID；3 for drt ：4:发送消息;5:发送图片
  uint8_t SourceID;
  uint8_t DestinationID;
  uint8_t data_size;
  uint16_t SerialNum;
  char data_buffer[40];

};

struct ImagePackage{
    uint8_t Package_type;
    uint8_t SourceID;
    uint8_t DestinationID;
    uint8_t PictureID;
    uint16_t ImageHeight;
    uint16_t ImageWidth;
    uint32_t SerialNum;
    char data_buffer[PICTUER_PACKAGE_SIZE];
};
struct TestPackage {
  uint16_t SerialNum;
  uint8_t DestinationID;
  uint8_t SourceID;
  uint16_t data_size;
  char data_buffer[PACKAGE_SIZE];
};

struct ImageHeader{
    uint8_t Package_type;
    uint8_t SourceID;
    uint8_t DestinationID;
    uint8_t PictureID;
    uint16_t DataSize;
    uint32_t OffSet;
    uint32_t ImageSize;
    uint32_t CRCCheckSum;
    char data_buffer[PICTUERHEADER_PACKAGE_SIZE];
};

struct ImageData{
    uint8_t Package_type;
    uint8_t SourceID;
    uint8_t DestinationID;
    uint8_t PictureID;
    uint16_t DataSize;
    uint32_t OffSet;
    char data_buffer[PICTUERDATA_PACKAGE_SIZE];
};


#endif //_APP_DATAPACKAGE
