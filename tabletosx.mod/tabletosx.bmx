
Module surj.TabletOSX

ModuleInfo "Version: 0.0.5"
ModuleInfo "Author: Nicolas Porter <yo@nicolasporter.ca>"
ModuleInfo "License: MIT"

Import "src/tablet.c"

Extern
    Function TabletOpen:Int()
    Function TabletClose:Int()
    Function TabletButtons:Int()
    Function TabletPressure:Float()
End Extern
