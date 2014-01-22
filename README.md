# [Yam][]

A User Interface System for Game


## Projects

* Yam Library
* Photoshop Plug-In
* Yam Editor


### Yam Library

__The core of yam, is a static library, was linked by other project.__

It will include the basic element of UI system, likes widget, panel, layout and layer.


### Photoshop Plug-In

__The plugin of Adobe Photoshop, is the file format module, can save the yam to file.__

We need use Adobe Photoshop to save the layer and image to yam format.


### Yam Editor

__A executable file, to edit/save the yam file(.yui).__

You can use it to edit/save the yam file and export the new format file.


## Ready

### Requirement

* [CMake][]
* [Visual C++][]
* [Qt][]
* [Photoshop SDK][]

### Environment

* set the PS\_PLUGIN\_SDK to the SDK directory for Photoshop Plug-In
* set the QT\_MSVC\_X32 to the Qt directory for Visual C++ x32

## Build

1. Generate the solution of VC++ by CMake
2. Compile/Build the project

## Usage

You can find all compiled files in "/out" directory.

### Photoshop Plug-In

1. Find the plugin file(pstoyam.8bi) in "/out" directory.
2. Copy it to the "/Plug-ins/File Formats" directory in the Photoshop directory __or__ Set the external plugin directory to the directory what contain the pstoyam.8bi file in Photoshop

### Yam Editor

1. Find the yeditor.exe in "/out" directory.
2. Run and use it.

### License

See [The MIT License][] or LICENSE file

## Link

1. [CMake][]
2. [Visual C++][]
3. [Qt][]
4. [Photoshop SDK][]
5. [The MIT License][]

[CMake]: http://cmake.org/ "CMake"
[Visual C++]: http://www.visualstudio.com/ "Visual C++"
[Qt]: http://qt-project.org/ "Qt"
[Photoshop]: http://www.adobe.com/products/photoshop.html "Photoshop"
[Photoshop SDK]: http://www.adobe.com/devnet/photoshop/sdk.html "Photoshop SDK"
[The MIT License]: http://opensource.org/licenses/MIT "The MIT License"
[Alex Chi]: http://alexchi.me/ "Alex Chi"
[Alex Chi's Blog]: http://blog.alexchi.me/ "Alex Chi's Blog"
[Code4Game]: http://c4g.alexchi.me/ "Code 4 Game"
[Yam]: http://c4g.alexchi.me/yam/ "Yam"
