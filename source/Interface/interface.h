/*
 * Copyright (c) 2010 Steven Noonan <steven@uplinklabs.net>
 *                and Miah Clayton <miah@ferrousmoon.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __interface_h_included
#define __interface_h_included

#include "Graphics/surface.h"
#include "Interface/text.h"
#include "Interface/widget.h"
#include "Interface/window.h"

class Interface
{
protected:
    Data::LList<Widget *> m_widgetList;

    Window *m_dragWindow;
    Widget *m_activeWidget;

    TextUI *m_fpsWidget;
    TextUI *m_rendererWidget;

    Uint32 m_mousePointer;

	int   m_mouseX;
	int   m_mouseY;
	Uint8 m_lastButtonState;
	Uint8 m_buttonState;

public:
    Interface();
    virtual ~Interface();

    virtual void AddWidget                 ( Widget *_widget );

    virtual void SetDragWindow             ( Window *_window );
    virtual void SetWindowFocus            ( Window *_window );
    virtual void SetWidgetFocus            ( Widget *_widget );
    virtual Widget *InsideWidget           ( int _mouseX, int _mouseY );

	virtual void InitWidgets               ();
    virtual void UpdateFPS                 ( unsigned int _fps );
    virtual void UpdateRendererWidget      ();
    virtual void RenderMouse               ();
    virtual void RenderWidgets             ();
    virtual void RemoveWidget              ( Widget *_widget );
    virtual Widget *GetWidgetOfType        ( WidgetClass _widgetType );
    virtual Widget *MouseUpdate            ();
    virtual int SendEnterKey               ();

	virtual int MouseX                     () const;
	virtual int MouseY                     () const;
	virtual bool MouseLeft                 () const;
	virtual bool MouseRight                () const;
	virtual bool MouseLeftEdge             () const;
	virtual bool MouseRightEdge            () const;

    virtual void Update ();
};

extern Interface *g_interface;

#endif
