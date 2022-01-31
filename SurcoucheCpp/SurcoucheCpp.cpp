#include "System.IO/Path/Path.h"
#include "System/Console/Console.h"
#include "System/Environment/Environment.h"
#include "System/Mail/Mail.h"

int main()
{
    System::Mail mail = System::Mail();
    mail.SetUserName("ggtcommunity338@gmail.com");
    mail.SetPassword("jgihrojudeswpbrc");
    mail.SetSubject("Test");
    mail.AddRecipient("thomashingraypro@gmail.com");
    mail.AddAttachment(System::IO::Path::Combine(System::Environment::SpecialFolder(System::SpecialFolder::Dekstop),
                                                 "Test.txt"));
    mail.AddLineBodyText("Salut, ceci est un test de mail venant de ma surcouche");
    mail.AddLineBodyText("tu me diras si tu la recu :)");
    mail.Send();
    System::Console::WriteLine(mail.Status());
    return 0;
}
