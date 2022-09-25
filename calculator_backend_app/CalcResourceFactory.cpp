#include "CalcResourceFactory.h"

#include <sstream>
#include <iomanip>

#include "json.hpp"

CalcResourceFactory::CalcResourceFactory()
{
    _resource = make_shared<Resource>();

    _resource->set_path(
        "/{operation: add|subtract|multiply|divide}" // operation of calculator
        "/{num1: [-+]?[0-9]*\\.?[0-9]*}"             // regex number float or integer
        "/{num2: [-+]?[0-9]*\\.?[0-9]*}");

    _resource->set_method_handler("GET", [&](const shared_ptr<Session> session)
                                  { get_handler(session); }); // http method
}

tuple<float, float, string> CalcResourceFactory::get_path_parameters(
    const shared_ptr<Session> session)
{
    const auto &request = session->get_request();
    auto operation = request->get_path_parameter("operation");
    auto num1 = atof(request->get_path_parameter("num1").c_str());
    auto num2 = atof(request->get_path_parameter("num2").c_str());

    return make_tuple(num1, num2, operation);
}

void CalcResourceFactory::get_handler(const shared_ptr<Session> session)
{
    // structure binding, in c++17 standard
    const auto [num1, num2, operation] = get_path_parameters(session);

    const auto result = Calculate(num1, num2, operation);
    auto content = to_json(result);

    session->close(OK, content,
                   {{"Content-Length", to_string(content.size())}});
}

float CalcResourceFactory::Calculate(float num1, float num2, string operation)
{
    if (operation == "add")
        return num1 + num2;
    else if (operation == "subtract")
        return num1 - num2;
    else if (operation == "multiply")
        return num1 * num2;
    else if (operation == "divide")
        return num1 / num2;
    return 0;
}

string CalcResourceFactory::to_json(float result)
{
    ostringstream str_stream;
    str_stream << result;
    nlohmann::json jsonResult = {
        {"result", str_stream.str()}};

    return jsonResult.dump();
}

shared_ptr<Resource> CalcResourceFactory::get_resource() const
{
    return _resource;
}