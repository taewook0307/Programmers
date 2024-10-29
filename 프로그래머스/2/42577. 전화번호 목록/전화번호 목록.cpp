#include <string>
#include <vector>
#include <algorithm>

bool solution(std::vector<std::string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());

    const size_t PhoneNumCount = phone_book.size();

    for (size_t i = 0; i < PhoneNumCount - 1; ++i)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            return false;
        }
    }

    return true;
}