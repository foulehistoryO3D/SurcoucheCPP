#pragma once
#include "../../System.Collections.Generic/List/List.h"
#include "../../System.Text/StringBuilder/StringBuilder.h"
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"

#include "EASendMailObj.tlh"

namespace System
{
    enum class EConnectType : uint8
    {
        Normal, SSLAuto, StartTLS, DirectSSL, TryTLS
    };
    /**
     * \brief
     * <summary>base value of server = smtp.gmail.com and port = 587 </summary>
     */
    class Mail : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        Collections::Generic::List<string> recipient = Collections::Generic::List<string>();
        Collections::Generic::List<string> attachment = Collections::Generic::List<string>();
        string username = string::Empty;
        string password = string::Empty;
        string subject = string::Empty;
        string lastError = string::Empty;
        string from = "gmailid@gmail.com";
        string server = "smtp.gmail.com";
        Text::StringBuilder bodyText = Text::StringBuilder::Empty;
        Int serverPort = 587;
        EConnectType connectType = EConnectType::SSLAuto;
#pragma endregion f/p
#pragma region constructor
    public:
        Mail();
        Mail(const Mail& copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        void SetUserName(const string& username);
        void SetPassword(const string& password);
        void SetSubject(const string& subject);
        void SetServer(const string& server);
        void SetFrom(const string& from);
        void AddLineBodyText(const string& line);
        void SetServerPort(const Int& port);
        void AddRecipient(const string& recipient);
        void AddAttachment(const string& attachment);
        void SetConnectType(EConnectType connectType);
        Boolean Send();
        String GetLastError()const;
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Integer GetHashCode() const override;;
#pragma endregion override
#pragma region operator
    public:
        Mail& operator=(const Mail& other);
        Bool operator==(const Mail& other);
#pragma endregion operator
    };
}
