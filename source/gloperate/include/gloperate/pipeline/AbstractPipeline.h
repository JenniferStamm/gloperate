#pragma once

#include <vector>
#include <string>
#include <set>

#include <gloperate/gloperate_api.h>

namespace gloperate
{

class AbstractData;
class AbstractStage;
class AbstractInputSlot;
template <typename T>
class Data;


class GLOPERATE_API AbstractPipeline
{
public:
    AbstractPipeline(const std::string & name = "");
    virtual ~AbstractPipeline();

    const std::string & name() const;
    void setName(const std::string & name);

    bool hasName() const;

    std::string asPrintable() const;

    bool isInitialized() const;
    void initialize();

    virtual void execute();

    virtual void addStage(AbstractStage * stage);

    void addParameter(AbstractData * parameter);
    void addParameter(const std::string & name, AbstractData * parameter);

    template <typename T>
    Data<T> * addConstantParameter(const T & value);

    void shareData(const AbstractData* data);
    void shareDataFrom(const AbstractInputSlot& slot);

    std::vector<AbstractInputSlot*> allInputs() const;
    std::vector<AbstractData*> allOutputs() const;

    AbstractData * findParameter(const std::string & name) const;
    std::vector<AbstractData*> findOutputs(const std::string & name) const;

    template <typename T>
    Data<T> * getParameter(const std::string & name) const;
    template <typename T>
    Data<T> * getParameter() const;

    template <typename T>
    Data<T> * getOutput(const std::string & name) const;
    template <typename T>
    Data<T> * getOutput() const;

    template<typename T, typename... Args>
    void addStages(T stage, Args... pipeline);

    const std::vector<AbstractStage*> & stages() const;
    const std::vector<AbstractData*> & parameters() const;

    std::set<AbstractData*> unusedParameters();

protected: 
    void sortDependencies();
    void addStages();
    void initializeStages();

    void tsort(std::vector<AbstractStage*> & stages);

protected:
    bool m_initialized;
    std::string m_name;
    std::vector<AbstractStage*> m_stages;
    std::vector<AbstractData*> m_parameters;
    std::vector<AbstractData*> m_constantParameters;
    std::vector<const AbstractData*> m_sharedData;
    bool m_dependenciesSorted;

private:
    AbstractPipeline(const AbstractPipeline&) = delete;
};

} // namespace gloperate

#include <gloperate/pipeline/AbstractPipeline.hpp>
