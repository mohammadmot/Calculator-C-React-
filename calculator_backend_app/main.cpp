#include "CalcResourceFactory.h"
#include "CalcServiceSettingsFactory.h"
#include "CalcService.h"

int main(int argc, char **argv)
{
    auto resource_factory = make_shared<CalcResourceFactory>();
    auto setting_factory = make_shared<CalcServiceSettingsFactory>();
    CalcService service{resource_factory, setting_factory};

    service.start();

    return 0;
}