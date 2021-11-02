#pragma once
#include "Exception/Exception/Exception.h"
#include "Exception/OutOfRange/OutOfRange.h"

#include "Collection/Generic/Interface/Enumerator/IEnumerator.h"
#include "Event/Action/Action.h"
#include "Event/Func/Func.h"
#include "Event/Predicate/Predicate.h"
#include "Collection/Generic/List/List.h"
#include "PrimaryType/String/String.h"
#include "PrimaryType/Boolean/Boolean.h"
#include "PrimaryType/Integer/Integer.h"
#include "PrimaryType/Float/Float.h"
#include "PrimaryType/Double/Double.h"
#include "PrimaryType/Byte/Byte.h"
#include "Console/Console.h"
#include "Interface/Equatable/IEquatable.h"
#include "IO/File/FileSystemInfo/FileSystemInfo.h"
#include "IO/Directory/Directory.h"
#include "IO/Directory/DirectoryInfo/DirectoryInfo.h"
#include "IO/Path/Path.h"
#include "Diagnostics/Process/Process.h"

using namespace System;
using namespace Collections::Generic;

template<typename T>
void foreach(IEnumerator<T>* _enumerator, Action<T> _callback)
{
    while (_enumerator->MoveNext())
        _callback.Invoke(_enumerator->Current());
    _enumerator->Reset();
}