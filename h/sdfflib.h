#pragma once

//-----------------------------------------------------------------------------
/*
  SDFFlib - high quality text rendering library for Marmalade SDK
  version 0.95b, October 7th, 2014

  Copyright (C) 2014 Boris Panov aka Danqon

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Boris Panov danqon@mail.ru

*/
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// SDFFlib API (ver 0.95b)
//-----------------------------------------------------------------------------

#ifndef _sdffont_h
#define _sdffont_h

#include "s3e.h"
#include "IwGx.h"
#include "IwResManager.h"

#define SDF_FONT_ALIGN_LEFT		0x00
#define SDF_FONT_ALIGN_CENTRE	0x01
#define SDF_FONT_ALIGN_RIGHT	0x02
#define SDF_FONT_ALIGN_TOP		0x04
#define SDF_FONT_ALIGN_MIDDLE	0x08
#define SDF_FONT_ALIGN_BOTTOM	0x10
#define SDF_FONT_NOWORDWRAP		0x20
#define SDF_FONT_ONELINE		0x40
#define SDF_FONT_NOOVERFLOW		0x80
#define SDF_FONT_NOWORDSPLIT	0x100
#define SDF_FONT_RIGHTTOLEFT	0x200

#define SDF_FONT_ENCODING_UTF8	0x00
#define SDF_FONT_ENCODING_ANSI	0x01

#define SDF_FONT_STYLE_SHARP	0x00
#define SDF_FONT_STYLE_SMOOTH	0x01
#define SDF_FONT_STYLE_ITALIC	0x02
#define SDF_FONT_STYLE_BOLD		0x04
#define SDF_FONT_STYLE_OUTLINE	0x08

#define SDF_FONT_SMOOTH_AUTO	-1.0f

#define IS_IN_RANGE(c,f,l) (((c)>=(f))&&((c)<=(l)))

void SDFFontInit();
void SDFFontTerminate();

#define SDF_PAGEINFO struct _sdf_pageinfo
SDF_PAGEINFO {
    char fname[64];
    CIwTexture* texture;
};

#define SDF_FILECHARINFO struct _sdf_filecharinfo
SDF_FILECHARINFO {
    uint32 id;
    uint16 x;
    uint16 y;
    uint16 width;
    uint16 height;
    int16 xoffset;
    int16 yoffset;
    int16 xadvance;
    uint16 page;
};

#define SDF_CHARINFO struct _sdf_charinfo
SDF_CHARINFO {
    uint32 id;
    CIwFVec2 uv[4];
    uint16 width;
    uint16 height;
    int16 xoffset;
    int16 yoffset;
    int16 xadvance;
    uint16 page;
};

#define SDF_REND_BATCH struct _sdf_rend_batch
SDF_REND_BATCH {
    uint16 material;
    uint16 index;
};

class CSDFFontTextData {
public:
    uint32 nchars;
    uint32 hash;
    float x;
    float y;
    float scale;
    float angle;
    float rect_width;
    float rect_height;
    uint32 color;
    uint32 bcolor;
    float interval;
    float kerning;
    uint16 flags;
    uint8 style;
    float softness;
    float bwidth;
    uint32 count;
    CIwFVec2* verts_stream;
    CIwFVec2* uvs_stream;
    uint16* inds_stream;
    uint16 nbatches;
    SDF_REND_BATCH* batches;
    uint32 nlines;
    float mwidth;
    float mheight;
    bool temp;
    CSDFFontTextData(bool bTemporary=false) {
        memset(this,0,sizeof(CSDFFontTextData));
        temp=bTemporary;
    }
    ~CSDFFontTextData() {
        if (!temp) {
            if (verts_stream) delete [] verts_stream;
            if (uvs_stream) delete [] uvs_stream;
            if (inds_stream) delete [] inds_stream;
            if (batches) delete [] batches;
        }
    }
    void ShiftDataXY(float fDx,float fDy) {
        uint32 N=count*4;
        for (uint32 i=0; i<N; i++) {
            verts_stream[i].x+=fDx;
            verts_stream[i].y+=fDy;
        }
    }
};

#define SDF_LINEINFO struct _sdf_lineinfo
SDF_LINEINFO {
    char* start;
    char* end;
    float xoffset;
    float yoffset;
    float width;
    float height;
};

class CSDFFontFormatData {
public:
    uint32 nchars;
    uint32 count;
    uint32 nlines;
    SDF_LINEINFO* lines;
    float width;
    float height;
    CSDFFontFormatData() {
        memset(this,0,sizeof(CSDFFontFormatData));
    }
    ~CSDFFontFormatData() {
        if (lines) delete [] lines;
    }
};

class CSDFFontRenderBuffer {
public:
    CIwMaterial* material;
    CIwFVec2* verts_stream;
    CIwFVec2* uvs_stream;
    uint16* inds_stream;
    uint16 size;
    uint16 count;
    CSDFFontRenderBuffer() {
        memset(this,0,sizeof(CSDFFontRenderBuffer));
    }
    void SetSize(uint16 uSize);
    void AddChars(CIwMaterial* pMaterial,CIwFVec2* pVerts,CIwFVec2* pUvs,uint16* pInds,uint16 uNum=1);
};

class CSDFFont {
protected:
    uint16 fontsize;
    uint16 lineHeight;
    uint16 base;
    uint16 spread;
    uint16 scaleW;
    uint16 scaleH;
    uint16 pages_count;
    uint16 chars_count;
    SDF_PAGEINFO* pages;
    SDF_CHARINFO* chars;
    bool loaded;

    float scale;
    float interval;
    float kerning;
    float indent;
    uint32 color;
    uint32 bcolor;
    uint16 flags;
    uint8 encoding;
    uint8 style;
    float softness;
    float bwidth;

    float rect_width;
    float rect_height;
    CSDFFontRenderBuffer* rendbuf;

    void Clear();
    void Init();
    void LoadTextures(char* path);
    uint32 GetStrHash(char* str);
    uint32 GetUTF8StrLen(const char* str);
    uint32 GetUTF8Char(const char* ptr,uint32* chr);
    int GetCharIndex(uint32 chr);
    float pointScale;

public:
    static CIwGxShaderTechnique* shader1;
    static CIwGxShaderTechnique* shader2;
    static CIwGxShaderTechnique* shader3;

    CSDFFont();
    ~CSDFFont();

    bool Load(const char* cFname);

    uint16 GetBaseSize() {
        return base;
    }
    uint16 GetLineHeight() {
        return lineHeight;
    }
    uint16 GetSpread() {
        return spread;
    }
    SDF_CHARINFO* GetCharInfo(uint32 chr);

    void SetRect(float fWidth=0.0f,float fHeight=0.0f) {
        rect_width=(fWidth>0.0f)?fWidth:0.0f;
        rect_height=(fHeight>0.0f)?fHeight:0.0f;
    };
    void GetRect(float* pfWidth,float* pfHeight) {
        if (pfWidth) *pfWidth=rect_width;
        if (pfHeight) *pfHeight=rect_height;
    }
    void SetScale(float fScale=1.0f) {
        scale=fScale>0.0f?fScale:scale;
    }
    void SetSize(float size) {
        SetScale(size * pointScale);
    }
    void SetPointScale(float scale) {
        pointScale = scale;
    }
    float GetScale() {
        return scale;
    }
    void SetInterval(float fInterval=1.0f) {
        interval=fInterval>0.0f?fInterval:interval;
    }
    float GetInterval() {
        return interval;
    }
    void SetKerning(float fKerning=0.0f) {
        kerning=fKerning;
    }
    float GetKerning() {
        return kerning;
    }
    void SetIndent(float fIndent=0.0f) {
        indent=fIndent>=0.0f?fIndent:indent;
    }
    float GetIndent() {
        return indent;
    }
    void SetColor(uint32 uColor) {
        color=uColor;
    }
    uint32 GetColor() {
        return color;
    }
    void SetBorderColor(uint32 uColor) {
        bcolor=uColor;
    }
    uint32 GetBorderColor() {
        return bcolor;
    }
    void SetFlags(uint16 uFlags=0) {
        flags=uFlags;
    }
    uint16 GetFlags() {
        return flags;
    }
    void SetEncoding(uint8 uEncoding) {
        encoding=uEncoding;
    }
    uint8 GetEncoding() {
        return encoding;
    }
    void SetStyle(uint8 uStyle=0) {
        style=uStyle;
    }
    uint8 GetStyle() {
        return style;
    }
    void SetSmooth(float fSmooth=SDF_FONT_SMOOTH_AUTO) {
        softness=(fSmooth>=0.0f&&fSmooth<=0.3f)?fSmooth:SDF_FONT_SMOOTH_AUTO;
    }
    float GetSmooth() {
        return softness;
    }
    void SetBorderWidth(float fBorderWidth=0.15f) {
        bwidth=(fBorderWidth>=0.0f&&fBorderWidth<=0.15f)?fBorderWidth:0.15f;
    }
    float GetBorderWidth() {
        return bwidth;
    }
    void SetParams(uint16 uFlags=0,uint8 uStyle=SDF_FONT_STYLE_SHARP,float fScale=1.0f,uint32 uColor=0xffffffff,float fWidth=0.0f,float fHeight=0.0f,float fInterval=1.0f) {
        SetFlags(uFlags);
        SetStyle(uStyle);
        SetScale(fScale);
        SetColor(uColor);
        SetRect(fWidth,fHeight);
        SetInterval(fInterval);
    }

    void PrepareTextData(CSDFFontTextData** ppTextData,float fX,float fY,char* cText,float fAngle=0.0f);
    void GetTextDimensions(CSDFFontTextData* pTextData,float* pfWidth,float* pfHeight,uint32* puNChars=NULL,uint32* puNLines=NULL);
    void GetTextDimensions(const char* cText,float* pfWidth,float* pfHeight,uint32* puNChars=NULL,uint32* puNLines=NULL);
    void PrepareFormatData(CSDFFontFormatData** ppFormatData,char* cText);
    void DrawText(float fX,float fY,char* cText,float fAngle=0.0f);
    void DrawTextData(CSDFFontTextData* pTextData);

    CSDFFontRenderBuffer* CreateRenderBuffer(uint16 uBufsize);
    void SetRenderBuffer(CSDFFontRenderBuffer* pRendbuffer=NULL);
    void DrawRenderBuffer(CSDFFontRenderBuffer* pRendbuffer);
};

#endif