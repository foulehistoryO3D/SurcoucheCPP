#include <windows.h>
#include "System/IncludeSystem.h"


class ThresholdReachedEventArgs : EventArgs
{
public:
    int ThreshHold;
    DateTime TimeReached;
};

class Counter : public Object
{
private:
    int threshold;
    int total;
public:
    explicit Counter(int _passedThreshold)
    {
        total = 0;
        threshold = _passedThreshold;
    }
    
    void Add(int x)
    {
        total+=x;
        Console::WriteLine(Integer(total));
        if (total >= threshold)
        {
            ThresholdReachedEventArgs* _args = new ThresholdReachedEventArgs();
            _args->ThreshHold = threshold;
            _args->TimeReached = DateTime::Now();
            OnThresholdReached(_args);
        }
    }
    EventHandler<ThresholdReachedEventArgs> ThresholdReached;
private:
    void OnThresholdReached(ThresholdReachedEventArgs* _event)
    {
        EventHandler<ThresholdReachedEventArgs> handler = ThresholdReached;
        if (handler != null)
            handler(this, _event);
    }
};

void ThresholdReached(object* _sender, ThresholdReachedEventArgs* _event)
{
    const String _str = string("Sender: ") + _sender->GetType()->FullName() + " The threshold of " + Integer(_event->ThreshHold) + " was reached at " + _event->TimeReached.ToString();
    Console::WriteLine(_str);
}

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    srand((unsigned) time(0));
    int result = 1 + (rand() % 6);
    Counter c = Counter(result);
    c.ThresholdReached += ThresholdReached;
    char _c = 'a';
    do
    {
        std::cin >> _c;
        if (_c != 'a') break;
        Console::WriteLine(string("adding one"));
        c.Add(1);
    }
    while (_c == 'a');
    // LanguageManager::Instance().AddLanguage(new Language("fr", "french.txt"));
    // LanguageManager::Instance().AddLanguage(new Language("en", "english.txt"));
    // LanguageManager::Instance().GetLanguage("fr").AddMessageToFile("salut", "Salut comment vas-tu ? @0");
    // const String& _message = LanguageManager::Instance().GetLanguage("fr").GetMessages("salut");
    // const String& _result = LanguageManager::Instance().Translate(_message, "Romain");
    // Console::WriteLine(_result);
    return 0;
}

