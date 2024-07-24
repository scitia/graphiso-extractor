#pragma once

#ifndef GROUND_WRITER_H
#define GROUND_WRITER_H

#include "groundfile.hpp"
#include "iwriteable.hpp"
#include <utility> // contains pair

class GroundWriter : public IWriteable
{
public:
    virtual bool write(GFile &file) const override;
private:
    void set_details(GroundFile &file, std::string filename) const;
    void write_single_ground(std::filesystem::path target, int value) const;
    std::pair<std::string, std::string> decompose_filename(std::string filename) const;
};

#endif //GROUND_WRITER_H