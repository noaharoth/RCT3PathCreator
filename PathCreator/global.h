// global.h

#pragma once

#include "stdafx.h"
#include "images.h"
#include "PathHelper.h"
#include "QueueHelper.h"
#include "ProgramSettings.h"

#define SECRET_ACTIONS

void BufferedFileCopy(const std::string& source, const std::string& dest);

ref class global {
public:
	static String^ ProjectName;
	static String^ SavedDirectory;
	static Rct3PathType Type;
	static BasicPath^ Basic;
	static ExtendedPath^ Extended;
	static QueuePath^ Queue;
	static ProgramSettings^ Settings;
	static String^ PreInitMessage;
	static unsigned int IsDarkHorizons;

	static bool openCpathProject(String^ filename);
	
};

bool IsPowerOfTwo(unsigned int value);

bool StringContains(String^ source, String^ find, System::StringComparison comp);

VersionInfo CheckForUpdates(String^& out_downloadUrl);