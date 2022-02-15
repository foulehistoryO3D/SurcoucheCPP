#pragma once
#include <deque>
#include <mutex>

namespace Net
{
    template <typename Item>
    class NetQueue
    {
#pragma region f/p
    private:
        std::mutex muxQueue                 = std::mutex();
        std::deque<Item> queue              = std::deque<Item>();
        std::condition_variable blocking    = std::condition_variable();
        std::mutex mutexBlocking            = std::mutex();
#pragma endregion f/p
#pragma region constructor / destructor
    public:
        NetQueue() = default;
        NetQueue(const NetQueue<Item>&) = delete;
        virtual ~NetQueue() { Clear(); }
#pragma endregion constructor / destructor
#pragma region custom methods
    public:
        const Item& Front()
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            return queue.front();
        }

        const Item& Back()
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            return queue.back();
        }
        Item PopFront()
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            std::remove_reference_t<Item> item = std::move(queue.front());
            queue.pop_front();
            return item;
        }
        Item PopBack()
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            std::remove_reference_t<Item> item = std::move(queue.back());
            queue.pop_back();
            return item;
        }

        void PushBack(const Item& item)
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            queue.emplace_back(std::move(item));
            std::unique_lock uniqueLock = mutexBlocking;
            blocking.notify_one();
        }

        void PushFront(const Item& item)
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            queue.emplace_front(std::move(item));
            std::unique_lock uniqueLock = mutexBlocking;
            blocking.notify_one();
        }

        bool Empty()
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            return queue.empty();
        }

        size_t Count()
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            return queue.size();
        }

        void Clear()
        {
            std::scoped_lock lock = std::scoped_lock(muxQueue);
            queue.clear();
        }

        void Wait()
        {
            while (Empty())
            {
                std::unique_lock uniqueLock = mutexBlocking;
                blocking.wait(uniqueLock);
            }
        }
#pragma endregion custom methods
    };
}
