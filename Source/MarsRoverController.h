#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

class MarsRover;

class MarsRoverController
{
public:
    MarsRoverController(const std::shared_ptr<MarsRover>& rover);
    
    void move(const std::string& commands);

private:
    using ROVER_ACTION = std::function<void(MarsRover&)>;

    std::shared_ptr<MarsRover> mRover;
    std::map<char, ROVER_ACTION> mActions;
};
