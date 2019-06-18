/*
 *      Copyright (C) 2005-2014 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "WinSystemX11.h"
#include "utils/GlobalsHandling.h"
#include "rendering/gles/RenderSystemGLES.h"
#include "platform/linux/OptionalsReg.h"
#include "GLContextEGL.h"
#include "EGL/egl.h"

class CWinSystemX11GLESContext : public CWinSystemX11, public CRenderSystemGLES
{
public:
  CWinSystemX11GLESContext();
  virtual ~CWinSystemX11GLESContext();

  bool InitWindowSystem() override;
  CRenderSystemBase *GetRenderSystem() override { return this; }
  bool CreateNewWindow(const std::string& name, bool fullScreen, RESOLUTION_INFO& res) override;
  bool ResizeWindow(int newWidth, int newHeight, int newLeft, int newTop) override;
  bool SetFullScreen(bool fullScreen, RESOLUTION_INFO& res, bool blankOtherDisplays) override;
  bool DestroyWindowSystem() override;
  bool DestroyWindow() override;

  bool IsExtSupported(const char* extension) const override;

  EGLDisplay GetEGLDisplay() const { return  m_pGLContext->m_eglDisplay; }
  EGLSurface GetEGLSurface() const { return  m_pGLContext->m_eglSurface; }
  EGLContext GetEGLContext() const { return  m_pGLContext->m_eglContext; }
  EGLConfig GetEGLConfig() const { return  m_pGLContext->m_eglConfig; }

protected:
  bool SetWindow(int width, int height, bool fullscreen, const std::string &output, int *winstate = NULL) override;
  void PresentRenderImpl(bool rendered) override;
  void SetVSyncImpl(bool enable) override;
  virtual bool RefreshGLContext(bool force);
  XVisualInfo* GetVisual() override;

  CGLContextEGL *m_pGLContext = nullptr;
  bool m_newGlContext;

  std::unique_ptr<OPTIONALS::CLircContainer, OPTIONALS::delete_CLircContainer> m_lirc;
};

