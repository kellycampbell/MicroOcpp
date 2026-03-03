// matth-x/MicroOcpp
// Copyright Matthias Akstaller 2019 - 2024
// MIT License

#ifndef MO_NOTIFYEVENT_H
#define MO_NOTIFYEVENT_H

#include <MicroOcpp/Version.h>

#if MO_ENABLE_V201

#include <MicroOcpp/Core/Operation.h>
#include <MicroOcpp/Core/Time.h>
#include <MicroOcpp/Core/Memory.h>

namespace MicroOcpp {

class Model;
class Variable;

namespace Ocpp201 {

class NotifyEvent : public Operation, public MemoryManaged {
private:
    Model& model;

    int requestId;
    Timestamp generatedAt;
    bool tbc;
    int seqNo;
    Vector<Variable*> reportData;
public:

    NotifyEvent(Model& model, int requestId, const Timestamp& generatedAt, bool tbc, int seqNo, const Vector<Variable*>& reportData);

    const char* getOperationType() override;

    std::unique_ptr<JsonDoc> createReq() override;

    void processConf(JsonObject payload) override;
};

} //end namespace Ocpp201
} //end namespace MicroOcpp
#endif // MO_ENABLE_V201
#endif
