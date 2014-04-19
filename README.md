surj.mod - BlitzMax Modules
===========================

#### Installing these modules
```bash
cd <blitzmax_folder>/mod
git clone https://github.com/surjikal/surj.mod
```

#### Compiling modules
```bash
cd <blitzmax_folder>/bin
./bmk makemods surj.<module>
```

# Modules

## surj.TabletOSX

Since `pub.Tablet` depends on the `wintab` API, we can't use it on OSX. This module serves as a basic implementation
for OSX.
