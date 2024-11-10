#ifndef __F_TRANSLATION_TRANSLATOR_INFO_H__
#define __F_TRANSLATION_TRANSLATOR_INFO_H__


#include <util/string.h>
#include <vector>


struct TranslatorInfo
{
	os::String m_cAuthor;
	os::String m_cDateCreated;
	os::String m_cSourceType;
	os::String m_cDestType;
	os::String m_cInfo;
	std::vector<os::String> m_cMimeTypes;
    float	m_vQuality;
};

#endif


