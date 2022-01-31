#include "System/Console/Console.h"
#include "System/Mail/Mail.h"

int main()
{
    System::Mail mail = System::Mail();
    mail.SetUserName("ggtcommunity338@gmail.com");
    mail.SetPassword("rifwralsxikroojo");
    mail.SetSubject("Test");
    mail.AddLineBodyText("SALUT OLIVIER");
    mail.AddLineBodyText("Hello How are u");
    mail.AddRecipient("olivierargentieri@gmail.com");
    const System::Bool result = mail.Send();
    System::Console::WriteLine("mail send {0}", result ? string("success") : string("error"));
    return 0;
}