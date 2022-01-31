#include "Mail.h"
#include "../Event/Action/Action.h"
#include <tchar.h>



#pragma region constructor
System::Mail::Mail()
{
}

System::Mail::Mail(const Mail& copy)
{
    recipient = copy.recipient;
    username = copy.username;
    password = copy.password;
    subject = copy.subject;
    server = copy.server;
    bodyText = copy.bodyText;
    serverPort = copy.serverPort;
    connectType = copy.connectType;
}
#pragma endregion constructor
#pragma region custom methods
void System::Mail::SetUserName(const string& username)
{
    this->username = username;
}

void System::Mail::SetPassword(const string& password)
{
    this->password = password;
}

void System::Mail::SetSubject(const string& subject)
{
    this->subject = subject;
}

void System::Mail::SetServer(const string& server)
{
    this->server = server;
}

void System::Mail::SetFrom(const string& from)
{
    this->from = from;
}

void System::Mail::AddLineBodyText(const string& line)
{
    this->bodyText.Append(line + "\n");
}

void System::Mail::SetServerPort(const Int& port)
{
    this->serverPort = port;
}

void System::Mail::AddRecipient(const string& recipient)
{
    this->recipient.Add(recipient);
}

void System::Mail::AddAttachment(const string& attachment)
{
    this->attachment.Add(attachment);
}

void System::Mail::SetConnectType(EConnectType connectType)
{
    this->connectType = connectType;
}

System::Boolean System::Mail::Send()
{
    ::CoInitialize(nullptr);
    EASendMailObjLib::IMailPtr mail = EASendMailObjLib::IMailPtr();
    mail.CreateInstance(__uuidof(EASendMailObjLib::Mail));
    mail->LicenseCode = _T("TryIt");
    mail->FromAddr = from.ToCstr();
    recipient.ForEach([&mail](String recipient)
    {
        mail->AddRecipientEx(recipient.ToCstr(), 0);
    });
    attachment.ForEach([&mail](string attachment)
    {
       mail->AddAttachment(attachment.ToCstr()); 
    });
    mail->Subject = subject.ToCstr();
    mail->BodyText = bodyText.ToString().ToCstr();
    mail->ServerAddr = server.ToCstr();
    mail->UserName = username.ToCstr();
    mail->Password = password.ToCstr();
    mail->ServerPort = serverPort;
    mail->ConnectType = static_cast<int>(connectType);
    const int result = mail->SendMail();
    lastError = string(mail->GetLastErrDescription());
    return result == 0;
}

System::String System::Mail::GetLastError() const
{
    return lastError;
}
#pragma endregion custom methods
#pragma region override
System::String System::Mail::ToString() const
{
    return string::Format("server: {0} port: {1} connectType: {2}", server, serverPort, Int(static_cast<int>(connectType)));
}

System::Integer System::Mail::GetHashCode() const
{
    return username.GetHashCode() ^ password.GetHashCode() << 2 ^ subject.GetHashCode() >> 2
        ^ server.GetHashCode() ^ bodyText.GetHashCode() << 2 ^ serverPort >> 2;
}
#pragma endregion override
#pragma region operator
System::Mail& System::Mail::operator=(const Mail& other)
{
    recipient = other.recipient;
    username = other.username;
    password = other.password;
    subject = other.subject;
    server = other.server;
    bodyText = other.bodyText;
    serverPort = other.serverPort;
    connectType = other.connectType;
    return *this;
}

System::Bool System::Mail::operator==(const Mail& other)
{
    return recipient == other.recipient && username == other.username && password == other.password && subject == other.subject
    && server == other.server && bodyText == other.bodyText && serverPort == other.serverPort && connectType == other.connectType;
}
#pragma endregion operator
