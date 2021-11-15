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
                Group(const int& _index, const String& _value, const CaptureCollection& _collection);
                Group(const Group& _copy);
#pragma endregion constructor
#pragma region operator
            public:
                String ToString() const override;
                Boolean Equals(const object* _obj) override;
                Boolean Equals(const object& _obj) override;
                size_t GetHashCode() const override;
#pragma endregion operator
            };
        }
    }
}
