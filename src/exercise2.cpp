#include <iostream>
#include <thread>
#include <sstream>
#include <memory>
#include <array>

/*
1.	What type of constructor of std::string is called in setCustomData?
2.	What is the difference between std::unique_ptr and std::shared_ptr? 
3.	What is this code trying to achieve?
4.	Is this code correct?
5.	If the answer is no, how you can fix it?
*/


std::uint32_t threshold = 1'000'000;

class CustomData
{
public:
    CustomData() : m_customData(std::make_unique<std::string>(""))
    {
    }

    std::string getCustomData() const
    {
        return *m_customData;
    }

    void setCustomData(const std::string& customData)
    {
        m_customData = std::make_unique<std::string>(customData);
    }
private:
    std::unique_ptr<std::string> m_customData;
};


int main()
{
    CustomData customData;

    const auto writeJob = [&customData]()
    {
        for (std::uint32_t i = 0; i <= threshold; ++i)
        {
            std::size_t tokenStrLen = i % 200 + 1;
            const std::string tokenStr(tokenStrLen, 'a');
            const auto data = tokenStr + " " + std::to_string(i);

            customData.setCustomData(data);
        }
    };

    const auto readJob = [&customData]()
    {
        while (true)
        {
            const auto data = customData.getCustomData();

            if (data.empty())
            {
                continue;
            }

            std::stringstream ss(data);
            std::string tokenStr;
            std::uint32_t tokenInt = 0;
            ss >> tokenStr >> tokenInt;
            if (tokenInt >= threshold)
            {
                break;
            }
        }
    };

    std::array<std::thread, 2> readerWorkers{std::thread(readJob), std::thread(readJob)};
    std::array<std::thread, 2> writerWorkers{std::thread(writeJob), std::thread(writeJob)};

    for (auto& worker : readerWorkers)
    {
        worker.join();
    }

    for (auto& worker : writerWorkers)
    {
        worker.join();
    }
}
