# [Yam][]

A User Interface System for Game. It belong to [Code4Game][].

#### Build Status

master: [![Build Status](https://travis-ci.org/code4game/yam.png?branch=master)](https://travis-ci.org/code4game/yam)

dev: [![Build Status](https://travis-ci.org/code4game/yam.png?branch=dev)](https://travis-ci.org/code4game/yam)

#### Coverage Status

[![Coverage Status](https://coveralls.io/repos/code4game/yam/badge.png)](https://coveralls.io/r/code4game/yam)


## Overview

* [**Projects**](#projects)
* [**Ready**](#ready)
* [**Build**](#build)
* [**Usage**](#usage)
* [**Credits**](#credits)
* [**License**](#license)
* [**Link**](#link)


## Projects

* Yam Library
* Yam Editor
* [Photoshop][] Plug-In (only compiled by [Visual C++][])

### Yam Library

___The core of yam, is a static library, was linked by other projects.___

It will include the basic element of UI system, likes widget, panel, layout and layer.

### Yam Editor

___A executable file, to edit/save the yam file(.yui).___

You can use it to edit/save the yam file and export the new format file.

### [Photoshop][] Plug-In (only compiled by [Visual C++][])

___The plugin of [Adobe][] [Photoshop][], is the file format module, can save the yam to file.___

It can save all layers and images of .psd file to yam format(.yui) by [Adobe][] [Photoshop][].


## Ready

### Requirement

* [CMake][]
* [Visual C++][] or [MinGW][]
* [Qt][]
* [Photoshop SDK][] (only compiled by [Visual C++][])

### Environment

* Add the [MinGW][] installation directory to the "PATH" environment variable if you want compile by [MinGW][].


## Build

1. Configure the environment by [CMake][].

    * Set QT\_SDK\_PATH to the [Qt][] SDK installation directory.
    * Set PHOTOSHOP\_SDK\_PATH to the [Photoshop SDK][] installation directory.

2.  Generate the solution by [CMake][].

    * Generate the [Visual C++][] soluction or [MinGW][] Makefile.
 
3. Compile/Build the project/makefile.


## Usage

You can find all compiled files in "/out" directory.

### Yam Editor

1. Find the yeditor.exe in "/out" directory.
2. Run and use it.

### [Photoshop][] Plug-In (only compiled by [Visual C++][])

1. Find the plugin file(pstoyam.8bi) in "/out" directory.
2. Copy it to the "/Plug-ins/File Formats" directory in the Photoshop directory __or__ Set the external plugin directory to the directory what contain the pstoyam.8bi file in Photoshop

## Credits

It is part of [Code4Game][] and was created by [Alex Chi][].


## License

See [MIT License][] or LICENSE file


## Link

1. [MIT License][]
1. [CMake][]
1. [Visual C++][]
1. [MinGW][]
1. [Qt][]
1. [Photoshop SDK][]


[CMake]: http://cmake.org/ "CMake"
[Visual C++]: http://www.visualstudio.com/ "Visual C++"
[MinGW]: http://www.mingw.org/ "MinGW"
[Qt]: http://qt-project.org/ "Qt"
[Adobe]: http://www.adobe.com/ "Adobe"
[Photoshop]: http://www.adobe.com/products/photoshop.html "Photoshop"
[Photoshop SDK]: http://www.adobe.com/devnet/photoshop/sdk.html "Photoshop SDK"
[MIT License]: http://opensource.org/licenses/MIT "MIT License"
[Alex Chi]: http://alexchi.me/ "Alex Chi"
[Alex Chi's Blog]: http://blog.alexchi.me/ "Alex Chi's Blog"
[Code4Game]: http://c4g.alexchi.me/ "Code 4 Game"
[Yam]: http://c4g.alexchi.me/yam/ "Yam"
