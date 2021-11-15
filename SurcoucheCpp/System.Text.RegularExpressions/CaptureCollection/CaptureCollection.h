#pragma once
#include "../../System/Object/Object.h"
#include "../../System.Collections.Generic/Interface/List/IList.h"
#include "../Capture/Capture.h"

namespace System
{
    namespace Text
    {
        namespace RegularExpressions
        {
            class CaptureCollection : public Object, public Collections::Generic::IList<Capture>, public Collections::Generic::IEnumerator<Capture>
            {
#pragma region f/p
            private:
                Capture* mTab = new Capture[0];
                Capture mCurrentItem = Capture();
                int mCurrentIndex = -1;
                int mCount = 0;
#pragma endregion f/p
#pragma region constructor
            public:
                CaptureCollection()=default;
                CaptureCollection(std::initializer_list<Capture> _tab);
                CaptureCollection(IEnumerator<Capture>* _enumerator);
                CaptureCollection(const CaptureCollection& _copy);
#pragma endregion constructor
#pragma region override
            public:
                Capture Current() override;
                bool MoveNext() override;
                void Reset() override;
                IEnumerator<Capture>* GetEnumerator() override;
                int Count() const override;
                void Add(Capture _item) override;
                void Clear() override;
                bool Contains(Capture _item) override;
                void Remove(Capture _item) override;
                int IndexOf(Capture _item) override;
                void Insert(const int32 _index, Capture _item) override;
                void RemoveAt(const int32 _index) override;
#pragma endregion override
#pragma region operator
            public:
                Capture& operator[](const int32& _index) const;
                CaptureCollection& operator=(const CaptureCollection& _other);
                Boolean operator==(const CaptureCollection& _other) const;
#pragma endregion operator
            };
        }
    }
}
