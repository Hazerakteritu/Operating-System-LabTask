hazera@hazera-VirtualBox:~/Desktop$ pwd
/home/hazera/Desktop
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  lab.sh  ritu.sh  w.c
hazera@hazera-VirtualBox:~/Desktop$ /home/hazera/Music
bash: /home/hazera/Music: Is a directory
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  lab.sh  ritu.sh  w.c
hazera@hazera-VirtualBox:~/Desktop$ pwd
/home/hazera/Desktop
hazera@hazera-VirtualBox:~/Desktop$ cd /home/hazera/Music
hazera@hazera-VirtualBox:~/Music$ pwd
/home/hazera/Music
hazera@hazera-VirtualBox:~/Music$ ls
hazera@hazera-VirtualBox:~/Music$ cd ..
hazera@hazera-VirtualBox:~$ pwd
/home/hazera
hazera@hazera-VirtualBox:~$ ls
Desktop  Documents  Downloads  Music  Pictures  Public  snap  Templates  Videos
hazera@hazera-VirtualBox:~$ cd Desktop
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  lab.sh  ritu.sh  w.c
hazera@hazera-VirtualBox:~/Desktop$ mkdir Hazera
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  Hazera  lab.sh  ritu.sh  w.c
hazera@hazera-VirtualBox:~/Desktop$ cd Hazera
hazera@hazera-VirtualBox:~/Desktop/Hazera$ touch file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ nano file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ nano file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ nano file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ gedit file1.txt
Command 'gedit' not found, but can be installed with:
sudo snap install gedit  # version 46.1, or
sudo apt  install gedit  # version 46.1-3
See 'snap info gedit' for additional versions.
hazera@hazera-VirtualBox:~/Desktop/Hazera$ cat file1.txt
Hello everyone
good night

//....................................Class 4...................
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  Hazera  lab.sh  ritu.sh  w.c
hazera@hazera-VirtualBox:~/Desktop$ cd Hazera
hazera@hazera-VirtualBox:~/Desktop/Hazera$ mkdir folder[1..5]
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
 file1.txt  'folder[1..5]'
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rm folder[1..5]
rm: cannot remove 'folder[1..5]': Is a directory
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rmdir folder[1..5]
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ mkdir folder{1..5}
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
file1.txt  folder1  folder2  folder3  folder4  folder5
hazera@hazera-VirtualBox:~/Desktop/Hazera$ touch B{1..3}.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B1.txt  B2.txt  B3.txt  file1.txt  folder1  folder2  folder3  folder4  folder5
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rmdir folder{1..2}
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B1.txt  B2.txt  B3.txt  file1.txt  folder3  folder4  folder5
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rmdir folder4
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B1.txt  B2.txt  B3.txt  file1.txt  folder3  folder5
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rmdir folder{1..5}
rmdir: failed to remove 'folder1': No such file or directory
rmdir: failed to remove 'folder2': No such file or directory
rmdir: failed to remove 'folder4': No such file or directory
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rmdir folder3
rmdir: failed to remove 'folder3': No such file or directory
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B1.txt  B2.txt  B3.txt  file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rmdir B{1..2}.txt
rmdir: failed to remove 'B1.txt': Not a directory
rmdir: failed to remove 'B2.txt': Not a directory
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B1.txt  B2.txt  B3.txt  file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ rm B{1..2}.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B3.txt  file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ touch B{1..3}.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B1.txt  B2.txt  B3.txt  file1.txt
hazera@hazera-VirtualBox:~/Desktop/Hazera$ mkdir folder{5..10}
hazera@hazera-VirtualBox:~/Desktop/Hazera$ ls
B1.txt  B3.txt     folder10  folder6  folder8
B2.txt  file1.txt  folder5   folder7  folder9
hazera@hazera-VirtualBox:~/Desktop/Hazera$ cd ..
hazera@hazera-VirtualBox:~/Desktop$ ls -a
.  ..  a.out  Hazera  lab.sh  ritu.sh  w.c
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  Hazera  lab.sh  ritu.sh  w.c
hazera@hazera-VirtualBox:~/Desktop$ chmod +x lab.sh
hazera@hazera-VirtualBox:~/Desktop$ ./lab.sh
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  Folder1  Hazera  lab.sh  ritu.sh  text.txt  w.c
hazera@hazera-VirtualBox:~/Desktop$ cd Folder
bash: cd: Folder: No such file or directory
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  Folder1  Hazera  lab.sh  ritu.sh  text.txt  w.c
hazera@hazera-VirtualBox:~/Desktop$ cd Folder1
hazera@hazera-VirtualBox:~/Desktop/Folder1$ cd ..
hazera@hazera-VirtualBox:~/Desktop$ ./lab.sh
hazera@hazera-VirtualBox:~/Desktop$ ls
Ab1  Ab2  Ab3  Ab4  Ab5  Ab6  Ab7  Ab8  Ab9  a.out  Folder1  Hazera  lab.sh  ritu.sh  text.txt  w.c
hazera@hazera-VirtualBox:~/Desktop$ rmdir Ab{1..9}
hazera@hazera-VirtualBox:~/Desktop$ ls
a.out  Folder1  Hazera  lab.sh  ritu.sh  text.txt  w.c
hazera@hazera-VirtualBox:~/Desktop$ cat lab.sh
#!/bin/bash

for (( i=1; i<10; i++ ))
do 
    mkdir Ab$i
done

hazera@hazera-VirtualBox:~/Desktop$ cat lab.sh | grep ir
    mkdir Ab$i
hazera@hazera-VirtualBox:~/Desktop$ cat lab.sh | grep i
#!/bin/bash
for (( i=1; i<10; i++ ))
    mkdir Ab$i
hazera@hazera-VirtualBox:~/Desktop$ locate -i hello
Command 'locate' not found, but can be installed with:
sudo apt install plocate
hazera@hazera-VirtualBox:~/Desktop$ sudo apt install plocate

hazera@hazera-VirtualBox:~/Desktop$ locate hello
/boot/grub/i386-pc/hello.mod
/snap/core22/1748/usr/lib/python3.10/__phello__.foo.py
/snap/core22/1748/usr/lib/python3.10/__pycache__/__phello__.foo.cpython-310.pyc
/snap/core22/1963/usr/lib/python3.10/__phello__.foo.py
/snap/core22/1963/usr/lib/python3.10/__pycache__/__phello__.foo.cpython-310.pyc
/snap/gnome-42-2204/202/usr/lib/python3.10/__phello__.foo.py
/snap/gnome-42-2204/202/usr/lib/x86_64-linux-gnu/peas-demo/plugins/helloworld
/snap/gnome-42-2204/202/usr/lib/x86_64-linux-gnu/peas-demo/plugins/pythonhello
/snap/gnome-42-2204/202/usr/lib/x86_64-linux-gnu/peas-demo/plugins/helloworld/helloworld.plugin
/snap/gnome-42-2204/202/usr/lib/x86_64-linux-gnu/peas-demo/plugins/helloworld/libhelloworld.so
/snap/gnome-42-2204/202/usr/lib/x86_64-linux-gnu/peas-demo/plugins/pythonhello/pythonhello.plugin
/snap/gnome-42-2204/202/usr/lib/x86_64-linux-gnu/peas-demo/plugins/pythonhello/pythonhello.py
/usr/lib/grub/i386-pc/hello.mod
/usr/lib/python3.12/__hello__.py
/usr/lib/python3.12/__phello__
/usr/lib/python3.12/__phello__/__init__.py
/usr/lib/python3.12/__phello__/__pycache__
/usr/lib/python3.12/__phello__/spam.py
/usr/lib/python3.12/__phello__/__pycache__/__init__.cpython-312.pyc
/usr/lib/python3.12/__phello__/__pycache__/spam.cpython-312.pyc
/usr/lib/python3.12/__pycache__/__hello__.cpython-312.pyc
/usr/share/doc/bpfcc-tools/examples/hello_world.py
/usr/share/doc/bpfcc-tools/examples/tracing/hello_fields.py
/usr/share/doc/bpfcc-tools/examples/tracing/hello_perf_output.py
/usr/share/doc/bpfcc-tools/examples/tracing/hello_perf_output_using_ns.py
/usr/share/locale-langpack/en@boldquot/LC_MESSAGES/hello.mo
/usr/share/locale-langpack/en@quot/LC_MESSAGES/hello.mo
/usr/share/locale-langpack/en_AU/LC_MESSAGES/hello.mo
/usr/share/locale-langpack/en_CA/LC_MESSAGES/hello.mo
/usr/share/locale-langpack/en_GB/LC_MESSAGES/hello.mo