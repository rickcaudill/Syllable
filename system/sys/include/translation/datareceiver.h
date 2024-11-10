#ifndef __F_TRANSLATION_DATARECEIVER_H__
#define __F_TRANSLATION_DATARECEIVER_H__

namespace os
{
class DataReceiver
{
public:
    DataReceiver();
    virtual ~DataReceiver();

    virtual void DataReady( void* pData, size_t nLen, bool bFinal ) = 0;
private:
    void* m;
};
}
#endif

