#include "DataBaseLocal.h"

#include "../../../System.IO/File/File/File.h"
#include "../../../System.IO/File/FileStream/FileStream.h"
#include "../../../System.IO/Exception/IOException/IOException.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Array/Array.h"

#pragma region constructor
System::IO::DataBaseLocal::DataBaseLocal(const String& path)
{
    this->path = path;
    fileStream = File::Create(path);
    if (!fileStream.Exists())
        throw IOException("Can't create|open database !");
    
    // Array tab = fileStream.Reader().ReadToEnd().Split(' ');
    // RegisterRows(tab[0]);
    
}

System::IO::DataBaseLocal::~DataBaseLocal()
{
    fileStream.Dispose(); 
}

// void System::IO::DataBaseLocal::RegisterRows(const String& str)
// {
//     const Array splitedRows = str.Split(',');
//     const Int& length = splitedRows.Count();
//     for (int32 i = 0; i < length; ++i)
//         rows.Add(splitedRows[i], Array<string>());
// }
#pragma endregion constructor
#pragma region custom methods

#pragma endregion custom methods
#pragma region override
System::String System::IO::DataBaseLocal::ToString() const
{
    return path;
}

System::Integer System::IO::DataBaseLocal::GetHashCode() const
{
    return ToString().GetHashCode() ^ (fileStream.GetHashCode() << 2);
}

void System::IO::DataBaseLocal::Dispose()
{
    fileStream.Dispose();
}
#pragma endregion override
