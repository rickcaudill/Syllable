#ifndef __F_TRANSLATION_TRANSLATOR_NODE_H__
#define __F_TRANSLATION_TRANSLATOR_NODE_H__

#include <translation/translator.h>
#include <translation/translator_info.h>


namespace os
{
class TranslatorNode
{
public:
    TranslatorNode();
    virtual ~TranslatorNode();

    virtual int Identify( const String& cSrcType, const String& cDstType, const void* pData, int nLen ) = 0;
    virtual TranslatorInfo GetTranslatorInfo() = 0;
    virtual Translator*	   CreateTranslator() = 0;
private:
    void* m;
};
}
#endif
