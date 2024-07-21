#pragma once

#ifndef I_TARGETABLE_H
#define I_TARGETABLE_H

#include <filesystem>
#include <string>

class ITargetable
{
public:
    virtual ~ITargetable() = default;
    virtual std::filesystem::path build_target_absolute() const = 0;
    virtual std::string build_target_filename() const = 0;
};

#endif //I_TARGETABLE_H