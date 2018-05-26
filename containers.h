#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>
#include <forward_list>

class ISequenceContainer
{
public:
    virtual void Insert(size_t index, const std::string& value) = 0;

};

class IMultiContainer
{
public:
    virtual void DeleteAll(const std::string& value) = 0;
};


class IContainer
{
public:

    virtual void Append(const std::string& value) = 0;

    virtual void AppendMove(std::string&& value) = 0;

    virtual const std::string& Find(const std::string& value) = 0;

    virtual void Clean() = 0;

    virtual void DeleteOne(const std::string& value) = 0;

    virtual std::string GetType() = 0;
};

class VectorContainer: public IContainer, ISequenceContainer, IMultiContainer
{
public:
    VectorContainer();

    virtual ~VectorContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    void DeleteAll(const std::string& value) override;

    void Insert(size_t index, const std::string& value) override;

    std::string GetType() override;

private:
    std::vector<std::string> m_container;
};

class DequeContainer: public IContainer, ISequenceContainer, IMultiContainer
{
public:
    DequeContainer();

    virtual ~DequeContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    void DeleteAll(const std::string& value) override;

    void Insert(size_t index, const std::string& value) override;

    std::string GetType() override;

private:
    std::deque<std::string> m_container;
};

class ListContainer: public IContainer, ISequenceContainer, IMultiContainer
{
public:
    ListContainer();

    virtual ~ListContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    void DeleteAll(const std::string& value) override;

    void Insert(size_t index, const std::string& value) override;

    std::string GetType() override;

private:
    std::list<std::string> m_container;
};

class ForwardListContainer: public IContainer, ISequenceContainer, IMultiContainer
{
public:
    ForwardListContainer();

    virtual ~ForwardListContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    void DeleteAll(const std::string& value) override;

    void Insert(size_t index, const std::string& value) override;

    std::string GetType() override;

private:
    std::forward_list<std::string> m_container;
};

class SetContainer: public IContainer
{
public:
    SetContainer();

    virtual ~SetContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    std::string GetType() override;

private:
    std::set<std::string> m_container;
};

class UnorderedSetContainer: public IContainer
{
public:
    UnorderedSetContainer();

    virtual ~UnorderedSetContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    std::string GetType() override;

private:
    std::unordered_set<std::string> m_container;
};

class MapContainer: public IContainer
{
public:
    MapContainer();

    virtual ~MapContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    std::string GetType() override;

private:
    std::map<std::string, std::string> m_container;
};

class UnorderedMapContainer: public IContainer
{
public:
    UnorderedMapContainer();

    virtual ~UnorderedMapContainer();

    void Append(const std::string& value) override;

    void AppendMove(std::string&& value) override;

    const std::string& Find(const std::string& value) override;

    void Clean() override;

    void DeleteOne(const std::string& value) override;

    std::string GetType() override;

private:
    std::unordered_map<std::string, std::string> m_container;
};
#endif // CONTAINERS_H
