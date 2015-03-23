// PathHelper.h

#pragma once

#include "stdafx.h"

#include <Path.hpp>
#include <Texture.hpp>
#include <FlicManager.hpp>
#include <SceneryItem.hpp>

#define READUSTRING(instance) length = f->ReadUInt16() * 2; \
	instance = Encoding::Unicode->GetString(f->ReadBytes(length))
#define READSTRING(instance) length = f->ReadUInt16(); \
	instance = gcnew String(f->ReadChars(length))
#define GETFILENAME(str) (marshal_as<std::string>(System::IO::Path::GetFileNameWithoutExtension((str))))

#define PATH_TYPE 19
#define CPATH_FILE_SIGNATURE 0x46464844
#define CPATH_FILE_VERSION 1.1f
#define CPATH_FILE_SIGNATURE2 0x33746372
#define CPATH_FILE_RESERVED 0

String^ getOvlName(String^ ovl);

public enum class Rct3PathType 
{
	Basic = 0x02060206,
	Extended = 0x05060506,
	Queue = 0x01070107
};

value struct MPathSection 
{
public:
	property String^ North;
	property String^ East;
	property String^ South;
	property String^ West;

	MPathSection(String^ filename);

	bool filled();
	bool complete();

	String^ incomplete(String^ sectionName, unsigned int* count);

	void copyFilesTo(String^ dest);
	void read(BinaryReader^ f);
	void serialize(BinaryWriter^ f);

	RCT3Asset::PathSection Convert();
};

ref class BasicPath 
{
public:
	String^ Name;
	String^ IngameName;
	String^ Icon;
	String^ TextureA, ^TextureB;
	String^ Shared;
	MPathSection Flat;
	MPathSection StraightA;
	MPathSection StraightB;
	MPathSection CornerA;
	MPathSection CornerB;
	MPathSection CornerC;
	MPathSection CornerD;
	MPathSection TurnU;
	MPathSection TurnLA;
	MPathSection TurnLB;
	MPathSection TurnTA;
	MPathSection TurnTB;
	MPathSection TurnTC;
	MPathSection TurnX;
	MPathSection Slope;
	MPathSection SlopeStraight;
	MPathSection SlopeStraightL;
	MPathSection SlopeStraightR;
	MPathSection SlopeMid;
	/*bool Underwater;

	unsigned int Unknown01;
	unsigned int Unknown02;*/

	unsigned int Flags;

	BasicPath();

	bool filled();

	String^ incomplete();

	void copyFilesTo(String^ dest);

	void CreateTextureOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateBlankOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateStubOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateIconOVL(String^ path, RCT3Debugging::OutputLog& log);

	void read(BinaryReader^ f);

	void serialize(BinaryWriter^ f);

	bool saveAsCpath(String^ filename, unsigned int IsDarkHorizons);

};

ref class ExtendedPath 
{
public:
	BasicPath^ Base;
	unsigned int Unknown03;
	unsigned int Unknown04;

	MPathSection FlatFC;
	MPathSection SlopeFC;
	MPathSection SlopeBC;
	MPathSection SlopeTC;
	MPathSection SlopeStraightFC;
	MPathSection SlopeStraightBC;
	MPathSection SlopeStraightTC;
	MPathSection SlopeStraightLFC;
	MPathSection SlopeStraightLBC;
	MPathSection SlopeStraightLTC;
	MPathSection SlopeStraightRFC;
	MPathSection SlopeStraightRBC;
	MPathSection SlopeStraightRTC;
	MPathSection SlopeMidFC;
	MPathSection SlopeMidBC;
	MPathSection SlopeMidTC;
	String^ Paving;

	ExtendedPath(BasicPath^ base);

	void copyFilesTo(String^ dest);

	void CreateTextureOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateBlankOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateStubOVL(String^ path, RCT3Debugging::OutputLog& log);

	void CreateIconOVL(String^ path, RCT3Debugging::OutputLog& log);

	void read(BinaryReader^ f);

	void serialize(BinaryWriter^ f);

	bool saveAsCpath(String^ filename, unsigned int IsDarkHorizons);

};