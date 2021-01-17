# MessagePack Library for ESP-IDF on PlatformIO

Wrapper Package to enable ESP-IDF on PlatformIO to use the MessagePack library.


## Workaround for using on VSCode on macOS

On VSCode on macOS, the IntelliSence reports an error where `#include <msgpack.h>`.

This error can be avoided by the following:

```
$ echo '#undef __APPLE__' > .vscode/cross.h
```

And add following to `c_cpp_properties.json` file:

```
"forcedInclude": [ "${workspaceFolder}/.vscode/cross.h" ]
```

refs. https://github.com/microsoft/vscode-cpptools/issues/1083
