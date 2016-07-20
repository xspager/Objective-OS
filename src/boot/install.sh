mkdir -p fd
mount ../../Objective-OS.ima fd/ -oloop
cp objos.elf fd/boot/
umount fd
rmdir fd
