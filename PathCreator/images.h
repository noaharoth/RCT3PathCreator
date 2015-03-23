// images.h
// Manages image resources.

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Reflection;

#define IMG_COUNT 21

#define IMG_BAR 0
#define IMG_BUTTON 1
#define IMG_BUTTON_G 2
#define IMG_BUTTON_Y 3
#define IMG_BUTTON_R 4
#define IMG_NO_IMAGE_SELECTED 5
#define IMG_BAR_DECOR 6
#define IMG_BAR_DECOR_B 7

#define ICN_BALLOON_EXCLAMATION 8
#define ICN_FOLDER_OPEN 9
#define ICN_GEAR 10
#define ICN_QUESTION 11
#define ICN_ARROW_L 12
#define ICN_ARROW_R 13
#define ICN_CROSS_SCRIPT 14
#define ICN_DISK 15
#define ICN_DISK_PENCIL 16
#define ICN_DISKS_BLACK 17
#define ICN_IMAGE 18
#define ICN_INFORMATION 19
#define ICN_STAIRS 20

ref class ImageResourceManager {
public:
	static array<String^> ^imageNames = 
	{
		"item_bar.png",
		"bar_button.png",
		"bar_button_green.png",
		"bar_button_yellow.png",
		"bar_button_red.png",
		"noImageSelected.png",
		"bar_decor.png",
		"bar_decor_blue.png",
		"balloon_exclamation.png",
		"folder_horizontal_open.png",
		"gear.png",
		"question.png",
		"arrow_left.png",
		"arrow_right.png",
		"cross_script.png",
		"disk.png",
		"disk_pencil.png",
		"disks_black.png",
		"image.png",
		"information.png",
		"stairs.png"
	};

	static array<Bitmap^> ^images;
};

void LoadResourceImages();
Bitmap^ GetResourceImage(unsigned int image);

