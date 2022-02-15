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
        DECLARE_CLASS_INFO(Object)
    private:
        static String GetOsVersionInternal();
        static String GetOsNameInternal();
        static bool Is64BitProcessInternal();
    public:
        static String CurrentDirectory();
        static const String OsVersion;
        static const String OsName;
        static const Boolean Is64BitProcess;
        static constexpr int EXIT_ERROR = -1;
        static constexpr int EXIT_VALID = 1;
        static String SpecialFolder(const SpecialFolder& _specialFolder);
        static Collections::Generic::List<String> GetLogicalDrives();

        static void Exit(const int& _exitStatus);
    };
}
