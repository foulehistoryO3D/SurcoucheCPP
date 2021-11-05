#pragma once
#include "../System/Object/Object.h"
#include "../System/PrimaryType/String/String.h"

class Test : public System::Object
{
private:
    
public:
    template<typename... Args>
    void Translate(const System::String& _playerName, const System::String& _key, Args... _args);
};

template <typename ... Args>
void Test::Translate(const System::String& _playerName, const System::String& _key, Args... _args)
{
    
}
