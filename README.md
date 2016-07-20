Objective-OS
============

That is supposed to be an OS mostily writen in Objective-C. Is a hobby OS, so, you know.

You need to install [NASM](http://www.nasm.us/) (and [QEMU](http://wiki.qemu.org/Main_Page) if you want to use it).

```bash
$ cd src/boot
$ make
$ sudo install.sh
$ qemu-system-i386 -fda ../../Objective-OS.ima
```
