#pragma once

#include "IServiceSettingsFactory.h"

class CalcServiceSettingsFactory : public IServiceSettingsFactory
{
public:
    CalcServiceSettingsFactory();

    shared_ptr<Settings> get_setting() const final;

private:
    shared_ptr<Settings> _settings;
};
