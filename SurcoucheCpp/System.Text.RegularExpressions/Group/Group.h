#pragma once
#include "../Capture/Capture.h"
#include "../CaptureCollection/CaptureCollection.h"

namespace System
{
    namespace Text
    {
        namespace RegularExpressions
        {
            class Group : public Capture
            {
                DECLARE_CLASS_INFO(Capture)
#pragma region f/p
            protected:
                CaptureCollection mCaptureCollection = CaptureCollection();
                const char* mName = null;
                bool mSuccess = false;
            public:
                CaptureCollection Captures()const;
                String Name()const;
                Boolean Success()const;
#pragma endregion f/p
#pragma region constructor
            public:
                Group()=default;
                Group(const Group& _copy);
#pragma endregion constructor
#pragma region custom methods
            public:
                void SetName(const String& _name);
                void SetSuccess(const bool _success);
                void AddCapture(const Capture& _capture);
#pragma endregion custom methods
#pragma region override
            public:
                String ToString() const override;
                Boolean Equals(const object* _obj) override;
                Boolean Equals(const object& _obj) override;
                size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
            public:
                Group operator=(const Group& _other);
#pragma endregion operator
            };
        }
    }
}
