
#ifndef __F_TRANSLATION_TRANSLATOR_FACTORY_H__
#define __F_TRANSLATION_TRANSLATOR_FACTORY_H__

#include <sys/types.h>

#include <translation/translator.h>
#include <translation/translator_info.h>
#include <translation/translator_node.h>

namespace os
{
class TranslatorFactory
{
public:
    enum { ERR_NOT_ENOUGH_DATA = -1, ERR_UNKNOWN_FORMAT = -2, ERR_NO_MEM = -3 };
public:
    TranslatorFactory();
    ~TranslatorFactory();

    static TranslatorFactory* GetDefaultFactory();
    
    void LoadAll();

    status_t FindTranslator( const String& cSrcType, const String& cDstType,
			     const void* pData, size_t nLen, Translator** ppcTrans );

    int             GetTranslatorCount();
    TranslatorNode* GetTranslatorNode( int nIndex );
    TranslatorInfo  GetTranslatorInfo( int nIndex );
    Translator*     CreateTranslator( int nIndex );

private:
    struct Internal;
    Internal* m;
};
}
#endif



