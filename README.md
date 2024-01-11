# GodotTemplate
Godot C++ project template configured for Windows and Linux.

Author: Daniel Lewiński

# Instructions for running the project

Requires [SCons](https://scons.org/pages/download.html) to be installed.

```console
$ git clone https://github.com/DanteX95X/GodotTemplate.git --recursive
$ # build project with debug symbols
$ scons target=template_debug dev_build=yes debug_symbols=yes
$ # build release project
$ scons target=template_release production=yes
```

Now you can open the project in Godot, work on it and export it if you wish.

Documentation of GDExtensions can be found here:
[GDExtenstions example](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html)

# QtCreator instructions

QtCreator project contained in this repository is configured to properly autocomplete and suggest godot code.
Users have to set their own build and run configurations.
To do that:

1. Open the QtCreator project.
1. Click on the Project button on the column on the left.
1. Select Build under Build & Run category.
1. Click Add -> Build and name your debug build configuration.
1. Make sure that your debug build configuration is selected from dropdown.
1. Set Build Directory to a director containing projects SConstruct file.
1. Clear the default build steps. It won't work with godot projects.
1. Add Build Step -> Custom Process Step.
1. Set the custom step data - Command: `scons`, Arguments: `target=template_debug dev_build=yes debug_symbols=yes`, Working directory: `%{buildDir}`.
1. Add new release configuration repeating the steps above but changing the Custom Process Step's Arguments to: `target=template_release production=yes`.
1. Select Run under Build & Run category.
1. Set Executable to Godot executable.
1. Set Command line arguments to `-e` if you want to run the whole editor via IDE or type the path to the scene you want Godot to run.

Now you should be able to build, run and debug the project from QtCreator.

# Building the engine

If you need to debug the engine you have to build it youself in dev_build mode.
[Godot building documentation](https://docs.godotengine.org/en/latest/contributing/development/compiling/)
