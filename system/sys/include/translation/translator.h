/*  libsyllable.so - the highlevel API library for Syllable
 *  Copyright (C) 1999 - 2001 Kurt Skauen
 *  Copyright (C) 2003 Syllable Team
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of version 2 of the GNU Library
 *  General Public License as published by the Free Software
 *  Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 *  MA 02111-1307, USA
 */

#ifndef __F_TRANSLATION_TRANSLATOR_H__
#define __F_TRANSLATION_TRANSLATOR_H__

#include <sys/types.h>

#include <gui/rect.h>
#include <gui/guidefines.h>
#include <util/messenger.h>
#include <util/message.h>
#include <util/string.h>
#include <translation/datareceiver.h>

static const char* TRANSLATOR_TYPE_IMAGE = "image/x-atheos_trans";


namespace os
{
class Translator
{
public:
    enum { ERR_OK = 0, ERR_INVALID_DATA = -1, ERR_SUSPENDED = -2 };
public:
    Translator();
    virtual ~Translator();

    
    void    SetMessage( const Message& cMsg );
    void    SetTarget( const Messenger& cTarget, bool bSendData );
    void    SetTarget( DataReceiver* pcTarget );

    virtual void     SetConfig( const Message& cConfig ) = 0;
    virtual status_t AddData( const void* pData, size_t nLen, bool bFinal );
    virtual ssize_t  AvailableDataSize() = 0;
    virtual ssize_t  Read( void* pData, size_t nLen ) = 0;
    virtual void     Abort() = 0;
    virtual void     Reset() = 0;

	static os::String GetExtensionPath();
protected:
    virtual status_t DataAdded( void* pData, size_t nLen, bool bFinal );
    void Invoke( void* pData, size_t nSize, bool bFinal );
private:
    struct Internal;

    Internal* m;
};   
} // end of namespace

#endif // __F_TRANSLATION_TRANSLATOR_H__





