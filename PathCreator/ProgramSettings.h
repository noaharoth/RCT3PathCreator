// ProgramSettings.h

#include "stdafx.h"

#define SETTINGS_FILE_SIGNATURE 0x66736370
#define RECENT_PROJECTS_MAX 7

#define FILE_BOOL_TRUE 0xFFFFFFFF
#define FILE_BOOL_FALSE 0

value struct VersionInfo
{
	unsigned int Major;
	unsigned int Minor;
	unsigned int PatchNumber;
	String^ SpecialNotes;
	String^ VersionInformationText;

	String^ ToString() override
	{
		String^ ret = Major.ToString() + "." + Minor.ToString() + "." + PatchNumber.ToString();
		if (!String::IsNullOrWhiteSpace(SpecialNotes))
		{
			ret += " (" + SpecialNotes + ")";
		}
		return ret;
	}

	static VersionInfo FromString(String^ str)
	{
		array<String^>^ numbers = str->Split('.');

		VersionInfo info;
		info.Major = Convert::ToUInt32(numbers[0]);
		info.Minor = Convert::ToUInt32(numbers[1]);
		info.PatchNumber = Convert::ToUInt32(numbers[2]);
		info.SpecialNotes = nullptr;

		if (numbers[3] != " ")
			info.SpecialNotes = numbers[3];

		return info;
	}
};

value struct RecentProject
{
public:
	String^ FileName;
	String^ ProjectName;

	String^ ToString() override
	{
		return ProjectName;
	}
};

public enum class UpdateFrequency
{
	EveryWeek = 0,
	EveryMonth = 1,
	Manually = 6
};

ref class ProgramSettings
{
public:
	List<RecentProject>^ RecentProjects;
	String^ RCT3InstallDirectory;
	VersionInfo CurrentVersion;
	bool DebugLog;
	bool SaveOnExit;
	UpdateFrequency UpdateCheckFreq;
	DateTime LastUpdateCheck;

	ProgramSettings();

	void AddRecentProject(RecentProject proj);

	void Save();

	void Open(String^% msg);

	static String^ FindRCT3InstallDirectory(String^% msg);

	static ProgramSettings^ CreateDefault(String^% msg);

	static VersionInfo GetCurrentVersion();

};