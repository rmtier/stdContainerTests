#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <unordered_set>

#include <random>
#include <string>
#include <algorithm>
#include "containers.h"
#include <memory>
#include <fstream>

std::string random_string()
{
     std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
     std::random_device rd;
     std::mt19937 generator(rd());
     std::shuffle(str.begin(), str.end(), generator);
     return str;
}

class Timer
{
public:
    void Start()
    {
        start = std::chrono::steady_clock::now();
    }

    size_t Stop()
    {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

private:
    std::chrono::steady_clock::time_point start;
};

struct Data
{
    std::string container;
    size_t containerSize;
    size_t appendTime;
    size_t findingTime;
    size_t deleteTime;
    size_t clearTime;
    size_t attemptNumber;
};

int main()
{
    std::vector<int> tests = {1000, 10000, 100000};
    std::vector<Data> results;
    for (size_t attempt = 0; attempt < 5; ++attempt)
    {
        std::vector<std::shared_ptr<IContainer>> containers = { std::make_shared<VectorContainer>(),
                                                              std::make_shared<DequeContainer>(),
                                                              std::make_shared<ListContainer>(),
                                                              std::make_shared<ForwardListContainer>(),
                                                              std::make_shared<SetContainer>(),
                                                              std::make_shared<UnorderedSetContainer>(),
                                                              std::make_shared<MapContainer>(),
                                                              std::make_shared<UnorderedMapContainer>()};

        for (auto containerIt = containers.begin(); containerIt != containers.end(); containerIt = containers.erase(containerIt))
        {
            std::cout << " ---------------------- Processing container: " << (*containerIt)->GetType() << std::endl;
            for (const int elemCount: tests)
            {
                std::vector<std::string> findingElements;
                std::vector<std::string> data;
                for (int i = 0; i < elemCount; ++i)
                {
                    auto value = random_string();
                    if (i%2 == 0)
                        findingElements.push_back(value);
                    data.push_back(value);
                }

                std::cout << " ------ Test: " << elemCount << " ------- " << std::endl;

                Data result;
                result.container = (*containerIt)->GetType();
                result.containerSize = elemCount;
                result.attemptNumber = attempt;
                {
                    Timer t;
                    t.Start();
                    for (int i = 0; i < elemCount; ++i)
                    {
                        (*containerIt)->Append(data.at(i));
                    }
                    result.appendTime = t.Stop();
                    std::cout << "Append: " << result.appendTime << std::endl;
                }
                {
                    Timer t;
                    t.Start();
                    for (const auto& elem: findingElements)
                    {
                        (*containerIt)->Find(elem);
                    }
                    result.findingTime = t.Stop();
                    std::cout << "Find: " << result.findingTime << std::endl;
                }
                {
                    Timer t;
                    t.Start();
                    for (const auto& elem: findingElements)
                    {
                        (*containerIt)->DeleteOne(elem);
                    }
                    result.deleteTime = t.Stop();
                    std::cout << "Delete regular: " << result.deleteTime << std::endl;
                }
                {
                    Timer t;
                    t.Start();

                     (*containerIt)->Clean();

                    result.clearTime = t.Stop();
                    std::cout << "Clean: " << result.clearTime << std::endl;
                }
                std::cout << "All: " << (result.appendTime + result.findingTime + result.deleteTime + result.clearTime) << std::endl;
                results.push_back(std::move(result));
            }
        }
    }

    std::ofstream resultFile;
    resultFile.open ("result.csv");

    resultFile << "Container;Try;Size;Append Time;Finding Time;Regular Deleting Time;Clear Time;All Time\n";
    for (const auto& result: results)
    {
        resultFile << result.container << ";" << result.attemptNumber << ";"  << result.containerSize << ";" << result.appendTime << ";"
               << result.findingTime << ";" << result.deleteTime << ";" << result.clearTime << ";"
               << (result.appendTime + result.findingTime + result.deleteTime + result.clearTime) << std::endl;
    }
    resultFile.close();

    return 0;
}
