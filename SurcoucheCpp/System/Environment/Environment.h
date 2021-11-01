#pragma once
#include "../Object/Object.h"

namespace System
{
    class String;
    namespace Collections
    {
        namespace Generic
        {
            template<typename Item>
            class List;
        }
    }
#pragma region enum
    enum class SpecialFolder
    {
        Dekstop = 0x0000,
        Programs = 0x0002,
        MyDocuments = 0x0005,
        MyMusic = 0x000d,
        MyVideo = 0x000e,
        LocalAppData = 0x001c,
        ProgramsFiles = 0x0026,
        MyPictures = 0x0027,
        Profile = 0x0028,
        ProgramFilesx86 = 0x002a,
    };
#pragma endregion enum    
    class Environment : public Object
    {
    public:
        static String CurrentDirectory();
        static String SpecialFolder(const SpecialFolder& _specialFolder);
        static Collections::Generic::List<String> GetLogicalDrives();
        static String GetOsVersion();
        static String GetOsName();
        static bool Is64BitProcess();
    };
}
