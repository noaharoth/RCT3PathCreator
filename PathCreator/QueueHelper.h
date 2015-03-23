// QueueHelper.h

#pragma once

#include "stdafx.h"
#include "PathHelper.h"

#include <Queue.hpp>
#include <Texture.hpp>

ref class QueuePath {
public:
	String^ Name;
	String^ IngameName;
	String^ Icon;
	String^ Texture;
	bool Recolor1;
	bool Recolor2;
	bool Recolor3;
	String^ Shared;
	String^ Straight;
	String^ TurnL;
	String^ TurnR;
	String^ SlopeUp;
	String^ SlopeDown;
	String^ SlopeStraight1;
	String^ SlopeStraight2;

	QueuePath();

	bool filled();

	String^ incomplete();

	void copyFilesTo(String^ dest);

	void CreateBlankOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateTextureOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateIconOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateStubOVL(String^ path, RCT3Debugging::OutputLog& log);

	void read(BinaryReader^ f);

	void serialize(BinaryWriter^ f);

	bool saveAsCpath(String^ filename, unsigned int IsDarkHorizons);

};