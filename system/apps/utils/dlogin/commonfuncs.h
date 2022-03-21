//  Sourcery -:-  (C)opyright 2003-2004 Rick Caudill
//
// This is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef COMMON_FUNCS_H
#define COMMON_FUNCS_H

//libsyllable
#include <util/string.h>
#include <util/datetime.h>
#include <gui/image.h>
#include <util/resources.h>
#include <syllable/image.h>
#include <syllable/sysinfo.h>
#include <syllable/power.h>
#include <gui/desktop.h>
#include <gui/point.h>
#include <gui/window.h>


class MainWindow;

using namespace os;

String				GetDateAndTime();
String				GetApplicationPath();
os::BitmapImage* 	LoadImageFromResource( const os::String &cName );
os::BitmapImage*	GetImageFromIcon(const os::String& cName);
String				GetSystemInfo();
IPoint				GetResolution();
int 				BecomeUser(struct passwd *psPwd );

#endif  //_COMMON_FUNCS_H_

