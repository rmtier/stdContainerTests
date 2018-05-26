#include "containers.h"
#include <algorithm>
#include <assert.h>

VectorContainer::VectorContainer()
{

}

VectorContainer::~VectorContainer()
{

}

void VectorContainer::Append(const std::string &value)
{
    m_container.push_back(value);
}

void VectorContainer::AppendMove(std::string &&value)
{
    m_container.push_back(value);
}

const std::string &VectorContainer::Find(const std::string &value)
{
    auto it = std::find(m_container.begin(), m_container.end(), value);
    if (it != m_container.end())
        return *it;
    assert(false);
}

void VectorContainer::Clean()
{
    m_container.clear();
}

void VectorContainer::DeleteOne(const std::string &value)
{
    auto it = std::find(m_container.begin(), m_container.end(), value);
    if (it != m_container.end())
        m_container.erase(it);
}

void VectorContainer::DeleteAll(const std::string &value)
{
    std::remove(m_container.begin(), m_container.end(), value);
}

void VectorContainer::Insert(size_t index, const std::string &value)
{
    m_container.insert(std::begin(m_container) + index, value);
}

std::string VectorContainer::GetType()
{
    return "VectorContainer";
}

DequeContainer::DequeContainer()
{

}

DequeContainer::~DequeContainer()
{

}

void DequeContainer::Append(const std::string &value)
{
    m_container.push_back(value);
}

void DequeContainer::AppendMove(std::string &&value)
{
    m_container.push_back(value);
}

const std::string &DequeContainer::Find(const std::string &value)
{
    auto it = std::find(m_container.begin(), m_container.end(), value);
    if (it != m_container.end())
        return *it;
    assert(false);
}

void DequeContainer::Clean()
{
    m_container.clear();
}

void DequeContainer::DeleteOne(const std::string &value)
{
    auto it = std::find(m_container.begin(), m_container.end(), value);
    if (it != m_container.end())
        m_container.erase(it);
}

void DequeContainer::DeleteAll(const std::string &value)
{
    std::remove(m_container.begin(), m_container.end(), value);
}

void DequeContainer::Insert(size_t index, const std::string &value)
{
    m_container.insert(std::begin(m_container) + index, value);
}

std::string DequeContainer::GetType()
{
    return "DequeContainer";
}

ListContainer::ListContainer()
{

}

ListContainer::~ListContainer()
{

}

void ListContainer::Append(const std::string &value)
{
    m_container.push_back(value);
}

void ListContainer::AppendMove(std::string &&value)
{
    m_container.push_back(value);
}

const std::string &ListContainer::Find(const std::string &value)
{
    auto it = std::find(m_container.begin(), m_container.end(), value);
    if (it != m_container.end())
        return *it;
    assert(false);
}

void ListContainer::Clean()
{
    m_container.clear();
}

void ListContainer::DeleteOne(const std::string &value)
{
    m_container.remove(value);
}

void ListContainer::DeleteAll(const std::string &value)
{
    std::remove(m_container.begin(), m_container.end(), value);
}

void ListContainer::Insert(size_t index, const std::string &value)
{
    m_container.insert(std::next(std::begin(m_container), index), value);
}

std::string ListContainer::GetType()
{
    return "ListContainer";
}

ForwardListContainer::ForwardListContainer()
{

}

ForwardListContainer::~ForwardListContainer()
{

}

void ForwardListContainer::Append(const std::string &value)
{
    m_container.push_front(value);
}

void ForwardListContainer::AppendMove(std::string &&value)
{
    m_container.push_front(value);
}

const std::string &ForwardListContainer::Find(const std::string &value)
{
    auto it = std::find(m_container.begin(), m_container.end(), value);
    if (it != m_container.end())
        return *it;
    assert(false);
}

void ForwardListContainer::Clean()
{
    m_container.clear();
}

void ForwardListContainer::DeleteOne(const std::string &value)
{
    m_container.remove(value);
}

void ForwardListContainer::DeleteAll(const std::string &value)
{
    m_container.remove(value);
}

void ForwardListContainer::Insert(size_t index, const std::string &value)
{
    m_container.insert_after(std::next(m_container.begin(), index), value);
}

std::string ForwardListContainer::GetType()
{
    return "ForwardListContainer";
}

SetContainer::SetContainer()
{

}

SetContainer::~SetContainer()
{

}

void SetContainer::Append(const std::string &value)
{
    m_container.insert(value);
}

void SetContainer::AppendMove(std::string &&value)
{
    m_container.insert(value);
}

const std::string &SetContainer::Find(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        return *it;
    assert(false);
}

void SetContainer::Clean()
{
    m_container.clear();
}

void SetContainer::DeleteOne(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        m_container.erase(it);
}

std::string SetContainer::GetType()
{
    return "SetContainer";
}


UnorderedSetContainer::UnorderedSetContainer()
{

}

UnorderedSetContainer::~UnorderedSetContainer()
{

}

void UnorderedSetContainer::Append(const std::string &value)
{
    m_container.insert(value);
}

void UnorderedSetContainer::AppendMove(std::string &&value)
{
    m_container.insert(value);
}

const std::string &UnorderedSetContainer::Find(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        return *it;
    assert(false);
}

void UnorderedSetContainer::Clean()
{
    m_container.clear();
}

void UnorderedSetContainer::DeleteOne(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        m_container.erase(it);
}

std::string UnorderedSetContainer::GetType()
{
    return "UnorderedSetContainer";
}

MapContainer::MapContainer()
{

}

MapContainer::~MapContainer()
{

}

void MapContainer::Append(const std::string &value)
{
    m_container.insert(std::pair<std::string, std::string>(value, value));
}

void MapContainer::AppendMove(std::string &&value)
{
    m_container.insert(std::pair<std::string, std::string>(value, "value"));
}

const std::string &MapContainer::Find(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        return it->first;
    assert(false);
}

void MapContainer::Clean()
{
    m_container.clear();
}

void MapContainer::DeleteOne(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        m_container.erase(it);
}

std::string MapContainer::GetType()
{
    return "MapContainer";
}

UnorderedMapContainer::UnorderedMapContainer()
{

}

UnorderedMapContainer::~UnorderedMapContainer()
{

}

void UnorderedMapContainer::Append(const std::string &value)
{
    m_container.insert(std::pair<std::string, std::string>(value, "value"));
}

void UnorderedMapContainer::AppendMove(std::string &&value)
{
    m_container.insert(std::pair<std::string, std::string>(std::string(value), value));
}

const std::string &UnorderedMapContainer::Find(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        return it->first;
    assert(false);
}

void UnorderedMapContainer::Clean()
{
    m_container.clear();
}

void UnorderedMapContainer::DeleteOne(const std::string &value)
{
    auto it = m_container.find(value);
    if (it != m_container.end())
        m_container.erase(it);
}

std::string UnorderedMapContainer::GetType()
{
    return "UnorderedMapContainer";
}
