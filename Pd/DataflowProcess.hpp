#pragma once
#include <Process/Dataflow/DataflowProcess.hpp>

#include <Pd/DataflowObjects.hpp>
#include <Process/Process.hpp>
#include <Process/TimeValue.hpp>
#include <iscore/serialization/VisitorInterface.hpp>
#include <ossia/dataflow/dataflow.hpp>
namespace QtNodes { class Node; }
namespace Dataflow
{
class CustomDataModel;
class ProcessModel : public Process::DataflowProcess
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos NOTIFY posChanged)
  public:
    using Process::DataflowProcess::DataflowProcess;

    QPointer<CustomDataModel> nodeModel{};
    QPointer<QtNodes::Node> node{};

    QPointF pos() const;

  signals:
    void posChanged(QPointF pos);

  public slots:
    void setPos(QPointF pos);

  private:
    QPointF m_pos;
};
}
