#pragma once
#include "../../../System/Object/Object.h"
#include "../../Reader/SQLReader.h"

namespace System
{
    namespace SQL
    {
        class ISQLCommand
        {
        public:
            virtual ~ISQLCommand() = default;
            virtual void Execute() PURE_VIRTUAL()
            virtual SQLReader ExecuteReader() PURE_VIRTUAL()
        };
    }
}
