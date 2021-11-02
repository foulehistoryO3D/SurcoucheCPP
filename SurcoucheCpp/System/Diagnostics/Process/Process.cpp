#include "Process.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include <ShlObj_core.h>
#include <shobjidl_core.h>

void System::Diagnostics::Process::Start(const String& _path, const String& _parameters)
{
    if (String::IsNullOrEmpty(_path))return;
    const LPCWSTR _pathToOpen = _path.ToWString()->c_str();
    LPCWSTR _params = LPCWSTR();
    const Bool& _parametersEmpty = String::IsNullOrEmpty(_parameters);
    if (!_parametersEmpty) _params = _parameters.ToWString()->c_str();
    ShellExecute(nullptr, nullptr, _pathToOpen, _parametersEmpty ? nullptr : _params, nullptr, SW_SHOWNORMAL);
}
