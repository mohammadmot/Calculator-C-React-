# Calculator-C-React-
Calculator project = webserver webApi Modern C++ + React as a client

## [front-end with React.js]
```
> npm install -g create-react-app
> npm create-react-app --version
> npx create-react-app calculator_frontend_app
> npm start

> git clone ....
> npm install
> npm start
```

### [Configuration]
```
Config client side, server IP:Port:
	/home/ubuntu/c++/Calculator-C-React-/calculator_frontend_app/src/App.js
    <Calculator CalculatorApi={new CalculatorApi('http://31.7.67.227:3002')} />
```

## [Back-end with Modern-C++]
[1]:
restApi in C++:

ref: https://github.com/Corvusoft/restbed.git

linux:
> sudo apt update

> sudo apt install librestbed-dev

[2]:
JSON libraries in C++:
> https://github.com/nlohmann/json.git

> https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp

[3]:
CMake is an open-source, cross-platform family of tools designed to build, test and package software. CMake is used to control the software compilation process using simple platform and compiler independent configuration files, and generate native makefiles and workspaces that can be used in the compiler environment of your choice.
https://cmake.org/

> sudo apt install cmake
or
> sudo snap install cmake


> mkdir build

> cmake ./ -Bbuild

> cmake --build ./build --target all --config Release

### [Configuration]
```
Config server Port:
	/home/ubuntu/c++/Calculator-C-React-/calculator_backend_app/CalcServiceSettingsFactory.cpp
	_settings->set_port(3002);
```
