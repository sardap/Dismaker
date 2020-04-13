#pragma once
#ifndef TEXT_BOX_CONFIG_INFO_H

	#define TEXT_BOX_CONFIG_INFO_H
	#include "BorderConfigInfo.h"
	#include "TextConfigInfo.h"
	#include "RectangleConfigInfo.h"

	struct TextBoxConfigInfo
	{
		BorderConfigInfo borderInfo;
		TextConfigInfo textInfo;
		RectangleConfigInfo rectangleInfo;
	};
	
#endif // !DIALOG_BUTTON_CONFIG_INFO_H
