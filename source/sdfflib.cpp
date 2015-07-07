#include "sdfflib.h"

CIwGxShaderTechnique* CSDFFont::shader1;
CIwGxShaderTechnique* CSDFFont::shader2;
CIwGxShaderTechnique* CSDFFont::shader3;

const uint32 sdff_shaders[]= {
    0x0007033d,0xe0870000,0x00158081,0x44530000,0x735f4646,0x65646168,0x00007372,0x77000000,0x14dc3c21,0x0100000c,
    0xc4000000,0x0362ab11,0x01000000,0x00032c01,0xe4c3f800,0x0001c2a3,0x61090a00,0x69727474,0x65747562,0x67696820,
    0x76207068,0x09346365,0x65566e69,0x0a3b7472,0x74746109,0x75626972,0x6d206574,0x75696465,0x7620706d,0x09326365,
    0x56556e69,0x0a0a3b30,0x696e7509,0x6d726f66,0x776f6c20,0x65762070,0x69093463,0x74614d6e,0x61697265,0x626d416c,
    0x746e6569,0x75090a3b,0x6f66696e,0x6c206d72,0x2070776f,0x34636576,0x456e6909,0x7373696d,0x3b657669,0x6e75090a,
    0x726f6669,0x6968206d,0x20706867,0x3474616d,0x506e6909,0x614d564d,0x090a3b74,0x66696e75,0x206d726f,0x6964656d,
    0x20706d75,0x32636576,0x556e6909,0x61635356,0x0a3b656c,0x6176090a,0x6e697972,0x656d2067,0x6d756964,0x65762070,
    0x6f093263,0x56557475,0x090a3b30,0x79726176,0x20676e69,0x70776f6c,0x63657620,0x756f0934,0x6c6f4374,0x76090a3b,
    0x69797261,0x6d20676e,0x75696465,0x6620706d,0x74616f6c,0x6f6d5309,0x4468746f,0x61747369,0x3b65636e,0x76090a0a,
    0x2064696f,0x6e69616d,0x696f7628,0x090a2964,0x090a7b09,0x5f6c6709,0x69736f50,0x6e6f6974,0x69203d20,0x564d506e,
    0x2a74614d,0x65566e69,0x0a3b7472,0x756f0909,0x30565574,0x69203d20,0x3056556e,0x556e692a,0x61635356,0x0a3b656c,
    0x756f0909,0x6c6f4374,0x69203d20,0x696d456e,0x76697373,0x090a3b65,0x6f6d5309,0x4468746f,0x61747369,0x2065636e,
    0x6e69203d,0x6574614d,0x6c616972,0x69626d41,0x2e746e65,0x2e332f78,0x3b333333,0x7d09090a,0x00090a20,0x00000154,
    0x6176090a,0x6e697972,0x656d2067,0x6d756964,0x65762070,0x6f093263,0x56557475,0x090a3b30,0x79726176,0x20676e69,
    0x70776f6c,0x63657620,0x756f0934,0x6c6f4374,0x76090a3b,0x69797261,0x6d20676e,0x75696465,0x6620706d,0x74616f6c,
    0x6f6d5309,0x4468746f,0x61747369,0x3b65636e,0x75090a0a,0x6f66696e,0x73206d72,0x6c706d61,0x44327265,0x536e6909,
    0x6c706d61,0x3b307265,0x76090a0a,0x2064696f,0x6e69616d,0x696f7628,0x090a2964,0x090a7b09,0x64656d09,0x706d7569,
    0x6f6c6620,0x64207461,0x41747369,0x6168706c,0x74203d20,0x75747865,0x44326572,0x536e6928,0x6c706d61,0x2c307265,
    0x5574756f,0x2e293056,0x090a3b61,0x776f6c09,0x65762070,0x72203463,0x20616267,0x756f203d,0x6c6f4374,0x09090a3b,
    0x61626772,0x2a20612e,0x6d73203d,0x68746f6f,0x70657473,0x352e3028,0x6f6d532d,0x4468746f,0x61747369,0x2c65636e,
    0x2b352e30,0x6f6f6d53,0x69446874,0x6e617473,0x642c6563,0x41747369,0x6168706c,0x090a3b29,0x5f6c6709,0x67617246,
    0x6f6c6f43,0x203d2072,0x61626772,0x09090a3b,0x090a207d,0x00000000,0x00032c00,0xc4ba7800,0x0001c2d9,0x61090a00,
    0x69727474,0x65747562,0x67696820,0x76207068,0x09346365,0x65566e69,0x0a3b7472,0x74746109,0x75626972,0x6d206574,
    0x75696465,0x7620706d,0x09326365,0x56556e69,0x0a0a3b30,0x696e7509,0x6d726f66,0x776f6c20,0x65762070,0x69093463,
    0x74614d6e,0x61697265,0x626d416c,0x746e6569,0x75090a3b,0x6f66696e,0x6c206d72,0x2070776f,0x34636576,0x456e6909,
    0x7373696d,0x3b657669,0x6e75090a,0x726f6669,0x6968206d,0x20706867,0x3474616d,0x506e6909,0x614d564d,0x090a3b74,
    0x66696e75,0x206d726f,0x6964656d,0x20706d75,0x32636576,0x556e6909,0x61635356,0x0a3b656c,0x6176090a,0x6e697972,
    0x656d2067,0x6d756964,0x65762070,0x6f093263,0x56557475,0x090a3b30,0x79726176,0x20676e69,0x70776f6c,0x63657620,
    0x756f0934,0x6c6f4374,0x76090a3b,0x69797261,0x6d20676e,0x75696465,0x6620706d,0x74616f6c,0x6f6d5309,0x4468746f,
    0x61747369,0x3b65636e,0x76090a0a,0x2064696f,0x6e69616d,0x696f7628,0x090a2964,0x090a7b09,0x5f6c6709,0x69736f50,
    0x6e6f6974,0x69203d20,0x564d506e,0x2a74614d,0x65566e69,0x0a3b7472,0x756f0909,0x30565574,0x69203d20,0x3056556e,
    0x556e692a,0x61635356,0x0a3b656c,0x756f0909,0x6c6f4374,0x69203d20,0x696d456e,0x76697373,0x090a3b65,0x6f6d5309,
    0x4468746f,0x61747369,0x2065636e,0x6e69203d,0x6574614d,0x6c616972,0x69626d41,0x2e746e65,0x2e332f78,0x3b333333,
    0x7d09090a,0x00090a20,0x00000154,0x6176090a,0x6e697972,0x656d2067,0x6d756964,0x65762070,0x6f093263,0x56557475,
    0x090a3b30,0x79726176,0x20676e69,0x70776f6c,0x63657620,0x756f0934,0x6c6f4374,0x76090a3b,0x69797261,0x6d20676e,
    0x75696465,0x6620706d,0x74616f6c,0x6f6d5309,0x4468746f,0x61747369,0x3b65636e,0x75090a0a,0x6f66696e,0x73206d72,
    0x6c706d61,0x44327265,0x536e6909,0x6c706d61,0x3b307265,0x76090a0a,0x2064696f,0x6e69616d,0x696f7628,0x090a2964,
    0x090a7b09,0x64656d09,0x706d7569,0x6f6c6620,0x64207461,0x41747369,0x6168706c,0x74203d20,0x75747865,0x44326572,
    0x536e6928,0x6c706d61,0x2c307265,0x5574756f,0x2e293056,0x090a3b61,0x776f6c09,0x65762070,0x72203463,0x20616267,
    0x756f203d,0x6c6f4374,0x09090a3b,0x61626772,0x2a20612e,0x6d73203d,0x68746f6f,0x70657473,0x342e3028,0x6f6d532d,
    0x4468746f,0x61747369,0x2c65636e,0x2b342e30,0x6f6f6d53,0x69446874,0x6e617473,0x642c6563,0x41747369,0x6168706c,
    0x090a3b29,0x5f6c6709,0x67617246,0x6f6c6f43,0x203d2072,0x61626772,0x09090a3b,0x090a207d,0x00000000,0x0005aa00,
    0xcf455700,0x00033c10,0x61090a00,0x69727474,0x65747562,0x67696820,0x76207068,0x09346365,0x65566e69,0x0a3b7472,
    0x74746109,0x75626972,0x6d206574,0x75696465,0x7620706d,0x09326365,0x56556e69,0x0a0a3b30,0x696e7509,0x6d726f66,
    0x776f6c20,0x65762070,0x69093463,0x74614d6e,0x61697265,0x626d416c,0x746e6569,0x75090a3b,0x6f66696e,0x6c206d72,
    0x2070776f,0x34636576,0x456e6909,0x7373696d,0x3b657669,0x6e75090a,0x726f6669,0x6f6c206d,0x76207077,0x09346365,
    0x614d6e69,0x69726574,0x69446c61,0x73756666,0x090a3b65,0x66696e75,0x206d726f,0x68676968,0x616d2070,0x69093474,
    0x564d506e,0x3b74614d,0x6e75090a,0x726f6669,0x656d206d,0x6d756964,0x65762070,0x69093263,0x5356556e,0x656c6163,
    0x090a0a3b,0x79726176,0x20676e69,0x6964656d,0x20706d75,0x32636576,0x74756f09,0x3b305655,0x6176090a,0x6e697972,
    0x6f6c2067,0x76207077,0x09346365,0x4374756f,0x0a3b6c6f,0x72617609,0x676e6979,0x776f6c20,0x65762070,0x6f093463,
    0x6f427475,0x72656472,0x3b6c6f43,0x6176090a,0x6e697972,0x656d2067,0x6d756964,0x6c662070,0x0974616f,0x6f6f6d53,
    0x69446874,0x6e617473,0x0a3b6563,0x72617609,0x676e6979,0x64656d20,0x706d7569,0x6f6c6620,0x6f097461,0x696c7475,
    0x614d656e,0x6c615678,0x3b306575,0x6176090a,0x6e697972,0x656d2067,0x6d756964,0x6c662070,0x0974616f,0x6c74756f,
    0x4d656e69,0x61567861,0x3165756c,0x76090a3b,0x69797261,0x6d20676e,0x75696465,0x6620706d,0x74616f6c,0x6e656309,
    0x3b726574,0x76090a0a,0x2064696f,0x6e69616d,0x696f7628,0x090a2964,0x090a7b09,0x5f6c6709,0x69736f50,0x6e6f6974,
    0x69203d20,0x564d506e,0x2a74614d,0x65566e69,0x0a3b7472,0x756f0909,0x30565574,0x69203d20,0x3056556e,0x556e692a,
    0x61635356,0x0a3b656c,0x756f0909,0x6c6f4374,0x69203d20,0x696d456e,0x76697373,0x090a3b65,0x74756f09,0x64726f42,
    0x6f437265,0x203d206c,0x4d6e6920,0x72657461,0x446c6169,0x75666669,0x0a3b6573,0x6d530909,0x68746f6f,0x74736944,
    0x65636e61,0x69203d20,0x74614d6e,0x61697265,0x626d416c,0x746e6569,0x332f782e,0x3333332e,0x09090a3b,0x6d09090a,
    0x75696465,0x6620706d,0x74616f6c,0x726f4220,0x20726564,0x6e69203d,0x6574614d,0x6c616972,0x69626d41,0x2e746e65,
    0x2e362f79,0x3b363636,0x6f09090a,0x696c7475,0x614d656e,0x6c615678,0x20306575,0x2e30203d,0x6f422d35,0x72656472,
    0x09090a3b,0x6c74756f,0x4d656e69,0x61567861,0x3165756c,0x30203d20,0x422b352e,0x6564726f,0x090a3b72,0x6e656309,
    0x20726574,0x756f203d,0x6e696c74,0x78614d65,0x756c6156,0x422d3065,0x6564726f,0x090a3b72,0x0a207d09,0x02580009,
    0x090a0000,0x79726176,0x20676e69,0x6964656d,0x20706d75,0x32636576,0x74756f09,0x3b305655,0x6176090a,0x6e697972,
    0x6f6c2067,0x76207077,0x09346365,0x4374756f,0x0a3b6c6f,0x72617609,0x676e6979,0x776f6c20,0x65762070,0x6f093463,
    0x6f427475,0x72656472,0x3b6c6f43,0x6176090a,0x6e697972,0x656d2067,0x6d756964,0x6c662070,0x0974616f,0x6f6f6d53,
    0x69446874,0x6e617473,0x0a3b6563,0x72617609,0x676e6979,0x64656d20,0x706d7569,0x6f6c6620,0x6f097461,0x696c7475,
    0x614d656e,0x6c615678,0x3b306575,0x6176090a,0x6e697972,0x656d2067,0x6d756964,0x6c662070,0x0974616f,0x6c74756f,
    0x4d656e69,0x61567861,0x3165756c,0x76090a3b,0x69797261,0x6d20676e,0x75696465,0x6620706d,0x74616f6c,0x6e656309,
    0x3b726574,0x75090a0a,0x6f66696e,0x73206d72,0x6c706d61,0x44327265,0x536e6909,0x6c706d61,0x3b307265,0x76090a0a,
    0x2064696f,0x6e69616d,0x696f7628,0x090a2964,0x090a7b09,0x64656d09,0x706d7569,0x6f6c6620,0x64207461,0x41747369,
    0x6168706c,0x74203d20,0x75747865,0x44326572,0x536e6928,0x6c706d61,0x2c307265,0x5574756f,0x2e293056,0x090a3b61,
    0x776f6c09,0x65762070,0x72203463,0x20616267,0x756f203d,0x6c6f4374,0x09090a3b,0x09090a09,0x61626772,0x7a79782e,
    0x6d203d20,0x72287869,0x2e616267,0x2c7a7978,0x4274756f,0x6564726f,0x6c6f4372,0x7a79782e,0x6f6d732c,0x7368746f,
    0x28706574,0x6c74756f,0x4d656e69,0x61567861,0x3165756c,0x74756f2c,0x656e696c,0x5678614d,0x65756c61,0x69642c30,
    0x6c417473,0x29616870,0x090a3b29,0x62677209,0x20612e61,0x73203d2a,0x746f6f6d,0x65747368,0x65632870,0x7265746e,
    0x6f6d532d,0x4468746f,0x61747369,0x2c65636e,0x746e6563,0x532b7265,0x746f6f6d,0x73694468,0x636e6174,0x69642c65,
    0x6c417473,0x29616870,0x09090a3b,0x6709090a,0x72465f6c,0x6f436761,0x20726f6c,0x6772203d,0x0a3b6162,0x207d0909,
    0x0000090a,0x00000000
};
const uint32 sdff_shaders_size=3131;

void SDFFontInit() {
    CIwResGroup* group=IwGetResManager()->LoadGroupFromMemory((uint8*)sdff_shaders,sdff_shaders_size);
    CSDFFont::shader1=(CIwGxShaderTechnique*)group->GetResNamed("sdf_font","CIwGxShaderTechnique");
    CSDFFont::shader2=(CIwGxShaderTechnique*)group->GetResNamed("sdf_font_bold","CIwGxShaderTechnique");
    CSDFFont::shader3=(CIwGxShaderTechnique*)group->GetResNamed("sdf_font_outline","CIwGxShaderTechnique");
}

void SDFFontTerminate() {
//if (CSDFFont::shader1) delete CSDFFont::shader1;
//if (CSDFFont::shader2) delete CSDFFont::shader2;
//if (CSDFFont::shader3) delete CSDFFont::shader3;
}

CSDFFont::CSDFFont() {
    memset(this,0,sizeof(CSDFFont));
}

CSDFFont::~CSDFFont() {
    Clear();
}

void CSDFFont::Clear() {
    if (pages) {
        for (uint16 i=0; i<pages_count; i++) {
            if (pages[i].texture) {
                delete pages[i].texture;
            }
        }
        delete [] pages;
    }
    if (chars) {
        delete [] chars;
    }
    memset(this,0,sizeof(CSDFFont));
}

void CSDFFont::Init() {
    scale=1.0f;
    interval=1.0f;
    kerning=0.0f;
    indent=0.0f;
    color=0xffffffff;
    bcolor=0xff000000;
    bwidth=0.15f;
    rect_width=0.0f;
    rect_height=0.0f;
    softness=SDF_FONT_SMOOTH_AUTO;
    flags=0;
    style=0;
    rendbuf=NULL;
}

bool CSDFFont::Load(const char* cFname) {
    Clear();

    s3eFile* file=NULL;
    SDF_FILECHARINFO* fchars=NULL;
    char path[193];
    char* sl=NULL;

    file=s3eFileOpen(cFname,"r");
    if (!file) {
        goto exit;
    }

    if (s3eFileRead(this,sizeof(int16),8,file)!=8||pages_count<=0||chars_count<=0) {
        goto exit;
    }

    pages=new SDF_PAGEINFO[pages_count];
    memset(pages,0,sizeof(SDF_PAGEINFO)*pages_count);
    if (s3eFileRead(this->pages,sizeof(SDF_PAGEINFO),pages_count,file)!=pages_count) {
        goto exit;
    }

    chars=new SDF_CHARINFO[chars_count];
    fchars=new SDF_FILECHARINFO[chars_count];
    if (s3eFileRead(fchars,sizeof(SDF_FILECHARINFO),chars_count,file)!=chars_count) {
        goto exit;
    }

    for (uint16 i=0; i<chars_count; i++) {
        float u1=(float)fchars[i].x/(float)scaleW,u2=u1+(float)fchars[i].width/(float)scaleW;
        float v1=(float)fchars[i].y/(float)scaleH,v2=v1+(float)fchars[i].height/(float)scaleH;
        chars[i].id=fchars[i].id;
        chars[i].uv[0].x=u1;
        chars[i].uv[0].y=v1;
        chars[i].uv[1].x=u1;
        chars[i].uv[1].y=v2;
        chars[i].uv[2].x=u2;
        chars[i].uv[2].y=v2;
        chars[i].uv[3].x=u2;
        chars[i].uv[3].y=v1;
        memcpy(&chars[i].width,&fchars[i].width,sizeof(int16)*6);
    }

    strncpy(path,cFname,192);
    sl=strrchr(path,'/');
    if (sl) {
        *(sl+1)=(char)0;
    } else {
        *path=(char)0;
    }

    LoadTextures(path);

    Init();

    loaded=true;

exit:

    if (fchars) {
        delete [] fchars;
    }
    if (file) {
        s3eFileClose(file);
    }

    return loaded;
}

void CSDFFont::LoadTextures(char* path) {
    char fname[256];
    for (uint16 i=0; i<pages_count; i++) {
        strncpy(fname,path,192);
        strcat(fname,pages[i].fname);
        pages[i].texture=new CIwTexture();
        pages[i].texture->LoadFromFile(fname);
        pages[i].texture->SetMipMapping(false);
        pages[i].texture->SetFiltering(true);
        pages[i].texture->Upload();
    }
}

uint32 CSDFFont::GetStrHash(char* str) {
    uint32 hash=1315423911,i=0;
    while (str[i]!=(char)0) {
        hash^=((hash<<5)+str[i++]+(hash>>2));
    }
    return hash;
}

uint32 CSDFFont::GetUTF8StrLen(const char* str) {
    uint32 i=0,j=0;
    while (str[i]) {
        if ((str[i]&0xc0)!=0x80) {
            j++;
        }
        i++;
    }
    return j;
}

uint32 CSDFFont::GetUTF8Char(const char* ptr,uint32* chr) {
    uint8 c1,c2;
    uint32 uc=0,seqlen=0;

    c1=ptr[0];
    if (c1==0) {
        return 0;
    }
    if((c1&0x80)==0) {
        uc=(uint32)(c1&0x7F);
        seqlen=1;
    } else if((c1&0xE0)==0xC0) {
        uc=(uint32)(c1&0x1F);
        seqlen=2;
    } else if((c1&0xF0)==0xE0) {
        uc=(uint32)(c1&0x0F);
        seqlen=3;
    } else if((c1&0xF8)==0xF0) {
        uc=(uint32)(c1&0x07);
        seqlen=4;
    }
    if (!seqlen) {
        return 0;
    }

    for(uint32 i=1; i<seqlen; i++) {
        if (((uint8)ptr[i]&0xC0)!=0x80||ptr[i]==0) {
            return 0;
        }
    }

    switch(seqlen) {
    case 2: {
        c1=ptr[0];
        if (!IS_IN_RANGE(c1,0xC2,0xDF)) {
            return 0;
        }
        break;
    }
    case 3: {
        c1=ptr[0];
        c2=ptr[1];
        if (((c1==0xE0)&&!IS_IN_RANGE(c2,0xA0,0xBF))||
                ((c1==0xED)&&!IS_IN_RANGE(c2,0x80,0x9F))||
                (!IS_IN_RANGE(c1,0xE1,0xEC)&&!IS_IN_RANGE(c1,0xEE,0xEF))) {
            return 0;
        }
        break;
    }
    case 4: {
        c1=ptr[0];
        c2=ptr[1];
        if (((c1==0xF0)&&!IS_IN_RANGE(c2,0x90,0xBF))||
                ((c1==0xF4)&&!IS_IN_RANGE(c2,0x80,0x8F))||
                !IS_IN_RANGE(c1,0xF1,0xF3)) {
            return 0;
        }
        break;
    }
    }

    for (uint32 i=1; i<seqlen; i++) {
        uc=((uc<<6)|(uint32)(ptr[i]&0x3F));
    }

    *chr=uc;
    return seqlen;
}

int CSDFFont::GetCharIndex(uint32 chr) {
    uint16 i;
    if (chr=='\n') {
        return -1;
    }
    for (i=0; i<chars_count; i++) {
        if (chars[i].id==chr) {
            break;
        }
    }
    return (i<chars_count)?(int)i:-2;
}

SDF_CHARINFO* CSDFFont::GetCharInfo(uint32 chr) {
    int ind=GetCharIndex(chr);
    if (ind>=0) {
        return &(chars[ind]);
    } else {
        return NULL;
    }
}

void CSDFFont::PrepareTextData(CSDFFontTextData** ppTextData,float fX,float fY,char* cText,float fAngle) {
    if (!loaded||!cText) {
        return;
    }

    uint32 N,hash;
    uint16 page;
    SDF_CHARINFO* chr;
    bool update_chars=true;
    bool difmat=false;
    static const uint16 quad_inds[6]= {0,1,2,2,3,0};

    if (!(*ppTextData)) {
        *ppTextData=new CSDFFontTextData(true);
    }
    CSDFFontTextData* tdata=*ppTextData;

    N=(encoding==SDF_FONT_ENCODING_UTF8)?GetUTF8StrLen(cText):strlen(cText);
    hash=GetStrHash(cText);

    if (N>0xffff) {
        return;
    }

    tdata->color=color;
    tdata->bcolor=bcolor;
    tdata->softness=softness;
    tdata->bwidth=bwidth;

    if (N==tdata->nchars&&hash==tdata->hash) {
        if (tdata->scale==scale&&tdata->angle==fAngle&&tdata->interval==interval&&tdata->kerning==kerning&&
                tdata->flags==flags&&tdata->style==style&&tdata->rect_width==rect_width&&tdata->rect_height==rect_height) {
            if (tdata->x!=fX||tdata->y!=fY) {
                tdata->ShiftDataXY(fX-tdata->x,fY-tdata->y);
            }
            tdata->x=fX;
            tdata->y=fY;
            return;
        }
        update_chars=false;
    } else {
        tdata->nchars=N;
        if (!tdata->temp) {
            if (tdata->uvs_stream) {
                delete [] tdata->uvs_stream;
            }
            tdata->uvs_stream=new CIwFVec2[N*4];
            if (tdata->batches) {
                delete [] tdata->batches;
            }
            tdata->batches=new SDF_REND_BATCH[pages_count];
        } else {
            tdata->uvs_stream=IW_GX_ALLOC(CIwFVec2,N*4);
            tdata->batches=IW_GX_ALLOC(SDF_REND_BATCH,pages_count);
        }
        tdata->nbatches=0;
        tdata->hash=hash;
    }

    tdata->x=fX;
    tdata->y=fY;
    tdata->scale=scale;
    tdata->interval=interval;
    tdata->kerning=kerning;
    tdata->flags=flags;
    tdata->style=style;
    tdata->rect_width=rect_width;
    tdata->rect_height=rect_height;

    if (!tdata->temp) {
        if (tdata->verts_stream) {
            delete [] tdata->verts_stream;
        }
        tdata->verts_stream=new CIwFVec2[N*4];
    } else {
        tdata->verts_stream=IW_GX_ALLOC(CIwFVec2,N*4);
    }

    int16* materials=new int16[N];
    uint16* orders=new uint16[N];

    float x=fX+indent,y=fY,my=fY,lmy=fY,miny=1e6f;
    float dx=0,dy=(float)lineHeight*interval*scale;
    float x1,y1,x2,y2;
    float ioffset=(tdata->style&SDF_FONT_STYLE_ITALIC)?fontsize*scale*0.33f:0.0f;
    uint32 ind=0,sline=0,i4;
    char* sline_ptr=cText;

    char* cptr=cText;
    int cindex;
    uint32 ccode,chrlen=0;

    char* lsp_ptr=NULL;
    uint32 lsp_i,lsp_ind;
    float lsp_x,lsp_dx;
    bool lsp_inc=false;
    if ((cindex=GetCharIndex(32))>=0) {
        if (chars[cindex].width>0&&chars[cindex].height>0) {
            lsp_inc=true;
        }
    }

    tdata->nlines=0;
    tdata->mwidth=0.0f;

    for (uint32 i=0; i<=N; i++) {
        if (i<N) {
            if (encoding==SDF_FONT_ENCODING_UTF8) {
                cptr+=chrlen;
                chrlen=GetUTF8Char(cptr,&ccode);
                if (chrlen) {
                    cindex=GetCharIndex(ccode);
                } else {
                    i=N;
                }
            } else {
                cptr=&cText[i];
                cindex=GetCharIndex((uint32)*cptr);
            }
            dx=(cindex>=0)?((float)chars[cindex].xadvance+kerning)*scale:0.0f;
        }

        if (i==N||cindex==-1||rect_width>0.0f&&(x-fX+dx+ioffset)>rect_width&&ind&&(!(tdata->flags&SDF_FONT_NOWORDSPLIT)||lsp_ptr||*cptr==(char)32)) {
            if (tdata->flags&SDF_FONT_NOOVERFLOW&&rect_height>0.0f&&my>fY+rect_height) {
                i=N;
                ind=sline;
                my=lmy;
            }
            if (tdata->flags&SDF_FONT_ONELINE) {
                i=N;
            }

            if (tdata->flags&SDF_FONT_NOWORDSPLIT&&(x-fX+dx+ioffset)>rect_width&&!lsp_ptr&&i!=N) {
                cindex=-2;
                chrlen=0;
                while(*cptr==(char)32) {
                    cptr++;
                    i++;
                }
                i--;
            } else

                if (!(tdata->flags&SDF_FONT_NOWORDWRAP)&&i!=N) {
                    if (lsp_ptr&&lsp_ind!=sline&&cindex!=-1) {
                        if (*cptr!=(char)32) {
                            cptr=lsp_ptr+1;
                        } else {
                            cptr=lsp_ptr;
                            lsp_i--;
                        }
                        ind=lsp_ind;
                        x=lsp_x;
                        i=lsp_i;
                        while(*cptr==(char)32) {
                            cptr++;
                            i++;
                        }
                        char* cp=lsp_ptr;
                        while (*cp==(char)32&&ind>sline) {
                            cp--;
                            if (lsp_inc) {
                                ind--;
                            }
                            x-=lsp_dx;
                        }
                        chrlen=0;
                        cindex=-2;
                    } else if (*cptr==(char)32) {
                        while(*cptr==(char)32) {
                            cptr++;
                            i++;
                        }
                        i--;
                        chrlen=0;
                        cindex=-2;
                    }
                }

            float ofs=0.0f;
            if (tdata->flags&SDF_FONT_ALIGN_CENTRE) {
                ofs=(rect_width-(x-fX+ioffset))/2.0f;
            } else if (tdata->flags&SDF_FONT_ALIGN_RIGHT) {
                ofs=rect_width-(x-fX+ioffset);
            }
            if (ofs!=0.0f) {
                int size=ind*4;
                for (int j=sline*4; j<size; j++) {
                    tdata->verts_stream[j].x+=ofs;
                }
            }
            if (x-fX>tdata->mwidth) {
                tdata->mwidth=x-fX;
            }

            if (tdata->flags&SDF_FONT_RIGHTTOLEFT) {
                float nx=x+ofs,twidth,tadv;
                uint32 cc,cl,idx;
                int ci;
                for (uint32 z=sline; z<ind; z++) {
ret:
                    do {
                        if (encoding==SDF_FONT_ENCODING_UTF8) {
                            cl=GetUTF8Char(sline_ptr,&cc);
                        } else {
                            cl=1;
                            cc=(uint32)(*sline_ptr);
                        }
                        ci=GetCharIndex(cc);
                        sline_ptr+=cl;
                    } while (ci<0);
                    tadv=((float)chars[ci].xadvance+kerning)*scale;
                    nx-=tadv;
                    if (chars[ci].width==0||chars[ci].height==0) {
                        goto ret;
                    }
                    twidth=((float)chars[ci].width)*scale;
                    idx=z*4;
                    tdata->verts_stream[idx].x=nx+chars[ci].xoffset*scale+ioffset;
                    tdata->verts_stream[idx+1].x=tdata->verts_stream[idx].x-ioffset;
                    tdata->verts_stream[idx+2].x=tdata->verts_stream[idx].x+twidth-ioffset;
                    tdata->verts_stream[idx+3].x=tdata->verts_stream[idx+2].x+ioffset;
                }
            }

            x=(cindex==-1)?fX+indent:fX;
            y+=dy;
            lmy=my;
            sline=ind;
            sline_ptr=cptr;
            lsp_ptr=NULL;
            tdata->nlines++;
            if (cindex<0||i==N) {
                continue;
            }
        }
        if (cindex<0) {
            continue;
        }

        chr=&chars[cindex];
        i4=ind*4;
        if (!ind) {
            page=chr->page;
        }

        if (chr->width>0&&chr->height>0) {
            if ((style&SDF_FONT_RIGHTTOLEFT)==0) {
                x1=x+chr->xoffset*scale,x2=x1+chr->width*scale;
                tdata->verts_stream[i4].x=x1+ioffset;
                tdata->verts_stream[i4+1].x=x1;
                tdata->verts_stream[i4+2].x=x2;
                tdata->verts_stream[i4+3].x=x2+ioffset;
            }
            y1=y+chr->yoffset*scale;
            y2=y1+chr->height*scale;
            tdata->verts_stream[i4].y=y1;
            tdata->verts_stream[i4+1].y=y2;
            tdata->verts_stream[i4+2].y=y2;
            tdata->verts_stream[i4+3].y=y1;
            if (y1<miny) {
                miny=y1;
            }
            if (y2>my) {
                my=y2;
            }

            memcpy(&(tdata->uvs_stream[i4]),chr->uv,sizeof(CIwFVec2)*4);
            materials[ind]=chr->page;
            orders[ind]=(uint16)ind;
            if (chr->page!=page) {
                difmat=true;
            }

            ind++;
        }
        x+=dx;

        if (*cptr==(char)32) {
            lsp_ptr=cptr;
            lsp_i=i;
            lsp_ind=ind;
            lsp_x=x;
            lsp_dx=dx;
        }
    }
    if (tdata->count!=ind) {
        update_chars=true;
    }
    tdata->count=ind;
    tdata->mheight=my-fY;
    if (tdata->flags&SDF_FONT_ALIGN_TOP||tdata->flags&SDF_FONT_ALIGN_MIDDLE||tdata->flags&SDF_FONT_ALIGN_BOTTOM) {
        tdata->mheight+=fY-miny;
    }

    float ofs=0.0f;
    if (tdata->flags&SDF_FONT_ALIGN_TOP) {
        ofs=fY-miny;
    } else if (tdata->flags&SDF_FONT_ALIGN_MIDDLE) {
        ofs=(rect_height-(my-fY-(fY-miny)))/2.0f;
    } else if (tdata->flags&SDF_FONT_ALIGN_BOTTOM) {
        ofs=rect_height-(my-fY);
    }
    if (ofs!=0.0f) {
        int size=tdata->count*4;
        for (int j=0; j<size; j++) {
            tdata->verts_stream[j].y+=ofs;
        }
    }

    if (fAngle!=0.0f) {
        CIwFMat2D m;
        CIwFVec2 center=(rect_width>0.0f&&rect_height>0.0f)?CIwFVec2(fX+rect_width/2.0f,fY+rect_height/2.0f):CIwFVec2(fX,fY);
        m.SetRot(fAngle*0.017453292f,center);
        for(uint32 j=0; j<tdata->count*4; j++) {
            tdata->verts_stream[j]=m.TransformVec(tdata->verts_stream[j]);
        }
    }

    if (update_chars) {
        if (!tdata->temp) {
            if (tdata->inds_stream) {
                delete [] tdata->inds_stream;
            }
            tdata->inds_stream=new uint16[tdata->count*6];
        } else {
            tdata->inds_stream=IW_GX_ALLOC(uint16,tdata->count*6);
        }

        if (difmat) {
            for (uint32 i=0; i<ind; i++)
                for (uint32 j=0; j<ind-i-1; j++)
                    if (materials[orders[j]]>materials[orders[j+1]]) {
                        uint16 tmp=orders[j];
                        orders[j]=orders[j+1];
                        orders[j+1]=tmp;
                    }
            int16 curmat=-1;
            for (uint32 k=0; k<tdata->count; k++)
                if (materials[orders[k]]!=curmat) {
                    curmat=materials[orders[k]];
                    tdata->batches[tdata->nbatches].material=curmat;
                    tdata->batches[tdata->nbatches].index=k;
                    tdata->nbatches++;
                }
        } else {
            tdata->nbatches=1;
            tdata->batches[0].material=materials[0];
            tdata->batches[0].index=0;
        }

        uint16* inds=tdata->inds_stream;
        for (uint32 n=0; n<tdata->count; n++) for (uint32 j=0; j<6; j++,inds++) {
                (*inds)=quad_inds[j]+orders[n]*4;
        }
    }

    if (materials) {
        delete [] materials;
    }
    if (orders) {
        delete [] orders;
    }
}

void CSDFFont::GetTextDimensions(CSDFFontTextData* pTextData,float* pfWidth,float* pfHeight,uint32* puNChars,uint32* puNLines) {
    if (!pTextData) {
        return;
    }
    if (pfWidth) {
        *pfWidth=pTextData->mwidth;
    }
    if (pfHeight) {
        *pfHeight=pTextData->mheight;
    }
    if (puNChars) {
        *puNChars=pTextData->count;
    }
    if (puNLines) {
        *puNLines=pTextData->nlines;
    }
}

void CSDFFont::GetTextDimensions(const char* cText,float* pfWidth,float* pfHeight,uint32* puNChars,uint32* puNLines) {
    if (!loaded||!cText) {
        return;
    }

    uint32 N;
    SDF_CHARINFO* chr;

    N=(encoding==SDF_FONT_ENCODING_UTF8)?GetUTF8StrLen(cText):strlen(cText);

    if (N>0xffff) {
        return;
    }
    float x=indent,y=0.0f,mx=0.0f,my=0.0f,lmy=0.0f,miny=1e6f;
    float dx=0,dy=(float)lineHeight*interval*scale,y1,y2;
    float ioffset=(style&SDF_FONT_STYLE_ITALIC)?fontsize*scale*0.33f:0.0f;
    uint32 ind=0,sline=0;

    char* cptr=(char*)cText;
    int cindex;
    uint32 ccode,chrlen=0;

    char* lsp_ptr=NULL;
    uint32 lsp_i,lsp_ind;
    float lsp_x,lsp_dx;
    bool lsp_inc=false;
    if ((cindex=GetCharIndex(32))>=0) {
        if (chars[cindex].width>0&&chars[cindex].height>0) {
            lsp_inc=true;
        }
    }
    uint32 nlines=0;

    for (uint32 i=0; i<=N; i++) {
        if (i<N) {
            if (encoding==SDF_FONT_ENCODING_UTF8) {
                cptr+=chrlen;
                chrlen=GetUTF8Char(cptr,&ccode);
                if (chrlen) {
                    cindex=GetCharIndex(ccode);
                } else {
                    i=N;
                }
            } else {
                cptr=(char*)&cText[i];
                cindex=GetCharIndex((uint32)*cptr);
            }
            dx=(cindex>=0)?((float)chars[cindex].xadvance+kerning)*scale:0.0f;
        }

        if (i==N||cindex==-1||rect_width>0.0f&&(x+dx+ioffset)>rect_width&&ind&&(!(flags&SDF_FONT_NOWORDSPLIT)||lsp_ptr||*cptr==(char)32)) {
            if (flags&SDF_FONT_NOOVERFLOW&&rect_height>0.0f&&my>rect_height) {
                i=N;
                ind=sline;
                my=lmy;
            }
            if (flags&SDF_FONT_ONELINE) {
                i=N;
            }

            if (flags&SDF_FONT_NOWORDSPLIT&&(x+dx+ioffset)>rect_width&&!lsp_ptr&&i!=N) {
                cindex=-2;
                chrlen=0;
                while(*cptr==(char)32) {
                    cptr++;
                    i++;
                }
                i--;
            } else if (!(flags&SDF_FONT_NOWORDWRAP)&&i!=N) {
                if (lsp_ptr&&lsp_ind!=sline&&cindex!=-1) {
                    if (*cptr!=(char)32) {
                        cptr=lsp_ptr+1;
                    } else {
                        cptr=lsp_ptr;
                        lsp_i--;
                    }
                    ind=lsp_ind;
                    x=lsp_x;
                    i=lsp_i;
                    while(*cptr==(char)32) {
                        cptr++;
                        i++;
                    }
                    char* cp=lsp_ptr;
                    while (*cp==(char)32&&ind>sline) {
                        cp--;
                        if (lsp_inc) {
                            ind--;
                        }
                        x-=lsp_dx;
                    }
                    chrlen=0;
                    cindex=-2;
                } else if (*cptr==(char)32) {
                    while(*cptr==(char)32) {
                        cptr++;
                        i++;
                    }
                    i--;
                    chrlen=0;
                    cindex=-2;
                }
            }

            if (x>mx) {
                mx=x;
            }
            x=(cindex==-1)?indent:0.0f;
            y+=dy;
            lmy=my;
            sline=ind;
            lsp_ptr=NULL;
            nlines++;
            if (cindex<0||i==N) {
                continue;
            }
        }
        if (cindex<0) {
            continue;
        }
        chr=&chars[cindex];
        if (chr->width>0&&chr->height>0) {
            y1=y+chr->yoffset*scale;
            y2=y1+chr->height*scale;
            if (y1<miny) {
                miny=y1;
            }
            if (y2>my) {
                my=y2;
            }
            ind++;
        }
        x+=dx;
        if (*cptr==(char)32) {
            lsp_ptr=cptr;
            lsp_i=i;
            lsp_ind=ind;
            lsp_x=x;
            lsp_dx=dx;
        }
    }

    if (pfWidth) {
        *pfWidth=mx;
    }
    if (pfHeight) {
        *pfHeight=my-((flags&SDF_FONT_ALIGN_TOP||flags&SDF_FONT_ALIGN_MIDDLE||flags&SDF_FONT_ALIGN_BOTTOM)?miny:0.0f);
    }
    if (puNChars) {
        *puNChars=ind;
    }
    if (puNLines) {
        *puNLines=nlines;
    }
}

void CSDFFont::PrepareFormatData(CSDFFontFormatData** ppFormatData,char* cText) {
    if (!loaded||!cText) {
        return;
    }
    if (!(*ppFormatData)) {
        *ppFormatData=new CSDFFontFormatData();
    }
    CSDFFontFormatData* fdata=*ppFormatData;

    uint16 fl=flags;
    if (flags&SDF_FONT_NOOVERFLOW) {
        flags=flags&(~(uint16)SDF_FONT_NOOVERFLOW);
    }
    GetTextDimensions(cText,&(fdata->width),&(fdata->height),&(fdata->count),&(fdata->nlines));
    flags=fl;
    fdata->lines=new SDF_LINEINFO[fdata->nlines];
    memset(fdata->lines,0,sizeof(SDF_LINEINFO)*fdata->nlines);

    uint32 N;
    SDF_CHARINFO* chr;

    N=(encoding==SDF_FONT_ENCODING_UTF8)?GetUTF8StrLen(cText):strlen(cText);
    if (N>0xffff) {
        return;
    }
    fdata->nchars=N;

    float x=indent,y=0.0f,my=0.0f;
    float dx=0,dy=(float)lineHeight*interval*scale,y2;
    float ioffset=(style&SDF_FONT_STYLE_ITALIC)?fontsize*scale*0.33f:0.0f;
    uint32 ind=0,sline=0;

    char* cptr=cText;
    int cindex;
    uint32 ccode,chrlen=0;

    char* lsp_ptr=NULL;
    uint32 lsp_i,lsp_ind;
    float lsp_x,lsp_dx;
    bool lsp_inc=false;
    if ((cindex=GetCharIndex(32))>=0) {
        if (chars[cindex].width>0&&chars[cindex].height>0) {
            lsp_inc=true;
        }
    }
    uint32 nline=0;

    for (uint32 i=0; i<=N; i++) {
        if (i<N) {
            if (encoding==SDF_FONT_ENCODING_UTF8) {
                cptr+=chrlen;
                chrlen=GetUTF8Char(cptr,&ccode);
                if (chrlen) {
                    cindex=GetCharIndex(ccode);
                } else {
                    i=N;
                }
            } else {
                cptr=&cText[i];
                cindex=GetCharIndex((uint32)*cptr);
            }
            dx=(cindex>=0)?((float)chars[cindex].xadvance+kerning)*scale:0.0f;
        }
        if (ind==sline) {
            fdata->lines[nline].xoffset=x;
        }

        if (i==N||cindex==-1||rect_width>0.0f&&(x+dx+ioffset)>rect_width&&ind&&(!(flags&SDF_FONT_NOWORDSPLIT)||lsp_ptr||*cptr==(char)32)) {
            if (flags&SDF_FONT_NOWORDSPLIT&&(x+dx+ioffset)>rect_width&&!lsp_ptr&&i!=N) {
                fdata->lines[nline].end=cptr;
                while(*cptr==(char)32) {
                    cptr++;
                    i++;
                }
                i--;
                cindex=-2;
                chrlen=0;
            } else if (!(flags&SDF_FONT_NOWORDWRAP)&&i!=N) {
                if (lsp_ptr&&lsp_ind!=sline&&cindex!=-1) {
                    if (*cptr!=(char)32) {
                        cptr=lsp_ptr+1;
                    } else {
                        cptr=lsp_ptr;
                        lsp_i--;
                    }
                    ind=lsp_ind;
                    x=lsp_x;
                    i=lsp_i;
                    while(*cptr==(char)32) {
                        cptr++;
                        i++;
                    }
                    char* cp=lsp_ptr;
                    while (*cp==(char)32&&ind>sline) {
                        cp--;
                        if (lsp_inc) {
                            ind--;
                        }
                        x-=lsp_dx;
                    }
                    fdata->lines[nline].end=cp+1;
                    chrlen=0;
                    cindex=-2;
                } else if (*cptr==(char)32) {
                    fdata->lines[nline].end=cptr;
                    while(*cptr==(char)32) {
                        cptr++;
                        i++;
                    }
                    i--;
                    chrlen=0;
                    cindex=-2;
                } else {
                    fdata->lines[nline].end=cptr;
                }
            } else {
                fdata->lines[nline].end=(i==N)?cptr+1:cptr;
            }

            if (fdata->lines[nline].start==NULL) {
                fdata->lines[nline].start=fdata->lines[nline].end;
            }
            fdata->lines[nline].yoffset=y;
            fdata->lines[nline].height=my-y;
            fdata->lines[nline].width=x;
            nline++;
            x=(cindex==-1)?indent:0.0f;
            y+=dy;
            my=y;
            sline=ind;
            lsp_ptr=NULL;
            if (cindex<0||i==N) {
                continue;
            }
        }
        if (cindex<0) {
            continue;
        }
        if (fdata->lines[nline].start==NULL) {
            fdata->lines[nline].start=cptr;
        }

        chr=&chars[cindex];
        if (chr->width>0&&chr->height>0) {
            y2=y+(chr->yoffset+chr->height)*scale;
            if (y2>my) {
                my=y2;
            }
            ind++;
        }
        x+=dx;
        if (*cptr==(char)32) {
            lsp_ptr=cptr;
            lsp_i=i;
            lsp_ind=ind;
            lsp_x=x;
            lsp_dx=dx;
        }
    }
}

void CSDFFont::DrawText(float fX,float fY,char* cText,float fAngle) {
    CSDFFontTextData* tdata=NULL;
    PrepareTextData(&tdata,fX,fY,cText,fAngle);
    DrawTextData(tdata);
    if (tdata) {
        delete tdata;
    }
}

void CSDFFont::DrawTextData(CSDFFontTextData* pTextData) {
    if (pTextData==NULL||!loaded||pTextData->count==0) {
        return;
    }

    uint32 smooth;
    float smoothfact=(pTextData->style&SDF_FONT_STYLE_SMOOTH)?1.5f:1.0f;
    if (pTextData->softness!=SDF_FONT_SMOOTH_AUTO) {
        smooth=(uint32)(pTextData->softness*850.0f);
    } else {
        smooth=(uint32)(MIN(0.3f,0.25f/(float)spread/scale*smoothfact)*850.0f);
    }
    uint32 outline=(uint32)(pTextData->bwidth*1700.0f);

    if (rendbuf==NULL) {
        IwGxSetVertStreamScreenSpace(pTextData->verts_stream,pTextData->count*4);
        IwGxSetUVStream(pTextData->uvs_stream);
        IwGxSetColStream(NULL);
    }

    uint16 ind=0;
    uint32 size;
    CIwMaterial* material=NULL;

    for (uint16 i=0; i<pTextData->nbatches; i++) {
        size=((i==pTextData->nbatches-1)?pTextData->count:pTextData->batches[i+1].index)-pTextData->batches[i].index;

        if (rendbuf==NULL||(rendbuf!=NULL&&rendbuf->count==0)) {
            material=IW_GX_ALLOC_MATERIAL();
            material->SetTexture(pages[pTextData->batches[i].material].texture);
            material->SetFiltering(true);
            material->SetAlphaMode(CIwMaterial::ALPHA_BLEND);
            material->SetColAmbient(smooth+(outline<<8));
            material->SetColEmissive(pTextData->color);
            material->SetColDiffuse(pTextData->bcolor);
            if (pTextData->style&SDF_FONT_STYLE_OUTLINE&&CSDFFont::shader3) {
                material->SetShaderTechnique(CSDFFont::shader3);
            } else if (pTextData->style&SDF_FONT_STYLE_BOLD&&CSDFFont::shader2) {
                material->SetShaderTechnique(CSDFFont::shader2);
            } else if (CSDFFont::shader1) {
                material->SetShaderTechnique(CSDFFont::shader1);
            }
        }

        if (rendbuf==NULL) {
            IwGxSetMaterial(material);
            IwGxDrawPrims(IW_GX_TRI_LIST,pTextData->inds_stream+pTextData->batches[i].index*6,size*6);
        } else {
            rendbuf->AddChars(material,pTextData->verts_stream,pTextData->uvs_stream,pTextData->inds_stream+pTextData->batches[i].index*6,size);
        }
    }
}

CSDFFontRenderBuffer* CSDFFont::CreateRenderBuffer(uint16 uBufsize) {
    CSDFFontRenderBuffer* pbuf=IW_GX_ALLOC_OBJECTS(CSDFFontRenderBuffer,1);
    pbuf->SetSize(uBufsize);
    return pbuf;
}

void CSDFFont::SetRenderBuffer(CSDFFontRenderBuffer* pRendbuffer) {
    rendbuf=pRendbuffer;
}

void CSDFFont::DrawRenderBuffer(CSDFFontRenderBuffer* pRendbuffer) {
    if (rendbuf==NULL||pRendbuffer->count==0) {
        return;
    }
    IwGxSetVertStreamScreenSpace(pRendbuffer->verts_stream,pRendbuffer->count*4);
    IwGxSetUVStream(pRendbuffer->uvs_stream);
    IwGxSetColStream(NULL);
    IwGxSetMaterial(pRendbuffer->material);
    IwGxDrawPrims(IW_GX_TRI_LIST,pRendbuffer->inds_stream,pRendbuffer->count*6);
}

void CSDFFontRenderBuffer::SetSize(uint16 uSize) {
    size=uSize;
    count=0;
    material=NULL;
    verts_stream=IW_GX_ALLOC(CIwFVec2,size*4);
    uvs_stream=IW_GX_ALLOC(CIwFVec2,size*4);
    inds_stream=IW_GX_ALLOC(uint16,size*6);
}

void CSDFFontRenderBuffer::AddChars(CIwMaterial* pMaterial,CIwFVec2* pVerts,CIwFVec2* pUvs,uint16* pInds,uint16 uNum) {
    if (count>=size) {
        return;
    }
    if (count+uNum>size) {
        uNum=size-count;
    }
    if (count==0&&pMaterial!=NULL) {
        material=pMaterial;
    }
    uint16 idx4=count*4,idx6=count*6;
    for (uint16 i=0; i<uNum; i++) {
        memcpy(&(verts_stream[idx4]),pVerts,sizeof(CIwFVec2)*4);
        memcpy(&(uvs_stream[idx4]),pUvs,sizeof(CIwFVec2)*4);
        memcpy(&(inds_stream[idx6]),pInds,sizeof(CIwFVec2)*6);
        for (uint16 j=0; j<6; j++) {
            inds_stream[idx6+j]+=idx4;
        }
        idx4+=4;
        idx6+=6;
        count++;
    }
}