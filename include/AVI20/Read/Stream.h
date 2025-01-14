#pragma once

#include <AVI20/AVI20Types.h>
#include <AVI20/Read/IStream.h>
#include <AVI20/AviFileWrapper.h>
#include <istream>

NAMESPACE_AVI20_WRITE_BEGIN
class Stream;
NAMESPACE_AVI20_WRITE_END

NAMESPACE_AVI20_READ_BEGIN

class AVI20_API Stream : public IStream
{
public:
   Stream(AviFileWrapper* file = NULL) : _File(file), _CachedSize(-1) {}
   Stream( Write::Stream& stream );

   bool IsNULL() const override;

   bool Read( uint8_t* dest, uint64_t size ) override;
   uint64_t Pos() override;
   void SetPos( uint64_t pos ) override;
   void SetPosToEnd() override;
   uint64_t Size() override;
   bool IsGood() const override;
   void Rewind() override;

private:

   template <typename T>
   T read()
   {
      T t;
      _File->read( (char *)&t, sizeof( T ) );
      return t;
   }
   AviFileWrapper* _File; // doesn't own
   int64_t       _CachedSize;
};

NAMESPACE_AVI20_READ_END