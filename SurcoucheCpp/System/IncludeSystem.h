#pragma once
#include "Event/EventArgs/EventArgs.h"
#include "Event/EventHandler/EventHandler.h"
#include "Event/Action/Action.h"
#include "Event/Func/Func.h"
#include "Event/Predicate/Predicate.h"
#include "Activator/Activator.h"

#include "Box/ConfirmationBox/ConfirmationBox.h"
#include "Box/BoxFile/BoxFile.h"
#include "Random/Random.h"
#include "PrimaryType/Char/Char.h"
#include "PrimaryType/String/String.h"
#include "PrimaryType/Boolean/Boolean.h"
#include "PrimaryType/Integer/Integer.h"
#include "PrimaryType/Float/Float.h"
#include "PrimaryType/Double/Double.h"
#include "PrimaryType/Byte/Byte.h"
#include "System/LanguageManager/LanguageManager.h"
#include "System/LanguageManager/Language/Language.h"
#include "Console/Console.h"
#include "Interface/Equatable/IEquatable.h"
#include "DateTime/DateTime.h"
#include "Environment/Environment.h"
#include "Version/Version.h"

#include "../System.Collections.Generic/List/List.h"
#include "../System.IO/Directory/Directory.h"
#include "../System.IO/Directory/DirectoryInfo/DirectoryInfo.h"
#include "../System.IO/Path/Path.h"
#include "../System.IO/File/File/File.h"
#include "System.IO/Stream/StreamReader/StreamReader.h"
#include "../System.IO/Stream/StreamWriter/StreamWriter.h"
#include "../System.IO/File/FileStream/FileStream.h"
#include "../System.IO/File/FileSystemInfo/FileSystemInfo.h"
#include "System.IO/Stream/TextReader/TextReader.h"

#include "../System.Collections.Generic/Interface/Enumerator/IEnumerator.h"


#include "../System.Diagnostics/Process/Process.h"

#include "Exception/Exception/Exception.h"
#include "Exception/OutOfRange/OutOfRange.h"

using namespace System;
using namespace IO;
using namespace Collections::Generic;

template<typename T>
void foreach(IEnumerator<T>* _enumerator, Action<T> _callback)
{
    while (_enumerator->MoveNext())
        _callback.Invoke(_enumerator->Current());
    _enumerator->Reset();
}