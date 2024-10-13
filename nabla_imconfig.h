#ifndef _NABLA_IMCONFIG_H_
#define _NABLA_IMCONFIG_H_

// we use test engine's config as start template
#include "imgui_test_suite_imconfig.h"
#include <cstdint>

//! Custom "ImTextureID" info struct for Nabla UI backend purposes for resource sampler & texture descriptor binding's array indicies
//! must be 4 bytes size & alignment to pass imgui static asserts (it checks for contiguous blocks in memory to make sure it can do some memcpies)
struct SImResourceInfo 
{ 
	//! texture descriptor binding's array index
    uint32_t textureID : 26; 

	//! sampler descriptor binding's array index
	uint32_t samplerIx : 6;

    SImResourceInfo() : textureID(0u), samplerIx(0u) {}

    SImResourceInfo(uint32_t texID) 
    {
        textureID = texID;
        samplerIx = 0u;
    }

	explicit operator intptr_t() const
	{
		return static_cast<intptr_t>(textureID);
	}

    bool operator==(const SImResourceInfo& other) const
    {
        return textureID == other.textureID;
    }

    bool operator!=(const SImResourceInfo& other) const
    {
        return textureID != other.textureID;
    }

    bool operator<(const SImResourceInfo& other) const
    {
        return textureID < other.textureID;
    }

    bool operator>(const SImResourceInfo& other) const
    {
        return textureID > other.textureID;
    }

    bool operator<=(const SImResourceInfo& other) const
    {
        return textureID <= other.textureID;
    }

    bool operator>=(const SImResourceInfo& other) const
    {
        return textureID >= other.textureID;
    }
};

// options
#define ImTextureID SImResourceInfo
#define IMGUI_ENABLE_FREETYPE
#define IMGUI_DISABLE_OBSOLETE_KEYIO
#undef IMGUI_DISABLE_OBSOLETE_FUNCTIONS // it breaks things

#endif // NABLA_IMCONFIG