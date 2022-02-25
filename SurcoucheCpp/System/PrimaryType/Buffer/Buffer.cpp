#include "Buffer.h"

#include "../../Exception/IndexOutOfRange/IndexOutOfRangeException.h"
#include "../String/String.h"
#include "../Byte/Byte.h"

#pragma region f/p

System::Integer System::Buffer::Size() const
{
    return this->buffer.size();
}

#pragma endregion f/p
#pragma region constructor/destructor

System::Buffer::Buffer(const Integer& size)
{
    this->buffer = std::vector<Byte>(size);
}

System::Buffer::Buffer(std::initializer_list<Byte> items)
{
    this->buffer = std::vector<Byte>();
    for (const Byte& item : items)
        Insert(item);
}

System::Buffer::Buffer(const Buffer& copy)
{
    this->buffer = std::move(copy.buffer);
}

System::Buffer::~Buffer()
{
    this->buffer.clear();
}
#pragma endregion constructor/destructor
#pragma region custom methods
void System::Buffer::Insert(Byte c)
{
    buffer.push_back(c);
}

void System::Buffer::CopyTo(Array<Byte>& out)
{
    const int size = this->buffer.size();
    out = Array<Byte>(size);
    for (int i = 0; i < size; i++)
    {
        out[i] = this->buffer[i];
    }
}

System::String System::Buffer::ToString() const
{
    string result = string::Empty;
    const int size = this->buffer.size();
    for (int i = 0; i < size; ++i)
    {
        if (i < size - 1)
            result += string::Format("{0}|", this->buffer[i]);
        else result += this->buffer[i];
    }
    return result;
}

System::Integer System::Buffer::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Boolean System::Buffer::operator==(const object& _obj)
{
    const Buffer& other = static_cast<const Buffer&>(_obj);
    return this->operator==(other);
}

System::Boolean System::Buffer::operator==(const object* _obj)
{
    const Buffer& other = static_cast<const Buffer&>(*_obj);
    return this->operator==(other);
}

System::Boolean System::Buffer::operator==(const Buffer& other)
{
    return this->buffer == other.buffer;
}

#pragma endregion custom methods
#pragma region operator
System::Buffer& System::Buffer::operator=(const Buffer& other)
{
    this->buffer = other.buffer;
    return *this;
}

System::Byte& System::Buffer::operator[](const Integer& index)
{
    if (index < 0 || index > this->buffer.size())
        throw IndexOutOfRangeException("Invalid index buffer");
    return this->buffer[index];
}
#pragma endregion operator
