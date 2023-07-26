#ifndef AVI_FILE_WRAPPER_H
#define AVI_FILE_WRAPPER_H

#include <iostream>

class AviFileWrapper {
public:
  AviFileWrapper() {}
  virtual ~AviFileWrapper() {}
  
  virtual void writeframe(bool isAudio, const char* data, uint64_t datalen) = 0;
  virtual void write(const char* data, uint64_t datalen) = 0;
  virtual void read(char* data, uint64_t datalen) = 0;
  virtual void seekp(uint64_t pos, std::ios::seekdir pt = std::ios::beg) = 0;
  virtual void seekg(uint64_t pos, std::ios::seekdir pt = std::ios::beg) = 0;
  virtual uint64_t tellp() = 0;
  virtual uint64_t tellg() = 0;
  virtual bool good() = 0;
  virtual void clear() = 0;
};

#endif  // AVI_FILE_WRAPPER_H
