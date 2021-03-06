//
//  subscriber.h
//  lab8
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H
#include <fstream>

class Sub {
public:
    virtual void output(std::vector<std::shared_ptr<figures::Figure>>& Vec) = 0;
    virtual ~Sub() = default;
};

class Print : public Sub {
public:
    void output(std::vector<std::shared_ptr<figures::Figure>>& Vec) override {
        for (auto& figure : Vec) {
            figure->print(std::cout);
        }
    }
};

class Log : public Sub {
public:
    Log() : in(1) {}
    void output(std::vector<std::shared_ptr<figures::Figure>>& Vec) override {
        std::string filename;
        filename = std::to_string(in);
        filename += ".txt";
        std::ofstream file;
        file.open(filename);
        for (auto& figure : Vec) {
            figure->print(file);
        }
        in++;
    }
private:
    int in;
};



#endif
