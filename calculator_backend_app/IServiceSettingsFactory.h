#pragma once

#include <memory>
#include <restbed>

class IServiceSettingsFactory
{
public:
    virtual shared_ptr<Settings> get_setting() const = 0;
};
