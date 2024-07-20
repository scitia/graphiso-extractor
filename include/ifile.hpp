#pragma once

#ifndef IFILE_H
#define IFILE_H

class IFile {

public:
    virtual void save() = 0;
    virtual ~IFile() {};
};

#endif //IFILE_H